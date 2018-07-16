//
//  CalcBrainMathOperation.hpp
//  testCalc
//
//  Created by MacOS on 15.07.2018.
//  Copyright © 2018 MacOS. All rights reserved.
//

#pragma once

#include <iostream>

const std::string OPERATION_AC = "AC";
const std::string OPERATION_REVERSE = "+/-";
const std::string OPERATION_PERCENT = "%";
const std::string OPERATION_DEVIDE = "/";
const std::string OPERATION_MULTIPLY = "*";
const std::string OPERATION_MINUS = "-";
const std::string OPERATION_PLUS = "+";
const std::string OPERATION_EQUALS = "=";

enum CalcBrainMathOperationType {
    CalcBrainMathOperationTypeAC,
    CalcBrainMathOperationTypeReverse,
    CalcBrainMathOperationTypePercent,
    CalcBrainMathOperationTypeDevide,
    CalcBrainMathOperationTypeMultiply,
    CalcBrainMathOperationTypeMinus,
    CalcBrainMathOperationTypePlus,
    CalcBrainMathOperationTypeEquals,
    CalcBrainMathOperationTypeErrorType
};

class CalcBrainMathOperation {

private:
    CalcBrainMathOperationType m_operationType;
    std::string m_stringValue;
    void commonInit();
    
public:
    static bool isValidOperation(std::string *operation);
    static CalcBrainMathOperationType loadOperationType(std::string *stringOperationType);
    static std::string* loadString(CalcBrainMathOperationType type);
    
    CalcBrainMathOperation(std::string stringValue);
    CalcBrainMathOperation(std::string *stringValue);
    CalcBrainMathOperation(CalcBrainMathOperationType operationType);
  
    CalcBrainMathOperationType operation();
    std::string stringOperation();
};
