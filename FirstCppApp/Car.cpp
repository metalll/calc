//
//  Car.cpp
//  FirstCppApp
//
//  Created by MacOS on 13.07.2018.
//  Copyright © 2018 MacOS. All rights reserved.
//

#pragma mark - Constructor

#include "Car.hpp"
#include "IReachable.h"

#include <iostream>

Car::Car(IReachable *reach,int speed):m_reach(reach),m_speed(speed) {
}

#pragma mark - Public

void Car::drive() {
    if (m_reach->isReachable()) {
        std::cout << "Offline";
    }
    std::cout << "Car driving with speed "
              << m_speed
              << std::endl;
}
