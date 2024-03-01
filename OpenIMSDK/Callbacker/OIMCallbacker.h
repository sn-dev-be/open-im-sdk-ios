//
//  OIMCallbacker.h
//  OpenIMSDK
//
//  Created by x on 2022/2/11.
//

#import <Foundation/Foundation.h>
#import "MJExtension.h"

#import "OIMDefine.h"
#import "OIMUserInfo.h"
#import "OIMFullUserInfo.h"
#import "OIMFriendApplication.h"
#import "OIMGroupApplicationInfo.h"
#import "OIMGroupInfo.h"
#import "OIMGroupMemberInfo.h"
#import "OIMConversationInfo.h"
#import "OIMMessageInfo.h"
#import "OIMSearchParam.h"
#import "OIMSearchResultInfo.h"
#import "OIMSimpleResultInfo.h"
#import "OIMSimpleRequstInfo.h"
#import "OIMClubApplicationInfo.h"
#import "OIMSignalVoiceInfo.h"



@import OpenIMCore;

NS_ASSUME_NONNULL_BEGIN


typedef void (^OIMSimpleResultCallback)(OIMSimpleResultInfo * _Nullable result);
typedef void (^OIMSimpleResultsCallback)(NSArray <OIMSimpleResultInfo *> * _Nullable results);

typedef void (^OIMUserInfoCallback)(OIMUserInfo * _Nullable userInfo);
typedef void (^OIMUsersInfoCallback)(NSArray <OIMUserInfo *> * _Nullable usersInfo);
typedef void (^OIMUsersCallback)(NSArray <OIMFullUserInfo *> * _Nullable userInfos);
typedef void (^OIMFullUserInfoCallback)(OIMFullUserInfo * _Nullable userInfo);
typedef void (^OIMFullUsersInfoCallback)(NSArray <OIMFullUserInfo *> * _Nullable userInfos);
typedef void (^OIMBlacksInfoCallback)(NSArray <OIMBlackInfo *> * _Nullable blackInfos);
typedef void (^OIMUserStatusInfoCallback)(OIMUserStatusInfo * _Nullable statusInfo);
typedef void (^OIMUserStatusInfosCallback)(NSArray <OIMUserStatusInfo *> * _Nullable statusInfos);

typedef void (^OIMFriendApplicationCallback)(OIMFriendApplication * _Nullable friendApplication);
typedef void (^OIMFriendApplicationsCallback)(NSArray <OIMFriendApplication *> * _Nullable friendApplications);

typedef void (^OIMFriendInfoCallback)(OIMFriendInfo * _Nullable friendInfo);
typedef void (^OIMFriendsInfoCallback)(NSArray<OIMFriendInfo *> * _Nullable friendInfo);
typedef void (^OIMBlackInfoCallback)(OIMBlackInfo * _Nullable blackInfo);
typedef void (^OIMBlacksInfoCallback)(NSArray<OIMBlackInfo *> * _Nullable blackInfo);
typedef void (^OIMSearchUsersInfoCallback)(NSArray<OIMSearchFriendsInfo *> * _Nullable usersInfo);

typedef void (^OIMGroupApplicationCallback)(OIMGroupApplicationInfo * _Nullable groupApplication);
typedef void (^OIMGroupsApplicationCallback)(NSArray <OIMGroupApplicationInfo *> * _Nullable groupsInfo);
typedef void (^OIMGroupInfoCallback)(OIMGroupInfo * _Nullable groupInfo);
typedef void (^OIMGroupsInfoCallback)(NSArray <OIMGroupInfo *> * _Nullable groupsInfo);
typedef void (^OIMGroupMemberInfoCallback)(OIMGroupMemberInfo * _Nullable groupMemberInfo);
typedef void (^OIMGroupMembersInfoCallback)(NSArray <OIMGroupMemberInfo *> * _Nullable groupMembersInfo);

