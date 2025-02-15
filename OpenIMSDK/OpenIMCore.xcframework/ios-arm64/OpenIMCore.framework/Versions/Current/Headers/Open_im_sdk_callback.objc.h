// Objective-C API for talking to github.com/openimsdk/openim-sdk-core/v3/open_im_sdk_callback Go package.
//   gobind -lang=objc github.com/openimsdk/openim-sdk-core/v3/open_im_sdk_callback
//
// File is generated by gobind. Do not edit.

#ifndef __Open_im_sdk_callback_H__
#define __Open_im_sdk_callback_H__

@import Foundation;
#include "ref.h"
#include "Universe.objc.h"


@protocol Open_im_sdk_callbackBase;
@class Open_im_sdk_callbackBase;
@protocol Open_im_sdk_callbackOnAdvancedMsgListener;
@class Open_im_sdk_callbackOnAdvancedMsgListener;
@protocol Open_im_sdk_callbackOnBatchMsgListener;
@class Open_im_sdk_callbackOnBatchMsgListener;
@protocol Open_im_sdk_callbackOnClubListener;
@class Open_im_sdk_callbackOnClubListener;
@protocol Open_im_sdk_callbackOnConnListener;
@class Open_im_sdk_callbackOnConnListener;
@protocol Open_im_sdk_callbackOnConversationListener;
@class Open_im_sdk_callbackOnConversationListener;
@protocol Open_im_sdk_callbackOnCustomBusinessListener;
@class Open_im_sdk_callbackOnCustomBusinessListener;
@protocol Open_im_sdk_callbackOnFriendshipListener;
@class Open_im_sdk_callbackOnFriendshipListener;
@protocol Open_im_sdk_callbackOnFriendshipListenerSdk;
@class Open_im_sdk_callbackOnFriendshipListenerSdk;
@protocol Open_im_sdk_callbackOnGroupListener;
@class Open_im_sdk_callbackOnGroupListener;
@protocol Open_im_sdk_callbackOnListenerForService;
@class Open_im_sdk_callbackOnListenerForService;
@protocol Open_im_sdk_callbackOnMessageKvInfoListener;
@class Open_im_sdk_callbackOnMessageKvInfoListener;
@protocol Open_im_sdk_callbackOnSignalingListener;
@class Open_im_sdk_callbackOnSignalingListener;
@protocol Open_im_sdk_callbackOnUserListener;
@class Open_im_sdk_callbackOnUserListener;
@protocol Open_im_sdk_callbackSendMsgCallBack;
@class Open_im_sdk_callbackSendMsgCallBack;
@protocol Open_im_sdk_callbackUploadFileCallback;
@class Open_im_sdk_callbackUploadFileCallback;

@protocol Open_im_sdk_callbackBase <NSObject>
- (void)onError:(int32_t)errCode errMsg:(NSString* _Nullable)errMsg;
- (void)onSuccess:(NSString* _Nullable)data;
@end

@protocol Open_im_sdk_callbackOnAdvancedMsgListener <NSObject>
- (void)onMsgDeleted:(NSString* _Nullable)message;
- (void)onNewRecvMessageRevoked:(NSString* _Nullable)messageRevoked;
- (void)onRecvC2CReadReceipt:(NSString* _Nullable)msgReceiptList;
- (void)onRecvGroupReadReceipt:(NSString* _Nullable)groupMsgReceiptList;
- (void)onRecvMessageExtensionsAdded:(NSString* _Nullable)msgID reactionExtensionList:(NSString* _Nullable)reactionExtensionList;
- (void)onRecvMessageExtensionsChanged:(NSString* _Nullable)msgID reactionExtensionList:(NSString* _Nullable)reactionExtensionList;
- (void)onRecvMessageExtensionsDeleted:(NSString* _Nullable)msgID reactionExtensionKeyList:(NSString* _Nullable)reactionExtensionKeyList;
- (void)onRecvNewMessage:(NSString* _Nullable)message;
- (void)onRecvOfflineNewMessage:(NSString* _Nullable)message;
- (void)onRecvRedPacketStatusChanged:(NSString* _Nullable)redPacketMsg;
- (void)onRecvSelfSendRedPacketSeqChanged:(NSString* _Nullable)message;
@end

