//
//  Parser.cpp
//  301Final
//
//  Created by MacBook Air on 4/12/17.
//  Copyright © 2017 Ubord, Inc. All rights reserved.
//

#include "Parser.hpp"

//Default constructor
Parser::Parser(){
}

//Constructor that intakes a file of strings
Parser::Parser(string file){

    
}



//Sets the file to input string file
void Parser::setFile(string file){
    check = "asd";
    fstream in;
    in.open(file.c_str());
    
    instructionList = LinkedList<Instruction>();
    if(in.bad()){
        cout <<"BAD FILE" << endl;
    }
    else{
        string line;
        
        
        while( getline(in, line)){
            //cout  << line << endl;
            
            line.erase(std::remove(line.begin(), line.end(), ','), line.end());
            
            //replace all parentheses with a space
            std::replace( line.begin(), line.end(), '(', ' ');
            //replace all parentheses with a space
            std::replace( line.begin(), line.end(), ')', ' ');
            
            string stringArray[10];
            int counter = 0;
            for (short i = 0; i<line.length(); i++){
                if (line[i] == ' '){
                    counter++;
                }else{
                    stringArray[counter] += line[i];
                }
            }
            instructionList.add(toInstruction(stringArray));
            
        }
    }
}

//Returns the instruction at an index
Instruction Parser::getInstruction(string binaryIndex){
    int index = hexToInt(getHexFromBin(binaryIndex));
    index = index - 262144;
    index = index/4;
    if (debug){
        
    cout << "GetInstruction: INPUT:  " << index << "    OUTPUT ";instructionList.get(index).print();
    }
    return instructionList.get(index);
}

//Returns an instruction from input stringArray
Instruction Parser::toInstruction(string stringArray[]){
    
    std::transform(stringArray[0].begin(), stringArray[0].end(), stringArray[0].begin(), ::tolower);
    
    Instruction instr = Instruction(stringArray[0], stringArray[1], stringArray[2], stringArray[3]);
    return instr;

}

//Prints all the instructions
void Parser::printAllInstructions(){
    for(int x = 0; x < instructionList.size(); x ++){
        cout << "Instruction #"<<x << " : "; instructionList.get(x).print();
    }
}

/*
 * Takes a binary string and returns its hex string representation
 */
string Parser::getHexFromBin(string sBinary)
{
    if(sBinary != ""){
    std::stringstream ss;
    ss << std::hex << std::stoll(sBinary, NULL, 2);
    //std::cout <<"hex test " << ss.str() << std::endl;
    
    string s =  ss.str();
    while (s.length() != 8){
        s = "0" + s;
    }
    s = "0x" + s;
    return s;
    }else{
        return "0x";
    }
}

/*
 * Takes a hex string as a parameter and returns its integer representation
 */
int Parser::hexToInt(string hexString) {
    unsigned int x;
    stringstream ss;
    ss << std::hex << hexString;
    ss >> x;
    return x;
    
}

void Parser::setDebug(bool value){
    debug = value;
}
<<<<<<< HEAD

int Parser::getNumberOfInstructions(){
    return instructionList.size();
}

bool Parser::weAreDone(string address){
    if((hexToInt(getHexFromBin(address)) - 262144)/4 >= instructionList.size()){
        return true;
    }
    return false;
}
=======
>>>>>>> parent of a3705bc... asd
