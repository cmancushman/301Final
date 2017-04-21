//
//  ProgramCounter.cpp
//  301Final
//
//  Created by MacBook Air on 4/13/17.
//  Copyright © 2017 Ubord, Inc. All rights reserved.
//


#include "ProgramCounter.hpp"



ProgramCounter::ProgramCounter(){
    currentAddress = "00000000000000000000000000000000";
}

void ProgramCounter::setAddress(string address){
    currentAddress = address;
}

string ProgramCounter::getAddress(){
    cout << "Parser getAddress OUTPUT: " << binaryOperation.getHexFromBin(currentAddress) << endl
        << endl;
    
    return currentAddress;
}

