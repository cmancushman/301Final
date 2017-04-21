//
//  ProgramCounter.cpp
//  301Final
//
//  Created by MacBook Air on 4/13/17.
//  Copyright © 2017 Ubord, Inc. All rights reserved.
//


#include "ProgramCounter.hpp"


//Constructor that sets the currentAddress equal to a string of 0's
ProgramCounter::ProgramCounter(){
    currentAddress = "00000000000000000000000000000000";
}

//Sets the programCounters address to the input address
void ProgramCounter::setAddress(string address){
    currentAddress = address;
}

//Retruns the current address
string ProgramCounter::getAddress(){
    cout << "Parser getAddress OUTPUT: " << binaryOperation.getHexFromBin(currentAddress) << endl
        << endl;
    
    return currentAddress;
}

