//
//  ALU.cpp
//  301Final
//
//  Created by MacBook Air on 4/13/17.
//  Copyright © 2017 Ubord, Inc. All rights reserved.
//

#include "ALU.hpp"

string intToHex(int integer);

ALU::ALU() {

}

ALU::ALU(int _operation, int _operand1, int _operand2) {

	//convert binary strings to int

	operation = _operation;
	operand1 = _operand1;
	operand2 = _operand2;

	if (operation < 0) {
		cout << "Error: operation value must be 0-2" << endl;
		exit();
	}

	execute();
}

void ALU::execute() {
	if (operation == 0) compare();

	else if (operation == 1) add();

	else if (operation == 2) subtract();
}

/*
* Compares the two operands, returns 1 if the same and 0 if different
*/
int ALU::compare() {

	if (operand1 == operand2) return 1;

	//operands are different
	return 0;
}

/*
* Adds two operands and returns the result
*/
string ALU::add() {

	string result = intToHex(operand1 + operand2);

	return result;
}

/*
* Subtracts two operands and returns the result
*/
string ALU::subtract() {
	
	//probably need some binary substraction method
	//how to represent a negative integer?
	int result = 0;

	return result;
}

/*
* converts int to a string representation of its hex value
*/
string intToHex(int integer){
    string hexString;
    stringstream ss;
    integer >> ss;
    ss >> std::hex >> hexString;
    return hexString;
}