@protocol Open_im_sdk_callbackOnBatchMsgListener <NSObject>
- (void)onRecvNewMessages:(NSString* _Nullable)messageList;
- (void)onRecvOfflineNewMessages:(NSString* _Nullable)messageList;
@end

@protocol Open_im_sdk_callbackOnClubListener <NSObject>
- (void)onJoinedServerAdded:(NSString* _Nullable)serverInfo;
- (void)onJoinedServerDeleted:(NSString* _Nullable)serverInfo;
- (void)onServerApplicationAccepted:(NSString* _Nullable)serverApplication;
- (void)onServerApplicationAdded:(NSString* _Nullable)serverApplication;
- (void)onServerApplicationDeleted:(NSString* _Nullable)serverApplication;
- (void)onServerApplicationRejected:(NSString* _Nullable)serverApplication;
- (void)onServerDismissed:(NSString* _Nullable)serverID;
- (void)onServerGroupDismissed:(NSString* _Nullable)groupInfo;
- (void)onServerInfoChanged:(NSString* _Nullable)serverInfo;
- (void)onServerMemberAdded:(NSString* _Nullable)serverMemberInfo;
- (void)onServerMemberDeleted:(NSString* _Nullable)serverMemberInfo;
- (void)onServerMemberInfoChanged:(NSString* _Nullable)serverMemberInfo;
- (void)onServerMemberKicked:(NSString* _Nullable)serverID;
@end

@protocol Open_im_sdk_callbackOnConnListener <NSObject>
- (void)onConnectFailed:(int32_t)errCode errMsg:(NSString* _Nullable)errMsg;
- (void)onConnectSuccess;
- (void)onConnecting;
- (void)onKickedOffline;
- (void)onUserTokenExpired;
@end

@protocol Open_im_sdk_callbackOnConversationListener <NSObject>
- (void)onConversationChanged:(NSString* _Nullable)conversationList;
- (void)onNewConversation:(NSString* _Nullable)conversationList;
- (void)onServerUnreadMessageCountChanged:(NSString* _Nullable)serverID totalUnreadCount:(int32_t)totalUnreadCount;
/**
 * OnSyncServerProgress(progress int)
 */
- (void)onSyncServerFailed;
- (void)onSyncServerFinish;
- (void)onSyncServerStart;
- (void)onTotalUnreadMessageCountChanged:(int32_t)totalUnreadCount;
@end

@protocol Open_im_sdk_callbackOnCustomBusinessListener <NSObject>
- (void)onRecvCustomBusinessMessage:(NSString* _Nullable)businessMessage;
@end

@protocol Open_im_sdk_callbackOnFriendshipListener <NSObject>
- (void)onBlackAdded:(NSString* _Nullable)blackInfo;
- (void)onBlackDeleted:(NSString* _Nullable)blackInfo;
- (void)onFriendAdded:(NSString* _Nullable)friendInfo;
- (void)onFriendApplicationAccepted:(NSString* _Nullable)friendApplication;
- (void)onFriendApplicationAdded:(NSString* _Nullable)friendApplication;
- (void)onFriendApplicationDeleted:(NSString* _Nullable)friendApplication;
- (void)onFriendApplicationRejected:(NSString* _Nullable)friendApplication;
- (void)onFriendDeleted:(NSString* _Nullable)friendInfo;
- (void)onFriendInfoChanged:(NSString* _Nullable)friendInfo;
@end

@protocol Open_im_sdk_callbackOnFriendshipListenerSdk <NSObject>
// skipped method OnFriendshipListenerSdk.OnBlackAdded with unsupported parameter or return types

// skipped method OnFriendshipListenerSdk.OnBlackDeleted with unsupported parameter or return types

// skipped method OnFriendshipListenerSdk.OnFriendAdded with unsupported parameter or return types

