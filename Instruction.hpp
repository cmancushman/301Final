//
//  Instruction.hpp
//  301Final
//
//  Created by MacBook Air on 4/13/17.
//  Copyright © 2017 Ubord, Inc. All rights reserved.
//

#ifndef Instruction_hpp
#define Instruction_hpp

#include <stdio.h>
#include <iostream>
#include <sstream>
using namespace std;
class Instruction{
    
private:
    int typeOfInstruction;
    string component1;
    string component2;
    string component3;
    string component4;
    string immediate;
    string jumpComponent;
    
public:
    
    Instruction(string str1, string str2, string str3, string str4);
    string getType();
    string getComponent1();
    string getComponent2();
    string getComponent3();
    string getComponent4();
    string getImmediate();
    void print();
};
#endif /* Instruction_hpp */
