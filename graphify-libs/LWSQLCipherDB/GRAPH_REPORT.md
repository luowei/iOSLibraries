# Graph Report - /Users/luowei/projects/libs/LWSQLCipherDB  (2026-05-04)

## Corpus Check
- Large corpus: 40 files · ~1,222,733 words. Semantic extraction will be expensive (many Claude tokens). Consider running on a subfolder, or use --no-semantic to run AST-only.

## Summary
- 485 nodes · 526 edges · 18 communities detected
- Extraction: 99% EXTRACTED · 1% INFERRED · 0% AMBIGUOUS · INFERRED: 6 edges (avg confidence: 0.8)
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

## God Nodes (most connected - your core abstractions)
1. `FMDatabase` - 105 edges
2. `FMResultSet` - 45 edges
3. `LWDBModel` - 33 edges
4. `FMDatabaseQueue` - 29 edges
5. `FMDatabasePool` - 28 edges
6. `LWDBModel` - 26 edges
7. `FMDatabase` - 21 edges
8. `LWViewController` - 15 edges
9. `LWQueryBuilder` - 14 edges
10. `LWDBColumnDes` - 13 edges

## Surprising Connections (you probably didn't know these)
- `ObservableLWDBModel` --inherits--> `LWDBModel`  [EXTRACTED]
  LWSQLCipherDB_swift/SwiftClasses/LWSQLCipherDB.swift →   _Bridges community 4 → community 2_
- `LWSQLCipherDBTool` --inherits--> `NSObject`  [EXTRACTED]
  LWSQLCipherDB_swift/SwiftClasses/LWSQLCipherDBTool.swift →   _Bridges community 3 → community 13_
- `LWDBModel` --inherits--> `NSObject`  [EXTRACTED]
  LWSQLCipherDB_swift/SwiftClasses/LWDBModel.swift →   _Bridges community 13 → community 7_
- `LWDBColumnDes` --inherits--> `NSObject`  [EXTRACTED]
  LWSQLCipherDB_swift/SwiftClasses/LWDBColumnDes.swift →   _Bridges community 13 → community 10_

## Communities (31 total, 2 thin omitted)

### Community 0 - "Community 0"
Cohesion: 0.02
Nodes (105): FMDatabase, -beginDeferredTransaction, -beginExclusiveTransaction, -beginImmediateTransaction, -beginTransaction, -bindObjecttoColumninStatement, -busyRetryTimeout, -cachedStatementForQuery (+97 more)

### Community 1 - "Community 1"
Cohesion: 0.04
Nodes (47): FMDatabase, -resultSetDidClose, FMResultSet, -boolForColumn, -boolForColumnIndex, -close, -columnCount, -columnIndexForName (+39 more)

### Community 2 - "Community 2"
Cohesion: 0.06
Nodes (7): ObservableObject, LWDatabaseConfig, LWDatabaseManager, LWDBModel, LWQueryBuilder, LWSQLCipherDB, ObservableLWDBModel

### Community 3 - "Community 3"
Cohesion: 0.06
Nodes (29): FMDatabaseQueue, -beginTransactionwithBlock, -checkpointerror, -checkpointnameerror, -checkpointnamelogFrameCountcheckpointCounterror, -close, -database, -databaseClass (+21 more)

### Community 4 - "Community 4"
Cohesion: 0.07
Nodes (12): LWDBModel, ObservableLWDBModel, AdvancedExamples, AsyncDatabaseExamples, CachedUser, DatabaseExamples, ObservableUser, Product (+4 more)

### Community 5 - "Community 5"
Cohesion: 0.06
Nodes (33): LWDBModel, -clearTable, -createTable, -deleteObject, -deleteObjects, -deleteObjectsByCriteria, -deleteObjectsWithFormat, -describeColumnDict (+25 more)

### Community 6 - "Community 6"
Cohesion: 0.07
Nodes (28): FMDatabasePool, -beginTransactionwithBlock, -countOfCheckedInDatabases, -countOfCheckedOutDatabases, -countOfOpenDatabases, -databaseClass, -databasePoolWithPath, -databasePoolWithPathflags (+20 more)

