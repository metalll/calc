//
//  OSXCalcBrainDelegate.h
//  testCalc
//
//  Created by MacOS on 15.07.2018.
//  Copyright © 2018 MacOS. All rights reserved.
//

#pragma once

#import <Foundation/Foundation.h>
#import "CalcBrainDelegateProtocol.h"

#include "ICalcBrainDelegate.h"

class OSXCalcBrainBridgeDelegate :  public ICalcBrainDelegate {

public:
    OSXCalcBrainBridgeDelegate(id<CalcBrainDelegateProtocol> delegate);
    virtual void renderResult(std::string *result) const;
    virtual void renderError(std::string *error) const;
    
private:
    id<CalcBrainDelegateProtocol> m_delegate;
};
