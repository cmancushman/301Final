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
    
    cout << "ALU INPUT 1: " << getHexFromBin(operand1) << endl;
    cout << "ALU INPUT 2: " << getHexFromBin(operand2) << endl;
    
    if (operation == 0){
        cout << "ALU OPERATION: compare equal" << endl;
        compareEqual();
    }
    
    
    else if (operation == 1){
        cout << "ALU OPERATION: add" << endl;
        
        add();
    }
    
    else if (operation == 2){
        cout << "ALU OPERATION: subtract" << endl;
        
        subtract();
    }
    else if (operation == 3){
        cout << "ALU OPERATION: compare less than" << endl;
        
        compareLessThan();
    }
}

/*
 * Compares the two operands, returns true if the same and false if different
 */
void ALU::compareEqual() {
    
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
 * Compares the two operands, returns true if the first is smaller than the other
 */
void ALU::compareLessThan() {
    
    if (hexToInt(getHexFromBin(operand1)) < hexToInt(getHexFromBin(operand2))) {
        //strings are different
        cout << "Operand 1 is smaller" << endl;
        comparisonResult = true;
    }
    
    else {
        cout << "Operand 1 is not smaller" << endl;
        comparisonResult = false;
    }
}

/*
 * Adds two operands and returns the result
 */
void ALU::add() {
    //convert hex string to int to add
    int temp1 = hexToInt(getHexFromBin(operand1));
    int temp2 = hexToInt(getHexFromBin(operand2));
    
    int result = temp1 + temp2;
    
    output = getBinFromHex(intToHex(result));
    
}

/*
 * Subtracts two operands and returns the result
 */
void ALU::subtract() {
    
    int temp1 = hexToInt(getHexFromBin(operand1));
    int temp2 = hexToInt(getHexFromBin(operand2));
    
    int result = temp1 + temp2;
    
    output = getBinFromHex(intToHex(result));
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
    return b.to_string();
    
}

/*
 * Sets the operand1 instance variable equal to the passed string
 */
void ALU::setOperand1(string operand){
    cout << "ALU: SETTING OPERAND1 TO " << getHexFromBin(operand) << endl;
    operand1 = operand;
}

/*
 * Sets the operand2 instance variable equal to the passed string
 */
void ALU::setOperand2(string operand){
    cout << "ALU: SETTING OPERAND2 TO " << getHexFromBin(operand) << endl;

    operand2 = operand;
    
}

/*
 * Sets the operation instance variable equal to the passed int
 */
void ALU::setOperation(int operationInput){
    cout << "ALU: SETTING OPERATION TO " << intToHex(operationInput) << endl;
    operation = operationInput;
}

/*
 * Returns the output instance variable. This will be a 32 bit hex string
 */
string ALU::getOutput(){
    cout << "ALU OUTPUT: " << getHexFromBin(output) << endl;

    return output;
}

/*
 * Returns the result of the compare() method, which will be either true or false
 */
bool ALU::getComparisonResult(){
    return comparisonResult;
}