typedef void (^OIMConversationsInfoCallback)(NSArray <OIMConversationInfo *> * _Nullable conversations);
typedef void (^OIMConversationInfoCallback)(OIMConversationInfo * _Nullable conversation);
typedef void (^OIMConversationNotDisturbInfoCallback)(NSArray <OIMConversationNotDisturbInfo *> * _Nullable conversations);

typedef void (^OIMMessageInfoCallback)(OIMMessageInfo * _Nullable message);
typedef void (^OIMMessagesInfoCallback)(NSArray <OIMMessageInfo *> * _Nullable messages);
typedef void (^OIMMessageSearchCallback)(OIMSearchResultInfo * _Nullable result);

typedef void (^OIMReceiptCallback)(NSArray <OIMReceiptInfo *> * _Nullable msgReceiptList);
typedef void (^OIMRevokedCallback)(OIMMessageRevokedInfo * _Nullable msgRovoked);
typedef void (^OIMRedPacketCallback)(OIMMessageRedPacketInfo *_Nullable msgRedPacket);

typedef void(^OIMSignalVoiceInfoCallback)(OIMSignalVoiceInfo *_Nullable signalVoiceInfo);
typedef void(^OIMSignalVoiceMichoneCallback)(OIMSignalVoiceMicphoneStatusInfo *_Nullable signalVoiceMicphoneStatusInfo);
typedef void(^OIMSignalVoiceSpeakCallback)(OIMSignalVoiceSpeakStatusInfo *_Nullable signalVoiceSpeakStatusInfo);


typedef void(^OIMSignalVoiceInvitationCallback)(OIMSignalVoiceInfo *_Nullable voiceInfo);
typedef void(^OIMSignalVoiceAcceptedCallback)(OIMSignalVoiceInfo *_Nullable voiceInfo);
typedef void(^OIMSignalVoiceRejectedCallback)(OIMSignalVoiceInfo *_Nullable voiceInfo);
typedef void(^OIMSignalVoiceJoinedCallback)(OIMSignalVoiceInfo *_Nullable voiceInfo);
typedef void(^OIMSignalVoiceCancelledCallback)(OIMSignalVoiceInfo *_Nullable );
typedef void(^OIMSignalVoiceHangUpCallback)(OIMSignalVoiceInfo *_Nullable voiceInfo);
typedef void(^OIMSignalVoiceClosedCallback)(OIMSignalVoiceInfo *_Nullable voiceInfo);
typedef void(^OIMSignalVoiceMicphoneCallback)(OIMSignalVoiceMicphoneStatusInfo *_Nullable micphoneInfo);
typedef void(^OIMSignalVoiceSpeakCallback)(OIMSignalVoiceSpeakStatusInfo *_Nullable speakInfo);


//typedef void(^OIMClubAcceptedCallback)(OIMClubApplicationInfo *_Nullable clubInfo);
//typedef void(^OIMClubAddedCallback)(OIMClubApplicationInfo *_Nullable clubInfo);
//typedef void(^OIMClubRejectedCallback)(OIMClubApplicationInfo *_Nullable clubInfo);
typedef void(^OIMClubDismissedCallback)(NSString *_Nullable clubID);
typedef void(^OIMClubMemberKickedCallback)(NSString *_Nullable clubID);

typedef void (^OIMGetAdvancedHistoryMessageListCallback)(OIMGetAdvancedHistoryMessageListInfo * _Nullable result);

/// IMSDK Core Callbacks
/// ConnectListener - SDK 连接状态监听器，当连接状态变化时回调。
@protocol OIMSDKListener <NSObject>
@optional
/**
 *  SDK is connecting to the server.
 */
- (void)onConnecting;

/**
 * SDK has successfully connected to the server.
 */
- (void)onConnectSuccess;

/**
 * SDK connection to the server has failed.
 */
- (void)onConnectFailed:(NSInteger)code err:(NSString *)err;

/**
 * The current user has been kicked offline. You can show a UI notification to the user.
 */
- (void)onKickedOffline;

/**
 * Token has expired while online: You need to generate a new UserToken and re-login.
 */
- (void)onUserTokenExpired;

