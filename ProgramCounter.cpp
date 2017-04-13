//
//  ProgramCounter.cpp
//  301Final
//
//  Created by MacBook Air on 4/13/17.
//  Copyright © 2017 Ubord, Inc. All rights reserved.
//

#include "ProgramCounter.hpp"



ProgramCounter::ProgramCounter(){
    currentAddress = 0;
}

void ProgramCounter::increment(){
    currentAddress +=4;
}

void ProgramCounter::jump(double amount){
    currentAddress += amount;
}

void ProgramCounter::branch(double amount){
    currentAddress += amount;
}
