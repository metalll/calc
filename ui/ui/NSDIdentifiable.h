//
//  NSDIdentifiable.h
//  ui
//
//  Created by MacOS on 16.07.2018.
//  Copyright © 2018 MacOS. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSDIdentifiable : NSObject

@end

@protocol NSDIdentifiableDelegate

- (NSString *)objectID;

@end