// skipped method OnFriendshipListenerSdk.OnFriendApplicationAccepted with unsupported parameter or return types

// skipped method OnFriendshipListenerSdk.OnFriendApplicationAdded with unsupported parameter or return types

// skipped method OnFriendshipListenerSdk.OnFriendApplicationDeleted with unsupported parameter or return types

// skipped method OnFriendshipListenerSdk.OnFriendApplicationRejected with unsupported parameter or return types

// skipped method OnFriendshipListenerSdk.OnFriendDeleted with unsupported parameter or return types

// skipped method OnFriendshipListenerSdk.OnFriendInfoChanged with unsupported parameter or return types

@end

@protocol Open_im_sdk_callbackOnGroupListener <NSObject>
- (void)onGroupApplicationAccepted:(NSString* _Nullable)groupApplication;
- (void)onGroupApplicationAdded:(NSString* _Nullable)groupApplication;
- (void)onGroupApplicationDeleted:(NSString* _Nullable)groupApplication;
- (void)onGroupApplicationRejected:(NSString* _Nullable)groupApplication;
- (void)onGroupDismissed:(NSString* _Nullable)groupInfo;
- (void)onGroupInfoChanged:(NSString* _Nullable)groupInfo;
- (void)onGroupMemberAdded:(NSString* _Nullable)groupMemberInfo;
- (void)onGroupMemberDeleted:(NSString* _Nullable)groupMemberInfo;
- (void)onGroupMemberInfoChanged:(NSString* _Nullable)groupMemberInfo;
- (void)onJoinedGroupAdded:(NSString* _Nullable)groupInfo;
- (void)onJoinedGroupDeleted:(NSString* _Nullable)groupInfo;
@end

@protocol Open_im_sdk_callbackOnListenerForService <NSObject>
/**
 * 好友申请被同意
 */
- (void)onFriendApplicationAccepted:(NSString* _Nullable)groupApplication;
/**
 * 有人申请添加你为好友
 */
- (void)onFriendApplicationAdded:(NSString* _Nullable)friendApplication;
/**
 * 进群申请被同意
 */
- (void)onGroupApplicationAccepted:(NSString* _Nullable)groupApplication;
/**
 * 有人申请进群
 */
- (void)onGroupApplicationAdded:(NSString* _Nullable)groupApplication;
/**
 * 收到新消息
 */
- (void)onRecvNewMessage:(NSString* _Nullable)message;
@end

@protocol Open_im_sdk_callbackOnMessageKvInfoListener <NSObject>
- (void)onMessageKvInfoChanged:(NSString* _Nullable)messageChangedList;
@end

@protocol Open_im_sdk_callbackOnSignalingListener <NSObject>
- (void)onClosed:(NSString* _Nullable)closedCallback;
/**
 * OnInvitationTimeout(invitationTimeoutCallback string)
 */
- (void)onHangUp:(NSString* _Nullable)hangUpCallback;
- (void)onInvitationCancelled:(NSString* _Nullable)invitationCancelledCallback;
- (void)onInviteeAccepted:(NSString* _Nullable)inviteeAcceptedCallback;
- (void)onInviteeRejected:(NSString* _Nullable)inviteeRejectedCallback;
- (void)onJoined:(NSString* _Nullable)joinedCallback;
- (void)onMicphoneStatusChanged:(NSString* _Nullable)onMicphoneStatusChangedCallback;
- (void)onReceiveNewInvitation:(NSString* _Nullable)receiveNewInvitationCallback;
- (void)onSpeakStatusChanged:(NSString* _Nullable)onSpeakStatusUpdatedCallback;
@end

@protocol Open_im_sdk_callbackOnUserListener <NSObject>
- (void)onSelfInfoUpdated:(NSString* _Nullable)userInfo;
- (void)onUserStatusChanged:(NSString* _Nullable)userOnlineStatus;
@end

