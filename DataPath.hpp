//
//  SignExtend.cpp
//  
//
//  Created by Alex Christine on 4/18/17.
//
//
#ifndef DataPath_hpp
#define DataPath_hpp

#include <iostream>
#include "ShiftLeft.hpp"
#include "Registers.hpp"
#include "DataMemory.hpp"
#include "ProgramCounter.hpp"
#include "Control.hpp"
#include "ALU.hpp"
#include "Parser.hpp"
using namespace std;

class DataPath{
public:
    DataPath();
    
    void fetch();
private:
    ShiftLeft shift;
    DataMemory memoryUnit;
    Control control;
    ALU alu;
    Registers registerFile;
    Parser parse;
};


#endif /* DataPath_hpp */
