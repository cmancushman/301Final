//
//  main.cpp
//  301Final
//
//  Created by MacBook Air on 4/12/17.
//  Copyright © 2017 Ubord, Inc. All rights reserved.
//

#include <iostream>
#include "Parser.hpp"
#include "Registers.hpp"
#include "ProgramCounter.hpp"
//include "Instruction.hpp"
int main(int argc, const char * argv[]) {
    // insert code here...
    //std::cout << "Hello, World!\n";
    Parser parse = Parser("inst.asm");
    //parse.printAllInstructions();
    Registers registers = Registers();
    registers.setRegister(8, "0xffffffff");
    //registers.print();
    
    ProgramCounter prgrmCounter = ProgramCounter();
    
    parse.getInstruction(prgrmCounter.getAddress());
    //parse.getNextInstruction().print();
    
    return 0;
}
