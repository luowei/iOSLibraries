#ifndef LWPINYINCORE_ENGINE_HPP
#define LWPINYINCORE_ENGINE_HPP

#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

namespace lwpy {

struct Entry {
  std::string text;
  std::string code;
  std::string compact_code;
  std::string initials;
  std::string digits;
  std::vector<std::string> syllables;
  double base_score = 0.0;
};

struct Candidate {
  std::string text;
  std::string code;
  double score = 0.0;
};

class Engine {
 public:
  Engine(const std::string &resource_dir, const std::string &user_db_path);

  void Reset();
  bool SetInput(const std::string &input);
  bool Backspace();

  int SearchFull(const std::string &pinyin);
  int SearchNine(const std::string &digits);

  const std::string &Composition() const;
  int CandidateCount() const;
  std::vector<Candidate> Candidates(int start, int count) const;

  bool Choose(int index);
  const std::string &CommitText() const;

  std::vector<std::string> Sidebar(int start, int count) const;
  int SelectSidebar(int index);

 private:
  enum class Mode {
    Full,
    Nine,
  };

  void LoadLexicon(const std::string &resource_dir);
  void LoadBuiltinLexicon();
  void LoadLearned(const std::string &user_db_path);
  void SaveLearned() const;
  void AddEntry(const std::string &text, const std::string &code, double base_score);
  void RebuildFullCandidates();
  void RebuildSegmentCandidates();
  void RebuildNineCandidates();
  void RebuildSidebar();
  double LearnedScore(const Entry &entry) const;

  std::vector<Entry> entries_;
  std::vector<Candidate> candidates_;
  std::vector<std::string> sidebar_;
  std::unordered_map<std::string, int> learned_;
  std::unordered_set<std::string> learned_entry_keys_;
  std::string user_db_path_;
  std::string input_;
  std::string composition_;
  std::string selected_nine_code_;
  std::string commit_text_;
  Mode mode_ = Mode::Full;
};

std::string NormalizeLetters(const std::string &input);
std::string NormalizeDigits(const std::string &input);
std::string CompactCode(const std::string &code);
std::string Initials(const std::string &code);
std::string DigitsForCode(const std::string &compact_code);

}  // namespace lwpy

#endif
