//
//  IMDefine.h
//  OpenIMSDK
//
//  Created by x on 2022/2/14.
//

#ifndef IMDefine_h
#define IMDefine_h

typedef NS_ENUM(NSInteger, OIMPlatform) {
    iPhone = 1, // iPhone
    android = 2,
    windows = 3,
    macOS = 4,
    web = 5,
    miniWeb = 6,
    linux = 7,
    androidPad = 8,
    iPad = 9,   // iPad
};

typedef void (^OIMVoidCallback)(void);
typedef void (^OIMSuccessCallback)(NSString * _Nullable data);
typedef void (^OIMFailureCallback)(NSInteger code, NSString * _Nullable msg);
typedef void (^OIMNumberCallback)(NSInteger number);
typedef void (^OIMNumberCallback)(NSInteger number);
typedef void (^OIMBoolCallback)(BOOL result);
typedef void (^OIMStringCallback)(NSString * _Nullable item);
typedef void (^OIMStringArrayCallback)(NSString * _Nullable value1, NSArray<NSString *> * _Nullable value2);
typedef void (^OIMObjectCallback)(NSDictionary * _Nullable item);
typedef void (^OIMNumberTupleCallback)(NSString * _Nullable kindID, NSInteger number);


/*
 * Message Types
 */
typedef NS_ENUM(NSInteger, OIMMessageContentType) {
    OIMMessageContentTypeText = 101,              /// Text message
    OIMMessageContentTypeImage = 102,             /// Image message
    OIMMessageContentTypeAudio = 103,             /// Audio message
    OIMMessageContentTypeVideo = 104,             /// Video message
    OIMMessageContentTypeFile = 105,              /// File message
    OIMMessageContentTypeAt = 106,                /// @ message
    OIMMessageContentTypeMerge = 107,             /// Merged message
    OIMMessageContentTypeCard = 108,              /// Card message
    OIMMessageContentTypeLocation = 109,          /// Location message
    OIMMessageContentTypeCustom = 110,            /// Custom message
    OIMMessageContentTypeTyping = 113,            /// Typing message
    OIMMessageContentTypeQuote = 114,             /// Quoted message
    OIMMessageContentTypeFace = 115,              /// Animated GIF message
    OIMMessageContentTypeAdvancedText = 117,      /// Advanced message
    OIMMessageContentTypeCustomMsgNotTriggerConversation = 119,  /// Backend API-specific
    OIMMessageContentTypeCustomMsgOnlineOnly = 120,            /// Backend API-specific
    /// The following are notification message enums
    OIMMessageContentTypeFriendAppApproved = 1201,          /// Friend request approved notification
    OIMMessageContentTypeFriendAppRejected = 1202,          /// Friend request rejected notification
    OIMMessageContentTypeFriendApplication = 1203,          /// Friend request notification
    OIMMessageContentTypeFriendAdded = 1204,                /// Friend added notification
    OIMMessageContentTypeFriendDeleted = 1205,              /// Friend deleted notification
    OIMMessageContentTypeFriendRemarkSet = 1206,            /// Friend remark set notification
    OIMMessageContentTypeBlackAdded = 1207,                 /// Added to blacklist notification
    OIMMessageContentTypeBlackDeleted = 1208,               /// Removed from blacklist notification
    OIMMessageContentTypeConversationOptChange = 1300,      /// Conversation notification settings
    OIMMessageContentTypeUserInfoUpdated = 1303,            /// User info updated notification
    OIMMessageContentTypeOANotification = 1400,             /// OA notification
    OIMMessageContentTypeGroupCreated = 1501,               /// Group created notification
    OIMMessageContentTypeGroupInfoSet = 1502,               /// Group info updated notification
    OIMMessageContentTypeJoinGroupApplication = 1503,       /// Join group application notification
    OIMMessageContentTypeMemberQuit = 1504,                 /// Member quit group notification
    OIMMessageContentTypeGroupAppAccepted = 1505,           /// Join group application accepted notification
    OIMMessageContentTypeGroupAppRejected = 1506,           /// Join group application rejected notification
    OIMMessageContentTypeGroupOwnerTransferred = 1507,      /// Group owner transferred notification
    OIMMessageContentTypeMemberKicked = 1508,               /// Member kicked from group notification
    OIMMessageContentTypeMemberInvited = 1509,              /// Member invited to group notification
    OIMMessageContentTypeMemberEnter = 1510,                /// Member entered group notification
    OIMMessageContentTypeDismissGroup = 1511,               /// Group dismissed notification
    OIMMessageContentTypeGroupMemberMutedNotification = 1512,
    OIMMessageContentTypeGroupMemberCancelMutedNotification = 1513,
    OIMMessageContentTypeGroupMutedNotification = 1514,
    OIMMessageContentTypeGroupCancelMutedNotification = 1515,
    OIMMessageContentTypeGroupMemberInfoSetNotification = 1516,
    OIMMessageContentTypeGroupMemberSetToAdminNotification = 1517,
    OIMMessageContentTypeGroupMemberSetToOrdinaryUserNotification = 1518,
    OIMMessageContentTypeGroupAnnouncement = 1519,          /// Group announcement
    OIMMessageContentTypeGroupSetNameNotification = 1520,   /// Group name updated
    OIMMessageContentTypeIsPrivateMessage = 1701,           /// Burn after reading notification
    OIMMessageContentTypeBusiness = 2001,                   /// Business notification
    OIMMessageContentTypeRevoke = 2101,                     /// Message revoked
    OIMMessageContentTypeHasReadReceipt = 2150,             /// Read receipt for one-to-one chat
    OIMMessageContentTypeGroupHasReadReceipt = 2155,        /// Group read receipt
    ///
    OIMMessageContentTypeTransferMessage    =     123,           //转账消息
    OIMMessageContentTypeRedPacketMessage    =     124,           //红包消息
    OIMMessageContentTypeRedPacketHasCollectedNotification    =     2401,           //红包已领完通知
    OIMMessageContentTypeRedPacketHasExpiredNotification    =     2402,           //红包已过期通知
    OIMMessageContentTypeRedPacketHasReceiveNotification    =     2403,           //用户领取了红包通知
    OIMMessageContentTypeInviteVoiceCallNotification    =     1602,           //邀请语音通话通知
    OIMMessageContentTypeGroupAudioCardMessage    =     201,           //群语音卡片消息
    OIMMessageContentTypeAcceptVoiceCallNotification    =     1603,           //接受语音通话通知
    OIMMessageContentTypeRejectVoiceCallNotification    =     1604,           //拒绝语音通话通知
    OIMMessageContentTypeVoiceCallChatMessage    =     1612,           //拒绝语音通话单聊消息
    OIMMessageContentTypeJoinVoiceCallNotification    =     1605,           //加入语音通话通知
    OIMMessageContentTypeGroupVoiceJoinMessage    =     1613,           //群语音加入消息
    OIMMessageContentTypeCancelVoiceCallNotification    =     1606,           //取消语音通话通知
    OIMMessageContentTypeCancelVoiceCallChatMessage    =     1614,           //取消语音通话单聊消息
    OIMMessageContentTypeHangUpVoiceCallNotification    =     1607,           //挂掉语音通话通知
    OIMMessageContentTypeCloseVoiceCallChatMessage    =     1615,           //关闭语音通话单聊消息
    OIMMessageContentTypeCloseVoiceCallChatNotification    =     1609,           //关闭语音通话通知
    OIMMessageContentTypeMicrophoneStatusChangeNotification    =     1608,           //麦克风状态改变通知
    OIMMessageContentTypeSpeekStatusChangedNotification    =     1610,           //说话状态改变通知
//    OIMMessageContentTypeCleanRegularlyNotification = 1653,                 // 定时清理开关通知
    OIMMessageContentTypeTransferSuccessNotification    =     2002,           //转账成功通知
    OIMMessageContentTypeTransferFailedNotification    =     2003,           //转账失败通知
    OIMMessageContentTypeRechargeSuccessNotification    =     2004,           //充值成功通知
    OIMMessageContentTypeRechargeFailedNotification    =     2005,           //充值失败通知
    OIMMessageContentTypeWithdrawalSuccessNotification    =     2006,           //提现成功通知
    OIMMessageContentTypeWithdrawalFailedNotification  =     2007,           //提现失败通知
    OIMMessageContentTypeRedPacketTimeoutNotification    =     2008,           //红包超时通知
    OIMMessageContentTypeReceiveTransferNotification    =     2009,           //收到转账通知
    OIMMessageContentTypeUnbindWalletNotification    =     2010,           // 钱包绑定解除通知
    OIMMessageContentTypeJoinedClubNotification     = 1803,                 // 加入部落通知
    OIMMessageContentTypeJoinedAcceptNotification   = 1805,                 // 加入部落接受通知
    OIMMessageContentTypeJoinedRefuseNotification   = 1806,                 // 加入部落拒绝通知
};

