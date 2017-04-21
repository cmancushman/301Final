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
#include <fstream>
#include <map>

using namespace std;
class Registers{
private:

    
    //This is the declaration of a linked list of strings
    map<int, string> registerMap;
    
    //Declaration of a string called writeIndex
    string writeIndex;
    
    //Declaration of a string called writeValue
    string writeValue;
    
    //Declaration of a boolean called shouldWrite
    bool shouldWrite;
    
    //This method takes in a binary string, converts the binary to hexadecimal, and outputs a string of hex numbers
    string getHexFromBin(string sBinary);
    
    //This method takes in a binary string, converts the binary to hexadecimal, and outputs a string of hex numbers
    string getBinFromHex(string sHex);
    
    //Declaration of a string called readRegister1
    string readRegister1;
    
    //Declaration of a string called readRegister2
    string readRegister2;

    //variable that determines whether or no debugger is on
    bool debug;
    
    bool toFile;
    //ofstream ofile;

public:
    //This is the constructor for the Register() function
    Registers();

    //This method reads in a file
    Registers(string file);

    //Reads in a file and assigns registers
    void setFile(string file);
    
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
    
    
    //This method intakes a boolean value called write and sets it equal to the value shouldWrite after determining if register memory can be overwritten
    void setWrite(bool write);
    
    //This method gets a hex value from a binary string, and if it should write, it sets the values of the index and the writeValue
    void write();
    
    //This method prints out the register number
    void print();

    //This method pads the string values in the linked list with zeros
    void init();
    
    //Sets the debug instance variable to true
    void setDebug(bool value);
    
    /* Sets toFile to true or false determining if a file is written to */
    void setToFile(bool val);
    
    /* Sets the location of the ostream that will be written to */
    //void setOfStream(ofstream& out);

};
#endif /* Registers_hpp */
