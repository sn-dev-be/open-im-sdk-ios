//
//  OIMSignalVoiceInfo.h
//  OpenIMSDKiOS_Example
//
//  Created by Mark on 2024/2/4.
//  Copyright © 2024 xpg. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "OIMFullUserInfo.h"

NS_ASSUME_NONNULL_BEGIN

@interface OIMSignalVoiceInfo : NSObject

@property (nonatomic, copy)   NSString *channelID; // 频道ID
@property (nonatomic, strong) OIMPublicUserInfo *opUser; // 用户
@property (nonatomic, strong) NSArray <OIMPublicUserInfo *>* participants; // 语音房成员数组
@property (nonatomic, assign) NSInteger remainingSec; // 语音房剩余时间(秒)
@property (nonatomic, assign) NSInteger elapsedSec; // 语音房持续时间
@property (nonatomic, copy)   NSString *conversationID; // 会话 id

@end

@interface OIMSignalVoiceSingleChatInfo : NSObject

@property (nonatomic, assign) NSInteger elapsedSec; // 语音房持续时间
@property (nonatomic, copy)   NSString *opUserID; // 操作用户 id

@end


@interface OIMSignalVoiceMicphoneStatusInfo : NSObject

@property (nonatomic, copy)   NSString *channelID; //  频道 id
@property (nonatomic, strong) OIMPublicUserInfo *opUser; // 用户
@property (nonatomic, assign) NSInteger micphoneStatus; // 麦克风状态 1 开/2 关

@end


@interface OIMSignalVoiceSpeakStatusInfo : NSObject

@property (nonatomic, copy)   NSString *channelID; // 频道 id
@property (nonatomic, strong) OIMPublicUserInfo *opUser; // 用户

@end


@interface OIMSignalGroupVoiceCardInfo : NSObject

@property (nonatomic, copy)   NSString *channelID; // 频道 id
@property (nonatomic, strong) NSArray <OIMPublicUserInfo *> *opUsers; // 用户数组
@property (nonatomic, assign) NSInteger status; // 1/正常 2/关闭
@property (nonatomic, assign) NSInteger createTime; // 创建时间

@end

NS_ASSUME_NONNULL_END
