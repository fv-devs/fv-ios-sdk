//
//  FullyVerified.h
//  FullyVerifiedSDK
//
//  Created by Krzysztof Ebert on 26/06/2018.
//  Copyright © 2018 Fully-Verified. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

typedef NS_ENUM(NSInteger, FullyVerifiedState) {
    FullyVerifiedStateConnecting = 0,
    FullyVerifiedStateConnected,
    FullyVerifiedStateWaiting,
    FullyVerifiedStateInProgress,
    FullyVerifiedStateFinished,
    FullyVerifiedStateDisconnected,
};

typedef NS_ENUM(NSInteger, FullyVerifiedEnvironment) {
    FullyVerifiedEnvironmentLive = 0,
    FullyVerifiedEnvironmentTest = 1,
#if defined (DEBUG) || defined (TESTFLIGHT)
    FullyVerifiedEnvironmentLiveAWS = 2,
    FullyVerifiedEnvironmentTestAWS = 3
#endif
};

@protocol FullyVerifiedDelegate;

@interface FullyVerified : NSObject<NSURLSessionDelegate>

@property (nonatomic, weak) id<FullyVerifiedDelegate> delegate;
@property (nonatomic, retain) NSURLSessionConfiguration *sessionConfig;

+ (instancetype)sharedInstance;
+ (NSString *) endpointURL:(NSString *)endpoint;

- (void) startVerification:(NSString *) verificationHash withViewController:(UIViewController *)viewController;
- (void) startVerification:(NSString *) mobileHash withOTP:(NSString *)oneTimePassword withViewController:(UIViewController *)viewController;
- (void) refreshToken:(void (^)(void))completionHandler;
- (void) setEnvironment:(FullyVerifiedEnvironment) environment;
- (void) registerNotificationToken:(NSString *)token;
- (FullyVerifiedEnvironment) environment;

@end

@protocol FullyVerifiedDelegate <NSObject>
@optional
- (void) FullyVerified:(FullyVerified *)fullyVerified connected:(BOOL)connected;
- (void) FullyVerified:(FullyVerified *)fullyVerified disconnected:(BOOL)connected;
- (void) FullyVerified:(FullyVerified *)fullyVerified state:(FullyVerifiedState)state error:(NSError * __autoreleasing *)error;

@end


