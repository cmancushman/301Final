//
//  Instruction.cpp
//  301Final
//
//  Created by MacBook Air on 4/13/17.
//  Copyright © 2017 Ubord, Inc. All rights reserved.
//

#include "Instruction.hpp"
#include "SignExtend.hpp"
int hexToInt(string hexString);
string intToHex(int integer);
Instruction::Instruction(){
    
}
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
        std::string s = std::bitset< 16 >( stoi(component4) ).to_string(); // string conversion
        immediate = s;
        cout << "bit test " << s << endl;
        
    }else if(component1 == "slt"){
        typeOfInstruction = 3;
    }else if(component1 == "lw"){
        
        typeOfInstruction = 4;
        
        std::string s = std::bitset< 16 >( stoi(component3)  ).to_string(); // string conversion
        
        immediate = s;
        
        cout <<"bit test " << s << endl;
        
        
    }else if(component1 == "sw"){
        typeOfInstruction = 5;
        
        std::string s = std::bitset< 16 >( stoi(component3)  ).to_string(); // string conversion
        immediate = s;
        
        cout <<"bit test " << s << endl;
    }else if(component1 == "beq"){
        typeOfInstruction = 6;
        if(component4.find("0x") == std::string::npos){
            component4 = "0x" + component4;
        }
        
        string s = component4;
        stringstream ss;
        ss << hex << s;
        unsigned n;
        ss >> n;
        bitset<16> b(n);
        // outputs "00000000000000000000000000001010"
        cout << "Test bits " << b.to_string() << endl;
        immediate = b.to_string();
        SignExtend ext = SignExtend();
        cout << "Sign extend " << ext.extend(b.to_string()) << endl;
        
        
    }else if(component1 == "j"){
        typeOfInstruction = 7;
        
        if(component2.find("0x") == std::string::npos){
            component2 = "0x" + component2;
        }
        
        string s = component2;
        stringstream ss;
        ss << hex << s;
        unsigned n;
        ss >> n;
        bitset<26> b(n);
        // outputs "00000000000000000000000000001010"
        cout << "Test bits " << b.to_string() << endl;
        jumpComponent = b.to_string();
        
        
        cout << "hex:" << component2 << " to int: " << hexToInt(component2) << endl;
        
        cout << "int:" << hexToInt(component2) << " to hex: " << intToHex(hexToInt(component2)) << endl;
        
        
        
    }
    
}

int hexToInt(string hexString){
    unsigned int x;
    stringstream ss;
    ss << std::hex << hexString;
    ss >> x;
    return x;
}
string intToHex(int integer){
    char output[100];
    sprintf(output, "%08x", integer);
    string result = output;
    result = "0x" + result;
    return result;
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
    //cout << "Print Separated Instruction:" << endl;
    cout << component1 << " " << component2 << " "  << component3 << " "  << component4 << " "  << endl;
    
}
