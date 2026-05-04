# Graph Report - /Users/luowei/projects/libs/LWWordEngine  (2026-05-04)

## Corpus Check
- Corpus is ~24,309 words - fits in a single context window. You may not need a graph.

## Summary
- 432 nodes · 422 edges · 24 communities detected
- Extraction: 99% EXTRACTED · 1% INFERRED · 0% AMBIGUOUS · INFERRED: 5 edges (avg confidence: 0.8)
- Token cost: 0 input · 0 output

## Community Hubs (Navigation)
- [[_COMMUNITY_Community 0|Community 0]]
- [[_COMMUNITY_Community 1|Community 1]]
- [[_COMMUNITY_Community 2|Community 2]]
- [[_COMMUNITY_Community 3|Community 3]]
- [[_COMMUNITY_Community 4|Community 4]]
- [[_COMMUNITY_Community 5|Community 5]]
- [[_COMMUNITY_Community 6|Community 6]]
- [[_COMMUNITY_Community 7|Community 7]]
- [[_COMMUNITY_Community 8|Community 8]]
- [[_COMMUNITY_Community 9|Community 9]]
- [[_COMMUNITY_Community 10|Community 10]]
- [[_COMMUNITY_Community 11|Community 11]]
- [[_COMMUNITY_Community 12|Community 12]]
- [[_COMMUNITY_Community 13|Community 13]]
- [[_COMMUNITY_Community 14|Community 14]]
- [[_COMMUNITY_Community 15|Community 15]]
- [[_COMMUNITY_Community 16|Community 16]]
- [[_COMMUNITY_Community 17|Community 17]]
- [[_COMMUNITY_Community 18|Community 18]]
- [[_COMMUNITY_Community 19|Community 19]]
- [[_COMMUNITY_Community 20|Community 20]]
- [[_COMMUNITY_Community 21|Community 21]]
- [[_COMMUNITY_Community 22|Community 22]]
- [[_COMMUNITY_Community 23|Community 23]]

## God Nodes (most connected - your core abstractions)
1. `LWPinyinService` - 26 edges
2. `LWSymbolService` - 25 edges
3. `LWInstanceFactory` - 20 edges
4. `LWWordsService` - 18 edges
5. `RCInputCoreService` - 17 edges
6. `LWSymbolService` - 17 edges
7. `LWInstanceFactory` - 17 edges
8. `LWWordsService` - 17 edges
9. `LWBihuaService` - 16 edges
10. `LWWubiService` - 15 edges

## Surprising Connections (you probably didn't know these)
- `LWWord` --inherits--> `NSObject`  [EXTRACTED]
  LWWordEngine_swift/Swift/WordEngine/Models/LWWord.swift →   _Bridges community 1 → community 15_
- `LWWordsService` --inherits--> `NSObject`  [EXTRACTED]
  LWWordEngine_swift/Swift/WordEngine/Services/LWWordsService.swift →   _Bridges community 1 → community 9_

## Communities (42 total, 4 thin omitted)

### Community 0 - "Community 0"
Cohesion: 0.05
Nodes (8): LWPinYinService, LWWordsService, LWBihuaService, LWEnlishService, LWHandwrittingService, LWHybridService, LWPyCoreService, LWWubiService

### Community 1 - "Community 1"
Cohesion: 0.08
Nodes (7): LWMarsItem, LWMarsService, LWCategory, LWSymbol, LWSymbolService, NSCopying, NSObject

### Community 2 - "Community 2"
Cohesion: 0.06
Nodes (31): LWCategory, -copyWithZone, -initWithIdtypenameen_namefile_urlhttp_urlselectorder, LWSymbol, -copyWithZone, -initWithIdcategoryIdtitletextfile_urlhttp_urlfrequencyorder, LWSymbolService, -categoriesWithType (+23 more)

### Community 3 - "Community 3"
Cohesion: 0.07
Nodes (26): LWPinyinService, -backspaceAChar, -checkFullWords, -checkNineWords, -codeViewNameWithNineIdxChars, -dealloc, -getPinYinNinegridIndexData, -initWithDBPath (+18 more)

### Community 4 - "Community 4"
Cohesion: 0.08
Nodes (9): RCInputCoreService, Int, KeyboardType, bihuaNine, enFull, handWriting, pingYingFull, pingYingNine (+1 more)

### Community 5 - "Community 5"
Cohesion: 0.09
Nodes (21): LWWord, -copyWithZone, -initWithIdcodeword, LWWordsService, -backspaceAChar, -checkFullWords, -checkNineWords, -getPinYinNinegridIndexData (+13 more)

### Community 6 - "Community 6"
Cohesion: 0.1
Nodes (20): LWInstanceFactory, -bundlePathWithBundleFileNamebundleURLString, -copyBundle2docdata, -copydb2docdata, -currentKeyboardType, -dbPathWithBunleName, -dbPathWithDBFileNamedbURLString, -exsitBundleFileName (+12 more)

