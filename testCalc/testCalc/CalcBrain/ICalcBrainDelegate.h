//
//  ICalcBrainDelegate.h
//  testCalc
//
//  Created by MacOS on 15.07.2018.
//  Copyright © 2018 MacOS. All rights reserved.
//

#pragma once

#include <iostream>

class ICalcBrainDelegate {
public:
    virtual void renderResult(std::string *result) const = 0;
    virtual void renderError(std::string *error) const = 0;
};
