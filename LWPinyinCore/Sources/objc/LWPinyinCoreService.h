#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface LWPinyinCoreService : NSObject

- (instancetype)initWithResourcePath:(nullable NSString *)resourcePath userDBPath:(nullable NSString *)userDBPath;
- (BOOL)searchFull:(NSString *)pinyin;
- (BOOL)searchNine:(NSString *)digits;
- (NSString *)compositionString;
- (NSArray<NSString *> *)candidatesFrom:(NSInteger)start count:(NSInteger)count;
- (NSArray<NSString *> *)sidebarCodes;
- (NSInteger)selectSidebarAtIndex:(NSInteger)index;
- (BOOL)chooseCandidateAtIndex:(NSInteger)index;
- (NSString *)commitText;
- (void)backspace;
- (void)reset;

@end

NS_ASSUME_NONNULL_END
