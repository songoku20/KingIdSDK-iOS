//
//  AccessToken.h
//  KingIdSDK-iOS
//
//  Created by Le Minh Son on 11/13/18.
//  Copyright © 2018 songoku20. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface AccessToken : NSObject

/**
 * @return Your accessToken when login via kingID successfully
 */
@property(nonatomic, weak) NSString* accessToken;
/**
 * @return time to expired token login
 */
@property(nonatomic, weak) NSString* expiresIn;
/**
 * @return token type of your login session
 */
@property(nonatomic, weak) NSString* tokenType;
/**
 * @return scope
 */
@property(nonatomic, weak) NSString* scope;
/**
 * Not call method everytime from your app
 */
+(AccessToken*) initFromDic:(NSDictionary*) dict;
/**
 * @return Current token when login successfully
 */
+(AccessToken*)getCurrentAccessToken;
/**
 * Set current accessToken nil if
 */
+(void)setCurrentAccessToken:(AccessToken*)accessToken;
/**
 * Get accessToken object as NSDictionary
 */
-(NSDictionary*)toDict;
@end

NS_ASSUME_NONNULL_END
