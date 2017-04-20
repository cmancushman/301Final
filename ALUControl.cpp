//
//  Control.cpp
//  301Final
//
//  Created by MacBook Air on 4/13/17.
//  Copyright © 2017 Ubord, Inc. All rights reserved.
//

#include "ALUControl.hpp"

ALUControl::ALUControl(){
    
}

void ALUControl::setALU(ALU *alu){
    aluToMemory = alu;
}



void ALUControl::sendSignals(string opcode){
    if(opcode == "00"){
        aluToMemory->setOperation(0);
    }else if(opcode == "01"){
        aluToMemory->setOperation(1);
    }else if(opcode == "10"){
        aluToMemory->setOperation(2);
    }else{
        aluToMemory->setOperation(3);
    }
}




//add  - destination is rd
//addi - rt
//lw   - rt
//sw   - rt
//slt  - rd
