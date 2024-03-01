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

// 邀请通话 - 返回ChannelID
- (void)SignalingInvite:(NSString *)conversationID
                    uid:(NSString *)uid
              channelID:(NSString *)channelID
              onSuccess: (OIMSuccessCallback)onSuccess
              onfailure:(OIMFailureCallback)onfailure;

// 拒绝邀请
- (void)signalingReject:(NSString *)conversationID
              channelID:(NSString *)channelID
              onSuccess: (OIMSuccessCallback)onSuccess
              onfailure:(OIMFailureCallback)onfailure;

// 接受邀请
- (void)signalingAccept:(NSString *)conversationID
              channelID:(NSString *)channelID
              onSuccess: (OIMSuccessCallback)onSuccess
              onfailure:(OIMFailureCallback)onfailure;

// 加入群语音房
- (void)signalingJoin:(NSString *)conversationID
            channelID:(NSString *)channelID
            onSuccess: (OIMSuccessCallback)onSuccess
            onfailure:(OIMFailureCallback)onfailure;

// 取消邀请
- (void)signalingCancel:(NSString *)conversationID
              channelID:(NSString *)channelID
           cancelUserID:(NSString *)cancelUserID
              onSuccess: (OIMSuccessCallback)onSuccess
              onfailure:(OIMFailureCallback)onfailure;

// 挂断 - 1为正常情况挂断，2为异常情况挂断
- (void)signalingHungUp:(NSString *)conversationID
              channelID:(NSString *)channelID
             hungUpType:(NSInteger)hungUpType
              onSuccess: (OIMSuccessCallback)onSuccess
              onfailure:(OIMFailureCallback)onfailure;

// 更新麦克风状态
- (void)updateMichoneStatus:(NSString *)conversationID
                  channelID:(NSString *)channelID
                     status:(NSInteger)status
                  onSuccess: (OIMSuccessCallback)onSuccess
                  onfailure:(OIMFailureCallback)onfailure;

// 更新说话状态
- (void)updateSpeakStatus:(NSString *)conversationID
                channelID:(NSString *)channelID
                onSuccess: (OIMSuccessCallback)onSuccess
                onfailure:(OIMFailureCallback)onfailure;

// 获取声网Token - 返回Token
- (void)getRtcToken:(NSString *)uid
          channelID:(NSString *)channelID
           roleType:(NSInteger)roleType
          onSuccess: (OIMSuccessCallback)onSuccess
          onfailure:(OIMFailureCallback)onfailure;

@end


NS_ASSUME_NONNULL_END
