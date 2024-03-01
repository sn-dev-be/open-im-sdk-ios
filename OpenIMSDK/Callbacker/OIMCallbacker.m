//
//  OIMCallbacker.m
//  OpenIMSDK
//
//  Created by x on 2021/2/11.
//

#import "OIMCallbacker.h"
#import "OIMGCDMulticastDelegate.h"

@interface OIMCallbacker ()
@property (nonatomic, strong) OIMGCDMulticastDelegate <OIMSDKListener> *sdkListeners;
@property (nonatomic, strong) OIMGCDMulticastDelegate <OIMUserListener> *userListeners;
@property (nonatomic, strong) OIMGCDMulticastDelegate <OIMFriendshipListener> *friendshipListeners;
@property (nonatomic, strong) OIMGCDMulticastDelegate <OIMGroupListener> *groupListeners;
@property (nonatomic, strong) OIMGCDMulticastDelegate <OIMConversationListener> *conversationListeners;
@property (nonatomic, strong) OIMGCDMulticastDelegate <OIMAdvancedMsgListener> *advancedMsgListeners;
@property (nonatomic, strong) OIMGCDMulticastDelegate <OIMCustomBusinessListener> *customBusinessListeners;
@property (nonatomic, strong) OIMGCDMulticastDelegate <OIMSignalingListener> *signalingListeners; // 信号监听
@property (nonatomic, strong) OIMGCDMulticastDelegate <OIMClubListener> *clubListeners; // 部落监听

@end

@implementation OIMCallbacker

+ (instancetype)callbacker {
    return [OIMCallbacker new];
}

- (void)setListener {
    Open_im_sdkSetUserListener(self);
    Open_im_sdkSetFriendListener(self);
    Open_im_sdkSetGroupListener(self);
    Open_im_sdkSetConversationListener(self);
    Open_im_sdkSetAdvancedMsgListener(self);
    Open_im_sdkSetCustomBusinessListener(self);
    Open_im_sdkSetSignalingListener(self);
    Open_im_sdkSetClubListener(self);
}

- (void)dispatchMainThread:(void (NS_NOESCAPE ^)(void))todo {
    if ([NSThread isMainThread]) {
        todo();
    } else {
        dispatch_async(dispatch_get_main_queue(), ^{
            todo();
        });
    }
}

#pragma mark -
#pragma mark - Listeners getter

- (OIMGCDMulticastDelegate<OIMSDKListener> *)sdkListeners {
    if (_sdkListeners == nil) {
        _sdkListeners = (OIMGCDMulticastDelegate <OIMSDKListener> *)[[OIMGCDMulticastDelegate alloc] init];
    }
    return _sdkListeners;
}

- (OIMGCDMulticastDelegate<OIMUserListener> *)userListeners {
    if (_userListeners == nil) {
        _userListeners = (OIMGCDMulticastDelegate <OIMUserListener> *)[[OIMGCDMulticastDelegate alloc] init];
    }
    return _userListeners;
}

- (OIMGCDMulticastDelegate<OIMFriendshipListener> *)friendshipListeners {
    if (_friendshipListeners == nil) {
        _friendshipListeners = (OIMGCDMulticastDelegate <OIMFriendshipListener> *)[[OIMGCDMulticastDelegate alloc] init];
    }
    return _friendshipListeners;
}

- (OIMGCDMulticastDelegate<OIMGroupListener> *)groupListeners {
    if (_groupListeners == nil) {
        _groupListeners = (OIMGCDMulticastDelegate <OIMGroupListener> *)[[OIMGCDMulticastDelegate alloc] init];
    }
    return _groupListeners;
}

- (OIMGCDMulticastDelegate<OIMConversationListener> *)conversationListeners {
    if (_conversationListeners == nil) {
        _conversationListeners = (OIMGCDMulticastDelegate <OIMConversationListener> *)[[OIMGCDMulticastDelegate alloc] init];
    }
    return _conversationListeners;
}

- (OIMGCDMulticastDelegate<OIMAdvancedMsgListener> *)advancedMsgListeners {
    if (_advancedMsgListeners == nil) {
        _advancedMsgListeners = (OIMGCDMulticastDelegate <OIMAdvancedMsgListener> *)[[OIMGCDMulticastDelegate alloc] init];
    }
    return _advancedMsgListeners;
}

