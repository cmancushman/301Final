//
//  Control.hpp
//  301Final
//
//  Created by MacBook Air on 4/13/17.
//  Copyright © 2017 Ubord, Inc. All rights reserved.
//

#ifndef ALUControl_hpp
#define ALUControl_hpp

#include <stdio.h>

#include "ALU.hpp"

using namespace std;
class ALUControl{
private:
    

    ALU *aluToMemory;

    
    string aluOP;
    
    
public:
    
    ALUControl();
    
    //void set
    void setALU(ALU *alu);
    
    //This method takes in an opcode in string form and sets the aluToMemory equal to setOperation(0, 1, 2, 
    void sendSignals(string opcode);
    
};
#endif /* ALUControl_hpp */
