//
//  ProgramCounter.hpp
//  301Final
//
//  Created by MacBook Air on 4/13/17.
//  Copyright © 2017 Ubord, Inc. All rights reserved.
//

#include "Processor.hpp"


Processor::Processor(){
    // insert code here...
    //std::cout << "Hello, World!\n";
    parse = Parser("inst.asm");
    //parse.printAllInstructions();
    registerFile = Registers();
    registerFile.setRegister(8, "0xffffffff");
    //registers.print();
    
    programCounter = ProgramCounter();
    
    //parse.getInstruction(programCounter.getAddress());
    
    memoryUnit = DataMemory();
    //data.getWord("00000000000000000000000000000011");
    
    
    fetch();
    //ALU alu = ALU();
    //parse.getNextInstruction().print();

}
void Processor::fetch(){
    currentInstruction = parse.getInstruction(programCounter.getAddress());
    currentInstruction.print();
}

void Processor::execute(){
    
}

void Processor::writeToMemory(){
    
}

void Processor::nextInstruction(){

    
}
