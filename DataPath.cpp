//
//  SignExtend.cpp
//  
//
//  Created by Alex Christine on 4/18/17.
//
//

#include "DataPath.hpp"

DataPath::DataPath()
{
    registerFile.setRegister(8, "0xffffffff");
    registerFile.print();
    registerFile.getRegister(8);
    
    parse.setFile("inst.asm");
    //parse.getInstruction(0);
    parse.printAllInstructions();
    
    
}
//

void DataPath::fetch(){
    
    
}
