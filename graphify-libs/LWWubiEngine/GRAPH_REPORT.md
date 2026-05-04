# Graph Report - /Users/luowei/projects/libs/LWWubiEngine  (2026-05-04)

## Corpus Check
- Corpus is ~23,904 words - fits in a single context window. You may not need a graph.

## Summary
- 373 nodes · 427 edges · 22 communities detected
- Extraction: 99% EXTRACTED · 1% INFERRED · 0% AMBIGUOUS · INFERRED: 3 edges (avg confidence: 0.8)
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

## God Nodes (most connected - your core abstractions)
1. `LWSymbolService` - 42 edges
2. `LWInstanceFactory` - 31 edges
3. `LWHybridService` - 26 edges
4. `LWWubiService` - 26 edges
5. `LWWordsService` - 26 edges
6. `LWPyCoreService` - 23 edges
7. `RCInputCoreServiceObjC` - 18 edges
8. `RCInputCoreService` - 17 edges
9. `LWHandwritingService` - 16 edges
10. `LWEnlishService` - 15 edges

## Surprising Connections (you probably didn't know these)
- `LWSymbolService` --inherits--> `NSObject`  [EXTRACTED]
  LWWubiEngine_swift/Classes/WordEngine/WordService/LWSymbolService.swift →   _Bridges community 0 → community 11_
- `LWHybridService` --inherits--> `LWWordsService`  [EXTRACTED]
  LWWubiEngine_swift/Classes/WordEngine/WordService/LWHybridService.swift →   _Bridges community 3 → community 7_
- `LWWubiService` --inherits--> `LWWordsService`  [EXTRACTED]
  LWWubiEngine_swift/Classes/WordEngine/WordService/LWWubiService.swift →   _Bridges community 4 → community 7_
- `LWPyCoreService` --inherits--> `LWWordsService`  [EXTRACTED]
  LWWubiEngine_swift/Classes/WordEngine/WordService/LWPyCoreService.swift →   _Bridges community 6 → community 7_
- `LWWordsService` --inherits--> `NSObject`  [EXTRACTED]
  LWWubiEngine_swift/Classes/WordEngine/WordService/LWWordsService.swift →   _Bridges community 5 → community 11_

## Communities (37 total, 3 thin omitted)

### Community 0 - "Community 0"
Cohesion: 0.06
Nodes (24): LWSymbolService, -categoriesWithType, -categoryIdWithTypename, -dealloc, -deleteCategoryWithId, -deleteSymbolWithCategoryId, -deleteSymbolWithId, -exchangeCategoryOrderWithSourceIddestinationId (+16 more)

### Community 2 - "Community 2"
Cohesion: 0.1
Nodes (11): LWInstanceFactory, -bundlePathWithBundleFileNamebundleURLString, -copyBundle2docdata, -copydb2docdata, -dbPathWithDBFileName, -dbPathWithDBFileNamedbURLString, -exsitBundleFileName, -factory (+3 more)

### Community 3 - "Community 3"
Cohesion: 0.12
Nodes (8): LWHybridService, -dealloc, -inputCharaters, -morePredictiveWithPageSize, -pycoreService, -setPycoreService, -updateUserWordwithCode, -wubiService

### Community 4 - "Community 4"
Cohesion: 0.08
Nodes (11): LWWubiService, -dealloc, -execSql, -initWithDBPath, -morePredictiveWithPageSize, -queryWords, -queryWordWithZi, -recordExist (+3 more)

### Community 5 - "Community 5"
Cohesion: 0.08
Nodes (10): LWWordsService, -handleUpdateParame, -handleWhereParame, -morePredictiveWithPageSize, -morePredictiveWithStartIndexpageSize, -selectNinegridWithIndex, -stringWithindex, -updateUserWordByIndex (+2 more)

### Community 6 - "Community 6"
Cohesion: 0.09
Nodes (6): LWPyCoreService, -morePredictiveWithStartIndexpageSize, -selectNinegridWithIndex, -serviceWithDBPath, -updateAppendingStringWhenDelete, -updateUserWordByIndex

### Community 7 - "Community 7"
Cohesion: 0.12
Nodes (5): LWWordsService, LWEnglishService, LWWord, -copyWithZone, -initWithIdcodeword

