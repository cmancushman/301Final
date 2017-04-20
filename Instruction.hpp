//
//  Instruction.hpp
//  301Final
//
//  Created by MacBook Air on 4/13/17.
//  Copyright © 2017 Ubord, Inc. All rights reserved.
//

#ifndef Instruction_hpp
#define Instruction_hpp

#include <stdio.h>
#include <iostream>
#include <sstream>
using namespace std;

//This class simulates the Instruction component of the processor, determining the register names, operands and 
//op-fields, and instruction type
class Instruction{
    
private:
    
    // Specifies J, R, or I-Type
    int typeOfInstruction;
    
    // Op-field: add, jump, etc.
    string component1;
    
    /*
        compenents hold additional operands for instruction including
        memory addresses, register names, etc.
    */
    string component2;
    string component3;
    string component4;
    
    // Immediate field if applicable
    string immediate;
    
    // Jump component if applicable
    string jumpComponent;
    
public:
    
    Instruction();
    
    /* Constructor with all inputs */
    Instruction(string str1, string str2, string str3, string str4);
    
    /* Returns instruction type */
    string getType();
    
    /* returns component1 */
    string getComponent1();
    
    /* Returns component2 */
    string getComponent2();
    
    /* Returns component3 */
    string getComponent3();
    
    /* Returns component4 */
    string getComponent4();
    
    /* Returns immediate field */
    string getImmediate();
    
    /* Prints the instruction */
    void print();
};
#endif /* Instruction_hpp */
