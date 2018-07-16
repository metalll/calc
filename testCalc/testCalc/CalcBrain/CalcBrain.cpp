//
//  CalcBrain.cpp
//  testCalc
//
//  Created by MacOS on 15.07.2018.
//  Copyright © 2018 MacOS. All rights reserved.
//

#include <regex>
#include <string>
#include <iostream>
#include <string>

#include "ICalcBrainDelegate.h"
#include "CalcBrain.hpp"
#include "CalcBrainMathOperation.hpp"

#pragma mark - Constants

const std::string DOUBLE_CHECK_REGEX = "[+-]?\\d+\\.?(\\d+)?";

const std::string DOT_OPERAND = ".";

#pragma mark - Constructor

CalcBrain::CalcBrain(ICalcBrainDelegate *delegate):m_delegate(delegate),m_accumulator(0) {
}

#pragma mark - Public

void CalcBrain::inputCommand(std::string *command) {
    std::regex doubleCheck(DOUBLE_CHECK_REGEX);
    
    this->updateUI();
    
    if (std::regex_match(*command,doubleCheck)) {
        this->setOperand(command);
        return;
    }
    if (CalcBrainMathOperation::isValidOperation(command)) {
        this->performOperation(new CalcBrainMathOperation(command));
        return;
    }
}

#pragma mark - Protected

void CalcBrain::setOperand(std::string *operand) {
    std::string::size_type size;
    double doubleOperand = std::stod(*(this->safeOperand(operand)),&size);
    if (m_accumulator == 0) {
        m_accumulator = doubleOperand;
    }
    m_lastUsedOperand = doubleOperand;
    this->updateUI();
}

void CalcBrain::performOperation(CalcBrainMathOperation *operation) {
    
    switch (operation->operation()) {
        case CalcBrainMathOperationTypeAC:
            this->resetBrain();
            break;
        case CalcBrainMathOperationTypeReverse:
            this->reveseBrain();
            break;
        case CalcBrainMathOperationTypePercent:
            this->percentBrain();
            break;
        case CalcBrainMathOperationTypeDevide:
            this->devideBrain();
            break;
        case CalcBrainMathOperationTypeMultiply:
            this->multiplyBrain();
            break;
        case CalcBrainMathOperationTypeMinus:
            this->minusBrain();
            break;
        case CalcBrainMathOperationTypePlus:
            this->plusBrain();
            break;
        case CalcBrainMathOperationTypeEquals:
            this->equalsBrain();
            break;
        case CalcBrainMathOperationTypeErrorType:
            
            break;
    }
}

#pragma mark - Private Logic

void CalcBrain::resetBrain() {
    m_accumulator = 0;
    m_lastUsedOperand = 0;
    m_operation = nullptr;
}

void CalcBrain::reveseBrain() {
    this->m_operation = new CalcBrainMathOperation(OPERATION_REVERSE);
}

void CalcBrain::percentBrain() {
    m_accumulator /= 100;
    this->updateUI();
}

void CalcBrain::devideBrain() {
    if (m_lastUsedOperand != 0) {
        m_accumulator = m_accumulator / m_lastUsedOperand;
        this->updateUI();
    }
}

void CalcBrain::multiplyBrain() {
    
}

void CalcBrain::minusBrain() {
    
}

void CalcBrain::plusBrain() {
    
}

void CalcBrain::equalsBrain() {
    
}

void CalcBrain::updateUI() {
    this->m_delegate->renderResult(new std::string(std::to_string(m_accumulator)));
}

std::string* CalcBrain::safeOperand(std::string *operand) {
    if (operand->compare(DOT_OPERAND)) {
        return new std::string("0.0");
    }
    return operand;
}
