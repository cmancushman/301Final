//
//  Multiplexer.hpp
//  
//
//  Created by Alex Christine on 4/18/17.
//
// Class creates a 2-to-1 Multiplexer

#ifndef Multiplexer_hpp
#define Multiplexer_hpp

#include <stdio.h>
#include <iostream>
#include "BinaryOperation.hpp"

using namespace std;
class Multiplexer
{
    
private:
    string output;
    
    bool control;
    
    string input0;
    
    string input1;
    
    void execute();
    
    bool debug;
    
public:
    // Default constructor
    BinaryOperation binaryOperation;
    
    Multiplexer();
    
    /*
         Selects an output based on control. If control is true it outputs input1,
         if control is false it outputs input2.
     */
    void setControl(bool newControl);
    
    void setInput0(string input);
    
    void setInput1(string input);
    
    string getOutput();
    
    /* Sets debug to true or false controlling print statements */
    void setDebug(bool debug);
};

#endif /* Multiplexer_hpp */
