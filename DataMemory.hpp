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
#include <string>
using namespace std;
class DataMemory{
public:
    DataMemory();
    
    DataMemory(string file);


    void getWord(string address);

    void print();
    
private:
    
    string GetHexFromBin(string sBinary);
    
    string GetBinFromHex(string sHex);


};

#endif /* DataMemory_hpp */
