//
//  OIMTransferElem.h
//  OpenIMSDKiOS_Example
//
//  Created by Mark on 2023/10/28.
//  Copyright © 2023 xpg. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface OIMTransferElem : NSObject

@property (nonatomic, copy)   NSString *tokenLogo; // 代币 logo url
@property (nonatomic, assign) CGFloat amount; // 金额
@property (nonatomic, copy)   NSString *token; // 代币名称
@property (nonatomic, copy)   NSString *transactionID; // 业务端转账交易 id


@end

NS_ASSUME_NONNULL_END
