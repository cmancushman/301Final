//
//  Instruction.cpp
//  301Final
//
//  Created by MacBook Air on 4/13/17.
//  Copyright © 2017 Ubord, Inc. All rights reserved.
//

#include "Instruction.hpp"
//#include "SignExtend.hpp"
int hexToInt(string hexString);
string intToHex(int integer);


Instruction::Instruction(){
    
}
Instruction::Instruction(string str1, string str2, string str3, string str4){
    component1 = str1;
    component2 = str2;
    component3 = str3;
    component4 = str4;
    
    str1.erase(std::remove(str1.begin(), str1.end(), '$'), str1.end());
    str2.erase(std::remove(str2.begin(), str2.end(), '$'), str2.end());
    str3.erase(std::remove(str3.begin(), str3.end(), '$'), str3.end());
    str4.erase(std::remove(str4.begin(), str4.end(), '$'), str4.end());


    opcode = str1;

    
    if(component1 == "add"){
        rd = str2;
        rs = str3;
        rt = str4;
    }else if(component1 == "sub"){
        rd = str2;
        rs = str3;
        rt = str4;
    }else if(component1 == "addi"){
        std::string s = std::bitset< 16 >( stoi(str4) ).to_string(); // string conversion
        immediate = s;
        
        rs = str3;
        rt = str2;
        //cout << "bit test " << s << endl;
        
    }else if(component1 == "slt"){
        
        rd = str2;
        rs = str3;
        rt = str4;
    }else if(component1 == "lw"){
        
        
        std::string s = std::bitset< 16 >( stoi(str3)  ).to_string(); // string conversion
        
        immediate = s;
        
        rt = str2;
        rs = str4;
        
        //cout <<"bit test " << s << endl;
        
        
    }else if(component1 == "sw"){
        
        std::string s = std::bitset< 16 >( stoi(str3)  ).to_string(); // string conversion
        immediate = s;
        
        rt = str2;
        rs = str4;
        
        //cout <<"bit test " << s << endl;
    }else if(component1 == "beq"){
        if(str4.find("0x") == std::string::npos){
            str4 = "0x" + str4;
        }
        
        string s = str4;
        stringstream ss;
        ss << hex << s;
        unsigned n;
        ss >> n;
        bitset<16> b(n);
        // outputs "00000000000000000000000000001010"
        //cout << "Test bits " << b.to_string() << endl;
        immediate = b.to_string();
        //SignExtend ext = SignExtend();
        //cout << "Sign extend " << ext.extend(b.to_string()) << endl;
        
        rs = str2;
        rt = str3;
        
    }else if(component1 == "j"){
        
        if(str2.find("0x") == std::string::npos){
            str2 = "0x" + str2;
        }
        
        string s = str2;
        stringstream ss;
        ss << hex << s;
        unsigned n;
        ss >> n;
        bitset<26> b(n);
        // outputs "00000000000000000000000000001010"
        //cout << "Test bits " << b.to_string() << endl;
        jumpComponent = b.to_string();
        
        
       // cout << "hex:" << component2 << " to int: " << hexToInt(component2) << endl;
        
        //cout << "int:" << hexToInt(component2) << " to hex: " << intToHex(hexToInt(component2)) << endl;
        
        
        
    }
    
}

int Instruction::hexToInt(string hexString){
    unsigned int x;
    stringstream ss;
    ss << std::hex << hexString;
    ss >> x;
    return x;
}
string Instruction::intToHex(int integer){
    char output[100];
    sprintf(output, "%08x", integer);
    string result = output;
    result = "0x" + result;
    return result;
}

string Instruction::getOpcode(){
    return opcode;
}
string Instruction::getRs(){
    return rs;
}
string Instruction::getRd(){
    return rd;
}
string Instruction::getRt(){
    return rt;
}
string Instruction::getJumpAmount(){
    return jumpComponent;
}
string Instruction::getImmediate(){
    return immediate;
}

void Instruction::print(){
    cout << component1 << " " << component2 << " "  << component3 << " "  << component4 << " "  << endl;
    
}
