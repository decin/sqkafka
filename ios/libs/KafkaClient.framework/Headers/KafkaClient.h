//
//  KafkaClient.h
//  KafkaClient
//
//  Created by Decin on 2023/7/25.
//

#import <Foundation/Foundation.h>

//! Project version number for KafkaClient.
FOUNDATION_EXPORT double KafkaClientVersionNumber;

//! Project version string for KafkaClient.
FOUNDATION_EXPORT const unsigned char KafkaClientVersionString[];

// In this header, you should import all the public headers of your framework using statements like #import <KafkaClient/PublicHeader.h>


@interface KafkaClient : NSObject
/**
 设置默认服务集群列表, 类属性, 实例均生效
 @param brokers 服务集群列表, 如 "47.x.x.1:30101,47.x.x.1:30102,47.x.x.2:30103"
 */
+ (void)setDefaultBrokers:(NSString *)brokers;
/**
 设置默认Topic, 类属性, 实例均生效
 */
+ (void)setDefaultTopic:(NSString *)topic;
/**
 设置默认发送的超时时间, 类属性, 实例均生效
 */
+ (void)setDefaultTimeout:(int)timeout;

/**
    默认初始化方法, 使用 使用默认超时时间 10s
 */
- (instancetype)init;

/**
 初始化方法
 @param brokers 服务集群列表, 如 "47.x.x.1:30101,47.x.x.1:30102,47.x.x.2:30103"
 @param timeout 超时时间, 单位 ms; <1000ms 时, 使用默认超时时间
 */
- (instancetype)initWithBrokers:(NSString *)brokers timeout:(int)timeout;

/**
 发送消息
 @param msg  kafka 消息
 @param topic 话题
 */
- (BOOL)send:(NSString *)msg forTopic:(NSString *)topic;

/**
 发送消息, 发送至默认topic, 需要初始化前通过 setDefaultTopic: 设置
 @param msg  kafka 消息
 */
- (BOOL)send:(NSString *)msg;
@end
