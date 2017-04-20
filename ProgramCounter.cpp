//
//  ProgramCounter.cpp
//  301Final
//
//  Created by MacBook Air on 4/13/17.
//  Copyright © 2017 Ubord, Inc. All rights reserved.
//


#include "ProgramCounter.hpp"



ProgramCounter::ProgramCounter(){
    std::cout << "asd" << std::endl;
    currentAddress = 0;
}

void ProgramCounter::increment(){
    currentAddress +=4;
}

void ProgramCounter::jump(double amount){
    currentAddress += amount;
}

double ProgramCounter::getAddress(){
    return currentAddress;
}
