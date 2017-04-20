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
    
    void storeWord(string word);
    
    void setCurrentAddress(string address);

    //Print function
    void print();

    void setShouldWrite(bool writeToMemory);
    
    void setShouldRead(bool readFromMemory);

    
    void saveMemory();
    
    string readMemory();
    
private:
    
    bool shouldWrite;
    
    bool shouldRead;

    
    string currentAddress;
    
    string currentWord;
    //Method that gets hexadecimal string from binary string
    string getHexFromBin(string sBinary);
    
    //Method that gets binary string from hexadecimal string
    string getBinFromHex(string sHex);
    
    //Declaration of the dictionary map
    map<string, string> memoryMap;


};

#endif /* DataMemory_hpp */
