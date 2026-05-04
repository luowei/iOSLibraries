# Graph Report - /Users/luowei/projects/libs/LWPinyinCore  (2026-05-04)

## Corpus Check
- Corpus is ~4,807 words - fits in a single context window. You may not need a graph.

## Summary
- 84 nodes · 159 edges · 8 communities detected
- Extraction: 95% EXTRACTED · 5% INFERRED · 0% AMBIGUOUS · INFERRED: 8 edges (avg confidence: 0.8)
- Token cost: 0 input · 0 output

## Community Hubs (Navigation)
- [[_COMMUNITY_Community 0|Community 0]]
- [[_COMMUNITY_Community 1|Community 1]]
- [[_COMMUNITY_Community 3|Community 3]]
- [[_COMMUNITY_Community 4|Community 4]]
- [[_COMMUNITY_Community 5|Community 5]]
- [[_COMMUNITY_Community 6|Community 6]]
- [[_COMMUNITY_Community 7|Community 7]]
- [[_COMMUNITY_Community 8|Community 8]]

## God Nodes (most connected - your core abstractions)
1. `LWPinyinCoreService` - 13 edges
2. `main()` - 12 edges
3. `RebuildFullCandidates()` - 10 edges
4. `RebuildNineCandidates()` - 9 edges
5. `AddEntry()` - 8 edges
6. `StartsWith()` - 7 edges
7. `CompactCode()` - 7 edges
8. `LoadLearned()` - 7 edges
9. `RebuildSegmentCandidates()` - 7 edges
10. `Engine()` - 6 edges

## Surprising Connections (you probably didn't know these)
- `main()` --calls--> `lwpy_engine_create()`  [INFERRED]
  Tests/test_core.cpp → Sources/core/lwpy_core.cpp
- `main()` --calls--> `lwpy_engine_search_full()`  [INFERRED]
  Tests/test_core.cpp → Sources/core/lwpy_core.cpp
- `main()` --calls--> `lwpy_engine_search_nine()`  [INFERRED]
  Tests/test_core.cpp → Sources/core/lwpy_core.cpp
- `main()` --calls--> `lwpy_engine_get_sidebar()`  [INFERRED]
  Tests/test_core.cpp → Sources/core/lwpy_core.cpp
- `main()` --calls--> `lwpy_engine_destroy()`  [INFERRED]
  Tests/test_core.cpp → Sources/core/lwpy_core.cpp

## Communities (12 total, 0 thin omitted)

### Community 0 - "Community 0"
Cohesion: 0.27
Nodes (16): Backspace(), CandidateKey(), EntryMatchesInputPiece(), FuzzyNormalize(), FuzzyStartsWith(), IsValidPinyinPrefix(), LearnedScore(), RebuildFullCandidates() (+8 more)

### Community 1 - "Community 1"
Cohesion: 0.14
Nodes (13): LWPinyinCoreService, -backspace, -candidatesFromcount, -chooseCandidateAtIndex, -commitText, -compositionString, -dealloc, -initWithResourcePathuserDBPath (+5 more)

### Community 3 - "Community 3"
Cohesion: 0.25
Nodes (8): Engine(), LoadBuiltinLexicon(), LoadLearned(), LoadLexicon(), ParseInt(), ParseUInt64(), Reset(), SplitTabs()

### Community 4 - "Community 4"
Cohesion: 0.43
Nodes (6): CandidateCount(), Candidates(), Choose(), SaveLearned(), SearchFull(), SelectSidebar()

### Community 5 - "Community 5"
Cohesion: 0.29
Nodes (7): lwpy_engine_choose(), lwpy_engine_create(), lwpy_engine_destroy(), lwpy_engine_get_sidebar(), lwpy_engine_search_full(), lwpy_engine_search_nine(), main()

### Community 6 - "Community 6"
Cohesion: 0.38
Nodes (6): lwpy_engine_get_candidates(), candidates(), contains(), file_has_four_columns(), first_candidate(), index_of()

### Community 7 - "Community 7"
Cohesion: 0.4
Nodes (6): AddEntry(), CompactCode(), DigitForLetter(), DigitsForCode(), SplitCodeSyllables(), SplitCompactPinyinSyllables()

### Community 8 - "Community 8"
Cohesion: 0.5
Nodes (4): Initials(), NormalizeDigits(), NormalizeLetters(), SetInput()

## Knowledge Gaps
- **12 isolated node(s):** `-initWithResourcePathuserDBPath`, `-dealloc`, `-searchFull`, `-searchNine`, `-compositionString` (+7 more)
  These have ≤1 connection - possible missing edges or undocumented components.

## Suggested Questions
_Questions this graph is uniquely positioned to answer:_

- **Why does `main()` connect `Community 5` to `Community 6`?**
  _High betweenness centrality (0.024) - this node is a cross-community bridge._
- **Why does `Engine()` connect `Community 3` to `Community 4`?**
  _High betweenness centrality (0.013) - this node is a cross-community bridge._
- **Are the 6 inferred relationships involving `main()` (e.g. with `lwpy_engine_create()` and `lwpy_engine_search_full()`) actually correct?**
  _`main()` has 6 INFERRED edges - model-reasoned connections that need verification._
- **What connects `-initWithResourcePathuserDBPath`, `-dealloc`, `-searchFull` to the rest of the system?**
  _12 weakly-connected nodes found - possible documentation gaps or missing edges._
- **Should `Community 1` be split into smaller, more focused modules?**
  _Cohesion score 0.14 - nodes in this community are weakly interconnected._