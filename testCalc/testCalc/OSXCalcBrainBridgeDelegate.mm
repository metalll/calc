//
//  OSXCalcBrainDelegate.m
//  testCalc
//
//  Created by MacOS on 15.07.2018.
//  Copyright © 2018 MacOS. All rights reserved.
//

#import "OSXCalcBrainBridgeDelegate.h"

OSXCalcBrainBridgeDelegate::OSXCalcBrainBridgeDelegate(id<CalcBrainDelegateProtocol> delegate):m_delegate(delegate) {
}

void OSXCalcBrainBridgeDelegate::renderResult(std::string *result) const {
    [m_delegate didUpdateResultWithResult:[NSString stringWithUTF8String:result->c_str()]];
}

void OSXCalcBrainBridgeDelegate::renderError(std::string *error) const {
    [m_delegate didReciveErrorWithMessage:[NSString stringWithUTF8String:error->c_str()]];
}
