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
    registerFile.init();
    registerFile.setWriteIndex("8");
    registerFile.setWriteValue("11111111111111111111111111111111");
    registerFile.setWrite(true);
    registerFile.write();
    registerFile.print();
    registerFile.setReadRegister1("8");
    registerFile.getReadRegister1();
    registerFile.setFile("Registers.asm");
    registerFile.print();
    
    parse.setFile("inst.asm");
    //parse.getInstruction(0);
    parse.printAllInstructions();
    
    memoryUnit.setFile("DataMemory.asm");
    
    aluAddPCand4.setOperation(1);
    aluAddBranchAndAddress.setOperation(1);


    control.setComponents(&registerFile,&memoryUnit,&aluToMemory,&registerMultiplexer,&registerOrImmediateMultiplexer,&memoryOrALUMultiplexer,&jumpOrIncrementMultiplexer);
    
    fetch();
    decode();
    execute();
    memory();
    writeback();
}

void DataPath::fetch(){
    

    currentInstruction = parse.getInstruction(programCounter.getAddress());
    if (debug)
        cout << "Current instruction to run: "; currentInstruction.print(); cout << endl;
    
    
    
    if (debug)
        cout << "INCREMENTING PC: " << endl;
    
    aluAddPCand4.setOperand1(programCounter.getAddress());
    aluAddPCand4.setOperand2("00000000000000000000000000000100");
    aluAddPCand4.execute();
    currentAddress = aluAddPCand4.getOutput();
    
    if (debug)
        cout<< endl;
    

    
    
    if (debug)
        cout << "address for instruction: " << getHexFromBin(currentAddress) << endl << endl;
    
    if (debug)
        cout << "SETTING THE OPERAND1 IN BRANCH AND CURRENT ADDRESS ALU" << endl << endl;
    
    aluAddBranchAndAddress.setOperand1(currentAddress);
    
    
    if (debug)
        cout << "SETTING THE MULTIPLEXER FOR BRANCH VS CURRENT ADDRESS" << endl << endl;
    
    branchOrIncrementMultiplexer.setInput0(currentAddress);

    
    opcode = currentInstruction.getOpcode();
    rs = currentInstruction.getRs();
    rt = currentInstruction.getRt();
    rd = currentInstruction.getRd();
    immediate = currentInstruction.getImmediate();
    jumpAmount = currentInstruction.getJumpAmount();
}

void DataPath::decode(){
    
    if (debug)
        cout << "ADJUSTING READ REGISTERS" << endl << endl;
    
    registerFile.setReadRegister1(rs);
    registerFile.setReadRegister2(rt);
    
    
    
    if (debug)
        cout <<"ADJUSTING REGISTER MULTIPLEXER INPUTS" << endl << endl;
    registerMultiplexer.setInput0(rt);
    registerMultiplexer.setInput1(rd);
    
    
    if (debug)
        cout <<"SETTING WRITE REGISTER" << endl << endl;
    
    registerFile.setWriteIndex(registerMultiplexer.getOutput());
    
    
    control.sendSignals(opcode);
    
    if (debug)
        cout << endl;

    
    jumpAmount = shiftJump.shift(jumpAmount);
    
    if (debug)
        cout << endl;

    if (debug)
        cout << "merging: first four bits of current address: " <<currentAddress.substr(0,4) << "  with shifted jump 28 bits: " <<jumpAmount<< " new current address: " << currentAddress.substr(0,4) + jumpAmount <<  endl << endl;
    
    jumpAmount = currentAddress.substr(0,4) + jumpAmount;
    jumpOrIncrementMultiplexer.setInput1(jumpAmount);
    

    if (debug)
        cout <<"SIGN EXTENDING IMMEDIATE" << endl << endl;
    
    immediate = signExtend.extend(immediate);


    if (debug)
        cout <<"ADJUSTING ALU SOURCE MULTIPLEXER INPUT0" << endl << endl;
    
    string temp = registerFile.getReadRegister2();
    registerOrImmediateMultiplexer.setInput0(temp);
    
    
    if (debug)
        cout <<"ADJUSTING ALU SOURCE MULTIPLEXER INPUT1" << endl << endl;
    
    registerOrImmediateMultiplexer.setInput1(immediate);
    
    
    if (debug)
        cout <<"SETTING THE MEMORY ALU OPERANDS" << endl;
    
    aluToMemory.setOperand1(registerFile.getReadRegister1());
    aluToMemory.setOperand2(registerOrImmediateMultiplexer.getOutput());
    
      
    if (debug)
        cout << "SETTING THE OPERAND2 IN BRANCH AND CURRENT ADDRESS ALU" << endl << endl;
    
    immediate = shiftBranch.shift(immediate);
    aluAddBranchAndAddress.setOperand2(immediate);
    
    
    aluAddBranchAndAddress.execute();
    branchOrIncrementMultiplexer.setInput1(aluAddBranchAndAddress.getOutput());
    
    
    
    
    
}

void DataPath::execute(){
    
    if (debug)
        cout <<"SETTING EXECUTING MEMORY ALU" << endl;
    
    aluToMemory.execute();
    
    cout <<"SETTING BRANCH OR INCREMENTED ADDRESS MULTIPLEXER CONTROL " << endl;
    branchOrIncrementMultiplexer.setControl(control.isBranch() && aluToMemory.getComparisonResult());

    if (debug)
        cout <<"SETTING EXECUTING MEMORY ALU" << endl;

    cout <<"SETTING JUMP OR INCREMENTED ADDRESS INPUT0" << endl;
    jumpOrIncrementMultiplexer.setInput0(branchOrIncrementMultiplexer.getOutput());
    

}
void DataPath::memory(){
    cout <<"SETTING DATA MEMORY ADDRESS AND WRITE DATA" << endl;

    if (debug)
        cout <<"SETTING DATA MEMORY ADDRESS AND WRITE DATA" << endl;
    
    string temp = aluToMemory.getOutput();
    memoryUnit.setCurrentAddress(temp);
    temp = registerFile.getReadRegister2();
    memoryUnit.storeWord(temp);
    memoryUnit.saveMemory();
    
    cout <<"SETTING MEMORY OR ALU MULTIPLEXER AS WELL AS WRITE DATA" << endl;

    if (debug)
        cout <<"SETTING DATA MEMORY ADDRESS AND WRITE DATA" << endl;
    
    memoryOrALUMultiplexer.setInput1(memoryUnit.readMemory());
    memoryOrALUMultiplexer.setInput0(aluToMemory.getOutput());
    registerFile.setWriteValue(memoryOrALUMultiplexer.getOutput());
    
}
void DataPath::writeback(){
    registerFile.write();
    programCounter.setAddress(jumpOrIncrementMultiplexer.getOutput());
    parse.getInstruction(programCounter.getAddress()).print();

}
string DataPath::getBinFromHex(string sHex)
{
    string s = sHex;
    stringstream ss;
    ss << std::hex << s;
    unsigned n;
    ss >> n;
    bitset<32> b(n);
    //cout << "Test Return Hex " << b.to_string() << endl;
    
    return b.to_string();
    
}

//This method is for converting binary string to hexadecmial values
//It receives a binary string and returns a hexadecimal string
string DataPath::getHexFromBin(string sBinary)
{
    std::stringstream ss;
    ss << std::hex << std::stoll(sBinary, NULL, 2);
    //std::cout <<"hex test " << ss.str() << std::endl;
    
    string s =  ss.str();
    while (s.length() != 8){
        s = "0" + s;
    }
    s = "0x" + s;
    return s;
}

void DataPath::setDebug(bool value)
{
    debug = value;
}
