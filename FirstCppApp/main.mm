//
//  main.m
//  FirstCppApp
//
//  Created by MacOS on 13.07.2018.
//  Copyright © 2018 MacOS. All rights reserved.
//

#import <Foundation/Foundation.h>

#include "Car.hpp"

#include "IReachable.h"
#include "OSXReachibility.h"

int main(int argc, const char * argv[]) {
    @autoreleasepool {
       
        IReachable *reach = new OSXReachibility;
        
        Car *car = new Car(reach,5);
        car->drive();
        
        
        delete car;
    }
    return 0;
}