- (OIMGCDMulticastDelegate<OIMCustomBusinessListener> *)customBusinessListeners {
    if (_customBusinessListeners == nil) {
        _customBusinessListeners = (OIMGCDMulticastDelegate <OIMCustomBusinessListener> *)[[OIMGCDMulticastDelegate alloc] init];
    }
    return _customBusinessListeners;
}

- (OIMGCDMulticastDelegate<OIMSignalingListener> *)signalingListeners {
    if (_signalingListeners == nil) {
        _signalingListeners = (OIMGCDMulticastDelegate <OIMSignalingListener> *)[[OIMGCDMulticastDelegate alloc] init];
    }
    
    return _signalingListeners;
}

- (OIMGCDMulticastDelegate<OIMClubListener> *)clubListeners {
    if (_clubListeners == nil) {
        _clubListeners = (OIMGCDMulticastDelegate <OIMClubListener> *)[[OIMGCDMulticastDelegate alloc] init];
    }
    
    return _clubListeners;
}

#pragma mark -
#pragma mark - Add/Remove listener

- (void)addIMSDKListener:(id<OIMSDKListener>)listener {
    [self.sdkListeners addDelegate:listener delegateQueue:dispatch_get_main_queue()];
}

- (void)removeIMSDKListener:(id<OIMSDKListener>)listener {
    [self.sdkListeners removeDelegate:listener];
}

- (void)addUserListener:(id<OIMUserListener>)listener {
    [self.userListeners addDelegate:listener delegateQueue:dispatch_get_main_queue()];
}

- (void)removeUserListener:(id<OIMUserListener>)listener {
    [self.userListeners removeDelegate:listener];
}

- (void)addFriendListener:(id<OIMFriendshipListener>)listener {
    [self.friendshipListeners addDelegate:listener delegateQueue:dispatch_get_main_queue()];
}

- (void)removeFriendListener:(id<OIMFriendshipListener>)listener {
    [self.friendshipListeners removeDelegate:listener];
}

- (void)addGroupListener:(id<OIMGroupListener>)listener {
    [self.groupListeners addDelegate:listener delegateQueue:dispatch_get_main_queue()];
}

- (void)removeGroupListener:(id<OIMGroupListener>)listener {
    [self.groupListeners removeDelegate:listener];
}

- (void)addConversationListener:(id<OIMConversationListener>)listener {
    [self.conversationListeners addDelegate:listener delegateQueue:dispatch_get_main_queue()];
}

- (void)removeConversationListener:(id<OIMConversationListener>)listener {
    [self.conversationListeners removeDelegate:listener];
}

- (void)addAdvancedMsgListener:(id<OIMAdvancedMsgListener>)listener {
    [self.advancedMsgListeners addDelegate:listener delegateQueue:dispatch_get_main_queue()];
}

- (void)removeAdvancedMsgListener:(id<OIMAdvancedMsgListener>)listener {
    [self.advancedMsgListeners removeDelegate:listener];
}

- (void)addCustomBusinessListener:(id<OIMCustomBusinessListener>)listener {
    [self.customBusinessListeners addDelegate:listener delegateQueue:dispatch_get_main_queue()];
}

- (void)removeCustomBusinessListener:(id<OIMCustomBusinessListener>)listener {
    [self.customBusinessListeners removeDelegate:listener];
}

- (void)addSignalingListener:(id<OIMSignalingListener>)listener {
    [self.signalingListeners addDelegate:listener delegateQueue:dispatch_get_main_queue()];
}

- (void)removeSignalingListener:(id<OIMSignalingListener>)listener {
    [self.signalingListeners removeDelegate:listener];
}

- (void)addClubListener:(id<OIMClubListener>)listener {
    [self.clubListeners addDelegate:listener delegateQueue:dispatch_get_main_queue()];
}

- (void)removeClubListener:(id<OIMClubListener>)listener {
    [self.clubListeners removeDelegate:listener];
}

#pragma mark -
#pragma mark - Connection

- (void)onConnectFailed:(int32_t)errCode errMsg:(NSString * _Nullable)errMsg {
    
    [self dispatchMainThread:^{
        if (self.connectFailure) {
            self.connectFailure(errCode, errMsg);
        }
        
        [self.sdkListeners onConnectFailed:errCode err:errMsg];
    }];
}

- (void)onConnectSuccess {
    [self dispatchMainThread:^{
        if (self.connectSuccess) {
            self.connectSuccess();
        }
        
        [self.sdkListeners onConnectSuccess];
    }];
}

