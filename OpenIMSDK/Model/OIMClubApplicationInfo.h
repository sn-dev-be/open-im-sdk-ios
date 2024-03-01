//
//  OIMClubApplicationInfo.h
//  OpenIMSDKiOS_Example
//
//  Created by Mark on 2024/2/29.
//  Copyright © 2024 xpg. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

// 部落状态：0 正常，1 被封，2 解散，3 禁言

// 该类未使用，使用时需放开注释内容
@interface OIMClubApplicationInfo : NSObject

//@property (nonatomic, assign) NSInteger status; // 部落状态 - 该字段未确定
//@property (nonatomic, copy)   NSString *description; // 部落简介 - 该字段冲突

@property (nonatomic, copy)   NSString *serverID; // 部落ID
@property (nonatomic, copy)   NSString *serverName; // 部落名称
@property (nonatomic, copy)   NSString *banner; // 部落封面图
//@property (nonatomic, copy)   NSString *description; // 部落简介 - 该字段冲突
@property (nonatomic, copy)   NSString *icon; // 部落头像
@property (nonatomic, assign) NSInteger createTime; // 申请进部落时间
@property (nonatomic, assign) OIMGroupStatus status; // 部落状态 - 该字段未确定
@property (nonatomic, copy)   NSString *creatorUserID; // 建部落者 ID
@property (nonatomic, copy)   NSString *ownerUserID; // 部落主 ID
@property (nonatomic, assign) NSInteger memberNum; // 部落成员数量
@property (nonatomic, copy)   NSString *userID; // 进部落申请者 ID
@property (nonatomic, copy)   NSString *nickname; // 进部落申请者昵称
@property (nonatomic, copy)   NSString *userFaceURL; // 进部落申请者头像
@property (nonatomic, assign) OIMApplicationStatus handleResult; // 处理结果
@property (nonatomic, copy)   NSString *reqMsg; // 申请加部落的附加信息
@property (nonatomic, copy)   NSString *handledMsg; // 处理附加信息
@property (nonatomic, assign) NSInteger reqTime; // 申请进部落时间
@property (nonatomic, copy)   NSString *handleUserID; // 处理进部落的用户 ID
@property (nonatomic, assign) NSInteger handledTime; // 处理近期申请时间
@property (nonatomic, copy)   NSString *ex; // 扩展字段
@property (nonatomic, assign) OIMJoinType joinSource; // 进部落方式
@property (nonatomic, copy)   NSString *inviterUserID; // 邀请进部落用户 ID


@end

NS_ASSUME_NONNULL_END
