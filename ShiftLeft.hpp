//
//  Instruction.hpp
//  301Final
//
//  Created by MacBook Air on 4/13/17.
//  Copyright © 2017 Ubord, Inc. All rights reserved.
//

#ifndef ShiftLeft_hpp
#define ShiftLeft_hpp

#include <stdio.h>
#include <iostream>
#include <sstream>
using namespace std;
class Instruction{
    
private:

    
public:
    
    Instruction(string str1, string str2, string str3, string str4);
    string getType();
    string getComponent1();
    string getComponent2();
    string getComponent3();
    string getComponent4();
    void print();
};
#endif /* ShiftLeft_hpp */
