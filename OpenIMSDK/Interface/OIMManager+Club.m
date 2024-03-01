//
//  OIMManager+Club.m
//  OpenIMSDKiOS_Example
//
//  Created by Mark on 2024/2/29.
//  Copyright © 2024 xpg. All rights reserved.
//

#import "OIMManager+Club.h"

@implementation OIMManager (Club)

- (void)dismissServerGroup:(NSString *)groupID 
                 onSuccess:(OIMSuccessCallback)onSuccess
                 onFailure:(OIMFailureCallback)onFailure {
    CallbackProxy *callback = [[CallbackProxy alloc] initWithOnSuccess:onSuccess onFailure:onFailure];
    Open_im_sdkDismissGroup(callback, [self operationId], groupID);
}

- (void)dismissServer:(NSString *)serverID
           onSuccess:(OIMSuccessCallback)onSuccess
           onFailure:(OIMFailureCallback)onFailure {
    CallbackProxy *callback = [[CallbackProxy alloc]initWithOnSuccess:onSuccess onFailure:onFailure];
    Open_im_sdkDismissServer(callback, [self operationId], serverID);
    
}

- (void)KickServerMember:(NSString *)serverID
                  reason:(NSString *)reason
           kickedUserIDs:(NSArray *)kickedUserIDs
               onSuccess:(OIMSuccessCallback)onSuccess
               onFailure:(OIMFailureCallback)onFailure {
    CallbackProxy *callback = [[CallbackProxy alloc] initWithOnSuccess:onSuccess onFailure:onFailure];
    Open_im_sdkKickGroupMember(callback, [self operationId], serverID, reason, kickedUserIDs.mj_JSONString);
}


- (void)kickServerMember:(NSString *)serverID
               OnSuccess:(OIMSuccessCallback)onSuccess
                onFailure:(OIMFailureCallback)onFailure {
    CallbackProxy *callback = [[CallbackProxy alloc] initWithOnSuccess:onSuccess onFailure:onFailure];
//    Open_im_sdkKickGroupMember(callback, [self operationId], <#NSString * _Nullable groupID#>, <#NSString * _Nullable reason#>, <#NSString * _Nullable userIDList#>)
//    
//    Open_im_sdkKickServerMember(callback, [self operationId], serverID);
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
