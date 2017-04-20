//
//  Processor.hpp
//  301Final
//
//  Created by MacBook Air on 4/13/17.
//  Copyright © 2017 Ubord, Inc. All rights reserved.
//


#ifndef Processor_hpp
#define Processor_hpp

#include <stdio.h>
#include <iostream>
#include "Parser.hpp"
#include "Registers.hpp"
#include "ProgramCounter.hpp"
#include "DataMemory.hpp"
#include "ALU.hpp"

#include "Multiplexer.hpp"

class Processor{
private:

    Instruction currentInstruction;
    DataMemory memoryUnit;
    Registers registerFile;
    Parser parse;
    ALU registerALU;

    ProgramCounter programCounter;
    
    void fetch();
    
    void execute();
    
    void writeToMemory();
    
    void nextInstruction();
public:
    
    Processor();

    
};




#endif /* Processor_hpp */
