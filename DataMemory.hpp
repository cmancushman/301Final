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
using namespace std;

//This class simulates the Data Memory portion of the processor
class DataMemory{
public:
    //Constructor for DataMemory
    DataMemory();
    
    //This method reads in a file
    DataMemory(string file);

    //Declaration for getWord method
    string getWord(string address);

    //Print function
    void print();

    
private:
    
    //Method that gets hexadecimal string from binary string
    string getHexFromBin(string sBinary);
    
    //Method that gets binary string from hexadecimal string
    string getBinFromHex(string sHex);
    
    //Declaration of the dictionary map
    map<string, string> memoryMap;


};

#endif /* DataMemory_hpp */
