//
//  OIMManager+Call.h
//  OpenIMSDKiOS
//
//  Created by Mark on 2024/1/24.
//  Copyright © 2024 xpg. All rights reserved.
//

#import <OpenIMSDK/OpenIMSDK.h>

NS_ASSUME_NONNULL_BEGIN

@interface OIMManager (Call)

// 语音通话邀请 - 单聊或群聊
// 单聊或群聊
- (void)signalingInvite:(NSString *)conversationID
                userIds:(NSString *)userIds
              onSuccess:(nullable OIMBoolCallback)onSuccess
              onFailure:(nullable OIMFailureCallback)onFailure;

// 拒绝邀请
- (void)signalingReject:(NSString *)conversationID
              channelID:(NSString *)channelID
              onSuccess:(nullable OIMBoolCallback)onSuccess
              onFailure:(nullable OIMFailureCallback)onFailure;

// 接受邀请
- (void)signalingAccept:(NSString *)conversationID
              channelID:(NSString *)channelID
              onSuccess:(nullable OIMBoolCallback)onSuccess
              onFailure:(nullable OIMFailureCallback)onFailure;

// 加入群语音房
- (void)signalingJoin:(NSString *)conversationID
            channelID:(NSString *)channelID
            onSuccess:(nullable OIMBoolCallback)onSuccess
            onFailure:(nullable OIMFailureCallback)onFailure;

// 取消邀请
- (void)SignalingCancel:(NSString *)conversationID
              channelID:(NSString *)channelID
           cancelUserID:(NSString *)cancelUserID
              onSuccess:(nullable OIMBoolCallback)onSuccess
              onFailure:(nullable OIMFailureCallback)onFailure;

// 挂断
- (void)signalingHungUp:(NSString *)conversationID
              channelID:(NSString *)channelID
              onSuccess:(nullable OIMBoolCallback)onSuccess
              onFailure:(nullable OIMFailureCallback)onFailure;

// 关闭语音房间
- (void)SignalingClose:(NSString *)conversationID
             channelID:(NSString *)channelID
             onSuccess:(nullable OIMBoolCallback)onSuccess
             onFailure:(nullable OIMFailureCallback)onFailure;

// 更新麦克风状态
- (void)updateMichoneStatus:(NSString *)conversationID
                  channelID:(NSString *)channelID
                     status:(int)status
                  onSuccess:(nullable OIMBoolCallback)onSuccess
                  onFailure:(nullable OIMFailureCallback)onFailure;

// 更新说话状态
- (void)updateSpeakStatus:(NSString *)conversationID
                channelID:(NSString *)channelID
                onSuccess:(nullable OIMBoolCallback)onSuccess
                onFailure:(nullable OIMFailureCallback)onFailure;


@end

NS_ASSUME_NONNULL_END
