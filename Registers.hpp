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
class Registers{
private:

    
    //This is the declaration of a linked list of strings
    LinkedList<string> wordListCompare1;
    
    int writeIndex;
    
    string writeValue;
    
    bool shouldWrite;
    
    string getHexFromBin(string sBinary);
    
    string getBinFromHex(string sHex);

public:
    //This is the constructor for the Register() function
    Registers();

    //This method reads in a file
    Registers(string file);
    
    //This method sets the value of the index and the value of a string
    void setWriteIndex(string value);
    
    void setWriteValue(string value);
    //This method gets the value of the index of the register
    string getRegister(int index);
    
    void setWrite(bool write);
    
    void write();
    
    //This method prints out the register number
    void print();

    void init();
    
    
    

};
#endif /* Registers_hpp */
