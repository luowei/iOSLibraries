#include "lwpy_core.h"

#include "Engine.hpp"

#include <memory>
#include <string>
#include <vector>

struct lwpy_engine {
  explicit lwpy_engine(const char *resource_dir, const char *user_db_path)
      : impl(resource_dir ? resource_dir : "", user_db_path ? user_db_path : "") {}

  lwpy::Engine impl;
  std::vector<lwpy::Candidate> last_candidates;
  std::vector<std::string> last_sidebar;
};

lwpy_engine_t *lwpy_engine_create(const char *resource_dir, const char *user_db_path) {
  return new lwpy_engine(resource_dir, user_db_path);
}

void lwpy_engine_destroy(lwpy_engine_t *engine) {
  delete engine;
}

void lwpy_engine_reset(lwpy_engine_t *engine) {
  if (engine) {
    engine->impl.Reset();
  }
}

bool lwpy_engine_set_input(lwpy_engine_t *engine, const char *input) {
  return engine && engine->impl.SetInput(input ? input : "");
}

bool lwpy_engine_backspace(lwpy_engine_t *engine) {
  return engine && engine->impl.Backspace();
}

int lwpy_engine_search_full(lwpy_engine_t *engine, const char *pinyin) {
  return engine ? engine->impl.SearchFull(pinyin ? pinyin : "") : 0;
}

int lwpy_engine_search_nine(lwpy_engine_t *engine, const char *digits) {
  return engine ? engine->impl.SearchNine(digits ? digits : "") : 0;
}

const char *lwpy_engine_composition(lwpy_engine_t *engine) {
  return engine ? engine->impl.Composition().c_str() : "";
}

int lwpy_engine_candidate_count(lwpy_engine_t *engine) {
  return engine ? engine->impl.CandidateCount() : 0;
}

int lwpy_engine_get_candidates(lwpy_engine_t *engine, int start, int count, lwpy_candidate_t *out) {
  if (!engine || !out || count <= 0) {
    return 0;
  }
  engine->last_candidates = engine->impl.Candidates(start, count);
  for (size_t i = 0; i < engine->last_candidates.size(); ++i) {
    const lwpy::Candidate &candidate = engine->last_candidates[i];
    out[i].text = candidate.text.c_str();
    out[i].code = candidate.code.c_str();
    out[i].score = candidate.score;
  }
  return static_cast<int>(engine->last_candidates.size());
}

bool lwpy_engine_choose(lwpy_engine_t *engine, int index) {
  return engine && engine->impl.Choose(index);
}

const char *lwpy_engine_commit_text(lwpy_engine_t *engine) {
  return engine ? engine->impl.CommitText().c_str() : "";
}

int lwpy_engine_get_sidebar(lwpy_engine_t *engine, int start, int count, const char **out_codes) {
  if (!engine || !out_codes || count <= 0) {
    return 0;
  }
  engine->last_sidebar = engine->impl.Sidebar(start, count);
  for (size_t i = 0; i < engine->last_sidebar.size(); ++i) {
    out_codes[i] = engine->last_sidebar[i].c_str();
  }
  return static_cast<int>(engine->last_sidebar.size());
}

int lwpy_engine_select_sidebar(lwpy_engine_t *engine, int index) {
  return engine ? engine->impl.SelectSidebar(index) : 0;
}
