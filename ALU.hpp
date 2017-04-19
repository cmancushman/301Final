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
	bool comparisonResult;
	void compare();
	void add();
	void subtract();

	int hexToInt(string hexString);

	string intToHex(int integer);

public:

	ALU();

	void execute();

	void setOperand1(string operand);

	void setOperand2(string operand);

	void setOperation(int operationInput);

};

#endif /* ALU_hpp */
