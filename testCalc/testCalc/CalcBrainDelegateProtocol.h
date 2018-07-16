//
//  CalcBrainDelegateProtocol.h
//  testCalc
//
//  Created by MacOS on 15.07.2018.
//  Copyright © 2018 MacOS. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol CalcBrainDelegateProtocol <NSObject>

- (void)didUpdateResultWithResult:(NSString *)result;
- (void)didReciveErrorWithMessage:(NSString *)message;

@end
