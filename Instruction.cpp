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
    
    if(component1 == "add"){
        typeOfInstruction = 0;
    }else if(component1 == "sub"){
        typeOfInstruction = 1;
    }else if(component1 == "addi"){
        typeOfInstruction = 2;
    }else if(component1 == "slt"){
        typeOfInstruction = 3;
    }else if(component1 == "lw"){
        typeOfInstruction = 4;
    }else if(component1 == "sw"){
        typeOfInstruction = 5;
    }else if(component1 == "beq"){
        typeOfInstruction = 6;
    }else if(component1 == "j"){
        typeOfInstruction = 7;
    }
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
