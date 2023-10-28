//
//  OIMRedPacketElem.h
//  OpenIMSDKiOS_Example
//
//  Created by Mark on 2023/10/28.
//  Copyright © 2023 xpg. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface OIMRedPacketElem : NSObject

@property (nonatomic, copy)   NSString *redPacketID; // 业务方红包 ID
@property (nonatomic, copy)   NSString *greetings; // 祝福文案
@property (nonatomic, assign) NSInteger status; // 1 正常/ 2 领完/ 3 失效

@end

NS_ASSUME_NONNULL_END
