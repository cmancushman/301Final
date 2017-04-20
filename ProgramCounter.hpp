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

using namespace std;
class ProgramCounter{
private:
    string currentAddress;
    
public:
    
    /* Constructor for program counter */
    ProgramCounter();
    
    
    void setAddress(string address);
    
    /* Retruns the current address */
    string getAddress();
    
};



#endif /* ProgramCounter_hpp */
