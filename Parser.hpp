//
//  Parser.hpp
//  301Final
//
//  Created by MacBook Air on 4/12/17.
//  Copyright © 2017 Ubord, Inc. All rights reserved.
//

#ifndef Parser_hpp
#define Parser_hpp

#include <stdio.h>
#include <fstream>
#include <iostream>
#include <algorithm>

using namespace std;
class Parser{
public:
    Parser();
    
    Parser(string file);
    
    void setFile(string file);
    
    void executeInstruction(string stringArray[]);
};
#endif /* Parser_hpp */
