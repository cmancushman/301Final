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

#include "ALU.hpp"


class Control{
private:
    

    ALU *aluToMemory;

    
    string aluOP;
    
    
    Instruction instruction;
    
public:
    
    Control();
    
    bool isBranch();
    
    //void set
    void setComponents(Registers *reg, DataMemory *mem, ALU *alu, Multiplexer *regMult, Multiplexer *regImm, Multiplexer *memALU, Multiplexer *jumpInc);
    void sendSignals(string opCode);
    
};
#endif /* Control_hpp */
