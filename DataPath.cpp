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
    registerFile.getRegister(8);
    
    parse.setFile("inst.asm");
    //parse.getInstruction(0);
    parse.printAllInstructions();
    
    memoryUnit.setFile("DataMemory.asm");
    
    aluAddPCand4.setOperation(1);

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
    
    
    
    opcode = currentInstruction.getOpcode();
    rs = currentInstruction.getRs();
    rt = currentInstruction.getRt();
    rd = currentInstruction.getRd();
    immediate = currentInstruction.getImmediate();
    jumpAmount = currentInstruction.getJumpAmount();
}

void DataPath::decode(){
    
    
    cout <<"ADJUSTING REGISTER MULTIPLEXER INPUTS" << endl;
    registerMultiplexer.setInput0(currentInstruction.getRt());
    registerMultiplexer.setInput1(currentInstruction.getRd());
    cout << endl;
    
    
    control.sendSignals(opcode);

    
    jumpAmount = shiftJump.shift(jumpAmount);
    
    
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
