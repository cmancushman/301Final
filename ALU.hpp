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

#include <iostream>
#include <string>
#include <sstream>

using namespace std;
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
    
    string getHexFromBin(string sBinary);
    
    string getBinFromHex(string sHex);

public:

	ALU();

	void execute();

	void setOperand1(string operand);

	void setOperand2(string operand);

	void setOperation(int operationInput);

	string getOutput();
	
	bool getComparisonResult();

};

#endif /* ALU_hpp */
