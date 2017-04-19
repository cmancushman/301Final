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

class DataMemory{
public:
    DataMemory();
    
    DataMemory(string file);

    GetHexFromBin(string sBinary);

    Mapping(string rest);

    GetBinFromHex(string sHex);

    print();
};

#endif /* DataMemory_hpp */