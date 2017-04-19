//
//  ALU.cpp
//  301Final
//
//  Created by MacBook Air on 4/13/17.
//  Copyright © 2017 Ubord, Inc. All rights reserved.
//

#include "ALU.hpp"

string intToHex(int integer);
int hexToInt(string hexString);

ALU::ALU() {

}


void ALU::execute() {
	if (operation == 0) compare();

	else if (operation == 1) add();

	else if (operation == 2) subtract();
}

/*
* Compares the two operands, returns 0 if the same and 1 if different
*/
void ALU::compare() {

	if (operand1.compare(operand2) != 0) {
		//strings are different
		cout << "The strings are not the same" << endl;
		comparisonResult = false;
	}

	else {
		cout << "The strings are the same" << endl;
		comparisonResult = true;
	}
}

/*
* Adds two operands and returns the result
*/
void ALU::add() {
	//convert hex string to int to add
	int temp1 = hexToInt(operand1);
	int temp2 = hexToInt(operand2);

	int result = temp1 + temp2;

	output = intToHex(result);

}

/*
* Subtracts two operands and returns the result
*/
void ALU::subtract() {
	
	int temp1 = hexToInt(operand1);
	int temp2 = hexToInt(operand2);

	int result = temp1 + temp2;

	output = intToHex(result);

}

/*
* Converts a hex string to its integer representation
*/
int ALU::hexToInt(string hexString) {
    unsigned int x;
    stringstream ss;
    ss << std::hex << hexString;
    ss >> x;
    return x;
}

/*
* converts int to a string representation of its hex value
*/
string ALU::intToHex(int integer) {
    string hexString;
    stringstream ss;
    integer >> ss;
    ss >> std::hex >> hexString;
    return hexString;
}


void ALU::setOperand1(string operand){
	operand1 = operand;
}

void ALU::setOperand2(string operand){
	operand2 = operand;

}

void ALU::setOperation(int operationInput){
	operation = operationInput;
}

string ALU::getOutput(){
	return output;
}

bool ALU::getComparisonResult(){
	return comparisonResult;
}


