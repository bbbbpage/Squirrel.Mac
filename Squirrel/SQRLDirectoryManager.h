//
//  SQRLDirectoryManager.h
//  Squirrel
//
//  Created by Justin Spahr-Summers on 2013-10-08.
//  Copyright (c) 2013 GitHub. All rights reserved.
//

#import <Foundation/Foundation.h>

@class RACSignal;

// Provides the file locations that Squirrel/ShipIt use.
@interface SQRLDirectoryManager : NSObject

// Returns the shared `SQRLDirectoryManager` for the running application, based
// on the bundle identifier or application name.
+ (instancetype)currentApplicationManager;

// Initializes the receiver to store files in a location identified by
// `appIdentifier`.
//
// This is the designated initializer for this class.
//
// appIdentifier - The unique identifier for the application or job to find
//                 on-disk locations for. This must not be nil.
- (instancetype)initWithApplicationIdentifier:(NSString *)appIdentifier;

// Finds or creates an Application Support subdirectory for the receiver’s
// application identifier.
//
// Returns a signal which synchronously sends a URL then completes, or errors.
- (RACSignal *)applicationSupportURL;

// Finds or creates a downloads directory to store update downloads in prior to
// installation. This is an applicationSupportURL subdirectory.
//
// Returns a signal which sends a URL then completes, or errors.
- (RACSignal *)downloadDirectoryURL;

// Finds or creates a directory to unpack downloaded updates into prior to
// installation. This is an applicationSupportURL subdirectory.
//
// Returns a signal which sends a URL then completes, or errors.
- (RACSignal *)unpackDirectoryURL;

// Determines where archived `SQRLShipItState` should be saved.
//
// Returns a signal which synchronously sends a URL then completes, or errors.
- (RACSignal *)shipItStateURL;

@end
