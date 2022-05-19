#import <Foundation/Foundation.h>

@class FIRAggregateQuery;
@class FIRAggregateQuerySnapshot;
@class FIRDocumentReference;
@class FIRDocumentSnapshot;
@class FIRGroupByQuery;
@class FIRGroupByQuerySnapshot;
@class FIRPartitionQuery;
@class FIRPartitionQuerySnapshot;
@class FIRQuery;
@class FIRQuerySnapshot;

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, FIROnlineState) {
  FIRFirestoreOnline,
  FIRFirestoreOffline
} NS_SWIFT_NAME(OnlineState);

NS_SWIFT_NAME(DirectToServerQueryExecutor)
@interface FIRDirectToServerQueryExecutor<T> : NSObject

/** :nodoc: */
- (id)init __attribute__((unavailable("FIRDirectToServerQueryExecutor cannot be created directly.")));

+ (FIRDirectToServerQueryExecutor<FIRDocumentSnapshot *> *)DirectToServerQueryExecutorForDocument:(FIRDocumentReference *)doc;

+ (FIRDirectToServerQueryExecutor<FIRQuerySnapshot *> *)DirectToServerQueryExecutorForQuery:(FIRQuery *)query;

+ (FIRDirectToServerQueryExecutor<FIRAggregateQuerySnapshot *> *)DirectToServerQueryExecutorForAggregateQuery:(FIRAggregateQuery *)query;

+ (FIRDirectToServerQueryExecutor<FIRGroupByQuerySnapshot *> *)DirectToServerQueryExecutorForGroupByQuery:(FIRGroupByQuery *)query;

+ (FIRDirectToServerQueryExecutor<FIRPartitionQuerySnapshot *> *)DirectToServerQueryExecutorForPartitionQuery:(FIRPartitionQuery *)query;

- (void)getWithCompletion:
    (void (^)(T *_Nullable snapshot, NSError *_Nullable error))completion
    NS_SWIFT_NAME(get(completion:));

- (id<FIRListenerRegistration>)addSnapshotListener:
    (void (^)(T *_Nullable snapshot, NSError *_Nullable error, FIROnlineState onlineState))listener
    NS_SWIFT_NAME(addSnapshotListener(_:));

@end

NS_ASSUME_NONNULL_END