- (void)onConnecting {
    [self dispatchMainThread:^{
        if (self.connecting) {
            self.connecting();
        }

        [self.sdkListeners onConnecting];
    }];
}

- (void)onKickedOffline {
    [self dispatchMainThread:^{
        if (self.kickedOffline) {
            self.kickedOffline();
        }
        
        [self.sdkListeners onKickedOffline];
    }];
}

- (void)onUserTokenExpired {
    [self dispatchMainThread:^{
        if (self.userTokenExpired) {
            self.userTokenExpired();
        }

        [self.sdkListeners onUserTokenExpired];
    }];
}

#pragma mark -
#pragma mark - User

- (void)onSelfInfoUpdated:(NSString * _Nullable)userInfo {
    OIMUserInfo *info = [OIMUserInfo mj_objectWithKeyValues:userInfo];
    
    [self dispatchMainThread:^{
        if (self.onSelfInfoUpdated) {
            self.onSelfInfoUpdated(info);
        }
        
        [self.userListeners onSelfInfoUpdated:info];
    }];
}

- (void)onUserStatusChanged:(NSString *)statusMap {
    OIMUserStatusInfo *info = [OIMUserStatusInfo mj_objectWithKeyValues:statusMap];
    
    [self dispatchMainThread:^{
        if (self.onUserStatusChanged) {
            self.onUserStatusChanged(info);
        }
        
        [self.userListeners onUserStatusChanged:info];
    }];
}

#pragma mark -
#pragma mark - Friend

- (void)onFriendApplicationAdded:(NSString * _Nullable)friendApplication {
    OIMFriendApplication *info = [OIMFriendApplication mj_objectWithKeyValues:friendApplication];
    
    [self dispatchMainThread:^{
        if (self.onFriendApplicationAdded) {
            self.onFriendApplicationAdded(info);
        }
        [self.friendshipListeners onFriendApplicationAdded:info];
    }];
}

- (void)onFriendApplicationRejected:(NSString * _Nullable)friendApplication {
    OIMFriendApplication *info = [OIMFriendApplication mj_objectWithKeyValues:friendApplication];
    
    [self dispatchMainThread:^{
        if (self.onFriendApplicationRejected) {
            self.onFriendApplicationRejected(info);
        }
        [self.friendshipListeners onFriendApplicationRejected:info];
    }];
}

- (void)onFriendApplicationAccepted:(NSString * _Nullable)friendApplication {
    OIMFriendApplication *info = [OIMFriendApplication mj_objectWithKeyValues:friendApplication];
    
    [self dispatchMainThread:^{
        if (self.onFriendApplicationAccepted) {
            self.onFriendApplicationAccepted(info);
        }
        [self.friendshipListeners onFriendApplicationAccepted:info];
    }];
}

- (void)onFriendApplicationDeleted:(NSString * _Nullable)friendApplication {
    OIMFriendApplication *info = [OIMFriendApplication mj_objectWithKeyValues:friendApplication];

    [self dispatchMainThread:^{
        if (self.onFriendApplicationDeleted) {
            self.onFriendApplicationDeleted(info);
        }
        [self.friendshipListeners onFriendApplicationDeleted:info];
    }];
}

- (void)onFriendAdded:(NSString * _Nullable)friendInfo {
    OIMFriendInfo *info = [OIMFriendInfo mj_objectWithKeyValues:friendInfo];
    
    [self dispatchMainThread:^{
        if (self.onFriendAdded) {
            self.onFriendAdded(info);
        }
        [self.friendshipListeners onFriendAdded:info];
    }];
}

- (void)onFriendDeleted:(NSString * _Nullable)friendInfo {
    OIMFriendInfo *info = [OIMFriendInfo mj_objectWithKeyValues:friendInfo];
    
    [self dispatchMainThread:^{
        if (self.onFriendDeleted) {
            self.onFriendDeleted(info);
        }
        [self.friendshipListeners onFriendDeleted:info];
    }];
}

- (void)onFriendInfoChanged:(NSString * _Nullable)friendInfo {
    OIMFriendInfo *info = [OIMFriendInfo mj_objectWithKeyValues:friendInfo];
    
    [self dispatchMainThread:^{
        if (self.onFriendInfoChanged) {
            self.onFriendInfoChanged(info);
        }
        [self.friendshipListeners onFriendInfoChanged:info];
    }];
}

