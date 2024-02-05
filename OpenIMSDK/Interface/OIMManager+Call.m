//
//  OIMManager+Call.m
//  OpenIMSDKiOS
//
//  Created by Mark on 2024/1/24.
//  Copyright © 2024 xpg. All rights reserved.
//

#import "OIMManager+Call.h"
#import "CallbackProxy.h"

@implementation OIMManager (Call)

// 邀请通话 - 返回ChannelID
- (void)SignalingInvite:(NSString *)conversationID
                    uid:(NSString *)uid
              channelID:(NSString *)channelID
              onSuccess: (OIMSuccessCallback)onSuccess
              onfailure:(OIMFailureCallback)onfailure {
    
    CallbackProxy *callback = [[CallbackProxy alloc] initWithOnSuccess:onSuccess onFailure:onfailure];
    Open_im_sdkSignalingInvite(callback, [self operationId], conversationID, uid, channelID);
}

// 拒绝邀请
- (void)signalingReject:(NSString *)conversationID 
              channelID:(NSString *)channelID
              onSuccess: (OIMSuccessCallback)onSuccess
              onfailure:(OIMFailureCallback)onfailure {
    CallbackProxy *callback = [[CallbackProxy alloc] initWithOnSuccess:onSuccess onFailure:onfailure];
    Open_im_sdkSignalingReject(callback, [self operationId], conversationID, channelID);
    
    
}

// 接受邀请
- (void)signalingAccept:(NSString *)conversationID 
              channelID:(NSString *)channelID
              onSuccess: (OIMSuccessCallback)onSuccess
              onfailure:(OIMFailureCallback)onfailure {
    CallbackProxy *callback = [[CallbackProxy alloc] initWithOnSuccess:onSuccess onFailure:onfailure];
    Open_im_sdkSignalingAccept(callback, [self operationId], conversationID, channelID);
}

// 加入群语音房
- (void)signalingJoin:(NSString *)conversationID 
            channelID:(NSString *)channelID
            onSuccess: (OIMSuccessCallback)onSuccess
            onfailure:(OIMFailureCallback)onfailure {
    CallbackProxy *callback = [[CallbackProxy alloc] initWithOnSuccess:onSuccess onFailure:onfailure];
    Open_im_sdkSignalingJoin(callback, [self operationId], conversationID, channelID);
}

// 取消邀请
- (void)signalingCancel:(NSString *)conversationID 
              channelID:(NSString *)channelID
           cancelUserID:(NSString *)cancelUserID
              onSuccess: (OIMSuccessCallback)onSuccess
              onfailure:(OIMFailureCallback)onfailure {
    CallbackProxy *callback = [[CallbackProxy alloc] initWithOnSuccess:onSuccess onFailure:onfailure];
    Open_im_sdkSignalingCancel(callback, [self operationId], conversationID, channelID, cancelUserID);
}

// 挂断
- (void)signalingHungUp:(NSString *)conversationID
              channelID:(NSString *)channelID
              onSuccess: (OIMSuccessCallback)onSuccess
              onfailure:(OIMFailureCallback)onfailure {
    CallbackProxy *callback = [[CallbackProxy alloc] initWithOnSuccess:onSuccess onFailure:onfailure];
    Open_im_sdkSignalingHungUp(callback, [self operationId], conversationID, channelID);
}

// 更新麦克风状态
- (void)updateMichoneStatus:(NSString *)conversationID
                  channelID:(NSString *)channelID
                     status:(NSInteger)status
                  onSuccess: (OIMSuccessCallback)onSuccess
                  onfailure:(OIMFailureCallback)onfailure {
    CallbackProxy *callback = [[CallbackProxy alloc] initWithOnSuccess:onSuccess onFailure:onfailure];
    Open_im_sdkUpdateMichoneStatus(callback, [self operationId], conversationID, channelID, status);
}

// 更新说话状态
- (void)updateSpeakStatus:(NSString *)conversationID
                channelID:(NSString *)channelID
                onSuccess: (OIMSuccessCallback)onSuccess
                onfailure:(OIMFailureCallback)onfailure {
    CallbackProxy *callback = [[CallbackProxy alloc] initWithOnSuccess:onSuccess onFailure:onfailure];
    Open_im_sdkUpdateSpeakStatuse(callback, [self operationId], conversationID, channelID);
}

// 获取声网Token - 返回Token
- (void)getRtcToken:(NSString *)uid
          channelID:(NSString *)channelID
           roleType:(NSInteger)roleType
          onSuccess: (OIMSuccessCallback)onSuccess
          onfailure:(OIMFailureCallback)onfailure {
    CallbackProxy *callback = [[CallbackProxy alloc] initWithOnSuccess:onSuccess onFailure:onfailure];
    Open_im_sdkGetRtcToken(callback, [self operationId], uid, channelID, (int32_t)roleType);
}

@end


