//
//  OIMManager+Club.h
//  OpenIMSDKiOS_Example
//
//  Created by Mark on 2024/2/29.
//  Copyright © 2024 xpg. All rights reserved.
//

#import <OpenIMSDK/OpenIMSDK.h>

NS_ASSUME_NONNULL_BEGIN

@interface OIMManager (Club)

// 部落房间解散通知 serverID: 部落ID
- (void)dismissServer:(NSString *)serverID
            onSuccess:(OIMSuccessCallback)onSuccess
            onFailure:(OIMFailureCallback)onFailure;





// 部落成员被踢出通知 serverID: 部落ID
- (void)kickServerMember:(NSString *)serverID
                  reason:(NSString *)reason
           kickedUserIDs:(NSArray *)kickedUserIDs
               onSuccess:(OIMSuccessCallback)onSuccess
               onFailure:(OIMFailureCallback)onFailure;


/// 同意部落申请
/// - Parameters:
///   - serverID: 部落ID
///   - fromUserID: 申请用户ID
///   - handleMsg: 处理意见
///   - conversationID: 会话ID
///   - onSuccess: 成功回调
///   - onFailure: 失败回调
- (void)acceptServerApplication:(NSString *)serverID
                     fromUserID:(NSString *)fromUserID
                      handleMsg:(NSString *)handleMsg
                 conversationID:(NSString *)conversationID
                      onSuccess:(OIMSuccessCallback)onSuccess
                      onFailure:(OIMFailureCallback)onFailure;

/// 拒绝部落申请
/// - Parameters:
///   - serverID: 部落ID
///   - fromUserID: 申请用户ID
///   - handleMsg: 处理意见
///   - conversationID: 会话ID
///   - onSuccess: 成功回调
///   - onFailure: 失败回调
- (void)refuseServerApplication:(NSString *)serverID
                     fromUserID:(NSString *)fromUserID
                      handleMsg:(NSString *)handleMsg
                 conversationID:(NSString *)conversationID
                      onSuccess:(OIMSuccessCallback)onSuccess
                      onFailure:(OIMFailureCallback)onFailure;

@end

NS_ASSUME_NONNULL_END
