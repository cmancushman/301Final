//
//  Processor.hpp
//  301Final
//
//  Created by MacBook Air on 4/13/17.
//  Copyright © 2017 Ubord, Inc. All rights reserved.
//

<<<<<<< HEAD
#ifndef Processor.hpp
#define Processor.hpp
=======
#ifndef Processor_hpp
#define Processor_hpp
>>>>>>> 95c998b18517b30ec1c47f3506eec7f82ca8b0ab

#include <stdio.h>
#include <iostream>
#include "Parser.hpp"
#include "Registers.hpp"
#include "ProgramCounter.hpp"
#include "DataMemory.hpp"
#include "ALU.hpp"
<<<<<<< HEAD
#include "Multiplexor.hpp"
=======
#include "Multiplexer.hpp"
>>>>>>> 95c998b18517b30ec1c47f3506eec7f82ca8b0ab

class Processor{
private:

    Instruction currentInstruction;
    DataMemory memoryUnit;
    Registers registerFile;
    Parser parse;
    ALU registerALU;
<<<<<<< HEAD
    
public:
    
    /* Constructor for program counter */
    ProgramCounter();
    
    
    /* Jump to a given address */
    void jump(double amount);
    
    /* Increment by 4 */
    void increment();
    
    /* Retruns the current address */
    double getAddress();
=======
    ProgramCounter programCounter;
    
    void fetch();
    
    void execute();
    
    void writeToMemory();
    
    void nextInstruction();
public:
    
    Processor();

>>>>>>> 95c998b18517b30ec1c47f3506eec7f82ca8b0ab
    
};



<<<<<<< HEAD
#endif /* Processor.hpp */
=======
#endif /* Processor_hpp */
>>>>>>> 95c998b18517b30ec1c47f3506eec7f82ca8b0ab
