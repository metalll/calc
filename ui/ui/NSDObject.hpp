//
//  NSDObject.hpp
//  ui
//
//  Created by MacOS on 16.07.2018.
//  Copyright © 2018 MacOS. All rights reserved.
//



#pragma once

#include <string>

#include "IIdentifiable.h"

class NSDObject : public IIdentifiable {
public:
    virtual const std::string& getID() const;
private:
    std::string *m_id;
};
