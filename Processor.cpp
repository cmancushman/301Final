//
//  ProgramCounter.hpp
//  301Final
//
//  Created by MacBook Air on 4/13/17.
//  Copyright © 2017 Ubord, Inc. All rights reserved.
//

//  Executes the simulation

#include "Processor.hpp"


Processor::Processor(){

    cout <<" 1" << endl;
   // parse = Parser("inst.asm");

    //parse.printAllInstructions();
    //registerFile = Registers();
    //registerFile.print();

    //registerFile.setRegister(8, "0xffffffff");
    //cout <<" 2" << endl;

    //programCounter = ProgramCounter();
    
    //parse.getInstruction(programCounter.getAddress());
    
    //memoryUnit = DataMemory();
    //data.getWord("00000000000000000000000000000011");
    

    //fetch();
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
