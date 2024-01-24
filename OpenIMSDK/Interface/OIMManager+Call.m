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

// 单聊或群聊
- (void)signalingInvite:(NSString *)conversationID
                    userIds:(NSString *)userIds
                     onSuccess:(nullable OIMBoolCallback)onSuccess
                     onFailure:(nullable OIMFailureCallback)onFailure {
    CallbackProxy *callback = [[CallbackProxy alloc]initWithOnSuccess:^(NSString * _Nullable data) {
        NSLog(@"单聊或群聊的回调，再确定回调内容");
//        if (onSuccess) {
//            onSuccess([data isEqualToString:@"true"]);
//        }
    } onFailure:onFailure];
    
    Open_im_sdkSignalingInvite(callback, [self operationId], conversationID, userIds);
}

// 拒绝邀请
- (void)signalingReject:(NSString *)conversationID
              channelID:(NSString *)channelID
              onSuccess:(nullable OIMBoolCallback)onSuccess
              onFailure:(nullable OIMFailureCallback)onFailure {
    CallbackProxy *callback = [[CallbackProxy alloc]initWithOnSuccess:^(NSString * _Nullable data) {
        NSLog(@"拒绝邀请的回调，再确定回调内容");
//        if (onSuccess) {
//            onSuccess([data isEqualToString:@"true"]);
//        }
    } onFailure:onFailure];
    
    Open_im_sdkSignalingReject(callback, [self operationId], conversationID, channelID);
}

// 接受邀请
- (void)signalingAccept:(NSString *)conversationID
              channelID:(NSString *)channelID
              onSuccess:(nullable OIMBoolCallback)onSuccess
              onFailure:(nullable OIMFailureCallback)onFailure {
    CallbackProxy *callback = [[CallbackProxy alloc]initWithOnSuccess:^(NSString * _Nullable data) {
        NSLog(@"接受邀请的回调，再确定回调内容");
//        if (onSuccess) {
//            onSuccess([data isEqualToString:@"true"]);
//        }
    } onFailure:onFailure];
    
    Open_im_sdkSignalingAccept(callback, [self operationId], conversationID, channelID);
}

// 加入群语音房
- (void)signalingJoin:(NSString *)conversationID
              channelID:(NSString *)channelID
              onSuccess:(nullable OIMBoolCallback)onSuccess
              onFailure:(nullable OIMFailureCallback)onFailure {
    CallbackProxy *callback = [[CallbackProxy alloc]initWithOnSuccess:^(NSString * _Nullable data) {
        NSLog(@"加入群语音房的回调，再确定回调内容");
//        if (onSuccess) {
//            onSuccess([data isEqualToString:@"true"]);
//        }
    } onFailure:onFailure];
    
    Open_im_sdkSignalingJoin(callback, [self operationId], conversationID, channelID);
}

// 取消邀请
- (void)SignalingCancel:(NSString *)conversationID
              channelID:(NSString *)channelID
           cancelUserID:(NSString *)cancelUserID
              onSuccess:(nullable OIMBoolCallback)onSuccess
              onFailure:(nullable OIMFailureCallback)onFailure {
    CallbackProxy *callback = [[CallbackProxy alloc]initWithOnSuccess:^(NSString * _Nullable data) {
        NSLog(@"取消邀请的回调，再确定回调内容");
//        if (onSuccess) {
//            onSuccess([data isEqualToString:@"true"]);
//        }
    } onFailure:onFailure];

    Open_im_sdkSignalingCancel(callback, [self operationId], conversationID, channelID, cancelUserID);
}

// 挂断
- (void)signalingHungUp:(NSString *)conversationID
              channelID:(NSString *)channelID
              onSuccess:(nullable OIMBoolCallback)onSuccess
              onFailure:(nullable OIMFailureCallback)onFailure {
    CallbackProxy *callback = [[CallbackProxy alloc]initWithOnSuccess:^(NSString * _Nullable data) {
        NSLog(@"挂断的回调，再确定回调内容");
//        if (onSuccess) {
//            onSuccess([data isEqualToString:@"true"]);
//        }
    } onFailure:onFailure];
    
    Open_im_sdkSignalingHungUp(callback, [self operationId], conversationID, channelID);
}

// 关闭语音房间
- (void)SignalingClose:(NSString *)conversationID
              channelID:(NSString *)channelID
              onSuccess:(nullable OIMBoolCallback)onSuccess
              onFailure:(nullable OIMFailureCallback)onFailure {
    CallbackProxy *callback = [[CallbackProxy alloc]initWithOnSuccess:^(NSString * _Nullable data) {
        NSLog(@"关闭语音房间的回调，再确定回调内容");
//        if (onSuccess) {
//            onSuccess([data isEqualToString:@"true"]);
//        }
    } onFailure:onFailure];
    
    Open_im_sdkSignalingClose(callback, [self operationId], conversationID, channelID);
}

// 更新麦克风状态
- (void)updateMichoneStatus:(NSString *)conversationID
              channelID:(NSString *)channelID
                     status:(int)status
              onSuccess:(nullable OIMBoolCallback)onSuccess
              onFailure:(nullable OIMFailureCallback)onFailure {
    CallbackProxy *callback = [[CallbackProxy alloc]initWithOnSuccess:^(NSString * _Nullable data) {
        NSLog(@"更新麦克风状态的回调，再确定回调内容");
//        if (onSuccess) {
//            onSuccess([data isEqualToString:@"true"]);
//        }
    } onFailure:onFailure];
    
    Open_im_sdkUpdateMichoneStatus(callback, [self operationId], conversationID, channelID, status);
}

// 更新说话状态
- (void)updateSpeakStatus:(NSString *)conversationID
              channelID:(NSString *)channelID
              onSuccess:(nullable OIMBoolCallback)onSuccess
              onFailure:(nullable OIMFailureCallback)onFailure {
    CallbackProxy *callback = [[CallbackProxy alloc]initWithOnSuccess:^(NSString * _Nullable data) {
        NSLog(@"更新说话状态的回调，再确定回调内容");
//        if (onSuccess) {
//            onSuccess([data isEqualToString:@"true"]);
//        }
    } onFailure:onFailure];
    
    Open_im_sdkUpdateSpeakStatuse(callback, [self operationId], conversationID, channelID);
}



@end