- (void)onBlackAdded:(NSString* _Nullable)blackInfo {
    OIMBlackInfo *info = [OIMBlackInfo mj_objectWithKeyValues:blackInfo];
    
    [self dispatchMainThread:^{
        if (self.onBlackAdded) {
            self.onBlackAdded(info);
        }
        [self.friendshipListeners onBlackAdded:info];
    }];
}

- (void)onBlackDeleted:(NSString * _Nullable)blackInfo {
    OIMBlackInfo *info = [OIMBlackInfo mj_objectWithKeyValues:blackInfo];
    
    [self dispatchMainThread:^{
        if (self.onBlackDeleted) {
            self.onBlackDeleted(info);
        }
        [self.friendshipListeners onBlackDeleted:info];
    }];
}

#pragma mark -
#pragma mark - Group

- (void)onGroupMemberAdded:(NSString * _Nullable)groupMemberInfo {
    OIMGroupMemberInfo *info = [OIMGroupMemberInfo mj_objectWithKeyValues:groupMemberInfo];
    
    [self dispatchMainThread:^{
        if (self.onGroupMemberAdded) {
            self.onGroupMemberAdded(info);
        }
        [self.groupListeners onGroupMemberAdded:info];
    }];
}

- (void)onGroupMemberDeleted:(NSString * _Nullable)groupMemberInfo {
    OIMGroupMemberInfo *info = [OIMGroupMemberInfo mj_objectWithKeyValues:groupMemberInfo];
    
    [self dispatchMainThread:^{
        if (self.onGroupMemberDeleted) {
            self.onGroupMemberDeleted(info);
        }
        
        [self.groupListeners onGroupMemberDeleted:info];
    }];
}

- (void)onGroupMemberInfoChanged:(NSString * _Nullable)groupMemberInfo {
    OIMGroupMemberInfo *info = [OIMGroupMemberInfo mj_objectWithKeyValues:groupMemberInfo];
    
    [self dispatchMainThread:^{
        if (self.onGroupMemberInfoChanged) {
            self.onGroupMemberInfoChanged(info);
        }
        
        [self.groupListeners onGroupMemberInfoChanged:info];
    }];
}

- (void)onGroupInfoChanged:(NSString * _Nullable)groupInfo {
    OIMGroupInfo *info = [OIMGroupInfo mj_objectWithKeyValues:groupInfo];

    [self dispatchMainThread:^{
        if (self.onGroupInfoChanged) {
            self.onGroupInfoChanged(info);
        }

        [self.groupListeners onGroupInfoChanged:info];
    }];
}

- (void)onJoinedGroupAdded:(NSString * _Nullable)groupInfo {
    OIMGroupInfo *info = [OIMGroupInfo mj_objectWithKeyValues:groupInfo];
    
    [self dispatchMainThread:^{
        if (self.onJoinedGroupAdded) {
            self.onJoinedGroupAdded(info);
        }
        
        [self.groupListeners onJoinedGroupAdded:info];
    }];
}

- (void)onJoinedGroupDeleted:(NSString * _Nullable)groupInfo {
    OIMGroupInfo *info = [OIMGroupInfo mj_objectWithKeyValues:groupInfo];
    
    [self dispatchMainThread:^{
        if (self.onJoinedGroupDeleted) {
            self.onJoinedGroupDeleted(info);
        }

        [self.groupListeners onJoinedGroupDeleted:info];
    }];
}

- (void)onGroupApplicationAccepted:(NSString * _Nullable)groupApplication {
    OIMGroupApplicationInfo *info = [OIMGroupApplicationInfo mj_objectWithKeyValues:groupApplication];
    
    [self dispatchMainThread:^{
        if (self.onGroupApplicationAccepted) {
            self.onGroupApplicationAccepted(info);
        }
        
        [self.groupListeners onGroupApplicationAccepted:info];
    }];
}

- (void)onGroupApplicationAdded:(NSString * _Nullable)groupApplication {
    OIMGroupApplicationInfo *info = [OIMGroupApplicationInfo mj_objectWithKeyValues:groupApplication];
    
    [self dispatchMainThread:^{
        if (self.onGroupApplicationAdded) {
            self.onGroupApplicationAdded(info);
        }

        [self.groupListeners onGroupApplicationAdded:info];
    }];
}

