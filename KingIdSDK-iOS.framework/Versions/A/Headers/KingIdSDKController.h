//
//  VietIdSDKController.h
//  VietidSDK-iOS
//
//  Created by Le Minh Son on 11/13/18.
//  Copyright © 2018 songoku20. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "AccessToken.h"
#import "KingIdException.h"
#import "UserInfo.h"
@import UIKit;

NS_ASSUME_NONNULL_BEGIN

#define VERSION_NAME @"1.0.5"

#define EN @"en"
#define VI @"vi"
#define FR @"fr"

static NSInteger NATIVE = 0;//Show fullscreen of dialog authen
static NSInteger NATIVE_WITH_FALLBACK = 1; //Show fullscreen authen otherwise show web dialog to authen
static NSInteger WEB_DIALOG = 2;//Show Web Dialog for authen

@protocol OnKingIdResponse
-(void)onRequestSuccess:(UserInfo*)userInfo;
-(void)onRequestFailed:(KingIdException*) e;
@end

@protocol OnKingIdLoginCallback
-(void)onAuthenSuccess:(AccessToken*) accessToken;
-(void)onAuthenFailed:(KingIdException*) kingIdException;
-(void)onAuthenCancel;
@end

//For VietIdSDK public method and properties
@interface KingIdSDKController : NSObject

@property(nonatomic, strong) NSString* language;
@property(nonatomic, readonly) NSInteger actionType;
@property(nonatomic, strong) id<OnKingIdLoginCallback> onKingIdLoginCallback;
@property(nonatomic, strong) id<OnKingIdResponse> onKingIdResponseRequest;

/**
 * Create singleton instance of VietIdSDKController
 */
+(instancetype)sharedInstance;

/**
 * Init and make config for vietidController
 * Call first before working with VietIdController
 * Such that: [[VietIdSDKController sharedInstance] configure];
 */
-(void) configure:(NSString*) clientId clientSecret:(NSString*)clientSecret;

/**
 * @return clientId for your application with vietIdSDK
 */
-(NSString*)getCLientId;

/**
 * @return redirectUri for your application with vietIdSDK
 */
-(NSString*)getRedirectUri;

/**
 * @return clientSecret for your application with vietIdSDK
 */
-(NSString*)getClientSecret;

/**
 * @return bundleId of your application
 */
-(NSString*)getBundleId;

/**
 * Call to check logged in session on local
 *
 * @return boolean state true if token is valid otherwise
 */
-(BOOL)checkTokenOnLocal;

/**
 * Call to check logged in session with asynchronous from server check
 * Callback result via delegate class: OnVietIdResponse
 */
-(void)checkTokenOnServer;

//For login/logout
/**
 * Call this when you want to login via vietID
 */
-(void)login;
/**
 * Call this when you want to logout via vietID
 */
-(BOOL)logout;

/**
 * Call this when you want to logout via vietID with asynchronous state
 */
-(void)logoutAsync:(void(^)(BOOL  success,KingIdException* error))callback;

//For get user information
/**
 * Get user info with asynchronous
 */
-(void)getUserInfoAsync:(void(^)(BOOL  success,KingIdException* error,UserInfo* userinfo))callback;
/**
 * Get user info with synchronous
 */
-(UserInfo*)getUserInfo;

/**
 * Set disable phone number on login session: YES if you want disable login via vietID with phonenumber otherwise
 */
-(void)disablePhone:(BOOL) disable;

/**
 * Get disable phone number on login session: YES if you want disable login via vietID with phonenumber otherwise
 */
-(NSString*)isDisablePhone;

@end

NS_ASSUME_NONNULL_END