@end

/// User Status Callbacks
@protocol OIMUserListener <NSObject> // UserListener
@optional
/**
 * User information has been updated.
 */
- (void)onSelfInfoUpdated:(OIMUserInfo *)info;

/**
 * User status has changed.
 */
- (void)onUserStatusChanged:(OIMUserStatusInfo *)info;

@end

/// Profile and Relationship Callbacks
/// RelationshipListener - 好友及黑名单关系链监听器，当好友及黑名单信息改变时回调。
@protocol OIMFriendshipListener <NSObject>
@optional

/**
 * New friend application notification.
 */
- (void)onFriendApplicationAdded:(OIMFriendApplication *)application;

/**
 * Friend application has been rejected.
 */
- (void)onFriendApplicationRejected:(OIMFriendApplication *)application;

/**
 * Friend application has been accepted.
 */
- (void)onFriendApplicationAccepted:(OIMFriendApplication *)application;

/**
 * Friend application has been deleted.
 */
- (void)onFriendApplicationDeleted:(OIMFriendApplication *)application;

/**
 * New friend notification.
 */
- (void)onFriendAdded:(OIMFriendInfo *)info;

/**
 * Friend deletion notification.
 */
- (void)onFriendDeleted:(OIMFriendInfo *)info;

/**
 * Friend profile change notification.
 */
- (void)onFriendInfoChanged:(OIMFriendInfo *)info;

/**
 * New blacklist notification.
 */
- (void)onBlackAdded:(OIMBlackInfo *)info;

/**
 * Blacklist deletion notification.
 */
- (void)onBlackDeleted:(OIMBlackInfo *)info;

@end


/// IMSDK Group Event Callbacks
/// GroupListener - 群组监听器，当群组及群成员信息改变时回调。
@protocol OIMGroupListener <NSObject>
@optional

/**
 *  New member joined the group.
 */
- (void)onGroupMemberAdded:(OIMGroupMemberInfo *)memberInfo;

/**
 *  Member left the group.
 */
- (void)onGroupMemberDeleted:(OIMGroupMemberInfo *)memberInfo;

/**
 *  Information of a member in the group has changed.
 */
- (void)onGroupMemberInfoChanged:(OIMGroupMemberInfo *)changeInfo;

/**
 *  Callback for group addition.
 */
- (void)onJoinedGroupAdded:(OIMGroupInfo *)groupInfo;

/**
 *  Callback for group removal.
 */
- (void)onJoinedGroupDeleted:(OIMGroupInfo *)groupInfo;

/**
 *  Information of a group that the user has joined has been modified.
 */
- (void)onGroupInfoChanged:(OIMGroupInfo *)changeInfo;

/**
 *  Group application has been accepted.
 */
- (void)onGroupApplicationAccepted:(OIMGroupApplicationInfo *)groupApplication;

/**
 *  Someone has applied to join the group.
 */
- (void)onGroupApplicationAdded:(OIMGroupApplicationInfo *)groupApplication;

/**
 *  Group application has been deleted.
 */
- (void)onGroupApplicationDeleted:(OIMGroupApplicationInfo *)groupApplication;

/**
 *  Group application has been rejected.
 */
- (void)onGroupApplicationRejected:(OIMGroupApplicationInfo *)groupApplication;

/**
 *  Group has been disbanded.
 */
- (void)onGroupDismissed:(OIMGroupInfo *)changeInfo;

@end


/// Conversation Event Callbacks
/// ConversationListener - 会话监听器，当会话变化及会话同步状态改变时回调。
@protocol OIMConversationListener <NSObject>
@optional

/**
 * Synchronization with the server has started for conversations.
 */
- (void)onSyncServerStart;

/**
 * Synchronization with the server for conversations has completed.
 */
- (void)onSyncServerFinish;

/**
 * Synchronization with the server for conversations has failed.
 */
- (void)onSyncServerFailed;

/**
 * New conversations have been added.
 */
- (void)onNewConversation:(NSArray <OIMConversationInfo *> *)conversations;