/*
 * Message Status
 */
typedef NS_ENUM(NSInteger, OIMMessageStatus) {
    OIMMessageStatusUndefine = 0,   /// Undefined
    OIMMessageStatusSending = 1,    /// Sending
    OIMMessageStatusSendSuccess,    /// Send success
    OIMMessageStatusSendFailure,    /// Send failure
    OIMMessageStatusRevoke          /// Revoked (client does not need to be concerned)
};

/*
 * Conversation Types
 */
typedef NS_ENUM(NSInteger, OIMConversationType) {
    OIMConversationTypeUndefine = 0,
    OIMConversationTypeC2C,                 /// One-to-one chat
    OIMConversationTypeGroup,               /// Group chat
    OIMConversationTypeSuperGroup = 3,      /// Super group
    OIMConversationTypeNotification = 4,    /// Notification
    OIMConversationTypeRoom         = 5     /// Club Room
};

/*
 * Message Level
 */
typedef NS_ENUM(NSInteger, OIMMessageLevel) {
    OIMMessageLevelUser = 100,  /// User
    OIMMessageLevelSystem = 200 /// System
};

/*
 * Message Receiving Options
 */
typedef NS_ENUM(NSInteger, OIMReceiveMessageOpt) {
    OIMReceiveMessageOptReceive = 0,    /// Receive messages online and receive APNs notifications when offline
    OIMReceiveMessageOptNotReceive = 1, /// Do not receive messages and no push notifications when offline
    OIMReceiveMessageOptNotNotify = 2,  /// Receive messages online but no push notifications when offline
};

