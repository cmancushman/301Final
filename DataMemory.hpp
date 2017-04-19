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
class DataMemory{
public:
    DataMemory();
    
    DataMemory(string file);


    string getWord(string address);

    void print();

    
private:
    
    string getHexFromBin(string sBinary);
    
    string getBinFromHex(string sHex);
    
    map<string, string> memoryMap;


};

#endif /* DataMemory_hpp */
