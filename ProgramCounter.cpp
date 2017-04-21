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
    currentAddress = getBinFromHex("0x00040000");
}

//Sets the programCounters address to the input address
void ProgramCounter::setAddress(string address){
    cout << "SETTING PROGRAM COUNTER ADDRESS " << address << endl;
    currentAddress = address;
}

//Retruns the current address
string ProgramCounter::getAddress(){
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> 5bddfa40c9ff1541df57ae548acf1ffbc9f69a46
=======
=======
>>>>>>> b09aa6e4f7111a4dd7aee00810c10587c0962c96

    if (debug)
    {
        cout << "Parser getAddress OUTPUT: " << binaryOperation.getHexFromBin(currentAddress) << endl
            << endl;
    }
<<<<<<< HEAD
=======
    if (debug) cout << "Parser getAddress OUTPUT: " << binaryOperation.getHexFromBin(currentAddress)
     << endl;
>>>>>>> 2cebb9321ded04ec3046f257f367fc6121d01396
=======

<<<<<<< HEAD
<<<<<<< HEAD
=======
    if (debug) cout << "Parser getAddress OUTPUT: " << binaryOperation.getHexFromBin(currentAddress)
     << endl;
>>>>>>> c2e45607c5dfcb563d18e4a84d503466310ed74d
    
>>>>>>> c2e45607c5dfcb563d18e4a84d503466310ed74d
=======

>>>>>>> b09aa6e4f7111a4dd7aee00810c10587c0962c96
    return currentAddress;
}

<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> c2e45607c5dfcb563d18e4a84d503466310ed74d
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
<<<<<<< HEAD
    
=======
void ProgramCounter::setDebug(bool value)
{
    debug = value;
>>>>>>> f0b9ae2f1dfc5530345335fc9e8deafd0f247f40
=======
}

void ProgramCounter::setDebug(bool value)
{
    debug = value;
>>>>>>> c2e45607c5dfcb563d18e4a84d503466310ed74d
}