/**
 * Key information of certain conversations has changed.
 */
- (void)onConversationChanged:(NSArray <OIMConversationInfo *> *)conversations;

/**
 * Notification of changes in the total unread message count of conversations.
 */
- (void)onTotalUnreadMessageCountChanged:(NSInteger)totalUnreadCount;

- (void)onServerUnreadMessageCountChanged:(NSString* _Nullable)serverID totalUnreadCount:(NSInteger)totalUnreadCount;

@end

/// Advanced Message Listener
/// AdvancedMsgListener - 消息监听器，当收到新消息、已读回执及撤回消息时回调
@protocol OIMAdvancedMsgListener <NSObject>
@optional

/**
 * Received a new message.
 */
- (void)onRecvNewMessage:(OIMMessageInfo *)msg;

/**
 * Read receipt for one-on-one messages.
 */
- (void)onRecvC2CReadReceipt:(NSArray<OIMReceiptInfo *> *)receiptList;

/**
 * Read receipt for group chat messages.
 */
- (void)onRecvGroupReadReceipt:(NSArray<OIMReceiptInfo *> *)groupMsgReceiptList;

/**
 * Received a message retraction.
 */
- (void)onRecvMessageRevoked:(OIMMessageRevokedInfo *)messageRevoked;

- (void)onMsgDeleted:(OIMMessageInfo *)message;

// 修改红包状态
- (void)onRecvMessageRedPacketed:(OIMMessageRedPacketInfo * _Nullable)redPacketInfo;

// 发送红包之后的回调
- (void)onRecvSelfSendRedPacketSeqChanged:(OIMMessageInfo *)message;

@end

// BatchMsgListener - 批量消息监听器，当收到新消息时回调。设置后AdvancedMsgListener中的onRecvNewMessage和onRecvOfflineNewMessage回调不再触发。
@protocol OIMBatchMsgListener <NSObject>



@end

/// Custom Business Callbacks for IM
@protocol OIMCustomBusinessListener <NSObject>
@optional

- (void)onRecvCustomBusinessMessage:(NSDictionary <NSString *, id>* _Nullable)businessMessage;

@end

// ------------- 新增监听 -------------

@protocol OIMSignalingListener <NSObject>

@optional
- (void)onReceiveNewInvitation:(OIMSignalVoiceInfo *)info; // 邀请信令
- (void)onInviteeAccepted:(OIMSignalVoiceInfo *)info; // 邀请接受信令
- (void)onInviteeRejected:(OIMSignalVoiceInfo *)info; // 邀请拒绝信令
- (void)onJoined:(OIMSignalVoiceInfo *)info; // 加入房间信令
- (void)onInvitationCancelled:(OIMSignalVoiceInfo *)info; // 邀请取消信令
- (void)onHangUp:(OIMSignalVoiceInfo *)info; // 挂断信令
- (void)onClosed:(OIMSignalVoiceInfo *)info; // 关闭信令
- (void)onMicphoneStatusChanged:(OIMSignalVoiceMicphoneStatusInfo *)info; // 麦克风状态改变信令
- (void)onSpeakStatusChanged:(OIMSignalVoiceSpeakStatusInfo *)info; // 说话状态通知信令

@end

// OIMClubListener - 群组监听器，当群组及群成员信息改变时回调。
@protocol OIMClubListener <NSObject>


//onServerMemberAdded:          有新成员加入部落
//onServerMemberDeleted         有成员离开部落
//onServerMemberInfoChanged     某成员信息发生变更
//onJoinedServerAdded           部落成员变更
//onJoinedServerDeleted         部落成员变更
//onServerInfoChanged           部落信息变更
//onServerApplicationAccepted   部落申请被接受通知
//onServerApplicationAdded      新的部落申请通知
//onServerApplicationDeleted    部落申请删除通知
//onServerApplicationRejected   部落申请被拒绝通知
//onServerDismissed             部落解散通知（可用）
//onServerMemberKicked          部落成员被踢出通知（可用）

