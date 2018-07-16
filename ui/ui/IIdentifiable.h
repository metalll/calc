//
//  Identifie.h
//  ui
//
//  Created by MacOS on 16.07.2018.
//  Copyright © 2018 MacOS. All rights reserved.
//

#pragma once

class IIdentifiable {
public:
    virtual const std::string& getID() const = 0;
};
