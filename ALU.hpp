//
//  ALU.hpp
//  301Final
//
//  Created by MacBook Air on 4/13/17.
//  Copyright © 2017 Ubord, Inc. All rights reserved.
//

#ifndef ALU_hpp
#define ALU_hpp

#include <stdio.h>
#include "Instruction.hpp"
#include "Registers.hpp"
#include "ALU.hpp"
#include "DataMemory.hpp"
#include "Instruction.hpp"
#include <iostream>
#include <string>


class ALU {

private:
	int operation; //0 = compare, 1 = add, 2 = subtract
	string operand1;
	string operand2;
	string output;

	string execute();
	int compare();
	string add();
	string subtract();

public:

	ALU();
	ALU(int _operation, string _operand1, string _operand2);

};

#endif /* ALU_hpp */
