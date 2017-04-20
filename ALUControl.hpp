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
    
    void sendSignals(string opcode);
    
};
#endif /* ALUControl_hpp */
