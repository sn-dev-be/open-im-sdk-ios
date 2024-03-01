//
//  OIMManager+Club.m
//  OpenIMSDKiOS_Example
//
//  Created by Mark on 2024/2/29.
//  Copyright © 2024 xpg. All rights reserved.
//

#import "OIMManager+Club.h"

@implementation OIMManager (Club)

- (void)dismissServerGroup:(NSString *)serverID
                  groupIds:(NSArray *)groupIds
                 onSuccess:(OIMSuccessCallback)onSuccess
                 onFailure:(OIMFailureCallback)onFailure {
    CallbackProxy *callback = [[CallbackProxy alloc] initWithOnSuccess:onSuccess onFailure:onFailure];
    Open_im_sdkDeleteServerGroup(callback, [self operationId], serverID, groupIds.mj_JSONString);
    
}

- (void)dismissServer:(NSString *)serverID
            onSuccess:(OIMSuccessCallback)onSuccess
            onFailure:(OIMFailureCallback)onFailure {
    CallbackProxy *callback = [[CallbackProxy alloc]initWithOnSuccess:onSuccess onFailure:onFailure];
    Open_im_sdkDismissServer(callback, [self operationId], serverID);
}

- (void)kickServerMember:(NSString *)serverID
                  reason:(NSString *)reason
           kickedUserIDs:(NSArray *)kickedUserIDs
               onSuccess:(OIMSuccessCallback)onSuccess
               onFailure:(OIMFailureCallback)onFailure {
    CallbackProxy *callback = [[CallbackProxy alloc] initWithOnSuccess:onSuccess onFailure:onFailure];
    Open_im_sdkKickServerMember(callback, [self operationId], serverID, reason, kickedUserIDs.mj_JSONString);
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
