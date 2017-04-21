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
    if (debug)
    {
        cout << "Parser getAddress OUTPUT: " << binaryOperation.getHexFromBin(currentAddress) << endl
            << endl;
    }
=======
    if (debug) cout << "Parser getAddress OUTPUT: " << binaryOperation.getHexFromBin(currentAddress)
     << endl;
>>>>>>> 2cebb9321ded04ec3046f257f367fc6121d01396
    
    return currentAddress;
}

<<<<<<< HEAD
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
    
=======
void ProgramCounter::setDebug(bool value)
{
    debug = value;
>>>>>>> f0b9ae2f1dfc5530345335fc9e8deafd0f247f40
}
