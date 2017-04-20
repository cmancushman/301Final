//
//  Control.cpp
//  301Final
//
//  Created by MacBook Air on 4/13/17.
//  Copyright © 2017 Ubord, Inc. All rights reserved.
//

#include "ALUControl.hpp"

ALUControl::ALUControl(){
    
}

void ALUControl::setALU(ALU *alu){
    
}



void Control::sendSignals(string opcode){
    cout <<"ADJUSTING REGISTER MULTIPLEXER CONTROL" << endl;
    regDst = (opcode == "add" || opcode == "sub" || opcode == "addi" || opcode == "slt");
    registerMultiplexer->setControl(regDst);
    cout << endl;
    
    cout <<"ADJUSTING JUMP MULTIPLEXER CONTROL" << endl;
    jump = (opcode == "jump");
    jumpOrIncrementMultiplexer->setControl(jump);
    cout << endl;
    
    cout <<"ADJUSTING MEMORY READ" << endl;
    memRead = (opcode == "lw");
    memoryUnit->setShouldRead(memRead);
    cout << endl;
    
    cout <<"ADJUSTING MEMORY WRITE" << endl;
    memWrite = (opcode == "sw");
    memoryUnit->setShouldWrite(memWrite);
    cout << endl;
    
    cout <<"ADJUSTING MEMORY VS ALU MULTIPLEXER" << endl;
    memToReg = (opcode == "lw");
    memoryOrALUMultiplexer->setControl(memToReg);
    cout << endl;
    
    cout <<"ADJUSTING REGISTER VS IMMEDIATE MULTIPLEXER" << endl;
    aluSRC = (opcode == "addi" || opcode == "lw" || opcode == "sw");
    registerOrImmediateMultiplexer->setControl(aluSRC);
    cout << endl;
    
    cout <<"ADJUSTING REGISTER WRITE" << endl;
    regWrite = (opcode == "add" || opcode == "addi" || opcode == "lw" || opcode == "slt");
    registerFile->setWrite(regWrite);
    cout << endl;
    
}





//add  - destination is rd
//addi - rt
//lw   - rt
//sw   - rt
//slt  - rd
