//
//  CalcBrain.hpp
//  testCalc
//
//  Created by MacOS on 15.07.2018.
//  Copyright © 2018 MacOS. All rights reserved.
//

#pragma once

#include "iostream"

class ICalcBrainDelegate;
class CalcBrainMathOperation;

class CalcBrain {

private:
    double m_accumulator;
    ICalcBrainDelegate* m_delegate;
    CalcBrainMathOperation* m_operation;
    double m_lastUsedOperand;
   
    std::string* safeOperand(std::string* operand);
    void resetBrain();
    void reveseBrain();
    void percentBrain();
    void devideBrain();
    void multiplyBrain();
    void minusBrain();
    void plusBrain();
    void equalsBrain();
    
    void updateUI();
    
public:
    CalcBrain(ICalcBrainDelegate *delegate);
    void inputCommand(std::string *command);

protected:
    void setOperand(std::string* operand);
    void performOperation(CalcBrainMathOperation* operation);
};