- (void)onGroupApplicationDeleted:(NSString * _Nullable)groupApplication {
    OIMGroupApplicationInfo *info = [OIMGroupApplicationInfo mj_objectWithKeyValues:groupApplication];
    
    [self dispatchMainThread:^{
        if (self.onGroupApplicationDeleted) {
            self.onGroupApplicationDeleted(info);
        }

        [self.groupListeners onGroupApplicationDeleted:info];
    }];
}

- (void)onGroupApplicationRejected:(NSString * _Nullable)groupApplication {
    OIMGroupApplicationInfo *info = [OIMGroupApplicationInfo mj_objectWithKeyValues:groupApplication];
    
    [self dispatchMainThread:^{
        if (self.onGroupApplicationRejected) {
            self.onGroupApplicationRejected(info);
        }
        
        [self.groupListeners onGroupApplicationRejected:info];
    }];
}

- (void)onGroupDismissed:(NSString *)groupInfo {
    OIMGroupInfo *info = [OIMGroupInfo mj_objectWithKeyValues:groupInfo];
    
    [self dispatchMainThread:^{
        if (self.onGroupDismissed) {
            self.onGroupDismissed(info);
        }

        [self.groupListeners onGroupDismissed:info];
    }];
}

#pragma mark -
#pragma mark - Message

- (void)onRecvC2CReadReceipt:(NSString * _Nullable)msgReceiptList {
    NSArray *receipts = [OIMReceiptInfo mj_objectArrayWithKeyValuesArray:msgReceiptList];
    
    [self dispatchMainThread:^{
        if (self.onRecvC2CReadReceipt) {
            self.onRecvC2CReadReceipt(receipts);
        }

        [self.advancedMsgListeners onRecvC2CReadReceipt:receipts];
    }];
}

- (void)onRecvGroupReadReceipt:(NSString* _Nullable)groupMsgReceiptList {
    NSArray *receipts = [OIMReceiptInfo mj_objectArrayWithKeyValuesArray:groupMsgReceiptList];
    
    [self dispatchMainThread:^{
        if (self.onRecvGroupReadReceipt) {
            self.onRecvGroupReadReceipt(receipts);
        }
        
        [self.advancedMsgListeners onRecvGroupReadReceipt:receipts];
    }];
}

- (void)onNewRecvMessageRevoked:(NSString *)messageRevoked {
    
    OIMMessageRevokedInfo *revoked = [OIMMessageRevokedInfo mj_objectWithKeyValues:messageRevoked];
    
    [self dispatchMainThread:^{
        if (self.onRecvMessageRevoked) {
            self.onRecvMessageRevoked(revoked);
        }
        
        [self.advancedMsgListeners onRecvMessageRevoked:revoked];
    }];
}

- (void)onRecvRedPacketStatusChanged:(NSString* _Nullable)redPacketMsg {
    OIMMessageRedPacketInfo *packet = [OIMMessageRedPacketInfo mj_objectWithKeyValues:redPacketMsg];
    [self dispatchMainThread:^{
        if (self.onRecvMessageRedPacketed) {
            self.onRecvMessageRedPacketed(packet);
        }
        
        [self.advancedMsgListeners onRecvMessageRedPacketed:packet];
    }];
}

- (void)onRecvSelfSendRedPacketSeqChanged:(NSString* _Nullable)message {
    OIMMessageInfo *msg = [OIMMessageInfo mj_objectWithKeyValues:message];
    [self dispatchMainThread:^{
        if (self.onRecvNewMessage) {
            self.onRecvNewMessage(msg);
        }
        
        [self.advancedMsgListeners onRecvSelfSendRedPacketSeqChanged:msg];
    }];
}

- (void)onRecvNewMessage:(NSString * _Nullable)message {
    OIMMessageInfo *msg = [OIMMessageInfo mj_objectWithKeyValues:message];
    
    [self dispatchMainThread:^{
        if (self.onRecvNewMessage) {
            self.onRecvNewMessage(msg);
        }
        
        [self.advancedMsgListeners onRecvNewMessage:msg];
    }];
}

- (void)onMsgDeleted:(NSString *)message {
    OIMMessageInfo *msg = [OIMMessageInfo mj_objectWithKeyValues:message];

    [self dispatchMainThread:^{
        if (self.onMessageDeleted) {
            self.onMessageDeleted(msg);
        }
        
        [self.advancedMsgListeners onMsgDeleted:msg];
    }];
}