### Community 8 - "Community 8"
Cohesion: 0.09
Nodes (21): FMDatabase, -applicationID, -applicationIDString, -boolForQuery, -columnExistscolumnName, -columnExistsinTableWithName, -dataForQuery, -dateForQuery (+13 more)

### Community 9 - "Community 9"
Cohesion: 0.11
Nodes (17): LWViewController, -delete, -delete1, -detete2, -query1, -query2, -query3, -query4 (+9 more)

### Community 11 - "Community 11"
Cohesion: 0.13
Nodes (14): FMDatabase, -load, -mySecretKey, LWSQLCipherDBTool, -allocWithZone, -changeDBWithDirectoryName, -copyWithZone, -dbPath (+6 more)

### Community 12 - "Community 12"
Cohesion: 0.14
Nodes (13): LWDBColumnDes, -checkStingNull, -customModifyWithPKautoInuniqueisNotNullcheckdefaultVforeignKey, -finishModify, -initWithAutoisNotNullcheckdefaultVa, -initWithFKFiekdUniqueisNotNullcheckdefaultforeignKey, -initWithgeneralFieldWithAutouniqueisNotNullcheckdefaultVa, -isAutoincrement (+5 more)

### Community 13 - "Community 13"
Cohesion: 0.2
Nodes (7): Int, NSObject, LWDBSQLState, QueryType, and, or, `where`

### Community 14 - "Community 14"
Cohesion: 0.25
Nodes (7): LWAppDelegate, -applicationDidBecomeActive, -applicationDidEnterBackground, -applicationdidFinishLaunchingWithOptions, -applicationWillEnterForeground, -applicationWillResignActive, -applicationWillTerminate

### Community 15 - "Community 15"
Cohesion: 0.29
Nodes (6): FMStatement, -close, -dealloc, -description, -finalize, -reset

### Community 16 - "Community 16"
Cohesion: 0.33
Nodes (5): LWDBSQLState, -ifEqualTOSQLTEXTKeyoptvaluecondition, -objecttypekeyoptvalue, -sqlOptionStr, -typeToString

### Community 17 - "Community 17"
Cohesion: 0.4
Nodes (4): Tests, -setUp, -tearDown, -testExample

## Knowledge Gaps
- **315 isolated node(s):** `-setUp`, `-tearDown`, `-testExample`, `-applicationdidFinishLaunchingWithOptions`, `-applicationWillResignActive` (+310 more)
  These have ≤1 connection - possible missing edges or undocumented components.
- **2 thin communities (<3 nodes) omitted from report** — run `graphify query` to explore isolated nodes.

## Suggested Questions
_Questions this graph is uniquely positioned to answer:_

- **Why does `FMDatabase` connect `Community 0` to `Community 15`?**
  _High betweenness centrality (0.052) - this node is a cross-community bridge._
- **Why does `LWDBModel` connect `Community 5` to `Community 4`?**
  _High betweenness centrality (0.024) - this node is a cross-community bridge._
- **Why does `ObservableLWDBModel` connect `Community 2` to `Community 4`?**
  _High betweenness centrality (0.019) - this node is a cross-community bridge._
- **Are the 2 inferred relationships involving `FMDatabaseQueue` (e.g. with `.changeDB()` and `.initializeDatabaseQueue()`) actually correct?**
  _`FMDatabaseQueue` has 2 INFERRED edges - model-reasoned connections that need verification._
- **What connects `-setUp`, `-tearDown`, `-testExample` to the rest of the system?**
  _315 weakly-connected nodes found - possible documentation gaps or missing edges._
- **Should `Community 0` be split into smaller, more focused modules?**
  _Cohesion score 0.02 - nodes in this community are weakly interconnected._
- **Should `Community 1` be split into smaller, more focused modules?**
  _Cohesion score 0.04 - nodes in this community are weakly interconnected._