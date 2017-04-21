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

void Control::sendSignals(string opcode){
    if (debug) cout <<"ADJUSTING REGISTER MULTIPLEXER CONTROL" << endl;
    regDst = (opcode == "add" || opcode == "sub" || opcode == "addi" || opcode == "slt");
    registerMultiplexer->setControl(regDst);
    cout << endl;
    
    if (debug) cout <<"ADJUSTING JUMP MULTIPLEXER CONTROL" << endl;
    jump = (opcode == "j");
    jumpOrIncrementMultiplexer->setControl(jump);
    cout << endl;
    
    if (debug) cout <<"ADJUSTING MEMORY READ" << endl;
    memRead = (opcode == "lw");
    memoryUnit->setShouldRead(memRead);
    cout << endl;
    
    if (debug) cout <<"ADJUSTING MEMORY WRITE" << endl;
    memWrite = (opcode == "sw");
    memoryUnit->setShouldWrite(memWrite);
    cout << endl;
    
    if (debug) cout <<"ADJUSTING MEMORY VS ALU MULTIPLEXER" << endl;
    memToReg = (opcode == "lw");
    memoryOrALUMultiplexer->setControl(memToReg);
    cout << endl;
    
    if (debug) cout <<"ADJUSTING REGISTER VS IMMEDIATE MULTIPLEXER" << endl;
    aluSRC = (opcode == "addi" || opcode == "lw" || opcode == "sw");
    registerOrImmediateMultiplexer->setControl(aluSRC);
    cout << endl;
    
    if (debug) cout <<"ADJUSTING REGISTER WRITE" << endl;
    regWrite = (opcode == "add" || opcode == "addi" || opcode == "lw" || opcode == "slt");
    registerFile->setWrite(regWrite);
    cout << endl;
    
    if(opcode == "beq"){
        aluControl.sendSignals("00");
    }else if(opcode == "add" || opcode == "addi" || opcode == "lw" || opcode == "sw"){
        aluControl.sendSignals("01");
    }else if(opcode == "sub"){
        aluControl.sendSignals("10");
    }else if(opcode == "slt"){
        aluControl.sendSignals("11");
    }


}





//add  - destination is rd
//addi - rt
//lw   - rt
//sw   - rt
//slt  - rd
