//
//  Control.hpp
//  301Final
//
//  Created by MacBook Air on 4/13/17.
//  Copyright © 2017 Ubord, Inc. All rights reserved.
//

#ifndef Control_hpp
#define Control_hpp

#include <stdio.h>
#include "Instruction.hpp"
#include "Registers.hpp"
#include "ALU.hpp"
#include "DataMemory.hpp"
#include "Instruction.hpp"
#include "Multiplexer.hpp"
#include "ProgramCounter.hpp"
#include "ALUControl.hpp"

class Control{
private:
    
    Registers *registerFile;
    DataMemory *memoryUnit;
    ALU *aluToMemory;
    ALUControl aluControl;
    Multiplexer *registerMultiplexer;
    Multiplexer *registerOrImmediateMultiplexer;
    Multiplexer *memoryOrALUMultiplexer;
    //Multiplexer branchOrIncrementMultiplexer;
    Multiplexer *jumpOrIncrementMultiplexer;

    
    bool branch;
    bool jump;
    bool memToReg;
    bool memRead;
    bool memWrite;
    bool aluSRC;
    bool regWrite;
    bool regDst;
    
    string aluOP;
    
    
    Instruction instruction;
    
    bool debug;
    
public:
    
    Control();
    
    // Checks if the instruction is a branch
    bool isBranch();
    
    // Sets the components of the processor
    void setComponents(Registers *reg, DataMemory *mem, ALU *alu, Multiplexer *regMult, Multiplexer *regImm, Multiplexer *memALU, Multiplexer *jumpInc);
    
    /*
     * Sends control signals to each processor component in accordance to what is required by
     * the opcode
     */
    void sendSignals(string opCode);
    
    void setDebug(bool value);
};
#endif /* Control_hpp */
