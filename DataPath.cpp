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

}

void DataPath::setConfig(string file){
    configure(file);

}
void DataPath::run(){
    cout << "print memory contents 2 " << printMemoryContents << endl;

    registerFile.init();
    registerFile.setFile(registerFileInput);
    //cout<< "*****CURRENT REGISTERS*****" <<endl;
    //registerFile.print();
    //cout << endl;
    
    //set debug values for all classes
    /****/
    //debug = true;
    programCounter.setDebug(debug);
    parse.setDebug(debug);
    registerFile.setDebug(debug);
    aluToMemory.setDebug(debug);
    aluAddBranchAndAddress.setDebug(debug);
    aluAddPCand4.setDebug(debug);
    shiftJump.setDebug(debug);
    shiftBranch.setDebug(debug);
    control.setDebug(debug);
    registerMultiplexer.setDebug(debug);
    registerOrImmediateMultiplexer.setDebug(debug);
    memoryOrALUMultiplexer.setDebug(debug);
    branchOrIncrementMultiplexer.setDebug(debug);
    jumpOrIncrementMultiplexer.setDebug(debug);
    signExtend.setDebug(debug);
    memoryUnit.setDebug(debug);
    /*****/
    
    cout << endl;
    parse.setFile(programInput);
    //cout<< "*****CURRENT INSTRUCTIONS*****" <<endl;
    //parse.printAllInstructions();
    //cout << endl;
    memoryUnit.setFile(memoryContentsInput);
    
    aluAddPCand4.setOperation(1);
    aluAddBranchAndAddress.setOperation(1);
    
    
    control.setComponents(&registerFile,&memoryUnit,&aluToMemory,&registerMultiplexer,&registerOrImmediateMultiplexer,&memoryOrALUMultiplexer,&jumpOrIncrementMultiplexer);
    //debug = true;
    
    if(printMemoryContents){
        cout<< "*****CURRENT REGISTERS*****" <<endl;
        registerFile.print();
        cout << endl;
        
        cout<< "*****CURRENT INSTRUCTIONS*****" <<endl;
        parse.printAllInstructions();
        cout << endl;
        
        cout<< "*****CURRENT DATA MEMORY*****" <<endl;
        memoryUnit.print();
    }
    
    std::ofstream out(outputFile);
    
    while(true){
        if(parse.weAreDone( programCounter.getAddress()) ){
            break;
        }
        out << "Current Instruction: " << parse.getInstruction(programCounter.getAddress()).getStringVersion() << endl;
        out<< "*****CURRENT INSTRUCTIONS*****" <<endl;
        out << parse.getAllInstructions();
        
        if(writeToFile){
            out<< "*****CURRENT REGISTERS*****" <<endl;
            out << registerFile.getAllRegisters();
            out << endl;
            out<< "*****CURRENT DATA MEMORY*****" <<endl;
            out << memoryUnit.getAllPairs();
        }
        
        fetch();
        decode();
        execute();
        memory();
        writeback();
        if(printMemoryContents){
            cout<< "*****CURRENT REGISTERS*****" <<endl;
            registerFile.print();
            cout << endl;
            
            cout<< "*****CURRENT INSTRUCTIONS*****" <<endl;
            parse.printAllInstructions();
            cout << endl;
            
            cout<< "*****CURRENT DATA MEMORY*****" <<endl;
            memoryUnit.print();
        }
        
        
        if(!batch){
            system("read");
        }
    }
    cout << endl << endl;
    cout << "WE DID IT! END OF FILE!!!" << endl;
    out.close();
    

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
    control.sendSignals(opcode);

    
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
        cout <<"EXECUTING MEMORY ALU" << endl;
    
    aluToMemory.execute();
    
    if (debug)
        cout <<"SETTING BRANCH OR INCREMENTED ADDRESS MULTIPLEXER CONTROL " << endl;
    
    branchOrIncrementMultiplexer.setControl(control.isBranch() && aluToMemory.getComparisonResult());
    
    if(debug)
        cout <<"SETTING JUMP OR INCREMENTED ADDRESS INPUT0" << endl;
    jumpOrIncrementMultiplexer.setInput0(branchOrIncrementMultiplexer.getOutput());
    
}

void DataPath::memory(){
    
    
    if (debug)
        cout <<"SETTING DATA MEMORY ADDRESS AND WRITE DATA" << endl;
    string temp = aluToMemory.getOutput();
    memoryUnit.setCurrentAddress(temp);
    temp = registerFile.getReadRegister2();
    memoryUnit.storeWord(temp);
    memoryUnit.saveMemory();
    
    
    
    if (debug)
        cout <<"SETTING MEMORY OR ALU MULTIPLEXER AS WELL AS WRITE DATA" << endl;
    memoryOrALUMultiplexer.setInput1(memoryUnit.readMemory());
    memoryOrALUMultiplexer.setInput0(aluToMemory.getOutput());
    registerFile.setWriteValue(memoryOrALUMultiplexer.getOutput());
    
}
void DataPath::writeback(){
    registerFile.write();
    programCounter.setAddress(jumpOrIncrementMultiplexer.getOutput());
    if(!parse.weAreDone( programCounter.getAddress())){
        cout <<"Next Instruction to run: ";parse.getInstruction(programCounter.getAddress()).print();
    }
    cout << endl;

    
}

//This method is for converting a hexadecimal string to a string of binary values
//It receives a binary string and returns a hexadecimal string
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

void DataPath::configure(string file)
{
    fstream in;
    in.open(file.c_str());
    
    if (in.bad())
        cout << "BAD CONFIG FILE" << endl;
    
    string line;
    
    while (getline(in, line))
    {
        if (line.find("#") != std::string::npos)
        {
            continue;
        }
        else if (line.find("program_input") != std::string::npos)
        {
            line.erase(line.begin(), line.begin() + 14);
            programInput = line;
        }
        else if (line.find("memory_contents_input") != std::string::npos)
        {
            line.erase(line.begin(), line.begin() + 22);
            memoryContentsInput = line;
        }
        else if (line.find("register_file_input") != std::string::npos)
        {
            line.erase(line.begin(), line.begin() + 20);
            registerFileInput = line;
        }
        else if (line.find("output_mode") != std::string::npos)
        {
            if (line.find("batch") != std::string::npos){
                batch = true;
            }else{
                batch = false;
            }
        }
        else if (line.find("debug_mode") != std::string::npos)
        {
            if (line.find("true") != std::string::npos){
                debug = true;
            }else{
                debug = false;
            }
        }
        else if (line.find("print_memory_contents") != std::string::npos)
        {
            if (line.find("true") != std::string::npos){
                printMemoryContents = true;
            }else{
                printMemoryContents = false;
            }
            cout << "print memory contents " << printMemoryContents << endl;

        }
        else if (line.find("write_to_file") != std::string::npos)
        {
            if (line.find("true") != std::string::npos){
                writeToFile = true;
            }else{
                writeToFile = false;
            }
        }
        else if (line.find("output_file") != std::string::npos)
        {
            line.erase(line.begin(), line.begin() + 12);
            outputFile = line;
        }
    }
}
