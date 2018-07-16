//
//  CalcBrainMathOperation.cpp
//  testCalc
//
//  Created by MacOS on 15.07.2018.
//  Copyright © 2018 MacOS. All rights reserved.
//

#include "CalcBrainMathOperation.hpp"

#pragma mark - Public (static utils)

bool CalcBrainMathOperation::isValidOperation(std::string *operation) {
    return CalcBrainMathOperation::loadOperationType(operation) != CalcBrainMathOperationTypeErrorType;
}

CalcBrainMathOperationType CalcBrainMathOperation::loadOperationType(std::string *stringOperationType) {
    
    if (stringOperationType->empty()) {
        return CalcBrainMathOperationTypeErrorType;
    }
    if (stringOperationType->compare(OPERATION_AC)) {
        return CalcBrainMathOperationTypeAC;
    }
    if (stringOperationType->compare(OPERATION_REVERSE)) {
        return CalcBrainMathOperationTypeReverse;
    }
    if (stringOperationType->compare(OPERATION_PERCENT)) {
        return CalcBrainMathOperationTypePercent;
    }
    if (stringOperationType->compare(OPERATION_DEVIDE)) {
        return CalcBrainMathOperationTypeDevide;
    }
    if (stringOperationType->compare(OPERATION_MULTIPLY)) {
        return CalcBrainMathOperationTypeMultiply;
    }
    if (stringOperationType->compare(OPERATION_MINUS)) {
        return CalcBrainMathOperationTypeMinus;
    }
    if (stringOperationType->compare(OPERATION_PLUS)) {
        return CalcBrainMathOperationTypePlus;
    }
    if (stringOperationType->compare(OPERATION_EQUALS)) {
        return CalcBrainMathOperationTypeEquals;
    }
    
    return CalcBrainMathOperationTypeErrorType;
}

std::string* CalcBrainMathOperation::loadString(CalcBrainMathOperationType type) {
    
    switch (type) {
        case CalcBrainMathOperationTypeAC:
            return new std::string(OPERATION_AC);
            break;
        case CalcBrainMathOperationTypeReverse:
            return new std::string(OPERATION_REVERSE);
            break;
        case CalcBrainMathOperationTypePercent:
            return new std::string(OPERATION_PERCENT);
            break;
        case CalcBrainMathOperationTypeDevide:
            return new std::string(OPERATION_DEVIDE);
            break;
        case CalcBrainMathOperationTypeMultiply:
            return new std::string(OPERATION_MULTIPLY);
            break;
        case CalcBrainMathOperationTypeMinus:
            return new std::string(OPERATION_MINUS);
            break;
        case CalcBrainMathOperationTypePlus:
            return new std::string(OPERATION_PLUS);
            break;
        case CalcBrainMathOperationTypeEquals:
            return new std::string(OPERATION_EQUALS);
            break;
        default:
            return new std::string();
            break;
    }
    
    return new std::string();
}


#pragma mark - Constuctors

CalcBrainMathOperation::CalcBrainMathOperation(std::string stringValue):m_stringValue(stringValue) {
    m_operationType = CalcBrainMathOperationTypeErrorType;
    this->commonInit();
}

CalcBrainMathOperation::CalcBrainMathOperation(std::string *stringValue):m_stringValue(*stringValue) {
    m_operationType = CalcBrainMathOperationTypeErrorType;
    this->commonInit();
}

CalcBrainMathOperation::CalcBrainMathOperation(CalcBrainMathOperationType operationType) {
    this->commonInit();
}

#pragma mark - Private

void CalcBrainMathOperation::commonInit() {
   
    if (m_stringValue.empty() &&
        m_operationType != CalcBrainMathOperationTypeErrorType) {
        m_stringValue = *CalcBrainMathOperation::loadString(m_operationType);
    }
    if (!m_stringValue.empty() &&
        m_operationType == CalcBrainMathOperationTypeErrorType) {
        m_operationType = CalcBrainMathOperation::loadOperationType(&m_stringValue);
    }
}

#pragma mark - Public getters

CalcBrainMathOperationType CalcBrainMathOperation::operation() {
    return m_operationType;
}

std::string CalcBrainMathOperation::stringOperation() {
    return m_stringValue;
}



