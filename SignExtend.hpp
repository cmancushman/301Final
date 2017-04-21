//
//  SignExtend.hpp
//  
//
//  Created by Alex Christine on 4/18/17.
//
//  Class Creates a signExtender that can be used to turn 16-bit binary inputs to
//  32-bit binary outputs

#ifndef SignExtend_hpp
#define SignExtend_hpp

#include <stdio.h>
#include <iostream>
#include "BinaryOperation.hpp"

using namespace std;

class SignExtend
{
    
private:
    BinaryOperation binaryOperation;
    
public:
    // Constructor
    SignExtend();
    
    /*
        Method takes in an input string that is a representation of a 
        16-bit binary string and translates it into an equivalent
        32-bit binary string. Returns the 32-bit equivalent string.
    */
    string extend(string input);
};
#endif /* SignExtend_hpp */