//// 入部落申请被同意时，申请发起者以及该部落的部落主、管理员会收到此回调。
//- (void)onClubApplicationAccepted:(OIMClubApplicationInfo *)groupApplication;
//// 用户发起入部落申请后，如进部落需要审批， 则申请发起者以及该部落的部落主、管理员会收到此回调。
//- (void)onClubApplicationAdded:(OIMClubApplicationInfo *)groupApplication;
//// 入部落申请被拒绝时，申请发起者以及该部落的部落主、管理员会收到此回调。
//- (void)onClubApplicationRejected:(OIMClubApplicationInfo *)groupApplication;
//// 入部落申请被拒绝时，申请发起者以及该部落的部落主、管理员会收到此回调。
//- (void)onClubApplicationRejected:(OIMClubApplicationInfo *)groupApplication;
// 部落被解散时，该部落所有成员会收到此回调。
- (void)onServerDismissed:(NString)serverID;
// 被剔除部落时，被踢出成员会收到此回调。
- (void)onServerMemberKicked:(NString)serverID;

@end




@interface OIMCallbacker : NSObject
<
Open_im_sdk_callbackOnConnListener,
Open_im_sdk_callbackOnAdvancedMsgListener,
Open_im_sdk_callbackOnConversationListener,
Open_im_sdk_callbackOnFriendshipListener,
Open_im_sdk_callbackOnGroupListener,
Open_im_sdk_callbackOnUserListener,
Open_im_sdk_callbackOnCustomBusinessListener,
Open_im_sdk_callbackOnSignalingListener,
Open_im_sdk_callbackOnClubListener
//open_im_adk
>

+ (instancetype)callbacker;

- (void)setListener;

/// Connection Listener
/// Set during InitSDK, called when the IM connection status changes.
@property (nonatomic, nullable, copy) OIMVoidCallback connecting;
@property (nonatomic, nullable, copy) OIMFailureCallback connectFailure;
@property (nonatomic, nullable, copy) OIMVoidCallback connectSuccess;
@property (nonatomic, nullable, copy) OIMVoidCallback kickedOffline;
@property (nonatomic, nullable, copy) OIMVoidCallback userTokenExpired;

/**
 * Add IM SDK listener.
 */
- (void)addIMSDKListener:(id<OIMSDKListener>)listener;

/**
 * Remove IM SDK listener.
 */
- (void)removeIMSDKListener:(id<OIMSDKListener>)listener;

/// User Listener
/// Set after a successful InitSDK and before Login, called when the personal profile of the logged-in user changes.
@property (nonatomic, nullable, copy) OIMUserInfoCallback onSelfInfoUpdated;
@property (nonatomic, nullable, copy) OIMUserStatusInfoCallback onUserStatusChanged;

/**
 * Add User listener.
 */
- (void)addUserListener:(id<OIMUserListener>)listener NS_SWIFT_NAME(addUserListener(listener:));

/**
 * Remove User listener.
 */
- (void)removeUserListener:(id<OIMUserListener>)listener NS_SWIFT_NAME(removeUserListener(listener:));

/// Friendship Listener
/// Set after a successful InitSDK and before Login, called when friend-related information changes.
@property (nonatomic, nullable, copy) OIMFriendApplicationCallback onFriendApplicationAdded;
@property (nonatomic, nullable, copy) OIMFriendApplicationCallback onFriendApplicationDeleted;
@property (nonatomic, nullable, copy) OIMFriendApplicationCallback onFriendApplicationAccepted;
@property (nonatomic, nullable, copy) OIMFriendApplicationCallback onFriendApplicationRejected;
@property (nonatomic, nullable, copy) OIMFriendInfoCallback onFriendAdded;
@property (nonatomic, nullable, copy) OIMFriendInfoCallback onFriendDeleted;
@property (nonatomic, nullable, copy) OIMFriendInfoCallback onFriendInfoChanged;
@property (nonatomic, nullable, copy) OIMBlackInfoCallback onBlackAdded;
@property (nonatomic, nullable, copy) OIMBlackInfoCallback onBlackDeleted;