@protocol Open_im_sdk_callbackSendMsgCallBack <NSObject>
- (void)onError:(int32_t)errCode errMsg:(NSString* _Nullable)errMsg;
- (void)onProgress:(long)progress;
- (void)onSuccess:(NSString* _Nullable)data;
@end

@protocol Open_im_sdk_callbackUploadFileCallback <NSObject>
- (void)complete:(int64_t)size url:(NSString* _Nullable)url typ:(long)typ;
- (void)hashPartComplete:(NSString* _Nullable)partsHash fileHash:(NSString* _Nullable)fileHash;
- (void)hashPartProgress:(long)index size:(int64_t)size partHash:(NSString* _Nullable)partHash;
- (void)open:(int64_t)size;
- (void)partSize:(int64_t)partSize num:(long)num;
- (void)uploadComplete:(int64_t)fileSize streamSize:(int64_t)streamSize storageSize:(int64_t)storageSize;
- (void)uploadID:(NSString* _Nullable)uploadID;
- (void)uploadPartComplete:(long)index partSize:(int64_t)partSize partHash:(NSString* _Nullable)partHash;
@end

FOUNDATION_EXPORT id<Open_im_sdk_callbackOnFriendshipListenerSdk> _Nullable Open_im_sdk_callbackNewOnFriendshipListenerSdk(id<Open_im_sdk_callbackOnFriendshipListener> _Nullable listener);

@class Open_im_sdk_callbackBase;

@class Open_im_sdk_callbackOnAdvancedMsgListener;

@class Open_im_sdk_callbackOnBatchMsgListener;

@class Open_im_sdk_callbackOnClubListener;

@class Open_im_sdk_callbackOnConnListener;

@class Open_im_sdk_callbackOnConversationListener;

@class Open_im_sdk_callbackOnCustomBusinessListener;

@class Open_im_sdk_callbackOnFriendshipListener;

@class Open_im_sdk_callbackOnFriendshipListenerSdk;

@class Open_im_sdk_callbackOnGroupListener;

@class Open_im_sdk_callbackOnListenerForService;

@class Open_im_sdk_callbackOnMessageKvInfoListener;

@class Open_im_sdk_callbackOnSignalingListener;

@class Open_im_sdk_callbackOnUserListener;

@class Open_im_sdk_callbackSendMsgCallBack;

@class Open_im_sdk_callbackUploadFileCallback;

@interface Open_im_sdk_callbackBase : NSObject <goSeqRefInterface, Open_im_sdk_callbackBase> {
}
@property(strong, readonly) _Nonnull id _ref;

- (nonnull instancetype)initWithRef:(_Nonnull id)ref;
- (void)onError:(int32_t)errCode errMsg:(NSString* _Nullable)errMsg;
- (void)onSuccess:(NSString* _Nullable)data;
@end

@interface Open_im_sdk_callbackOnAdvancedMsgListener : NSObject <goSeqRefInterface, Open_im_sdk_callbackOnAdvancedMsgListener> {
}
@property(strong, readonly) _Nonnull id _ref;

- (nonnull instancetype)initWithRef:(_Nonnull id)ref;
- (void)onMsgDeleted:(NSString* _Nullable)message;
- (void)onNewRecvMessageRevoked:(NSString* _Nullable)messageRevoked;
- (void)onRecvC2CReadReceipt:(NSString* _Nullable)msgReceiptList;
- (void)onRecvGroupReadReceipt:(NSString* _Nullable)groupMsgReceiptList;
- (void)onRecvMessageExtensionsAdded:(NSString* _Nullable)msgID reactionExtensionList:(NSString* _Nullable)reactionExtensionList;
- (void)onRecvMessageExtensionsChanged:(NSString* _Nullable)msgID reactionExtensionList:(NSString* _Nullable)reactionExtensionList;
- (void)onRecvMessageExtensionsDeleted:(NSString* _Nullable)msgID reactionExtensionKeyList:(NSString* _Nullable)reactionExtensionKeyList;
- (void)onRecvNewMessage:(NSString* _Nullable)message;
- (void)onRecvOfflineNewMessage:(NSString* _Nullable)message;
- (void)onRecvRedPacketStatusChanged:(NSString* _Nullable)redPacketMsg;
- (void)onRecvSelfSendRedPacketSeqChanged:(NSString* _Nullable)message;
@end

