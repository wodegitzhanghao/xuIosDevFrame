//
//  AFNetworkCacheHelper.h
//  NewLzShortMsg
//
//  Created by ios开发 on 2017/1/23.
//  Copyright © 2017年 oilchem. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "YYCache.h"
@interface AFNetworkCacheHelper : NSObject{
}

+(YYCache *) getCache;
/**
 *  异步缓存网络数据,根据请求的 URL与parameters
 *  做KEY存储数据, 这样就能缓存多级页面的数据
 *
 *  @param httpData   服务器返回的数据
 *  @param URL        请求的URL地址
 *  @param parameters 请求的参数
 */
+ (void)setHttpCache:(id)httpData URL:(NSString *)URL parameters:(NSDictionary *)parameters;

/**
 *  根据请求的 URL与parameters 异步取出缓存数据
 *
 *  @param URL        请求的URL
 *  @param parameters 请求的参数
 *  @param block      异步回调缓存的数据
 *
 *  @return 缓存的服务器数据
 */
+ (void)httpCacheForURL:(NSString *)URL parameters:(NSDictionary *)parameters withBlock:(void(^)(id<NSCoding> object))block;

/**
 *  获取网络缓存的总大小 bytes(字节)
 */
+ (NSInteger)getAllHttpCacheSize;


/**
 *  删除所有网络缓存,
 */
+ (void)removeAllHttpCache;


+ (NSString *)cacheKeyWithURL:(NSString *)URL parameters:(NSDictionary *)parameters;
@end
