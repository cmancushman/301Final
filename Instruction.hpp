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
    

    
    // Op-field: add, jump, etc.
    string opcode;
    
    /*
        compenents hold additional operands for instruction including
        memory addresses, register names, etc.
    */
    string rs;
    string rt;
    string rd;
    
    string component1;
    string component2;
    string component3;
    string component4;

    
    // Immediate field if applicable
    string immediate;
    
    // Jump component if applicable
    string jumpComponent;
    
    //Converts a hexadecimal string to an integer
    int hexToInt(string hexString);
    
    //Converts an integer to a hexadecimal string
    string intToHex(int integer);
    
public:
    
    //Constructor
    Instruction();
    
    /* Constructor with all inputs */
    Instruction(string str1, string str2, string str3, string str4);
    
    /* Returns opcode for instruction */
    string getOpcode();
    
    /* returns component1 */
    string getRs();
    
    /* Returns component2 */
    string getRd();
    
    /* Returns component3 */
    string getRt();
    
    /* Returns jump amount*/
    string getJumpAmount();
    
    /* Returns immediate field */
    string getImmediate();
    
    /* Prints the instruction */
    void print();
    
    string getStringVersion();
};
#endif /* Instruction_hpp */
