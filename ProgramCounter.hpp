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

class ProgramCounter{
private:
    double currentAddress;
    
public:
    
    /* Constructor for program counter */
    ProgramCounter();
    
    
    /* Jump to a given address */
    void jump(double amount);
    
    /* Increment by 4 */
    void increment();
    
    /* Retruns the current address */
    double getAddress();
    
};



#endif /* ProgramCounter_hpp */