/**
 * Add Friendship listener.
 */
- (void)addFriendListener:(id<OIMFriendshipListener>)listener NS_SWIFT_NAME(addFriendListener(listener:));

/**
 * Remove Friendship listener.
 */
- (void)removeFriendListener:(id<OIMFriendshipListener>)listener NS_SWIFT_NAME(removeFriendListener(listener:));

/// Group Listener
/// Set after a successful InitSDK and before Login, called when group-related information changes.
@property (nonatomic, nullable, copy) OIMGroupInfoCallback onGroupInfoChanged;
@property (nonatomic, nullable, copy) OIMGroupInfoCallback onJoinedGroupAdded;
@property (nonatomic, nullable, copy) OIMGroupInfoCallback onJoinedGroupDeleted;
@property (nonatomic, nullable, copy) OIMGroupMemberInfoCallback onGroupMemberAdded;
@property (nonatomic, nullable, copy) OIMGroupMemberInfoCallback onGroupMemberDeleted;
@property (nonatomic, nullable, copy) OIMGroupMemberInfoCallback onGroupMemberInfoChanged;
@property (nonatomic, nullable, copy) OIMGroupApplicationCallback onGroupApplicationAdded;
@property (nonatomic, nullable, copy) OIMGroupApplicationCallback onGroupApplicationDeleted;
@property (nonatomic, nullable, copy) OIMGroupApplicationCallback onGroupApplicationAccepted;
@property (nonatomic, nullable, copy) OIMGroupApplicationCallback onGroupApplicationRejected;
@property (nonatomic, nullable, copy) OIMGroupInfoCallback onGroupDismissed;

/**
 * Set group listener.
 */
- (void)addGroupListener:(id<OIMGroupListener>)listener NS_SWIFT_NAME(addGroupListener(listener:));

/**
 * Remove group listener.
 */
- (void)removeGroupListener:(id<OIMGroupListener>)listener NS_SWIFT_NAME(removeGroupListener(listener:));

/// Conversation Listener
/// Set after a successful InitSDK and before Login, called when conversation-related information changes.
@property (nonatomic, nullable, copy) OIMVoidCallback syncServerStart;
@property (nonatomic, nullable, copy) OIMVoidCallback syncServerFinish;
@property (nonatomic, nullable, copy) OIMVoidCallback syncServerFailed;
@property (nonatomic, nullable, copy) OIMConversationsInfoCallback onNewConversation;
@property (nonatomic, nullable, copy) OIMConversationsInfoCallback onConversationChanged;
@property (nonatomic, nullable, copy) OIMNumberCallback onTotalUnreadMessageCountChanged;
@property (nonatomic, nullable, copy) OIMNumberTupleCallback onServerUnreadMessageCountChanged;

/**
 * Add conversation listener.
 */
- (void)addConversationListener:(id<OIMConversationListener>)listener NS_SWIFT_NAME(addConversationListener(listener:));

/**
 * Remove conversation listener.
 */
- (void)removeConversationListener:(id<OIMConversationListener>)listener NS_SWIFT_NAME(removeConversationListener(listener:));

/// Message Listener
/// Set after a successful InitSDK and before Login, called when message-related information changes.
@property (nonatomic, nullable, copy) OIMMessageInfoCallback onRecvNewMessage;
@property (nonatomic, nullable, copy) OIMReceiptCallback onRecvC2CReadReceipt;
@property (nonatomic, nullable, copy) OIMReceiptCallback onRecvGroupReadReceipt;
@property (nonatomic, nullable, copy) OIMRevokedCallback onRecvMessageRevoked;
@property (nonatomic, nullable, copy) OIMMessageInfoCallback onMessageDeleted;
@property (nonatomic, nullable, copy) OIMRedPacketCallback onRecvMessageRedPacketed; // 红包回调
/**
 * Add advanced message event listener.
 */
