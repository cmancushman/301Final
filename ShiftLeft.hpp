//
//  Instruction.hpp
//  301Final
//
//  Created by MacBook Air on 4/13/17.
//  Copyright © 2017 Ubord, Inc. All rights reserved.
//
//  Creates a shift left 2 object that shifts the binary input left by 2 bits

#ifndef ShiftLeft_hpp
#define ShiftLeft_hpp

#include <stdio.h>
#include <iostream>
#include <sstream>

#include "BinaryOperation.hpp"

using namespace std;

class ShiftLeft
{
    
private:

    
public:
    // Default constructor
    ShiftLeft();
    
    /*
        Method takes in a 26-bit string that represents a binary number.
        The method shifts the binary number left by 2 and adds 2 additional
        bits. The method returns the modifed 28-bit binary string.
    */
    string shift(string input);
};

#endif /* ShiftLeft_hpp */
