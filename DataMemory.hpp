//
//  DataMemory.hpp
//  301Final
//
//  Created by MacBook Air on 4/13/17.
//  Copyright © 2017 Ubord, Inc. All rights reserved.
//

#ifndef DataMemory_hpp
#define DataMemory_hpp

#include <stdio.h>
#include <map>
#include <sstream>
#include <iostream>
#include <fstream>
#include <iterator>
using namespace std;

//This class simulates the Data Memory portion of the processor
class DataMemory{
public:
    //Constructor for DataMemory
    DataMemory();
    
    //This method reads in a file
    DataMemory(string file);

    //This method sets the file
    void setFile(string file);

    //Declaration for getWord method
    string getWord(string address);
    
    //This method intakes a string called word and sets the currentWord variable equal to a hexadecimal number
    void storeWord(string word);
    
    //This method intakes a string called address and sets the currentAddress variable equal to a hexadecimal number
    void setCurrentAddress(string address);

    //Print function
    void print();

    //This method intakes a boolen called writeToMemory and determines whether or not it can be overwritten
    void setShouldWrite(bool writeToMemory);
    
    //This method intakes a boolen called readFromMemory and determines whether or not it can be read
    void setShouldRead(bool readFromMemory);

    //This method saves the memory address by setting the currentWord hex number to the address of the memory map
    void saveMemory();
    
    //This method reads the memory address by returning the hex value assocaiated with the memory map key and outputting that hex string
    string readMemory();
    
    void setDebug(bool value);

    //void setOfStream(ofstream& out);
    
    void setToFile(bool val);
    void setFile(bool val);

    string getAllPairs();
    
private:
    
    //ofstream ofile;
    
    bool tofile;
    
    bool shouldWrite;
    
    bool shouldRead;

    //a string called currentAddress
    string currentAddress;
    
    //a string called currentWord
    string currentWord;

    //Method that gets hexadecimal string from binary string
    string getHexFromBin(string sBinary);
    
    //Method that gets binary string from hexadecimal string
    string getBinFromHex(string sHex);
    
    //Declaration of the dictionary map
    map<string, string> memoryMap;
    
    bool debug;

    bool output;


};

#endif /* DataMemory_hpp */
