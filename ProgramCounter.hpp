//
//  ProgramCounter.hpp
//  301Final
//
//  Created by MacBook Air on 4/13/17.
//  Copyright © 2017 Ubord, Inc. All rights reserved.
//
//  Creates a program counter object to be used in the Process simulator

#ifndef ProgramCounter_hpp
#define ProgramCounter_hpp

#include <stdio.h>
#include <iostream>
#include "BinaryOperation.hpp"

using namespace std;
class ProgramCounter{
private:
    string currentAddress;
    BinaryOperation binaryOperation;
    bool debug;
    
public:
    
    /* Constructor for program counter */
    ProgramCounter();
    
    /* Sets the programCounters address to the input address */
    void setAddress(string address);
    
    /* Retruns the current address */
    string getAddress();
    
    /* Sets debug to true or false controlling print statements */
    void setDebug(bool debug);
};



#endif /* ProgramCounter_hpp */
