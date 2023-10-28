//
//  RedPacketInfo.h
//  OpenIMSDKiOS_Example
//
//  Created by Mark on 2023/10/28.
//  Copyright © 2023 xpg. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "OIMFullUserInfo.h"

NS_ASSUME_NONNULL_BEGIN

@interface RedPacketInfo : NSObject

@property (nonatomic, copy)   NSString *clientMsgID; // 消息ID
@property (nonatomic, copy)   NSString *redPacketID; // 红包ID
@property (nonatomic, strong) OIMPublicUserInfo *claimUser; // 领取用户
@property (nonatomic, assign) NSInteger status; // 状态 1:正常 2:领完 3:失效

@end

NS_ASSUME_NONNULL_END
