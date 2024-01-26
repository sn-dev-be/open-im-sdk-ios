//
//  OIMUserInfo.h
//  OpenIMSDK
//
//  Created by x on 2022/2/11.
//

#import <Foundation/Foundation.h>
#import "OIMDefine.h"

NS_ASSUME_NONNULL_BEGIN

/// Personal information, including all details
///
@interface OIMUserInfo : NSObject

@property (nonatomic, nullable, copy) NSString *userID;             // 用户 ID
@property (nonatomic, nullable, copy) NSString *nickname;           // 用户昵称
@property (nonatomic, nullable, copy) NSString *faceURL;            // 用户头像
@property (nonatomic, assign) NSInteger createTime;                 // 用户注册时间（毫秒）
@property (nonatomic, nullable, copy) NSString *ex;                 // 用户扩展字段
@property (nonatomic, nullable, copy) NSString *attachedInfo;       // SDK 内部扩展字段，应用层无需关注
@property (nonatomic, assign) OIMReceiveMessageOpt globalRecvMsgOpt;// 全局消息接收设置
@property (nonatomic, assign) NSInteger appMangerLevel;             // 内部字段，可忽略
@property (nonatomic, assign) NSInteger allowBeep;                  // 新消息提醒声音 1-开启 2-关闭
@property (nonatomic, assign) NSInteger allowVibration;             // 新消息提醒震动 1-开启 2-关闭
@property (nonatomic, assign) NSInteger allowPushContent;           // 新消息提醒聊天内容 1-开启 2-关闭
@property (nonatomic, assign) NSInteger allowOnlinePush;            // 新消息应用内推送 1-开启 2-关闭

@end

@interface OIMUserStatusInfo : NSObject

@property (nonatomic, nullable, copy) NSString *userID;
@property (nonatomic, nullable, copy) NSArray *platformIDs;
@property (nonatomic, assign) NSInteger status;
@end

NS_ASSUME_NONNULL_END
