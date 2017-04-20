//
//  ProgramCounter.hpp
//  301Final
//
//  Created by MacBook Air on 4/13/17.
//  Copyright © 2017 Ubord, Inc. All rights reserved.
//

#include "Processor.hpp"
void fetch(){
    currentInstruction = parse.getInstruction(prgrmCounter.getAddress());
    currentInstruction.print();
}

void execute(){
    
}

void writeToMemory(){
    
}

void nextInstruction(){
    
}
