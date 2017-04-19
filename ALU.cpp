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

ALU::ALU(int _operation, string _operand1, string _operand2) {

	//convert binary strings to int

	operation = _operation;
	operand1 = _operand1;
	operand2 = _operand2;

	if (operation < 0 || operation > 2) {
		cout << "Error: operation value must be 0-2" << endl;
		//HANDLE THIS ERROR
		//exit();
	}

	execute();

}

string ALU::execute() {
	if (operation == 0) compare();

	else if (operation == 1) add();

	else if (operation == 2) subtract();

	return output;
}

/*
* Compares the two operands, returns 0 if the same and 1 if different
*/
int ALU::compare() {

	if (operand1.compare(operand2) != 0) {
		//strings are different
		cout << "The strings are not the same" << endl;
		return 1;
	}

	else {
		cout << "The strings are the same" << endl;
		return 0;
	}
}

/*
* Adds two operands and returns the result
*/
string ALU::add() {
	//convert hex string to int to add
	int temp1 = hexToInt(operand1);
	int temp2 = hexToInt(operand2);

	int result = temp1 + temp2;

	output = intToHex(result);

	return output;
}

/*
* Subtracts two operands and returns the result
*/
string ALU::subtract() {
	
	int temp1 = hexToInt(operand1);
	int temp2 = hexToInt(operand2);

	int result = temp1 + temp2;

	string output = intToHex(result);

	return output;
}

/*
* Converts a hex string to its integer representation
*/
int hexToInt(string hexString) {
    unsigned int x;
    stringstream ss;
    ss << std::hex << hexString;
    ss >> x;
    return x;
}

/*
* converts int to a string representation of its hex value
*/
string intToHex(int integer) {
    string hexString;
    stringstream ss;
    integer >> ss;
    ss >> std::hex >> hexString;
    return hexString;
}

