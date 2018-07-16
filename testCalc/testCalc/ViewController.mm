//
//  ViewController.m
//  testCalc
//
//  Created by MacOS on 15.07.2018.
//  Copyright © 2018 MacOS. All rights reserved.
//

#import "ViewController.h"

#include "CalcBrainDelegateProtocol.h"
#include "CalcBrain.hpp"
#include "OSXCalcBrainBridgeDelegate.h"

@interface ViewController() <CalcBrainDelegateProtocol>
@property (assign,nonatomic) CalcBrain *calcBrain;
@end

@implementation ViewController

#pragma mark - ViewController Life Cycle

- (void)viewDidLoad {
    [super viewDidLoad];
    if (self.calcBrain) {
        
    }
}

#pragma mark - Override Getters/Setters

- (CalcBrain *)calcBrain {
    __weak typeof(self) weakSelf = self;
    if (!_calcBrain) {
        _calcBrain = new CalcBrain(new OSXCalcBrainBridgeDelegate(weakSelf));
        _calcBrain->inputCommand(new std::string([@"2" UTF8String]));
    }
    return _calcBrain;
}

#pragma mark - CalcBrainDelegateProtocol

- (void)didReciveErrorWithMessage:(NSString *)message {
    
}

- (void)didUpdateResultWithResult:(NSString *)result {
    
}
@end
