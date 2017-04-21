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
    
    parse.setFile("inst.asm");
    //parse.getInstruction(0);
    parse.printAllInstructions();
    
    memoryUnit.setFile("DataMemory.asm");
    
    aluAddPCand4.setOperation(1);
    aluAddBranchAndAddress.setOperation(1);


    control.setComponents(&registerFile,&memoryUnit,&aluToMemory,&registerMultiplexer,&registerOrImmediateMultiplexer,&memoryOrALUMultiplexer,&jumpOrIncrementMultiplexer);
    
    fetch();
    decode();
}

void DataPath::fetch(){
    

    currentInstruction = parse.getInstruction(programCounter.getAddress());
    cout << "Current instruction to run: "; currentInstruction.print(); cout << endl;
    
    
    
    cout << "INCREMENTING PC: " << endl;
    aluAddPCand4.setOperand1(programCounter.getAddress());
    aluAddPCand4.setOperand2("00000000000000000000000000000100");
    aluAddPCand4.execute();
    currentAddress = aluAddPCand4.getOutput();
    
    cout<< endl;
    

    
    
    cout << "address for instruction: " << getHexFromBin(currentAddress) << endl << endl;
    
    cout << "SETTING THE OPERAND1 IN BRANCH AND CURRENT ADDRESS ALU" << endl;
    aluAddBranchAndAddress.setOperand1(currentAddress);
    cout << endl;
    
    cout << "SETTING THE MULTIPLEXER FOR BRANCH VS CURRENT ADDRESS" << endl;
    branchOrIncrementMultiplexer.setInput0(currentAddress);
    cout << endl;

    
    opcode = currentInstruction.getOpcode();
    rs = currentInstruction.getRs();
    rt = currentInstruction.getRt();
    rd = currentInstruction.getRd();
    immediate = currentInstruction.getImmediate();
    jumpAmount = currentInstruction.getJumpAmount();
}

void DataPath::decode(){
    
    cout << "ADJUSTING READ REGISTERS" << endl;
    registerFile.setReadRegister1(rs);
    registerFile.setReadRegister2(rt);
    cout << endl;
    
    
    cout <<"ADJUSTING REGISTER MULTIPLEXER INPUTS" << endl;
    registerMultiplexer.setInput0(rt);
    registerMultiplexer.setInput1(rd);
    cout << endl;
    
    cout <<"SETTING WRITE REGISTER" << endl;
    registerFile.setWriteIndex(registerMultiplexer.getOutput());
    cout << endl;
    
    control.sendSignals(opcode);
    cout << endl;

    
    jumpAmount = shiftJump.shift(jumpAmount);
    cout << endl;

    cout << "merging: first four bits of current address: " <<currentAddress.substr(0,4) << "  with shifted jump 28 bits: " <<jumpAmount<< " new current address: " << currentAddress.substr(0,4) + jumpAmount <<  endl;
    jumpAmount = currentAddress.substr(0,4) + jumpAmount;
    jumpOrIncrementMultiplexer.setInput1(jumpAmount);
    cout << endl;

    cout <<"SIGN EXTENDING IMMEDIATE" << endl;
    immediate = signExtend.extend(immediate);
    cout << endl;

    cout <<"ADJUSTING ALU SOURCE MULTIPLEXER INPUT0" << endl;
    string temp = registerFile.getReadRegister2();
    registerOrImmediateMultiplexer.setInput0(temp);
    cout << endl;
    
    cout <<"ADJUSTING ALU SOURCE MULTIPLEXER INPUT1" << endl;
    registerOrImmediateMultiplexer.setInput1(immediate);
    cout << endl;
    
    cout <<"SETTING THE MEMORY ALU OPERANDS" << endl;
    aluToMemory.setOperand1(registerFile.getReadRegister1());
    aluToMemory.setOperand2(registerOrImmediateMultiplexer.getOutput());
    
      
    cout << "SETTING THE OPERAND2 IN BRANCH AND CURRENT ADDRESS ALU" << endl;
    immediate = shiftBranch.shift(immediate);
    aluAddBranchAndAddress.setOperand2(immediate);
    cout << endl;
    
    aluAddBranchAndAddress.execute();
    branchOrIncrementMultiplexer.setInput1(aluAddBranchAndAddress.getOutput());
    
    
    
    
    
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
