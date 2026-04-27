#import "LWPinyinCoreService.h"

#import "lwpy_core.h"

@interface LWPinyinCoreService ()
@property (nonatomic, assign) lwpy_engine_t *engine;
@end

@implementation LWPinyinCoreService

- (instancetype)initWithResourcePath:(NSString *)resourcePath userDBPath:(NSString *)userDBPath {
    self = [super init];
    if (self) {
        _engine = lwpy_engine_create(resourcePath.UTF8String, userDBPath.UTF8String);
    }
    return self;
}

- (void)dealloc {
    if (_engine) {
        lwpy_engine_destroy(_engine);
        _engine = NULL;
    }
}

- (BOOL)searchFull:(NSString *)pinyin {
    return lwpy_engine_search_full(self.engine, pinyin.UTF8String) > 0;
}

- (BOOL)searchNine:(NSString *)digits {
    return lwpy_engine_search_nine(self.engine, digits.UTF8String) > 0;
}

- (NSString *)compositionString {
    const char *text = lwpy_engine_composition(self.engine);
    return text ? [NSString stringWithUTF8String:text] : @"";
}

- (NSArray<NSString *> *)candidatesFrom:(NSInteger)start count:(NSInteger)count {
    if (count <= 0) {
        return @[];
    }

    lwpy_candidate_t *buffer = (lwpy_candidate_t *)calloc((size_t)count, sizeof(lwpy_candidate_t));
    int actual = lwpy_engine_get_candidates(self.engine, (int)start, (int)count, buffer);
    NSMutableArray<NSString *> *items = [NSMutableArray arrayWithCapacity:(NSUInteger)actual];
    for (int i = 0; i < actual; i++) {
        const char *text = buffer[i].text;
        if (text) {
            [items addObject:[NSString stringWithUTF8String:text]];
        }
    }
    free(buffer);
    return items;
}

- (NSArray<NSString *> *)sidebarCodes {
    const int limit = 64;
    const char **buffer = (const char **)calloc(limit, sizeof(const char *));
    int actual = lwpy_engine_get_sidebar(self.engine, 0, limit, buffer);
    NSMutableArray<NSString *> *items = [NSMutableArray arrayWithCapacity:(NSUInteger)actual];
    for (int i = 0; i < actual; i++) {
        const char *text = buffer[i];
        if (text) {
            [items addObject:[NSString stringWithUTF8String:text]];
        }
    }
    free(buffer);
    return items;
}

- (NSInteger)selectSidebarAtIndex:(NSInteger)index {
    return lwpy_engine_select_sidebar(self.engine, (int)index);
}

- (BOOL)chooseCandidateAtIndex:(NSInteger)index {
    return lwpy_engine_choose(self.engine, (int)index);
}

- (NSString *)commitText {
    const char *text = lwpy_engine_commit_text(self.engine);
    return text ? [NSString stringWithUTF8String:text] : @"";
}

- (void)backspace {
    lwpy_engine_backspace(self.engine);
}

- (void)reset {
    lwpy_engine_reset(self.engine);
}

@end