- (void)onRecvOfflineNewMessage:(NSString * _Nullable)message {
    
}

- (void)onRecvMessageExtensionsAdded:(NSString * _Nullable)msgID reactionExtensionList:(NSString * _Nullable)reactionExtensionList {
    
}

- (void)onRecvMessageExtensionsChanged:(NSString * _Nullable)msgID reactionExtensionList:(NSString * _Nullable)reactionExtensionList {
    
}

- (void)onRecvMessageExtensionsDeleted:(NSString * _Nullable)msgID reactionExtensionKeyList:(NSString * _Nullable)reactionExtensionKeyList {
    
}

#pragma mark -
#pragma mark - Conversation

- (void)onConversationChanged:(NSString * _Nullable)conversationList {
    
    NSArray *tConversations = [OIMConversationInfo mj_objectArrayWithKeyValuesArray:conversationList];
    
    [self dispatchMainThread:^{
        if (self.onConversationChanged) {
            self.onConversationChanged(tConversations);
        }

        [self.conversationListeners onConversationChanged:tConversations];
    }];
}

- (void)onNewConversation:(NSString * _Nullable)conversationList {
    
    NSArray *tConversations = [OIMConversationInfo mj_objectArrayWithKeyValuesArray:conversationList];
    
    [self dispatchMainThread:^{
        if (self.onNewConversation) {
            self.onNewConversation(tConversations);
        }
        
        [self.conversationListeners onNewConversation:tConversations];
    }];
}

- (void)onSyncServerFailed {
    [self dispatchMainThread:^{
        if (self.syncServerFailed) {
            self.syncServerFailed();
        }
        
        [self.conversationListeners onSyncServerFailed];
    }];
}

- (void)onSyncServerFinish {
    [self dispatchMainThread:^{
        if (self.syncServerFinish) {
            self.syncServerFinish();
        }

        [self.conversationListeners onSyncServerFinish];
    }];
}

- (void)onSyncServerStart {
    [self dispatchMainThread:^{
        if (self.syncServerStart) {
            self.syncServerStart();
        }
        
        [self.conversationListeners onSyncServerStart];
    }];
}

- (void)onTotalUnreadMessageCountChanged:(int32_t)totalUnreadCount {
    [self dispatchMainThread:^{
        if (self.onTotalUnreadMessageCountChanged) {
            self.onTotalUnreadMessageCountChanged(totalUnreadCount);
        }
        
        [self.conversationListeners onTotalUnreadMessageCountChanged:totalUnreadCount];
    }];
}

- (void)onServerUnreadMessageCountChanged:(NSString *)serverID totalUnreadCount:(int32_t)totalUnreadCount {
    [self dispatchMainThread:^{
        if (self.onServerUnreadMessageCountChanged) {
            self.onServerUnreadMessageCountChanged(serverID, totalUnreadCount);
        }
        [self.conversationListeners onServerUnreadMessageCountChanged:serverID totalUnreadCount:totalUnreadCount];
    }];
    
    
}

#pragma mark -
#pragma mark - CustomBusiness

- (void)onRecvCustomBusinessMessage:(NSString *)businessMessage {
    NSDictionary *output = businessMessage.mj_JSONObject;
    
    [self dispatchMainThread:^{
        if (self.onRecvCustomBusinessMessage) {
            self.onRecvCustomBusinessMessage(output);
        }

        [self.customBusinessListeners onRecvCustomBusinessMessage:output];
    }];
}

#pragma mark -
#pragma mark - OIMSignalingListener


//OIMSignalVoiceInfo
//OIMSignalVoiceMicphoneStatusInfo
//OIMSignalVoiceSpeakStatusInfo

// 邀请信令
- (void)onReceiveNewInvitation:(NSString * _Nullable)voiceInfo {
    OIMSignalVoiceInfo *info = [OIMSignalVoiceInfo mj_objectWithKeyValues:voiceInfo];
    [self dispatchMainThread:^{
        if (self.onVoiceInvitation) {
            self.onVoiceInvitation(info);
        }
        [self.signalingListeners onReceiveNewInvitation:info];
    }];
}

