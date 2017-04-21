
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
#include "Multiplexer.hpp"
#include "SignExtend.hpp"
using namespace std;

class DataPath{
public:
    
    // Default Constructor
    DataPath();
    // The following methods execute the 5 stages of our pipelined processor
    void fetch();
    void decode();
    void execute();
    void memory();
    void writeback();
    
    /* Sets debug to true or false controlling print statements */
    void setDebug(bool debug);
private:
    
    ProgramCounter programCounter;
    Parser parse;
    Registers registerFile;
    DataMemory memoryUnit;
    ALU aluToMemory;
    ALU aluAddBranchAndAddress;
    ALU aluAddJumpAndAddress;
    ALU aluAddPCand4;
    ShiftLeft shiftJump;
    ShiftLeft shiftBranch;
    Control control;
    Multiplexer registerMultiplexer;
    Multiplexer registerOrImmediateMultiplexer;
    Multiplexer memoryOrALUMultiplexer;
    Multiplexer branchOrIncrementMultiplexer;
    Multiplexer jumpOrIncrementMultiplexer;
    SignExtend signExtend;
    
    
    string currentAddress;
    Instruction currentInstruction;
    
    string opcode;
    string rs;
    string rt;
    string rd;
    string immediate;
    string jumpAmount;
    
    string getBinFromHex(string sHex);
    string getHexFromBin(string sBinary);
    
    bool degug;
    
};


#endif /* DataPath_hpp */
