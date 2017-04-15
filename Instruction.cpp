//
//  Instruction.cpp
//  301Final
//
//  Created by MacBook Air on 4/13/17.
//  Copyright © 2017 Ubord, Inc. All rights reserved.
//

#include "Instruction.hpp"


Instruction::Instruction(string str1, string str2, string str3, string str4){
    component1 = str1;
    component2 = str2;
    component3 = str3;
    component4 = str4;
}

string Instruction::getComponent1(){
    return component1;
}

string Instruction::getComponent2(){
    return component2;
}

string Instruction::getComponent3(){
    return component3;
}

string Instruction::getComponent4(){
    return component4;
}

void Instruction::print(){
    cout << "Print Separated Instruction:" << endl;
    cout << component1 << endl << component2 << endl << component3 << endl << component4 << endl << endl;
    
}
