//
//  Parser.hpp
//  301Final
//
//  Created by MacBook Air on 4/12/17.
//  Copyright © 2017 Ubord, Inc. All rights reserved.
//
//  Reads in the information from the input file

#ifndef Parser_hpp
#define Parser_hpp

#include <stdio.h>
#include <fstream>
#include <iostream>
#include <algorithm>
#include "Instruction.hpp"
#include "LinkedList.h"
using namespace std;
class Parser{
    
private:
    
    
    /* Returns an instruction from input stringArray */
    Instruction toInstruction(string stringArray[]);
    
    /* List of instructions */
    LinkedList<Instruction>  instructionList;

    string check;
    
    //This method intakes a string of hexadecimal and converts it to an integer and outputs it
    int hexToInt(string hexString);
    
    //This method intakes a string of binaries, converts it to a hexadecimal number, and outputs the string of hex numbers
    string getHexFromBin(string sBinary);
    
    bool debug;
    
public:
    
    /* Default Constructor */
    Parser();
    
    /* Constructor that takes a string fileName */
    Parser(string file);
    
    /* Sets the file to input string "file" */
    void setFile(string file);
    
    /* Returns the instruction at index */
    Instruction getInstruction(string binaryIndex);
    
    /* Prints all the instructions of the instance */
    void printAllInstructions();

    
    void setDebug(bool value);
    
    int getNumberOfInstructions();

};
#endif /* Parser_hpp */
