//
//  OIMManager+User.h
//  OpenIMSDK
//
//  Created by x on 2022/2/16.
//

#import "OIMManager.h"

NS_ASSUME_NONNULL_BEGIN

@interface OIMManager (User)

/**
 * Batch query user information by uid
 *
 * @param uids List of user IDs
 */
- (void)getUsersInfo:(NSArray <NSString *> *)uids
           onSuccess:(nullable OIMFullUsersInfoCallback)onSuccess
           onFailure:(nullable OIMFailureCallback)onFailure;

/**
 * Modify the information of the currently logged-in user
 *
 */
- (void)setSelfInfo:(OIMUserInfo *)userInfo
          onSuccess:(nullable OIMSuccessCallback)onSuccess
          onFailure:(nullable OIMFailureCallback)onFailure;

/**
 * Information of the currently logged-in user
 *
 */
- (void)getSelfInfoWithOnSuccess:(nullable OIMUserInfoCallback)onSuccess
                       onFailure:(nullable OIMFailureCallback)onFailure;

/**
 * Update FCM token
 */
- (void)updateFcmToken:(NSString *)fcmToken
             onSuccess:(nullable OIMSuccessCallback)onSuccess
             onFailure:(nullable OIMFailureCallback)onFailure;

/**
 * Subscribe to the online status of users
 */
- (void)subscribeUsersStatus:(NSArray<NSString *> *)userIDs
                   onSuccess:(nullable OIMUserStatusInfosCallback)onSuccess
                   onFailure:(nullable OIMFailureCallback)onFailure;

/**
 * Unsubscribe from the online status of users
 */
- (void)unsubscribeUsersStatus:(NSArray<NSString *> *)userIDs
                     onSuccess:(nullable OIMSuccessCallback)onSuccess
                     onFailure:(nullable OIMFailureCallback)onFailure;

/**
 * Get the online status of all subscribed users
 */
- (void)getSubscribeUsersStatusWithOnSuccess:(nullable OIMUserStatusInfosCallback)onSuccess
                                   onFailure:(nullable OIMFailureCallback)onFailure;

/**
 * Get user status for regular users
 */
- (void)getUserStatus:(NSArray<NSString *> *)userIDs
            onSuccess:(nullable OIMUserStatusInfosCallback)onSuccess
            onFailure:(nullable OIMFailureCallback)onFailure;

- (void)getUsersInfoWithCache:(NSArray<NSString *> *)userIDs
                     groupID:(NSString * _Nullable)groupID
                   onSuccess:(nullable OIMFullUsersInfoCallback)onSuccess
                   onFailure:(nullable OIMFailureCallback)onFailure;

- (void)isBeBlock:(NSString *)userID
        onSuccess:(nullable OIMSuccessCallback)onSuccess
        onFailure:(nullable OIMFailureCallback)onFailure;

- (void)setUserAllowBeep:(BOOL)isAllowed
               onSuccess:(nullable OIMSuccessCallback)onSuccess
               onFailure:(nullable OIMFailureCallback)onFailure;

- (void)setUserAllowVibration:(BOOL)isAllowed
                    onSuccess:(nullable OIMSuccessCallback)onSuccess
                    onFailure:(nullable OIMFailureCallback)onFailure;

- (void)setUserAllowPushContent:(BOOL)isAllowed
                      onSuccess:(nullable OIMSuccessCallback)onSuccess
                      onFailure:(nullable OIMFailureCallback)onFailure;

- (void)setUserAllowOnlinePush:(BOOL)isAllowed
                     onSuccess:(nullable OIMSuccessCallback)onSuccess
                     onFailure:(nullable OIMFailureCallback)onFailure;

- (void)setUserAllowStrangerMsg:(BOOL)isAllowed
                      onSuccess:(nullable OIMSuccessCallback)onSuccess
                      onFailure:(nullable OIMFailureCallback)onFailure;

- (void)allowedSendMsg:(NSArray<NSString *> *)ids
             onSuccess:(nullable OIMSuccessCallback)onSuccess
             onFailure:(nullable OIMFailureCallback)onFailure;

- (void)setUserLanguage:(NSString *)language
              onSuccess:(OIMSuccessCallback)onSuccess
              onFailure:(OIMFailureCallback)onFailure;

@end

NS_ASSUME_NONNULL_END
