# Graph Report - /Users/luowei/projects/libs/LWWordConverter  (2026-05-04)

## Corpus Check
- Large corpus: 28 files · ~1,132,836 words. Semantic extraction will be expensive (many Claude tokens). Consider running on a subfolder, or use --no-semantic to run AST-only.

## Summary
- 88 nodes · 83 edges · 9 communities detected
- Extraction: 100% EXTRACTED · 0% INFERRED · 0% AMBIGUOUS
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
- [[_COMMUNITY_Community 9|Community 9]]

## God Nodes (most connected - your core abstractions)
1. `LWConverterService` - 24 edges
2. `LWEncryptService` - 10 edges
3. `LWWordConverterView` - 8 edges
4. `LWAppDelegate` - 7 edges
5. `LWNetworkReachabilityStatus` - 6 edges
6. `LWNetworkReachabilityManager` - 6 edges
7. `EncryptMode` - 5 edges
8. `Tests` - 4 edges
9. `LWViewController` - 3 edges
10. `LWWordConverterView_Previews` - 2 edges

## Surprising Connections (you probably didn't know these)
- `EncryptMode` --inherits--> `Int`  [EXTRACTED]
  LWWordConverter_swift/Classes/LWEncryptService.swift →   _Bridges community 5 → community 1_

## Communities (18 total, 2 thin omitted)

### Community 0 - "Community 0"
Cohesion: 0.12
Nodes (12): LWConverterService, -dealloc, -enumerateCharactersusingBlock, -fanyiZitoupdateUIBlock, -initWithDBPathbihuaDBPath, -isBlankString, -md5HexDigest, -queryBiShunWithZi (+4 more)

### Community 1 - "Community 1"
Cohesion: 0.15
Nodes (6): EncryptMode, emoji, sanGuoSha, LWEncryptService, -encryptTextdisplayText, -load

### Community 2 - "Community 2"
Cohesion: 0.18
Nodes (4): LWWordConverterView, LWWordConverterView_Previews, PreviewProvider, View

### Community 3 - "Community 3"
Cohesion: 0.25
Nodes (7): LWAppDelegate, -applicationDidBecomeActive, -applicationDidEnterBackground, -applicationdidFinishLaunchingWithOptions, -applicationWillEnterForeground, -applicationWillResignActive, -applicationWillTerminate

### Community 5 - "Community 5"
Cohesion: 0.33
Nodes (6): LWNetworkReachabilityStatus, notReachable, reachableViaWiFi, reachableViaWWAN, unknown, Int

### Community 6 - "Community 6"
Cohesion: 0.4
Nodes (4): Tests, -setUp, -tearDown, -testExample

### Community 7 - "Community 7"
Cohesion: 0.5
Nodes (3): LWViewController, -didReceiveMemoryWarning, -viewDidLoad

## Knowledge Gaps
- **30 isolated node(s):** `-serviceWithDBPathbihuaDBPath`, `-initWithDBPathbihuaDBPath`, `-dealloc`, `-queryWithZiupdateUIBlock`, `-queryWithZi` (+25 more)
  These have ≤1 connection - possible missing edges or undocumented components.
- **2 thin communities (<3 nodes) omitted from report** — run `graphify query` to explore isolated nodes.

## Suggested Questions
_Questions this graph is uniquely positioned to answer:_

- **Why does `LWConverterService` connect `Community 0` to `Community 8`, `Community 10`, `Community 11`, `Community 12`?**
  _High betweenness centrality (0.072) - this node is a cross-community bridge._
- **Why does `LWNetworkReachabilityStatus` connect `Community 5` to `Community 4`?**
  _High betweenness centrality (0.053) - this node is a cross-community bridge._
- **Why does `EncryptMode` connect `Community 1` to `Community 5`?**
  _High betweenness centrality (0.051) - this node is a cross-community bridge._
- **What connects `-serviceWithDBPathbihuaDBPath`, `-initWithDBPathbihuaDBPath`, `-dealloc` to the rest of the system?**
  _30 weakly-connected nodes found - possible documentation gaps or missing edges._
- **Should `Community 0` be split into smaller, more focused modules?**
  _Cohesion score 0.12 - nodes in this community are weakly interconnected._