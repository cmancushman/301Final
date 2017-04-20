//
//  Parser.cpp
//  301Final
//
//  Created by MacBook Air on 4/12/17.
//  Copyright © 2017 Ubord, Inc. All rights reserved.
//

#include "Parser.h"

Parser::Parser(){
    cout << "oy" << endl;
}

Parser::Parser(string file){
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
            
            std::replace( line.begin(), line.end(), '(', ' ');
            
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

void Parser::setFile(string file){
    
}


Instruction Parser::getInstruction(double index){
    cout << "GetInstruction: INPUT:  " << index << "    OUTPUT "; instructionList.get((int)index).print();
    return instructionList.get((int)index);
}

Instruction Parser::toInstruction(string stringArray[]){
    
    std::transform(stringArray[0].begin(), stringArray[0].end(), stringArray[0].begin(), ::tolower);
    
    Instruction instr = Instruction(stringArray[0], stringArray[1], stringArray[2], stringArray[3]);
    //instr.print();
    return instr;

}

void Parser::printAllInstructions(){
    for(int x = 0; x < instructionList.size(); x ++){
        cout << "Instruction #"<<x << " : "; instructionList.get(x).print();
    }
}
