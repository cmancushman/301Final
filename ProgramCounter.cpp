//
//  ProgramCounter.cpp
//  301Final
//
//  Created by MacBook Air on 4/13/17.
//  Copyright © 2017 Ubord, Inc. All rights reserved.
//


#include "ProgramCounter.hpp"



ProgramCounter::ProgramCounter(){
    currentAddress = getBinFromHex("0x00040000");
}

void ProgramCounter::setAddress(string address){
    cout << "SETTING PROGRAM COUNTER ADDRESS " << address << endl;
    currentAddress = address;
}

string ProgramCounter::getAddress(){
<<<<<<< HEAD
=======

>>>>>>> c2e45607c5dfcb563d18e4a84d503466310ed74d
    if (debug)
    {
        cout << "Parser getAddress OUTPUT: " << binaryOperation.getHexFromBin(currentAddress) << endl
            << endl;
    }

<<<<<<< HEAD
=======
    if (debug) cout << "Parser getAddress OUTPUT: " << binaryOperation.getHexFromBin(currentAddress)
     << endl;
    
>>>>>>> c2e45607c5dfcb563d18e4a84d503466310ed74d
    return currentAddress;
}

string ProgramCounter::getBinFromHex(string sHex)
{
    string s = sHex;
    stringstream ss;
    ss << std::hex << s;
    unsigned n;
    ss >> n;
    bitset<32> b(n);
    //cout << "Test Return Hex " << b.to_string() << endl;
    
    return b.to_string();
}
<<<<<<< HEAD
=======
    
>>>>>>> c2e45607c5dfcb563d18e4a84d503466310ed74d
void ProgramCounter::setDebug(bool value)
{
    debug = value;
}