- (void)addAdvancedMsgListener:(id<OIMAdvancedMsgListener>)listener NS_SWIFT_NAME(addAdvancedMsgListener(listener:));

/**
 * Remove advanced message event listener.
 */
- (void)removeAdvancedMsgListener:(id<OIMAdvancedMsgListener>)listener NS_SWIFT_NAME(removeAdvancedMsgListener(listener:));

/// Custom Business Message Listener
@property (nonatomic, nullable, copy) OIMObjectCallback onRecvCustomBusinessMessage;

/**
 * Add IM listener for custom business events.
 */
- (void)addCustomBusinessListener:(id<OIMCustomBusinessListener>)listener NS_SWIFT_NAME(addCustomBusinessListener(listener:));

/**
 * Remove IM listener for custom business events.
 */
- (void)removeCustomBusinessListener:(id<OIMCustomBusinessListener>)listener NS_SWIFT_NAME(removeCustomBusinessListener(listener:));

@property (nonatomic, nullable, copy) OIMSignalVoiceInvitationCallback onVoiceInvitation;   // 邀请通话
@property (nonatomic, nullable, copy) OIMSignalVoiceAcceptedCallback onVoiceAccepted;       // 接受通话
@property (nonatomic, nullable, copy) OIMSignalVoiceRejectedCallback onVoiceRejected;       // 拒绝通话
@property (nonatomic, nullable, copy) OIMSignalVoiceJoinedCallback onVoiceJoined;           // 加入通话
@property (nonatomic, nullable, copy) OIMSignalVoiceCancelledCallback onVoiceCancelled;     // 取消邀请
@property (nonatomic, nullable, copy) OIMSignalVoiceHangUpCallback onVoiceHangUp;           // 挂断通话
@property (nonatomic, nullable, copy) OIMSignalVoiceClosedCallback onVoiceClosed;           // 关闭语音房 - 未使用
@property (nonatomic, nullable, copy) OIMSignalVoiceMicphoneCallback onVoiceMicphone;       // 更新麦克风状态
@property (nonatomic, nullable, copy) OIMSignalVoiceSpeakCallback onVoiceSpeak;             // 更新说话状态

- (void)addSignalingListener:(id<OIMSignalingListener>)listener NS_SWIFT_NAME(addSignalingListener(listener:));

- (void)removeSignalingListener:(id<OIMSignalingListener>)listener NS_SWIFT_NAME(removeSignalingListener(listener:));



//typedef void(^OIMSignalVoiceInvitationCallback)(OIMSignalVoiceInfo *)info;
//typedef void(^OIMSignalVoiceAcceptedCallback)(OIMSignalVoiceInfo *)info;
//typedef void(^OIMSignalVoiceRejectedCallback)(OIMSignalVoiceInfo *)info;
//typedef void(^OIMSignalVoiceJoinedCallback)(OIMSignalVoiceInfo *)info;
//typedef void(^OIMSignalVoiceCancelledCallback)(OIMSignalVoiceInfo *)info;
//typedef void(^OIMSignalVoiceHangUpCallback)(OIMSignalVoiceInfo *)info;
//typedef void(^OIMSignalVoiceClosedCallback)(OIMSignalVoiceInfo *)info;
//typedef void(^OIMSignalVoiceMicphoneCallback)(OIMSignalVoiceMicphoneStatusInfo *)info;
//typedef void(^OIMSignalVoiceSpeakCallback)(OIMSignalVoiceSpeakStatusInfo *)info;


@property (nonatomic, nullable, copy) OIMClubDismissedCallback onClubDismissed;   // 部落解散通知
@property (nonatomic, nullable, copy) OIMClubMemberKickedCallback onClubMemberKicked;   // 部落成员被踢出通知

- (void)addClubListener:(id<OIMClubListener>)listener NS_SWIFT_NAME(addClubListener(listener:));

- (void)removeClubListener:(id<OIMClubListener>)listener NS_SWIFT_NAME(removeClubListener(listener:));



@end

NS_ASSUME_NONNULL_END
