//
//  OIMMessageInfo.h
//  OpenIMSDK
//
//  Created by x on 2022/2/11.
//

#import <Foundation/Foundation.h>
#import "OIMPictureElem.h"
#import "OIMSoundElem.h"
#import "OIMVideoElem.h"
#import "OIMFileElem.h"
#import "OIMMergeElem.h"
#import "OIMAtElem.h"
#import "OIMLocationElem.h"
#import "OIMCustomElem.h"
#import "OIMQuoteElem.h"
#import "OIMNotificationElem.h"
#import "OIMFaceElem.h"
#import "OIMAttachedInfoElem.h"
#import "OIMDefine.h"
#import "OIMMessageElem.h"
#import "OIMRedPacketElem.h"
#import "OIMTransferElem.h"
#import "OIMFullUserInfo.h"

NS_ASSUME_NONNULL_BEGIN

@interface OIMOfflinePushInfo : NSObject

@property (nonatomic, nullable, copy) NSString *title;
@property (nonatomic, nullable, copy) NSString *desc;
@property (nonatomic, nullable, copy) NSString *iOSPushSound;
@property (nonatomic, assign) BOOL iOSBadgeCount;
@property (nonatomic, nullable, copy) NSString *operatorUserID;
@property (nonatomic, nullable, copy) NSString *ex;

@end

/// Message Model
///
@interface OIMMessageInfo : NSObject

@property (nonatomic, nullable, copy) NSString *clientMsgID;

@property (nonatomic, nullable, copy) NSString *serverMsgID;

@property (nonatomic, assign) NSTimeInterval createTime;

@property (nonatomic, assign) NSTimeInterval sendTime;

@property (nonatomic, assign) OIMConversationType sessionType;

@property (nonatomic, nullable, copy) NSString *sendID;

@property (nonatomic, nullable, copy) NSString *recvID;

@property (nonatomic, nullable, copy) NSString *handleMsg;

@property (nonatomic, assign) OIMMessageLevel msgFrom;

@property (nonatomic, assign) OIMMessageContentType contentType;

@property (nonatomic, assign) OIMPlatform senderPlatformID;

@property (nonatomic, nullable, copy) NSString *senderNickname;

@property (nonatomic, nullable, copy) NSString *senderFaceUrl;

@property (nonatomic, nullable, copy) NSString *groupID;

@property (nonatomic, nullable, copy) NSString *content;
/**
 * Message unique sequence number
 */
@property (nonatomic, assign) NSInteger seq;

@property (nonatomic, assign) BOOL isRead;

@property (nonatomic, assign) OIMMessageStatus status;

@property (nonatomic, nullable, copy) NSString *attachedInfo;

@property (nonatomic, nullable, copy) NSString *ex;

@property (nonatomic, strong) OIMOfflinePushInfo *offlinePush;

@property (nonatomic, nullable, strong) OIMTextElem *textElem;

@property (nonatomic, nullable, strong) OIMCardElem *cardElem;

@property (nonatomic, nullable, strong) OIMPictureElem *pictureElem;

@property (nonatomic, nullable, strong) OIMSoundElem *soundElem;

@property (nonatomic, nullable, strong) OIMVideoElem *videoElem;

@property (nonatomic, nullable, strong) OIMFileElem *fileElem;

@property (nonatomic, nullable, strong) OIMMergeElem *mergeElem;

@property (nonatomic, nullable, strong) OIMAtTextElem *atTextElem;

@property (nonatomic, nullable, strong) OIMLocationElem *locationElem;

@property (nonatomic, nullable, strong) OIMQuoteElem *quoteElem;

@property (nonatomic, nullable, strong) OIMCustomElem *customElem;

@property (nonatomic, nullable, strong) OIMNotificationElem *notificationElem;

@property (nonatomic, nullable, strong) OIMFaceElem *faceElem;

@property (nonatomic, nullable, strong) OIMAttachedInfoElem *attachedInfoElem;

@property (nonatomic, nullable, strong) OIMAdvancedTextElem *advancedTextElem;

@property (nonatomic, nullable, strong) OIMTypingElem *typingElem;
@property (nonatomic, nullable, strong) OIMRedPacketElem *redPacketElem; //
@property (nonatomic, strong) OIMTransferElem *transferElem; // <#注释#>

@property (nonatomic, assign) NSTimeInterval hasReadTime;

@property (nonatomic, assign) BOOL isReact;

@property (nonatomic, assign) BOOL isExternalExtensions;

@end

@interface OIMReceiptInfo : NSObject

/**
 * User ID - for one-on-one chat
 */
@property (nonatomic, nullable, copy) NSString *userID;

/**
 * Group ID - for group chat
 */
@property (nonatomic, nullable, copy) NSString *groupID;

/**
 * Read message IDs
 */
@property (nonatomic, nullable, copy) NSArray<NSString *> *msgIDList;

/**
 * Reading time
 */
@property (nonatomic, assign) NSInteger readTime;

@property (nonatomic, assign) OIMMessageLevel msgFrom;

@property (nonatomic, assign) OIMMessageContentType contentType;

@property (nonatomic, assign) OIMConversationType sessionType;

@end

@interface OIMMessageRevokedInfo : NSObject

/**
 * ID of the revoker
 */
@property (nonatomic, copy) NSString *revokerID;

@property (nonatomic, copy) NSString *revokerNickname;

/**
 * Revoker's role, e.g., group owner, group administrator
 */
@property (nonatomic, assign) OIMGroupMemberRole revokerRole;

@property (nonatomic, copy) NSString *clientMsgID;

@property (nonatomic, assign) NSTimeInterval revokeTime;

@property (nonatomic, assign) NSTimeInterval sourceMessageSendTime;

@property (nonatomic, copy) NSString *sourceMessageSendID;

@property (nonatomic, copy) NSString *sourceMessageSenderNickname;

@property (nonatomic, assign) OIMConversationType sessionType;

@property (nonatomic, copy) NSString *ex;

@end

@interface OIMKeyValue: NSObject

@property (nonatomic, copy) NSString *errMsg;

@property (nonatomic, assign) NSInteger errCode;

@property (nonatomic, copy) NSString *typeKey;

@property (nonatomic, copy) NSString *value;

@property (nonatomic, assign) NSTimeInterval latestUpdateTime;

@end

@interface OIMKeyValues: NSObject

@property (nonatomic, copy) NSString *errMsg;

@property (nonatomic, assign) NSInteger errCode;

@property (nonatomic, copy) NSString *clientMsgID;

@property (nonatomic, copy) NSDictionary<NSString *, OIMKeyValue *> *reactionExtensionList;

@end

@interface OIMMessageRedPacketInfo : NSObject

@property (nonatomic, copy)   NSString *clientMsgID; // 消息 ID
@property (nonatomic, assign) NSInteger seq; // 消息 seq
@property (nonatomic, copy)   NSString *conversationID; // 会话 ID
@property (nonatomic, assign) OIMMessageContentType contentType; // 消息类型
@property (nonatomic, copy)   NSString *redPacketID; // 红包 ID
@property (nonatomic, strong) OIMPublicUserInfo *claimUser; // 领取用户

@end

NS_ASSUME_NONNULL_END
