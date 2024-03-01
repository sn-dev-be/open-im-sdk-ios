//
//  OIMManager+Club.m
//  OpenIMSDKiOS_Example
//
//  Created by Mark on 2024/2/29.
//  Copyright © 2024 xpg. All rights reserved.
//

#import "OIMManager+Club.h"

@implementation OIMManager (Club)

- (void)dismissServer:(NSString *)serverID
           onSuccess:(OIMSuccessCallback)onSuccess
           onFailure:(OIMFailureCallback)onFailure {
    CallbackProxy *callback = [[CallbackProxy alloc]initWithOnSuccess:onSuccess onFailure:onFailure];
    Open_im_sdkDismissServer(callback, [self operationId], serverID);
    
}

- (void)onServerMemberKickedOnSuccess:(OIMSuccessCallback)onSuccess
                            onFailure:(OIMFailureCallback)onFailure {
    CallbackProxy *callback = [[CallbackProxy alloc] initWithOnSuccess:onSuccess onFailure:onFailure];
}



- (void)acceptServerApplication:(NSString *)serverID
                     fromUserID:(NSString *)fromUserID
                      handleMsg:(NSString *)handleMsg
                 conversationID:(NSString *)conversationID
           onSuccess:(OIMSuccessCallback)onSuccess
           onFailure:(OIMFailureCallback)onFailure {
    CallbackProxy *callback = [[CallbackProxy alloc]initWithOnSuccess:onSuccess onFailure:onFailure];
    Open_im_sdkAcceptServerApplication(callback, [self operationId], serverID, fromUserID, handleMsg, conversationID);
}

- (void)refuseServerApplication:(NSString *)serverID
                     fromUserID:(NSString *)fromUserID
                      handleMsg:(NSString *)handleMsg
                 conversationID:(NSString *)conversationID
           onSuccess:(OIMSuccessCallback)onSuccess
           onFailure:(OIMFailureCallback)onFailure {
    CallbackProxy *callback = [[CallbackProxy alloc]initWithOnSuccess:onSuccess onFailure:onFailure];
    Open_im_sdkRefuseServerApplication(callback, [self operationId], serverID, fromUserID, handleMsg, conversationID);
}

@end
