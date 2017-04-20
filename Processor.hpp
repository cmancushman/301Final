//
//  Processor.hpp
//  301Final
//
//  Created by MacBook Air on 4/13/17.
//  Copyright © 2017 Ubord, Inc. All rights reserved.
//

#ifndef Processor.hpp
#define Processor.hpp

#include <stdio.h>
#include <iostream>
#include "Parser.hpp"
#include "Registers.hpp"
#include "ProgramCounter.hpp"
#include "DataMemory.hpp"
#include "ALU.hpp"
#include "Multiplexor.hpp"

class Processor{
private:

    Instruction currentInstruction;
    DataMemory memoryUnit;
    Registers registerFile;
    Parser parse;
    ALU registerALU;
    
public:
    
    /* Constructor for program counter */
    ProgramCounter();
    
    
    /* Jump to a given address */
    void jump(double amount);
    
    /* Increment by 4 */
    void increment();
    
    /* Retruns the current address */
    double getAddress();
    
};



#endif /* Processor.hpp */
