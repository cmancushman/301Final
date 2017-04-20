//
//  ALU.cpp
//  301Final
//
//  Created by MacBook Air on 4/13/17.
//  Copyright © 2017 Ubord, Inc. All rights reserved.
//

#include "ALU.hpp"


/*
* Default constructor
*/
ALU::ALU() {
    //cout << "testing " << getBinFromHex(intToHex(hexToInt(getHexFromBin("00000000000000000000000000000011")))) << endl;
    
}

/*
* Calls either the compare(), add(), or subtract() function depending on the value
* of the operation instance variable
*/
void ALU::execute() {

    cout << "ALU INPUT 1: " << operand1 << endl;
    cout << "ALU INPUT 2: " << operand2 << endl;
    cout << "ALU OPERATION: " << operation << endl;

	if (operation == 0) compare();

	else if (operation == 1) add();

	else if (operation == 2) subtract();
}

/*
* Compares the two operands, returns true if the same and false if different
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
* Takes a binary string and returns its hex string representation
*/
string ALU::getHexFromBin(string sBinary)
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

/*
* Takes a hex string as a parameter and returns its integer representation
*/
int ALU::hexToInt(string hexString) {
    unsigned int x;
    stringstream ss;
    ss << std::hex << hexString;
    ss >> x;
    return x;
}

/*
* Takes an int as a parameter and returns its hex representation as a string
*/
string ALU::intToHex(int integer) {
    char output[100];
    sprintf(output, "%08x", integer);
    string result = output;
    result = "0x" + result;
    return result;
}

/*
* Takes a hex string and returns its binary string representation
*/
string ALU::getBinFromHex(string sHex)
{
    string s = sHex;
    stringstream ss;
    ss << std::hex << s;
    unsigned n;
    ss >> n;
    bitset<32> b(n);
    cout << "Test Return Hex " << b.to_string() << endl;
    
    return b.to_string();
    
}

/*
* Sets the operand1 instance variable equal to the passed string
*/
void ALU::setOperand1(string operand){
	operand1 = operand;
}

/*
* Sets the operand2 instance variable equal to the passed string
*/
void ALU::setOperand2(string operand){
	operand2 = operand;

}

/*
* Sets the operation instance variable equal to the passed int
*/
void ALU::setOperation(int operationInput){
	operation = operationInput;
}

/*
* Returns the output instance variable. This will be a 32 bit hex string
*/
string ALU::getOutput(){
	return output;
}

/*
* Returns the result of the compare() method, which will be either true or false
*/
bool ALU::getComparisonResult(){
	return comparisonResult;
}


