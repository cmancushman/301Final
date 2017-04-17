//
//  Parser.hpp
//  301Final
//
//  Created by MacBook Air on 4/12/17.
//  Copyright © 2017 Ubord, Inc. All rights reserved.
//

#ifndef Parser_hpp
#define Parser_hpp

#include <stdio.h>
#include <fstream>
#include <iostream>
#include <algorithm>
#include "Instruction.hpp"
#include "LinkedList.h"
using namespace std;
class Parser{
    
private:
    Instruction toInstruction(string stringArray[]);
    LinkedList<Instruction>  instructionList;

public:
    Parser();
    
    Parser(string file);
    
    void setFile(string file);
    
    
    Instruction getInstruction(double index);
    
    void printAllInstructions();
    

};
#endif /* Parser_hpp */
