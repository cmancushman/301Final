
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
    
    string programInput;
    string memoryContentsInput;
    string registerFileInput;
    bool batch;
    bool printMemoryContents;
    bool writeToFile;
    string outputFile;
    
    /* Sets debug to true or false controlling print statements */
    void setDebug(bool debug);
    
    void configure(string file);
    
    void setConfig(string file);
    void run();
private:
    
    ProgramCounter programCounter;
    Parser parse;
    Registers registerFile;
    DataMemory memoryUnit;
    ALU aluToMemory;
    ALU aluAddBranchAndAddress;
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
    
    //This method is for converting a hexadecimal string to a string of binary values
    //It receives a binary string and returns a hexadecimal string
    string getBinFromHex(string sHex);

    //This method is for converting binary string to hexadecmial values
    //It receives a binary string and returns a hexadecimal string
    string getHexFromBin(string sBinary);
    
    bool debug;
};


#endif /* DataPath_hpp */
