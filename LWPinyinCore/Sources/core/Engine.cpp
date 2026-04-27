#include "Engine.hpp"

#include <algorithm>
#include <cctype>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <unordered_set>

namespace lwpy {
namespace {

bool StartsWith(const std::string &text, const std::string &prefix) {
  return text.size() >= prefix.size() && text.compare(0, prefix.size(), prefix) == 0;
}

std::string FuzzyNormalize(const std::string &text) {
  std::string out;
  for (size_t i = 0; i < text.size();) {
    if (text.compare(i, 2, "zh") == 0 || text.compare(i, 2, "ch") == 0 || text.compare(i, 2, "sh") == 0) {
      out.push_back(text[i]);
      i += 2;
    } else if (text.compare(i, 3, "ang") == 0) {
      out += "an";
      i += 3;
    } else if (text.compare(i, 3, "eng") == 0) {
      out += "en";
      i += 3;
    } else if (text.compare(i, 3, "ing") == 0) {
      out += "in";
      i += 3;
    } else if (text.compare(i, 2, "ou") == 0) {
      out += "o";
      i += 2;
    } else {
      char ch = text[i++];
      if (ch == 'l') {
        ch = 'n';
      }
      out.push_back(ch);
    }
  }
  return out;
}

bool FuzzyStartsWith(const std::string &text, const std::string &prefix) {
  return StartsWith(FuzzyNormalize(text), FuzzyNormalize(prefix));
}

void UpsertCandidate(std::vector<Candidate> &candidates, std::unordered_map<std::string, size_t> &index,
                     const Candidate &candidate) {
  auto it = index.find(candidate.text);
  if (it == index.end()) {
    index[candidate.text] = candidates.size();
    candidates.push_back(candidate);
    return;
  }
  Candidate &existing = candidates[it->second];
  if (candidate.score > existing.score) {
    existing = candidate;
  }
}

std::vector<std::string> SplitTabs(const std::string &line) {
  std::vector<std::string> parts;
  std::string item;
  std::stringstream ss(line);
  while (std::getline(ss, item, '\t')) {
    parts.push_back(item);
  }
  return parts;
}

std::vector<std::string> SplitCodeSyllables(const std::string &code) {
  std::vector<std::string> syllables;
  std::string item;
  for (unsigned char ch : code) {
    if (std::isalpha(ch)) {
      item.push_back(static_cast<char>(std::tolower(ch)));
    } else if (!item.empty()) {
      syllables.push_back(item);
      item.clear();
    }
  }
  if (!item.empty()) {
    syllables.push_back(item);
  }
  if (syllables.empty()) {
    std::string compact = CompactCode(code);
    if (!compact.empty()) {
      syllables.push_back(compact);
    }
  }
  return syllables;
}

std::string CandidateKey(const Entry &entry) {
  return entry.text + "\t" + entry.compact_code;
}

std::string CandidateKey(const std::string &text, const std::string &code) {
  return text + "\t" + CompactCode(code);
}

char DigitForLetter(char ch) {
  switch (ch) {
    case 'a':
    case 'b':
    case 'c':
      return '2';
    case 'd':
    case 'e':
    case 'f':
      return '3';
    case 'g':
    case 'h':
    case 'i':
      return '4';
    case 'j':
    case 'k':
    case 'l':
      return '5';
    case 'm':
    case 'n':
    case 'o':
      return '6';
    case 'p':
    case 'q':
    case 'r':
    case 's':
      return '7';
    case 't':
    case 'u':
    case 'v':
      return '8';
    case 'w':
    case 'x':
    case 'y':
    case 'z':
      return '9';
    default:
      return '\0';
  }
}

}  // namespace

std::string NormalizeLetters(const std::string &input) {
  std::string out;
  for (unsigned char ch : input) {
    if (std::isalpha(ch)) {
      out.push_back(static_cast<char>(std::tolower(ch)));
    }
  }
  return out;
}

std::string NormalizeDigits(const std::string &input) {
  std::string out;
  for (unsigned char ch : input) {
    if (ch >= '0' && ch <= '9') {
      out.push_back(static_cast<char>(ch));
    }
  }
  return out;
}

std::string CompactCode(const std::string &code) {
  return NormalizeLetters(code);
}

std::string Initials(const std::string &code) {
  std::string out;
  bool at_start = true;
  for (unsigned char ch : code) {
    if (std::isalpha(ch)) {
      if (at_start) {
        out.push_back(static_cast<char>(std::tolower(ch)));
      }
      at_start = false;
    } else {
      at_start = true;
    }
  }
  if (out.empty()) {
    out = NormalizeLetters(code);
  }
  return out;
}

std::string DigitsForCode(const std::string &compact_code) {
  std::string out;
  for (char ch : compact_code) {
    char digit = DigitForLetter(ch);
    if (digit != '\0') {
      out.push_back(digit);
    }
  }
  return out;
}

Engine::Engine(const std::string &resource_dir, const std::string &user_db_path) {
  user_db_path_ = user_db_path;
  LoadLexicon(resource_dir);
  if (entries_.empty()) {
    LoadBuiltinLexicon();
  }
  LoadLearned(user_db_path_);
  Reset();
}

void Engine::Reset() {
  candidates_.clear();
  sidebar_.clear();
  input_.clear();
  composition_.clear();
  selected_nine_code_.clear();
  commit_text_.clear();
  mode_ = Mode::Full;
}

bool Engine::SetInput(const std::string &input) {
  input_ = mode_ == Mode::Nine ? NormalizeDigits(input) : NormalizeLetters(input);
  composition_ = input_;
  return !input_.empty();
}

bool Engine::Backspace() {
  if (input_.empty()) {
    return false;
  }
  input_.pop_back();
  composition_ = input_;
  selected_nine_code_.clear();
  if (mode_ == Mode::Nine) {
    RebuildSidebar();
    RebuildNineCandidates();
  } else {
    RebuildFullCandidates();
  }
  return true;
}

int Engine::SearchFull(const std::string &pinyin) {
  mode_ = Mode::Full;
  input_ = NormalizeLetters(pinyin);
  composition_ = input_;
  selected_nine_code_.clear();
  RebuildFullCandidates();
  return CandidateCount();
}

int Engine::SearchNine(const std::string &digits) {
  mode_ = Mode::Nine;
  input_ = NormalizeDigits(digits);
  selected_nine_code_.clear();
  RebuildSidebar();
  RebuildNineCandidates();
  composition_ = selected_nine_code_.empty() ? input_ : selected_nine_code_;
  return CandidateCount();
}

const std::string &Engine::Composition() const {
  return composition_;
}

int Engine::CandidateCount() const {
  return static_cast<int>(candidates_.size());
}

std::vector<Candidate> Engine::Candidates(int start, int count) const {
  std::vector<Candidate> out;
  if (start < 0 || count <= 0 || start >= CandidateCount()) {
    return out;
  }
  int end = std::min(start + count, CandidateCount());
  for (int i = start; i < end; ++i) {
    out.push_back(candidates_[static_cast<size_t>(i)]);
  }
  return out;
}

bool Engine::Choose(int index) {
  if (index < 0 || index >= CandidateCount()) {
    return false;
  }
  const Candidate &candidate = candidates_[static_cast<size_t>(index)];
  commit_text_ = candidate.text;
  learned_[CandidateKey(candidate.text, candidate.code)] += 1;
  SaveLearned();
  return true;
}

const std::string &Engine::CommitText() const {
  return commit_text_;
}

std::vector<std::string> Engine::Sidebar(int start, int count) const {
  std::vector<std::string> out;
  if (start < 0 || count <= 0 || start >= static_cast<int>(sidebar_.size())) {
    return out;
  }
  int end = std::min(start + count, static_cast<int>(sidebar_.size()));
  for (int i = start; i < end; ++i) {
    out.push_back(sidebar_[static_cast<size_t>(i)]);
  }
  return out;
}

int Engine::SelectSidebar(int index) {
  if (index < 0 || index >= static_cast<int>(sidebar_.size())) {
    selected_nine_code_.clear();
  } else {
    selected_nine_code_ = sidebar_[static_cast<size_t>(index)];
  }
  composition_ = selected_nine_code_.empty() ? input_ : selected_nine_code_;
  RebuildNineCandidates();
  return CandidateCount();
}

void Engine::LoadLexicon(const std::string &resource_dir) {
  if (resource_dir.empty()) {
    return;
  }
  std::string path = resource_dir;
  if (!path.empty() && path.back() != '/') {
    path += '/';
  }
  path += "lexicon.tsv";

  std::ifstream file(path);
  if (!file.is_open()) {
    return;
  }

  std::string line;
  while (std::getline(file, line)) {
    if (line.empty() || line[0] == '#') {
      continue;
    }
    std::vector<std::string> parts = SplitTabs(line);
    if (parts.size() < 3) {
      continue;
    }
    AddEntry(parts[0], parts[1], std::stod(parts[2]));
  }
}

void Engine::LoadBuiltinLexicon() {
  const char *rows[][3] = {
      {"你", "ni", "90000"},       {"你好", "ni hao", "100000"},
      {"呢", "ne", "30000"},       {"好", "hao", "85000"},
      {"中国", "zhong guo", "98000"}, {"中文", "zhong wen", "76000"},
      {"中", "zhong", "70000"},    {"国", "guo", "65000"},
      {"输入法", "shu ru fa", "90000"}, {"输入", "shu ru", "70000"},
      {"手机", "shou ji", "70000"}, {"苹果", "ping guo", "65000"},
      {"今天", "jin tian", "70000"}, {"明天", "ming tian", "60000"},
      {"我", "wo", "95000"},       {"我们", "wo men", "90000"},
      {"想", "xiang", "60000"},    {"一段", "yi duan", "40000"},
      {"话", "hua", "50000"},      {"候选", "hou xuan", "40000"},
      {"键盘", "jian pan", "52000"}, {"拼音", "pin yin", "72000"},
      {"项目", "xiang mu", "42000"}, {"测试", "ce shi", "50000"},
      {"我的", "wo de", "65000"}, {"重新", "chong xin", "40000"},
      {"实现", "shi xian", "45000"}, {"核心", "he xin", "43000"},
      {"候选词", "hou xuan ci", "42000"}, {"质量", "zhi liang", "40000"},
      {"学习", "xue xi", "48000"}, {"用户", "yong hu", "50000"},
      {"词库", "ci ku", "46000"}, {"持久化", "chi jiu hua", "35000"},
      {"模糊音", "mo hu yin", "36000"}, {"排序", "pai xu", "36000"},
      {"我想", "wo xiang", "62000"}, {"我想输入", "wo xiang shu ru", "56000"},
      {"一段话", "yi duan hua", "52000"}, {"我想输入一段话", "wo xiang shu ru yi duan hua", "50000"},
  };
  for (const auto &row : rows) {
    AddEntry(row[0], row[1], std::stod(row[2]));
  }
}

void Engine::LoadLearned(const std::string &user_db_path) {
  if (user_db_path.empty()) {
    return;
  }
  std::ifstream file(user_db_path);
  if (!file.is_open()) {
    return;
  }
  std::string line;
  while (std::getline(file, line)) {
    std::vector<std::string> parts = SplitTabs(line);
    if (parts.size() < 3) {
      continue;
    }
    std::string text = parts[0];
    std::string code = CompactCode(parts[1]);
    int count = std::max(0, std::stoi(parts[2]));
    if (text.empty() || code.empty() || count <= 0) {
      continue;
    }
    learned_[text + "\t" + code] = count;
    std::string entry_key = text + "\t" + code;
    if (learned_entry_keys_.insert(entry_key).second) {
      AddEntry(text, code, 30000.0 + static_cast<double>(count) * 1000.0);
    }
  }
}

void Engine::SaveLearned() const {
  if (user_db_path_.empty()) {
    return;
  }
  std::ofstream file(user_db_path_, std::ios::trunc);
  if (!file.is_open()) {
    return;
  }
  for (const auto &row : learned_) {
    size_t tab = row.first.find('\t');
    if (tab == std::string::npos) {
      continue;
    }
    file << row.first.substr(0, tab) << '\t' << CompactCode(row.first.substr(tab + 1)) << '\t' << row.second << '\n';
  }
}

void Engine::AddEntry(const std::string &text, const std::string &code, double base_score) {
  Entry entry;
  entry.text = text;
  entry.code = code;
  entry.compact_code = CompactCode(entry.code);
  entry.initials = Initials(entry.code);
  entry.digits = DigitsForCode(entry.compact_code);
  entry.syllables = SplitCodeSyllables(entry.code);
  entry.base_score = base_score;
  if (!entry.text.empty() && !entry.compact_code.empty()) {
    entries_.push_back(entry);
  }
}

void Engine::RebuildFullCandidates() {
  candidates_.clear();
  if (input_.empty()) {
    return;
  }

  std::unordered_map<std::string, size_t> seen;
  for (const Entry &entry : entries_) {
    bool exact_code = StartsWith(entry.compact_code, input_);
    bool exact_initials = StartsWith(entry.initials, input_);
    bool fuzzy_code = !exact_code && FuzzyStartsWith(entry.compact_code, input_);
    if (!exact_code && !exact_initials && !fuzzy_code) {
      continue;
    }

    double score = entry.base_score + LearnedScore(entry);
    if (entry.compact_code == input_) {
      score += 5000.0;
    }
    if (fuzzy_code) {
      score -= 1200.0;
    }
    if (exact_initials && !exact_code) {
      score -= 1000.0;
    }

    UpsertCandidate(candidates_, seen, {entry.text, entry.compact_code, score});
  }

  std::sort(candidates_.begin(), candidates_.end(), [](const Candidate &lhs, const Candidate &rhs) {
    if (lhs.score == rhs.score) {
      return lhs.text.size() > rhs.text.size();
    }
    return lhs.score > rhs.score;
  });

  RebuildSegmentCandidates();
}

void Engine::RebuildSegmentCandidates() {
  struct Beam {
    std::string text;
    std::string code;
    double score = 0.0;
    int parts = 0;
  };

  const size_t n = input_.size();
  std::vector<std::vector<Beam>> beams(n + 1);
  std::vector<Beam> partials;
  beams[0].push_back({"", "", 0.0, 0});

  for (size_t pos = 0; pos < n; ++pos) {
    if (beams[pos].empty()) {
      continue;
    }
    for (const Entry &entry : entries_) {
      if (entry.compact_code.empty()) {
        continue;
      }

      size_t rest = n - pos;
      bool full_match = rest >= entry.compact_code.size() &&
                        input_.compare(pos, entry.compact_code.size(), entry.compact_code) == 0;
      bool partial_tail_match = !full_match && rest > 0 && StartsWith(entry.compact_code, input_.substr(pos));
      if (!full_match && !partial_tail_match) {
        continue;
      }

      for (const Beam &beam : beams[pos]) {
        Beam merged;
        merged.text = beam.text + entry.text;
        merged.code = beam.code.empty() ? entry.compact_code : beam.code + " " + entry.compact_code;
        merged.score = beam.score + entry.base_score + LearnedScore(entry) - 2500.0 * beam.parts;
        merged.parts = beam.parts + 1;
        if (full_match) {
          std::vector<Beam> &next = beams[pos + entry.compact_code.size()];
          next.push_back(merged);
          std::sort(next.begin(), next.end(), [](const Beam &lhs, const Beam &rhs) {
            return lhs.score > rhs.score;
          });
          if (next.size() > 24) {
            next.resize(24);
          }
        } else if (merged.parts > 1) {
          merged.score -= 7000.0;
          partials.push_back(merged);
        }
      }
    }
  }

  std::unordered_map<std::string, size_t> seen;
  for (const Candidate &candidate : candidates_) {
    seen[candidate.text] = seen.size();
  }
  for (const Beam &beam : beams[n]) {
    if (beam.parts < 2 || beam.text.empty()) {
      continue;
    }
    UpsertCandidate(candidates_, seen, {beam.text, beam.code, beam.score + 3000.0});
  }
  std::sort(partials.begin(), partials.end(), [](const Beam &lhs, const Beam &rhs) {
    return lhs.score > rhs.score;
  });
  if (partials.size() > 12) {
    partials.resize(12);
  }
  for (const Beam &beam : partials) {
    UpsertCandidate(candidates_, seen, {beam.text, beam.code, beam.score});
  }
  std::sort(candidates_.begin(), candidates_.end(), [](const Candidate &lhs, const Candidate &rhs) {
    if (lhs.score == rhs.score) {
      return lhs.text.size() > rhs.text.size();
    }
    return lhs.score > rhs.score;
  });
}

void Engine::RebuildNineCandidates() {
  candidates_.clear();
  if (input_.empty()) {
    return;
  }

  std::unordered_map<std::string, size_t> seen;
  for (const Entry &entry : entries_) {
    if (!StartsWith(entry.digits, input_)) {
      continue;
    }
    if (!selected_nine_code_.empty() && !StartsWith(entry.compact_code, selected_nine_code_)) {
      continue;
    }
    double score = entry.base_score + LearnedScore(entry);
    if (!selected_nine_code_.empty() && entry.compact_code == selected_nine_code_) {
      score += 5000.0;
    }
    UpsertCandidate(candidates_, seen, {entry.text, entry.compact_code, score});
  }

  std::sort(candidates_.begin(), candidates_.end(), [](const Candidate &lhs, const Candidate &rhs) {
    if (lhs.score == rhs.score) {
      return lhs.code < rhs.code;
    }
    return lhs.score > rhs.score;
  });
}

void Engine::RebuildSidebar() {
  sidebar_.clear();
  if (input_.empty()) {
    return;
  }

  std::unordered_map<std::string, double> scores;
  for (const Entry &entry : entries_) {
    if (StartsWith(entry.digits, input_)) {
      scores[entry.compact_code] += entry.base_score + LearnedScore(entry);
    }
  }

  std::vector<std::pair<std::string, double>> rows(scores.begin(), scores.end());
  std::sort(rows.begin(), rows.end(), [](const auto &lhs, const auto &rhs) {
    if (lhs.first.size() == rhs.first.size()) {
      return lhs.second > rhs.second;
    }
    return lhs.first.size() < rhs.first.size();
  });

  for (const auto &row : rows) {
    sidebar_.push_back(row.first);
  }
}

double Engine::LearnedScore(const Entry &entry) const {
  auto it = learned_.find(CandidateKey(entry));
  if (it == learned_.end()) {
    return 0.0;
  }
  return static_cast<double>(it->second) * 10000.0;
}

}  // namespace lwpy