### Community 8 - "Community 8"
Cohesion: 0.16
Nodes (9): ObservableObject, PreviewProvider, CandidateButton, InputMethodView, InputMethodView_Previews, InputMethodViewModel, KeyboardView, KeyButton (+1 more)

### Community 9 - "Community 9"
Cohesion: 0.12
Nodes (15): LWEnlishService, -backspaceAChar, -dealloc, -execSql, -initWithDBPath, -inputAChar, -morePredictiveWithPageSize, -openDatabase (+7 more)

### Community 11 - "Community 11"
Cohesion: 0.21
Nodes (5): LWCategory, LWSymbol, LWWord, NSCopying, NSObject

### Community 12 - "Community 12"
Cohesion: 0.18
Nodes (10): LWHandwrittingService, -backspaceAChar, -createBodyWithBoundaryparametersfileDatamimetypefieldNamefileName, -init, -inputAChar, -morePredictiveWithPageSize, -predResultsArray, -queryWords (+2 more)

### Community 13 - "Community 13"
Cohesion: 0.2
Nodes (3): Array, Bundle, String

### Community 14 - "Community 14"
Cohesion: 0.22
Nodes (6): APIEndpoint, BundleDirectoryName, DatabaseFileName, KeyboardType, UserDefaultsKey, OptionSet

### Community 15 - "Community 15"
Cohesion: 0.25
Nodes (7): WBAppDelegate, -applicationDidBecomeActive, -applicationDidEnterBackground, -applicationdidFinishLaunchingWithOptions, -applicationWillEnterForeground, -applicationWillResignActive, -applicationWillTerminate

### Community 16 - "Community 16"
Cohesion: 0.29
Nodes (6): LWCategory, -copyWithZone, -initWithIdtypenameen_namefile_urlhttp_urlselectorder, LWSymbol, -copyWithZone, -initWithIdcategoryIdtitletextfile_urlhttp_urlfrequencyorder

### Community 17 - "Community 17"
Cohesion: 0.29
Nodes (6): NSBundle, -load, -myResourcePath, NSObject, -lwim_swizzleClassMethodwithMethod, -lwim_swizzleMethodwithMethod

### Community 18 - "Community 18"
Cohesion: 0.33
Nodes (5): NSArray, -containsStringItem, NSString, -eg_enumerateCharactersUsingBlock, -eg_isBlank

### Community 19 - "Community 19"
Cohesion: 0.4
Nodes (4): Tests, -setUp, -tearDown, -testExample

### Community 20 - "Community 20"
Cohesion: 0.5
Nodes (3): WBViewController, -didReceiveMemoryWarning, -viewDidLoad

## Knowledge Gaps
- **114 isolated node(s):** `-setUp`, `-tearDown`, `-testExample`, `-applicationdidFinishLaunchingWithOptions`, `-applicationWillResignActive` (+109 more)
  These have ≤1 connection - possible missing edges or undocumented components.
- **3 thin communities (<3 nodes) omitted from report** — run `graphify query` to explore isolated nodes.

## Suggested Questions
_Questions this graph is uniquely positioned to answer:_

- **Why does `LWWordsService` connect `Community 5` to `Community 11`, `Community 7`?**
  _High betweenness centrality (0.313) - this node is a cross-community bridge._
- **Why does `LWHandwritingService` connect `Community 10` to `Community 2`, `Community 7`?**
  _High betweenness centrality (0.213) - this node is a cross-community bridge._
- **Why does `LWSymbolService` connect `Community 0` to `Community 16`, `Community 11`?**
  _High betweenness centrality (0.173) - this node is a cross-community bridge._
- **What connects `-setUp`, `-tearDown`, `-testExample` to the rest of the system?**
  _114 weakly-connected nodes found - possible documentation gaps or missing edges._
- **Should `Community 0` be split into smaller, more focused modules?**
  _Cohesion score 0.06 - nodes in this community are weakly interconnected._
- **Should `Community 1` be split into smaller, more focused modules?**
  _Cohesion score 0.08 - nodes in this community are weakly interconnected._
- **Should `Community 2` be split into smaller, more focused modules?**
  _Cohesion score 0.1 - nodes in this community are weakly interconnected._