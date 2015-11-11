//
//  VoucherServer.h
//  Voucher
//
//  Created by Rizwan Sattar on 11/7/15.
//  Copyright © 2015 Rizwan Sattar. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "VoucherStreamsController.h"

@class VoucherServer;
@protocol VoucherServerDelegate <NSObject>

@optional
- (void)voucherServer:(nonnull VoucherServer *)server didUpdateAdvertising:(BOOL)isAdvertising;
- (void)voucherServer:(nonnull VoucherServer *)server didUpdateConnectionToClient:(BOOL)isConnectedToClient;
@end


typedef void (^VoucherServerResponseHandler)(NSData * _Nullable authData, NSError * _Nullable error);
typedef void (^VoucherServerRequestHandler)(NSString * _Nonnull displayName, VoucherServerResponseHandler _Nonnull responseHandler);

@interface VoucherServer : VoucherStreamsController

@property (weak, nonatomic) NSObject <VoucherServerDelegate> *delegate;

@property (readonly, copy, nonatomic, nonnull) NSString *displayName;
@property (readonly, copy, nonatomic, nonnull) NSString *uniqueSharedId;
@property (readonly, assign, nonatomic) BOOL isAdvertising;
@property (readonly, assign, nonatomic) BOOL isConnectedToClient;

- (nullable instancetype)init NS_UNAVAILABLE;
- (nonnull instancetype)initWithDisplayName:(nonnull NSString *)displayName uniqueSharedId:(nonnull NSString *)uniqueSharedId NS_DESIGNATED_INITIALIZER;

- (void)startAdvertisingWithRequestHandler:(nonnull VoucherServerRequestHandler)requestHandler;
- (void)stop;

@end