typedef NS_ENUM(NSInteger, OIMGroupMemberFilter) {
    OIMGroupMemberFilterAll = 0,               /// All members, suitable for querying
    OIMGroupMemberFilterOwner = 1,             /// Group owner
    OIMGroupMemberFilterAdmin = 2,             /// Group admin
    OIMGroupMemberFilterMember = 3,            /// Group member
    OIMGroupMemberFilterAdminAndMember = 4,    /// Admins and members
    OIMGroupMemberFilterSuperAndAdmin = 5,     /// Group owner and admins
};

typedef NS_ENUM(NSInteger, OIMGroupMemberRole) {
    OIMGroupMemberRoleOwner = 100,   /// Group owner
    OIMGroupMemberRoleAdmin = 60,    /// Group admin
    OIMGroupMemberRoleMember = 20,  /// Group member
};

typedef NS_ENUM(NSInteger, OIMApplicationStatus) {
    OIMApplicationStatusDecline = -1,  /// Declined
    OIMApplicationStatusNormal = 0,    /// Waiting for processing
    OIMApplicationStatusAccept = 1,    /// Accepted
};

typedef NS_ENUM(NSInteger, OIMRelationship) {
    OIMRelationshipBlack  = 0,
    OIMRelationshipFriend = 1
};

typedef NS_ENUM(NSInteger, OIMGroupAtType) {
    OIMGroupAtTypeAtNormal = 0,
    OIMGroupAtTypeAtMe = 1,
    OIMGroupAtTypeAtAll = 2,
    OIMGroupAtTypeAtAllAtMe = 3,
    OIMGroupAtTypeGroupNotification = 4
};

/*
 * Group Entry Verification Options
 */
typedef NS_ENUM(NSInteger,  OIMGroupVerificationType) {
    OIMGroupVerificationTypeApplyNeedVerificationInviteDirectly = 0,    /// Apply requires approval, invite directly
    OIMGroupVerificationTypeAllNeedVerification = 1,                    /// Everyone entering the group requires verification, except for group owner and admin invitations
    OIMGroupVerificationTypeDirectly = 2,                               /// Enter the group directly
};

/**
 * Group Types
 */
typedef NS_ENUM(NSInteger, OIMGroupType) {
    OIMGroupTypeNormal = 0,     /// Normal group
    OIMGroupTypeSuper = 1,      /// Super group
    OIMGroupTypeWorking = 2,    /// Working group
};

/**
 * Group Status
 */
typedef NS_ENUM(NSInteger, OIMGroupStatus) {
    OIMGroupStatusOk = 0,       /// Normal
    OIMGroupStatusBanChat = 1,  /// Banned
    OIMGroupStatusDismissed = 2,/// Dismissed
    OIMGroupStatusMuted = 3,    /// Muted
};

/**
 * Joining Group Methods
 */
typedef NS_ENUM(int32_t, OIMJoinType) {
    OIMJoinTypeInvited = 2, /// Joining by invitation
    OIMJoinTypeSearch = 3,  /// Joining by search
    OIMJoinTypeQRCode = 4   /// Joining by QR code
};

/**
 * Is it allowed?
 */
typedef NS_ENUM(NSInteger, OIMAllowType) {
    OIMAllowTypeAllowed = 0,
    OIMAllowTypeNotAllowed = 1,
};

/**
 * Is it allowed?
 */
typedef NS_ENUM(NSInteger, OIMLoginStatus) {
    OIMLoginStatusLogout = 0,
    OIMLoginStatusLogging = 1,
    OIMLoginStatusLogged = 2,
};

#endif /* IMDefine_h */
