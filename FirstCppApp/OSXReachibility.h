//
//  OSXReachibility.h
//  FirstCppApp
//
//  Created by MacOS on 14.07.2018.
//  Copyright © 2018 MacOS. All rights reserved.
//

#pragma once

#include "IReachable.h"

class OSXReachibility : public IReachable {
public:
    virtual bool isReachable() const ;
};
