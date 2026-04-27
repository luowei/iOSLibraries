#ifndef LWPY_CORE_H
#define LWPY_CORE_H

#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct lwpy_engine lwpy_engine_t;

typedef struct {
  const char *text;
  const char *code;
  double score;
} lwpy_candidate_t;

lwpy_engine_t *lwpy_engine_create(const char *resource_dir, const char *user_db_path);
void lwpy_engine_destroy(lwpy_engine_t *engine);

void lwpy_engine_reset(lwpy_engine_t *engine);
bool lwpy_engine_set_input(lwpy_engine_t *engine, const char *input);
bool lwpy_engine_backspace(lwpy_engine_t *engine);

int lwpy_engine_search_full(lwpy_engine_t *engine, const char *pinyin);
int lwpy_engine_search_nine(lwpy_engine_t *engine, const char *digits);

const char *lwpy_engine_composition(lwpy_engine_t *engine);
int lwpy_engine_candidate_count(lwpy_engine_t *engine);
int lwpy_engine_get_candidates(lwpy_engine_t *engine, int start, int count, lwpy_candidate_t *out);

bool lwpy_engine_choose(lwpy_engine_t *engine, int index);
const char *lwpy_engine_commit_text(lwpy_engine_t *engine);

int lwpy_engine_get_sidebar(lwpy_engine_t *engine, int start, int count, const char **out_codes);
int lwpy_engine_select_sidebar(lwpy_engine_t *engine, int index);

#ifdef __cplusplus
}
#endif

#endif
