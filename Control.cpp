//
//  Control.cpp
//  301Final
//
//  Created by MacBook Air on 4/13/17.
//  Copyright © 2017 Ubord, Inc. All rights reserved.
//

#include "Control.hpp"

Control::Control(){
    
}

bool Control::isBranch(){
    return branch;
}

//This method sets the components of the registers, data memory, and multiplexor
void Control::setComponents(Registers *reg, DataMemory *mem, ALU *alu, Multiplexer *regMult, Multiplexer *regImm, Multiplexer *memALU, Multiplexer *jumpInc){
    registerFile = reg;
    memoryUnit = mem;
    aluToMemory = alu;
    registerMultiplexer = regMult;
    registerOrImmediateMultiplexer = regImm;
    memoryOrALUMultiplexer = memALU;
    jumpOrIncrementMultiplexer = jumpInc;
    
    
    aluControl.setALU(aluToMemory);
}

//Sends control signals to each processor component in accordance to what is required by the opcode
void Control::sendSignals(string opcode){
    
    cout << "OPCODE : " << opcode << endl;
    if (debug) cout <<"ADJUSTING REGISTER MULTIPLEXER CONTROL" << endl;
    regDst = (opcode == "add" || opcode == "sub" || opcode == "slt");
    cout << "regDst " << "0x" << regDst << endl;

    registerMultiplexer->setControl(regDst);
    cout << endl;
    
    if (debug) cout <<"ADJUSTING JUMP MULTIPLEXER CONTROL" << endl;
    jump = (opcode == "j");
    jumpOrIncrementMultiplexer->setControl(jump);
    cout << "jump " << "0x" << jump << endl;
    
    if (debug) cout <<"ADJUSTING MEMORY READ" << endl;
    memRead = (opcode == "lw");
    memoryUnit->setShouldRead(memRead);
    cout << "memRead " << "0x" << memRead << endl;
    
    if (debug) cout <<"ADJUSTING MEMORY WRITE" << endl;
    memWrite = (opcode == "sw");
    memoryUnit->setShouldWrite(memWrite);
    cout << endl;
    cout << "memWrite " << "0x" << memWrite << endl;
    
    if (debug) cout <<"ADJUSTING MEMORY VS ALU MULTIPLEXER" << endl;
    memToReg = (opcode == "lw");
    memoryOrALUMultiplexer->setControl(memToReg);
    cout << "memToReg " << "0x" << memToReg << endl;
    cout << endl;
    
    if (debug) cout <<"ADJUSTING REGISTER VS IMMEDIATE MULTIPLEXER" << endl;
    
    aluSRC = (opcode == "addi" || opcode == "lw" || opcode == "sw");
    
    registerOrImmediateMultiplexer->setControl(aluSRC);
    cout << "aluSRC " << "0x" << aluSRC << endl;
    cout << endl;
    
    if (debug) cout <<"ADJUSTING REGISTER WRITE" << endl;
    
    regWrite = (opcode == "add" || opcode == "addi" || opcode == "lw" || opcode == "slt" || opcode == "sub");
    registerFile->setWrite(regWrite);
    cout << "regWrite " << "0x" << regWrite << endl;

    cout << endl;
    
    branch = (opcode == "beq");
    cout << "branch " << "0x" << branch << endl;
    
    
    ALUOp1 = (opcode == "add" || opcode == "sub" || opcode == "slt" || opcode == "addi");
    cout << "ALUOp1 " << "0x" << ALUOp1 << endl;

    ALUOp0 = (opcode == "beq");
    cout << "ALUOp0 " << "0x" << ALUOp0 << endl;
    
    if(opcode == "beq"){
        aluControl.sendSignals("00");
    }else if(opcode == "add" || opcode == "addi" || opcode == "lw" || opcode == "sw"){
        aluControl.sendSignals("01");
    }else if(opcode == "sub"){
        aluControl.sendSignals("10");
    }else if(opcode == "slt"){
        aluControl.sendSignals("11");
    }

    cout << "Signal for beq: " << getHexFromBin("00") << endl; 
    cout << "Signal for add, addi, lw, sw: " << getHexFromBin("01") << endl;
    cout << "Signal for sub: " << getHexFromBin("10") << endl;
    cout << "Signal for slt: " << getHexFromBin("11") << endl;
}

//This method is for converting binary string to hexadecmial values
//It receives a binary string and returns a hexadecimal string
string Control::getHexFromBin(string sBinary)
{
    if(sBinary != ""){
        std::stringstream ss;
        ss << std::hex << std::stoll(sBinary, NULL, 2);
        //std::cout <<"hex test " << ss.str() << std::endl;
        
        string s =  ss.str();
        while (s.length() != 8){
            s = "0" + s;
        }
        s = "0x" + s;
        return s;
    }else{
        return "0x";
    }
}

void Control::setDebug(bool value){
    debug = value;
}




//add  - destination is rd
//addi - rt
//lw   - rt
//sw   - rt
//slt  - rd