@interface Open_im_sdk_callbackOnBatchMsgListener : NSObject <goSeqRefInterface, Open_im_sdk_callbackOnBatchMsgListener> {
}
@property(strong, readonly) _Nonnull id _ref;

- (nonnull instancetype)initWithRef:(_Nonnull id)ref;
- (void)onRecvNewMessages:(NSString* _Nullable)messageList;
- (void)onRecvOfflineNewMessages:(NSString* _Nullable)messageList;
@end

@interface Open_im_sdk_callbackOnClubListener : NSObject <goSeqRefInterface, Open_im_sdk_callbackOnClubListener> {
}
@property(strong, readonly) _Nonnull id _ref;

- (nonnull instancetype)initWithRef:(_Nonnull id)ref;
- (void)onJoinedServerAdded:(NSString* _Nullable)serverInfo;
- (void)onJoinedServerDeleted:(NSString* _Nullable)serverInfo;
- (void)onServerApplicationAccepted:(NSString* _Nullable)serverApplication;
- (void)onServerApplicationAdded:(NSString* _Nullable)serverApplication;
- (void)onServerApplicationDeleted:(NSString* _Nullable)serverApplication;
- (void)onServerApplicationRejected:(NSString* _Nullable)serverApplication;
- (void)onServerDismissed:(NSString* _Nullable)serverID;
- (void)onServerGroupDismissed:(NSString* _Nullable)groupInfo;
- (void)onServerInfoChanged:(NSString* _Nullable)serverInfo;
- (void)onServerMemberAdded:(NSString* _Nullable)serverMemberInfo;
- (void)onServerMemberDeleted:(NSString* _Nullable)serverMemberInfo;
- (void)onServerMemberInfoChanged:(NSString* _Nullable)serverMemberInfo;
- (void)onServerMemberKicked:(NSString* _Nullable)serverID;
@end

@interface Open_im_sdk_callbackOnConnListener : NSObject <goSeqRefInterface, Open_im_sdk_callbackOnConnListener> {
}
@property(strong, readonly) _Nonnull id _ref;

- (nonnull instancetype)initWithRef:(_Nonnull id)ref;
- (void)onConnectFailed:(int32_t)errCode errMsg:(NSString* _Nullable)errMsg;
- (void)onConnectSuccess;
- (void)onConnecting;
- (void)onKickedOffline;
- (void)onUserTokenExpired;
@end

@interface Open_im_sdk_callbackOnConversationListener : NSObject <goSeqRefInterface, Open_im_sdk_callbackOnConversationListener> {
}
@property(strong, readonly) _Nonnull id _ref;

- (nonnull instancetype)initWithRef:(_Nonnull id)ref;
- (void)onConversationChanged:(NSString* _Nullable)conversationList;
- (void)onNewConversation:(NSString* _Nullable)conversationList;
- (void)onServerUnreadMessageCountChanged:(NSString* _Nullable)serverID totalUnreadCount:(int32_t)totalUnreadCount;
/**
 * OnSyncServerProgress(progress int)
 */
- (void)onSyncServerFailed;
- (void)onSyncServerFinish;
- (void)onSyncServerStart;
- (void)onTotalUnreadMessageCountChanged:(int32_t)totalUnreadCount;
@end

@interface Open_im_sdk_callbackOnCustomBusinessListener : NSObject <goSeqRefInterface, Open_im_sdk_callbackOnCustomBusinessListener> {
}
@property(strong, readonly) _Nonnull id _ref;

- (nonnull instancetype)initWithRef:(_Nonnull id)ref;
- (void)onRecvCustomBusinessMessage:(NSString* _Nullable)businessMessage;
@end

@interface Open_im_sdk_callbackOnFriendshipListener : NSObject <goSeqRefInterface, Open_im_sdk_callbackOnFriendshipListener> {
}
@property(strong, readonly) _Nonnull id _ref;