// 邀请接受信令
- (void)onInviteeAccepted:(NSString * _Nullable)voiceInfo {
    OIMSignalVoiceInfo *info = [OIMSignalVoiceInfo mj_objectWithKeyValues:voiceInfo];
    [self dispatchMainThread:^{
        if (self.onVoiceAccepted) {
            self.onVoiceAccepted(info);
        }
        [self.signalingListeners onInviteeAccepted:info];
    }];
}

// 邀请拒绝信令
- (void)onInviteeRejected:(NSString * _Nullable)voiceInfo {
    OIMSignalVoiceInfo *info = [OIMSignalVoiceInfo mj_objectWithKeyValues:voiceInfo];
    [self dispatchMainThread:^{
        if (self.onVoiceRejected) {
            self.onVoiceRejected(info);
        }
        [self.signalingListeners onInviteeRejected:info];
    }];
}

// 加入房间信令
- (void)onJoined:(NSString * _Nullable)voiceInfo {
    OIMSignalVoiceInfo *info = [OIMSignalVoiceInfo mj_objectWithKeyValues:voiceInfo];
    [self dispatchMainThread:^{
        if (self.onVoiceJoined) {
            self.onVoiceJoined(info);
        }
        [self.signalingListeners onJoined:info];
    }];
}

// 邀请取消信令
- (void)onInvitationCancelled:(NSString * _Nullable)voiceInfo {
    OIMSignalVoiceInfo *info = [OIMSignalVoiceInfo mj_objectWithKeyValues:voiceInfo];
    [self dispatchMainThread:^{
        if (self.onVoiceInvitation) {
            self.onVoiceInvitation(info);
        }
        [self.signalingListeners onInvitationCancelled:info];
    }];
}

// 挂断信令
- (void)onHangUp:(NSString * _Nullable)voiceInfo {
    OIMSignalVoiceInfo *info = [OIMSignalVoiceInfo mj_objectWithKeyValues:voiceInfo];
    [self dispatchMainThread:^{
        if (self.onVoiceHangUp) {
            self.onVoiceHangUp(info);
        }
        [self.signalingListeners onHangUp:info];
    }];
}

// 关闭信令
- (void)onClosed:(NSString * _Nullable)voiceInfo {
    OIMSignalVoiceInfo *info = [OIMSignalVoiceInfo mj_objectWithKeyValues:voiceInfo];
    [self dispatchMainThread:^{
        if (self.onVoiceClosed) {
            self.onVoiceClosed(info);
        }
        [self.signalingListeners onClosed:info];
    }];
}

// 麦克风状态改变信令
- (void)onMicphoneStatusChanged:(NSString * _Nullable)micphoneInfo {
    OIMSignalVoiceMicphoneStatusInfo *info = [OIMSignalVoiceMicphoneStatusInfo mj_objectWithKeyValues:micphoneInfo];
    [self dispatchMainThread:^{
        if (self.onVoiceMicphone) {
            self.onVoiceMicphone(info);
        }
        [self.signalingListeners onMicphoneStatusChanged:info];
    }];
}

// 说话状态通知信令
- (void)onSpeakStatusChanged:(NSString * _Nullable)speakInfo {
    OIMSignalVoiceSpeakStatusInfo *info = [OIMSignalVoiceSpeakStatusInfo mj_objectWithKeyValues:speakInfo];
    [self dispatchMainThread:^{
        if (self.onVoiceSpeak) {
            self.onVoiceSpeak(info);
        }
        [self.signalingListeners onSpeakStatusChanged:info];
    }];
}


#pragma mark - OIMClubListener

// 部落解散通知
- (void)onServerDismissed:(NSString *)serverID {
    [self dispatchMainThread:^{
        if (self.onClubDismissed) {
            self.onClubDismissed(serverID);
        }
        [self.clubListeners onServerDismissed:serverID];
    }];
}
// 部落成员被踢出通知
- (void)onServerMemberKicked:(NSString *)serverID {
    [self dispatchMainThread:^{
        if (self.onClubMemberKicked) {
            self.onClubMemberKicked(serverID);
        }
        [self.clubListeners onServerMemberKicked:serverID];
    }];
}

- (void)onServerGroupDismissed:(NSString *)groupInfo {
    OIMGroupInfo *info = [OIMGroupInfo mj_objectWithKeyValues:groupInfo];
    [self dispatchMainThread:^{
        if (self.onClubGroupDismissed) {
            self.onClubGroupDismissed(info);
        }

        [self.clubListeners onServerGroupDismissed:info];
    }];
}




@end