### Community 8 - "Community 8"
Cohesion: 0.12
Nodes (16): LWBihuaService, -backspaceAChar, -convert2NumCode, -dealloc, -execSql, -initWithDBPath, -inputAChar, -morePredictiveWithPageSize (+8 more)

### Community 10 - "Community 10"
Cohesion: 0.12
Nodes (15): LWWubiService, -backspaceAChar, -dealloc, -execSql, -initWithDBPath, -inputAChar, -morePredictiveWithPageSize, -openDatabase (+7 more)

### Community 11 - "Community 11"
Cohesion: 0.12
Nodes (15): LWPyCoreService, -backspaceAChar, -checkFullWords, -checkNineWords, -getPinYinNinegridIndexData, -init, -inputAChar, -morePredictiveWithStartIndexpageSize (+7 more)

### Community 12 - "Community 12"
Cohesion: 0.12
Nodes (15): LWEnlishService, -backspaceAChar, -dealloc, -execSql, -initWithDBPath, -inputAChar, -morePredictiveWithPageSize, -openDatabase (+7 more)

### Community 13 - "Community 13"
Cohesion: 0.12
Nodes (15): LWMarsItem, -copyWithZone, -initWithIdsourceTextconvertedText, LWMarsService, -dealloc, -execSql, -getAllSimplify2Mars, -getAllSimplify2Traditional (+7 more)

### Community 14 - "Community 14"
Cohesion: 0.13
Nodes (14): LWHybridService, -backspaceAChar, -checkFullWords, -dealloc, -inputAChar, -inputCharaters, -morePredictiveWithPageSize, -predResultsArray (+6 more)

### Community 15 - "Community 15"
Cohesion: 0.15
Nodes (8): Codable, CodingKey, CodingKeys, code, id, word, LWWord, String

### Community 17 - "Community 17"
Cohesion: 0.18
Nodes (10): LWHandwrittingService, -backspaceAChar, -createBodyWithBoundaryparametersfileDatamimetypefieldNamefileName, -init, -inputAChar, -morePredictiveWithPageSize, -predResultsArray, -queryWords (+2 more)

### Community 19 - "Community 19"
Cohesion: 0.25
Nodes (7): LWAppDelegate, -applicationDidBecomeActive, -applicationDidEnterBackground, -applicationdidFinishLaunchingWithOptions, -applicationWillEnterForeground, -applicationWillResignActive, -applicationWillTerminate

### Community 20 - "Community 20"
Cohesion: 0.29
Nodes (6): NSBundle, -load, -myResourcePath, NSObject, -lwim_swizzleClassMethodwithMethod, -lwim_swizzleMethodwithMethod

### Community 21 - "Community 21"
Cohesion: 0.29
Nodes (6): KeyboardViewController, -textDidChange, -textWillChange, -updateViewConstraints, -viewDidLoad, -viewWillLayoutSubviews

### Community 22 - "Community 22"
Cohesion: 0.33
Nodes (5): NSArray, -containsStringItem, NSString, -eg_enumerateCharactersUsingBlock, -eg_isBlank

### Community 23 - "Community 23"
Cohesion: 0.5
Nodes (3): LWViewController, -settingBtnAction, -viewDidLoad

## Knowledge Gaps
- **212 isolated node(s):** `-factory`, `-releaseAllService`, `-traditionalDict`, `-unLoadTraditionalDict`, `-marsDict` (+207 more)
  These have ≤1 connection - possible missing edges or undocumented components.
- **4 thin communities (<3 nodes) omitted from report** — run `graphify query` to explore isolated nodes.

## Suggested Questions
_Questions this graph is uniquely positioned to answer:_

- **Why does `LWPinYinService` connect `Community 0` to `Community 7`?**
  _High betweenness centrality (0.030) - this node is a cross-community bridge._
- **Why does `KeyboardType` connect `Community 4` to `Community 7`?**
  _High betweenness centrality (0.024) - this node is a cross-community bridge._
- **Why does `LWInstanceFactory` connect `Community 7` to `Community 0`?**
  _High betweenness centrality (0.023) - this node is a cross-community bridge._
- **What connects `-factory`, `-releaseAllService`, `-traditionalDict` to the rest of the system?**
  _212 weakly-connected nodes found - possible documentation gaps or missing edges._
- **Should `Community 0` be split into smaller, more focused modules?**
  _Cohesion score 0.05 - nodes in this community are weakly interconnected._
- **Should `Community 1` be split into smaller, more focused modules?**
  _Cohesion score 0.08 - nodes in this community are weakly interconnected._
- **Should `Community 2` be split into smaller, more focused modules?**
  _Cohesion score 0.06 - nodes in this community are weakly interconnected._