- (nonnull instancetype)initWithRef:(_Nonnull id)ref;
- (void)onBlackAdded:(NSString* _Nullable)blackInfo;
- (void)onBlackDeleted:(NSString* _Nullable)blackInfo;
- (void)onFriendAdded:(NSString* _Nullable)friendInfo;
- (void)onFriendApplicationAccepted:(NSString* _Nullable)friendApplication;
- (void)onFriendApplicationAdded:(NSString* _Nullable)friendApplication;
- (void)onFriendApplicationDeleted:(NSString* _Nullable)friendApplication;
- (void)onFriendApplicationRejected:(NSString* _Nullable)friendApplication;
- (void)onFriendDeleted:(NSString* _Nullable)friendInfo;
- (void)onFriendInfoChanged:(NSString* _Nullable)friendInfo;
@end

@interface Open_im_sdk_callbackOnFriendshipListenerSdk : NSObject <goSeqRefInterface, Open_im_sdk_callbackOnFriendshipListenerSdk> {
}
@property(strong, readonly) _Nonnull id _ref;

- (nonnull instancetype)initWithRef:(_Nonnull id)ref;
// skipped method OnFriendshipListenerSdk.OnBlackAdded with unsupported parameter or return types

// skipped method OnFriendshipListenerSdk.OnBlackDeleted with unsupported parameter or return types

// skipped method OnFriendshipListenerSdk.OnFriendAdded with unsupported parameter or return types

// skipped method OnFriendshipListenerSdk.OnFriendApplicationAccepted with unsupported parameter or return types

// skipped method OnFriendshipListenerSdk.OnFriendApplicationAdded with unsupported parameter or return types

// skipped method OnFriendshipListenerSdk.OnFriendApplicationDeleted with unsupported parameter or return types

// skipped method OnFriendshipListenerSdk.OnFriendApplicationRejected with unsupported parameter or return types

// skipped method OnFriendshipListenerSdk.OnFriendDeleted with unsupported parameter or return types

// skipped method OnFriendshipListenerSdk.OnFriendInfoChanged with unsupported parameter or return types

@end

@interface Open_im_sdk_callbackOnGroupListener : NSObject <goSeqRefInterface, Open_im_sdk_callbackOnGroupListener> {
}
@property(strong, readonly) _Nonnull id _ref;

- (nonnull instancetype)initWithRef:(_Nonnull id)ref;
- (void)onGroupApplicationAccepted:(NSString* _Nullable)groupApplication;
- (void)onGroupApplicationAdded:(NSString* _Nullable)groupApplication;
- (void)onGroupApplicationDeleted:(NSString* _Nullable)groupApplication;
- (void)onGroupApplicationRejected:(NSString* _Nullable)groupApplication;
- (void)onGroupDismissed:(NSString* _Nullable)groupInfo;
- (void)onGroupInfoChanged:(NSString* _Nullable)groupInfo;
- (void)onGroupMemberAdded:(NSString* _Nullable)groupMemberInfo;
- (void)onGroupMemberDeleted:(NSString* _Nullable)groupMemberInfo;
- (void)onGroupMemberInfoChanged:(NSString* _Nullable)groupMemberInfo;
- (void)onJoinedGroupAdded:(NSString* _Nullable)groupInfo;
- (void)onJoinedGroupDeleted:(NSString* _Nullable)groupInfo;
@end

@interface Open_im_sdk_callbackOnListenerForService : NSObject <goSeqRefInterface, Open_im_sdk_callbackOnListenerForService> {
}
@property(strong, readonly) _Nonnull id _ref;

- (nonnull instancetype)initWithRef:(_Nonnull id)ref;
/**
 * 好友申请被同意
 */
- (void)onFriendApplicationAccepted:(NSString* _Nullable)groupApplication;
/**
 * 有人申请添加你为好友
 */
- (void)onFriendApplicationAdded:(NSString* _Nullable)friendApplication;
/**
 * 进群申请被同意
 */
