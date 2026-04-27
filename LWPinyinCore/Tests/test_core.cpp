#include "lwpy_core.h"

#include <cassert>
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>

static std::vector<std::string> candidates(lwpy_engine_t *engine) {
  lwpy_candidate_t rows[16] = {};
  int count = lwpy_engine_get_candidates(engine, 0, 16, rows);
  std::vector<std::string> out;
  for (int i = 0; i < count; ++i) {
    out.emplace_back(rows[i].text);
  }
  return out;
}

static bool contains(const std::vector<std::string> &items, const std::string &text) {
  for (const auto &item : items) {
    if (item == text) {
      return true;
    }
  }
  return false;
}

static int index_of(lwpy_engine_t *engine, const std::string &text) {
  lwpy_candidate_t rows[32] = {};
  int count = lwpy_engine_get_candidates(engine, 0, 32, rows);
  for (int i = 0; i < count; ++i) {
    if (rows[i].text && text == rows[i].text) {
      return i;
    }
  }
  return -1;
}

int main(int argc, char **argv) {
  const char *resource_dir = argc > 1 ? argv[1] : "Resources";
  lwpy_engine_t *engine = lwpy_engine_create(resource_dir, "");

  assert(lwpy_engine_search_full(engine, "nihao") > 0);
  assert(contains(candidates(engine), "你好"));

  assert(lwpy_engine_search_full(engine, "zg") > 0);
  assert(contains(candidates(engine), "中国"));

  assert(lwpy_engine_search_full(engine, "shurufa") > 0);
  assert(contains(candidates(engine), "输入法"));

  assert(lwpy_engine_search_full(engine, "woxiangshuruyiduanhua") > 0);
  assert(contains(candidates(engine), "我想输入一段话"));

  assert(lwpy_engine_search_full(engine, "congxin") > 0);
  assert(contains(candidates(engine), "重新"));

  assert(lwpy_engine_search_full(engine, "woshizhongguoren") > 0);
  assert(contains(candidates(engine), "我是中国人"));

  assert(lwpy_engine_search_full(engine, "woxiangshuruce") > 0);
  assert(contains(candidates(engine), "我想输入测试"));

  assert(lwpy_engine_search_full(engine, "meiwenti") > 0);
  assert(contains(candidates(engine), "没问题"));

  assert(lwpy_engine_search_full(engine, "bianyichenggong") > 0);
  assert(contains(candidates(engine), "编译成功"));

  assert(lwpy_engine_search_full(engine, "pinyinqiefen") > 0);
  assert(contains(candidates(engine), "拼音切分"));

  assert(lwpy_engine_search_full(engine, "shurufahexin") > 0);
  assert(contains(candidates(engine), "输入法核心"));

  assert(lwpy_engine_search_nine(engine, "64") > 0);
  const char *codes[16] = {};
  int code_count = lwpy_engine_get_sidebar(engine, 0, 16, codes);
  assert(code_count > 0);

  lwpy_engine_destroy(engine);

  const char *learn_path = "/tmp/lwpy_core_test_user.tsv";
  std::remove(learn_path);
  engine = lwpy_engine_create(resource_dir, learn_path);
  assert(lwpy_engine_search_full(engine, "woxiangshuruceshi") > 0);
  int learned_index = index_of(engine, "我想输入测试");
  assert(learned_index >= 0);
  assert(lwpy_engine_choose(engine, learned_index));
  lwpy_engine_destroy(engine);

  engine = lwpy_engine_create(resource_dir, learn_path);
  assert(lwpy_engine_search_full(engine, "woxiangshuruceshi") > 0);
  assert(contains(candidates(engine), "我想输入测试"));
  lwpy_engine_destroy(engine);
  std::remove(learn_path);

  std::cout << "LWPinyinCore tests passed\n";
  return 0;
}
