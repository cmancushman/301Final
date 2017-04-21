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
    cout << "SETTING PROGRAM COUNTER ADDRESS " << binaryOperation.getHexFromBin(address) << endl;
    currentAddress = address;
}

//Retruns the current address
string ProgramCounter::getAddress(){
   if (debug)
    {
        cout << "Parser getAddress OUTPUT: " << binaryOperation.getHexFromBin(currentAddress) << endl
            << endl;
    }
<<<<<<< HEAD
<<<<<<< HEAD
=======
    if (debug) cout << "Parser getAddress OUTPUT: " << binaryOperation.getHexFromBin(currentAddress)
     << endl;
>>>>>>> 2cebb9321ded04ec3046f257f367fc6121d01396
=======

<<<<<<< HEAD
    if (debug) cout << "Parser getAddress OUTPUT: " << binaryOperation.getHexFromBin(currentAddress)
     << endl;
    
=======
<<<<<<< HEAD
<<<<<<< HEAD
=======
    if (debug) cout << "Parser getAddress OUTPUT: " << binaryOperation.getHexFromBin(currentAddress)
     << endl;
>>>>>>> c2e45607c5dfcb563d18e4a84d503466310ed74d
    
>>>>>>> c2e45607c5dfcb563d18e4a84d503466310ed74d
=======
>>>>>>> 9db97d8ba24fb96a60bc18548d26eac4269c2dc3
=======
>>>>>>> 2b49359dc14acf92151d6d4337a3726dfed0832c

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
void ProgramCounter::setDebug(bool value)
{
    debug = value;
}