- (void)onGroupApplicationAccepted:(NSString* _Nullable)groupApplication;
/**
 * 有人申请进群
 */
- (void)onGroupApplicationAdded:(NSString* _Nullable)groupApplication;
/**
 * 收到新消息
 */
- (void)onRecvNewMessage:(NSString* _Nullable)message;
@end

@interface Open_im_sdk_callbackOnMessageKvInfoListener : NSObject <goSeqRefInterface, Open_im_sdk_callbackOnMessageKvInfoListener> {
}
@property(strong, readonly) _Nonnull id _ref;

- (nonnull instancetype)initWithRef:(_Nonnull id)ref;
- (void)onMessageKvInfoChanged:(NSString* _Nullable)messageChangedList;
@end

@interface Open_im_sdk_callbackOnSignalingListener : NSObject <goSeqRefInterface, Open_im_sdk_callbackOnSignalingListener> {
}
@property(strong, readonly) _Nonnull id _ref;

- (nonnull instancetype)initWithRef:(_Nonnull id)ref;
- (void)onClosed:(NSString* _Nullable)closedCallback;
/**
 * OnInvitationTimeout(invitationTimeoutCallback string)
 */
- (void)onHangUp:(NSString* _Nullable)hangUpCallback;
- (void)onInvitationCancelled:(NSString* _Nullable)invitationCancelledCallback;
- (void)onInviteeAccepted:(NSString* _Nullable)inviteeAcceptedCallback;
- (void)onInviteeRejected:(NSString* _Nullable)inviteeRejectedCallback;
- (void)onJoined:(NSString* _Nullable)joinedCallback;
- (void)onMicphoneStatusChanged:(NSString* _Nullable)onMicphoneStatusChangedCallback;
- (void)onReceiveNewInvitation:(NSString* _Nullable)receiveNewInvitationCallback;
- (void)onSpeakStatusChanged:(NSString* _Nullable)onSpeakStatusUpdatedCallback;
@end

@interface Open_im_sdk_callbackOnUserListener : NSObject <goSeqRefInterface, Open_im_sdk_callbackOnUserListener> {
}
@property(strong, readonly) _Nonnull id _ref;

- (nonnull instancetype)initWithRef:(_Nonnull id)ref;
- (void)onSelfInfoUpdated:(NSString* _Nullable)userInfo;
- (void)onUserStatusChanged:(NSString* _Nullable)userOnlineStatus;
@end

@interface Open_im_sdk_callbackSendMsgCallBack : NSObject <goSeqRefInterface, Open_im_sdk_callbackSendMsgCallBack> {
}
@property(strong, readonly) _Nonnull id _ref;

- (nonnull instancetype)initWithRef:(_Nonnull id)ref;
- (void)onError:(int32_t)errCode errMsg:(NSString* _Nullable)errMsg;
- (void)onProgress:(long)progress;
- (void)onSuccess:(NSString* _Nullable)data;
@end

@interface Open_im_sdk_callbackUploadFileCallback : NSObject <goSeqRefInterface, Open_im_sdk_callbackUploadFileCallback> {
}
@property(strong, readonly) _Nonnull id _ref;

- (nonnull instancetype)initWithRef:(_Nonnull id)ref;
- (void)complete:(int64_t)size url:(NSString* _Nullable)url typ:(long)typ;
- (void)hashPartComplete:(NSString* _Nullable)partsHash fileHash:(NSString* _Nullable)fileHash;
- (void)hashPartProgress:(long)index size:(int64_t)size partHash:(NSString* _Nullable)partHash;
- (void)open:(int64_t)size;
- (void)partSize:(int64_t)partSize num:(long)num;
- (void)uploadComplete:(int64_t)fileSize streamSize:(int64_t)streamSize storageSize:(int64_t)storageSize;
- (void)uploadID:(NSString* _Nullable)uploadID;
- (void)uploadPartComplete:(long)index partSize:(int64_t)partSize partHash:(NSString* _Nullable)partHash;
@end

#endif
