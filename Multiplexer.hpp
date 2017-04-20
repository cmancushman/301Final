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

using namespace std;
class Multiplexer
{
    
private:
    string output;
    
    string control;
    
    string input1;
    
    string input2;
    
public:
    // Default constructor
    Multiplexer();
    
    /*
         Selects an output based on control. If control is true it outputs input1,
         if control is false it outputs input2.
     */
    void setControl(bool newControl);
    
    void setInput1(string input);
    
    void setInput2(string input);
    
    string getOutput();
    
    
};

#endif /* Multiplexer_hpp */
