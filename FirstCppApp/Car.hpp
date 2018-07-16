//
//  Car.hpp
//  FirstCppApp
//
//  Created by MacOS on 13.07.2018.
//  Copyright © 2018 MacOS. All rights reserved.
//

#pragma once

class IReachable;

class Car {

public:
    Car(IReachable *reach, int speed);
    void drive();
    
private:
    int m_speed;
    IReachable *m_reach;
};
