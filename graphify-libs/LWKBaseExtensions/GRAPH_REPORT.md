# Graph Report - /Users/luowei/projects/libs/LWKBaseExtensions  (2026-05-04)

## Corpus Check
- Corpus is ~21,523 words - fits in a single context window. You may not need a graph.

## Summary
- 309 nodes · 275 edges · 34 communities detected
- Extraction: 98% EXTRACTED · 2% INFERRED · 0% AMBIGUOUS · INFERRED: 5 edges (avg confidence: 0.8)
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
- [[_COMMUNITY_Community 24|Community 24]]
- [[_COMMUNITY_Community 25|Community 25]]
- [[_COMMUNITY_Community 26|Community 26]]
- [[_COMMUNITY_Community 27|Community 27]]
- [[_COMMUNITY_Community 28|Community 28]]
- [[_COMMUNITY_Community 29|Community 29]]
- [[_COMMUNITY_Community 30|Community 30]]
- [[_COMMUNITY_Community 31|Community 31]]
- [[_COMMUNITY_Community 32|Community 32]]
- [[_COMMUNITY_Community 33|Community 33]]

## God Nodes (most connected - your core abstractions)
1. `UIImage` - 36 edges
2. `UIView` - 28 edges
3. `UIView` - 23 edges
4. `NSString` - 21 edges
5. `UIColor` - 16 edges
6. `UIImage` - 14 edges
7. `String` - 11 edges
8. `UIColor` - 10 edges
9. `UIColor` - 10 edges
10. `LWAppDelegate` - 7 edges

## Surprising Connections (you probably didn't know these)
- None detected - all connections are within the same source files.

## Communities (55 total, 18 thin omitted)

### Community 0 - "Community 0"
Cohesion: 0.05
Nodes (36): UIImage, -addImageToImagewithImage2andRectwithImageSize, -averageColor, -blurImageWithRadius, -blurWithRectradius, -calculatedSize, -combineBGImagewithImageandSizeinSize, -compressImageDataInMaxFileSize (+28 more)

### Community 1 - "Community 1"
Cohesion: 0.07
Nodes (28): UIView, -applicationDidBecomeActive, -applicationDidEnterBackground, -applicationWillEnterForeground, -applicationWillResignActive, -applicationWillTerminate, -copyView, -getSubviewsFirstResponder (+20 more)

### Community 3 - "Community 3"
Cohesion: 0.09
Nodes (21): NSString, -base64Decode, -base64Encode, -chineseCharactersIntoPinyin, -containsChineseCharacters, -documentPath, -isBlank, -isDomain (+13 more)

### Community 5 - "Community 5"
Cohesion: 0.12
Nodes (16): UIColor, -adjustByPercentage, -adjustColorWithPercentage, -colorComponentFromstartlength, -colorWithHexalpha, -colorWithHexString, -colorWithRGBAString, -darkerByPercentage (+8 more)

### Community 7 - "Community 7"
Cohesion: 0.18
Nodes (10): UIColor, -colorBetweenFirstColorsecondColoratRatiowithAlpha, -colorConvertedToRGBA, -colorForFadeBetweenFirstColorsecondColoratRatio, -colorForFadeBetweenFirstColorsecondColoratRatiocompareColorSpaces, -colorsForFadeBetweenFirstColorlastColorinSteps, -colorsForFadeBetweenFirstColorlastColorwithRatioEquationinSteps, -keyframeAnimationForKeyPathdurationbetweenFirstColorlastColor (+2 more)

### Community 8 - "Community 8"
Cohesion: 0.25
Nodes (7): LWAppDelegate, -applicationDidBecomeActive, -applicationDidEnterBackground, -applicationdidFinishLaunchingWithOptions, -applicationWillEnterForeground, -applicationWillResignActive, -applicationWillTerminate

### Community 9 - "Community 9"
Cohesion: 0.29
Nodes (6): NSObject, -is_iPad, -performSelectorSafely, -performSelectorwithObjects, -performSelectorwithParameters, -vibrate

### Community 10 - "Community 10"
Cohesion: 0.29
Nodes (6): NSDictionary, -objectForKeyPath, NSMutableDictionary, -setObjectforKeyPath, NSObject, -objectForKeyPath

### Community 14 - "Community 14"
Cohesion: 0.4
Nodes (4): Tests, -setUp, -tearDown, -testExample

### Community 15 - "Community 15"
Cohesion: 0.4
Nodes (4): NSData, -base64Encode, -md5, -md5Data

### Community 16 - "Community 16"
Cohesion: 0.4
Nodes (4): NSArray, -containsString, -containsStringItem, -indexOfStringObject

### Community 17 - "Community 17"
Cohesion: 0.4
Nodes (4): UIResponder, -canOpenURLWithString, -openURLWithString, -openURLWithUrl

### Community 18 - "Community 18"
Cohesion: 0.4
Nodes (4): UIButton, -hitTestEdgeInsets, -pointInsidewithEvent, -setHitTestEdgeInsets

### Community 21 - "Community 21"
Cohesion: 0.5
Nodes (3): LWViewController, -didReceiveMemoryWarning, -viewDidLoad

### Community 22 - "Community 22"
Cohesion: 0.5
Nodes (3): NSURL, -queryDictionary, -urlIsImage

### Community 23 - "Community 23"
Cohesion: 0.5
Nodes (3): CALayer, -borderUIColor, -setBorderUIColor

## Knowledge Gaps
- **150 isolated node(s):** `-applicationdidFinishLaunchingWithOptions`, `-applicationWillResignActive`, `-applicationDidEnterBackground`, `-applicationWillEnterForeground`, `-applicationDidBecomeActive` (+145 more)
  These have ≤1 connection - possible missing edges or undocumented components.
- **18 thin communities (<3 nodes) omitted from report** — run `graphify query` to explore isolated nodes.

## Suggested Questions
_Questions this graph is uniquely positioned to answer:_

- **What connects `-applicationdidFinishLaunchingWithOptions`, `-applicationWillResignActive`, `-applicationDidEnterBackground` to the rest of the system?**
  _150 weakly-connected nodes found - possible documentation gaps or missing edges._
- **Should `Community 0` be split into smaller, more focused modules?**
  _Cohesion score 0.05 - nodes in this community are weakly interconnected._
- **Should `Community 1` be split into smaller, more focused modules?**
  _Cohesion score 0.07 - nodes in this community are weakly interconnected._
- **Should `Community 2` be split into smaller, more focused modules?**
  _Cohesion score 0.09 - nodes in this community are weakly interconnected._
- **Should `Community 3` be split into smaller, more focused modules?**
  _Cohesion score 0.09 - nodes in this community are weakly interconnected._
- **Should `Community 4` be split into smaller, more focused modules?**
  _Cohesion score 0.14 - nodes in this community are weakly interconnected._
- **Should `Community 5` be split into smaller, more focused modules?**
  _Cohesion score 0.12 - nodes in this community are weakly interconnected._