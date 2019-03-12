//
//  UserInfo.h
//  KingIdSDK-iOS
//
//  Created by Le Minh Son on 11/13/18.
//  Copyright © 2018 songoku20. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface KingUserInfo : NSObject

@property(nonatomic, strong) NSString* userId      ;
@property(nonatomic, strong) NSString* uniqid      ;
@property(nonatomic, strong) NSString* name        ;
@property(nonatomic, strong) NSString* mobile      ;
@property(nonatomic, strong) NSString* status      ;
@property(nonatomic, strong) NSString* fullname    ;
@property(nonatomic, strong) NSString* birthday    ;
@property(nonatomic, strong) NSString* address     ;
@property(nonatomic, strong) NSString* avatar      ;
@property(nonatomic, strong) NSString* email_old   ;
@property(nonatomic, strong) NSString* email       ;
@property(nonatomic, strong) NSString* code_login  ;
@property(nonatomic, strong) NSString* change_info ;
/**
 * Not call method everytime from your app
 */
+(KingUserInfo*) initFromDic:(NSDictionary*) dict;
/**
 * Get userinfo object as NSDictionary
 */
-(NSDictionary*)toDict;
@end
NS_ASSUME_NONNULL_END
