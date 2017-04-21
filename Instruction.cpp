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

//This method intakes 4 string values and determines what kind of instruction it is
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

    //This if statement runs if the instruction is "add" and sets rd, rs, and rt to str2, str3, and str4 respectively
    if(component1 == "add"){
        rd = str2;
        rs = str3;
        rt = str4;
    }

    //This if statement runs if the instruction is "sub" and sets rd, rs, and rt to str2, str3, and str4 respectively
    else if(component1 == "sub"){
        rd = str2;
        rs = str3;
        rt = str4;
    }

    //This if statement runs if the instruction is "addi" and sets immediate, rs, and rt to s, str3, and str2 respectively
    else if(component1 == "addi"){
        std::string s = std::bitset< 16 >( stoi(str4) ).to_string(); // string conversion
        immediate = s;
        
        rs = str3;
        rt = str2;
        //cout << "bit test " << s << endl;
        
    }

    //This if statement runs if the instruction is "slt" and sets rd, rs, and rt to str2, str3, and str4 respectively
    else if(component1 == "slt"){
        
        rd = str2;
        rs = str3;
        rt = str4;
    }

    //This if statement runs if the instruction is "lw" and sets rd, rs, and rt to str2, str3, and str4 respectively
    else if(component1 == "lw"){
        
        
        std::string s = std::bitset< 16 >( stoi(str3)  ).to_string(); // string conversion
        
        immediate = s;
        
        rt = str2;
        rs = str4;
        
        //cout <<"bit test " << s << endl;
        
        
    }

    //This if statement runs if the instruction is "sw" and sets immediate, rt, and rs to s, str2, and str4 respectively
    else if(component1 == "sw"){
        
        std::string s = std::bitset< 16 >( stoi(str3)  ).to_string(); // string conversion
        immediate = s;
        
        rt = str2;
        rs = str4;
        
        //cout <<"bit test " << s << endl;
    }

    //This if statement runs if the instruction is "beq" and sets s, rs, and rt to str4, str2, and str3 respectively and converts
    //immediate to a binary string
    else if(component1 == "beq"){
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
        
    }

    //This if statement runs if the instruction is "j" and sets s to str2 and converts it to a binary string
    else if(component1 == "j"){
        
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

//This method converts a hexadecimal string to an integer
int Instruction::hexToInt(string hexString){
    unsigned int x;
    stringstream ss;
    ss << std::hex << hexString;
    ss >> x;
    return x;
}

//This method converts an integer to a hexadecimal string
string Instruction::intToHex(int integer){
    char output[100];
    sprintf(output, "%08x", integer);
    string result = output;
    result = "0x" + result;
    return result;
}

//This method returns the opcode
string Instruction::getOpcode(){
    return opcode;
}

//This method returns the rs
string Instruction::getRs(){
    return rs;
}

//This method returns the rd
string Instruction::getRd(){
    return rd;
}

//This method returns the rt
string Instruction::getRt(){
    return rt;
}

//This method returns the jumpComponent
string Instruction::getJumpAmount(){
    return jumpComponent;
}

//This method returns the immediate
string Instruction::getImmediate(){
    return immediate;
}

void Instruction::print(){
    cout << component1 << " " << component2 << " "  << component3 << " "  << component4 << " "  << endl;
    
}
