//
//  Registers.hpp
//  301Final
//
//  Created by MacBook Air on 4/13/17.
//  Copyright © 2017 Ubord, Inc. All rights reserved.
//

#ifndef Registers_hpp
#define Registers_hpp

#include <stdio.h>
#include "LinkedList.h"
#include <iostream>

using namespace std;
class Registers{
private:

    
    //This is the declaration of a linked list of strings
    LinkedList<string> wordListCompare1;
    
    string writeIndex;
    
    string writeValue;
    
    bool shouldWrite;
    
    string getHexFromBin(string sBinary);
    
    string getBinFromHex(string sHex);
    
    string readRegister1;
    
    string readRegister2;

public:
    //This is the constructor for the Register() function
    Registers();

    //This method reads in a file
    Registers(string file);
    
    //This method sets the value of the index and the value of a string
    void setWriteIndex(string value);
    
    void setWriteValue(string value);
    
    //This method gets the value of the readRegister1
    string getReadRegister1();
    
    //This method gets the value of the readRegister2
    string getReadRegister2();


    //This method sets the value of the readRegister1
    void setReadRegister1(string registerNumber);
    
    //This method sets the value of the readRegister2
    void setReadRegister2(string registerNumber);
    
    
    
    void setWrite(bool write);
    
    void write();
    
    //This method prints out the register number
    void print();

    void init();
    
    
    

};
#endif /* Registers_hpp */
