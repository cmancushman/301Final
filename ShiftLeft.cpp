//
//  Instruction.cpp
//  301Final
//
//  Created by MacBook Air on 4/13/17.
//  Copyright © 2017 Ubord, Inc. All rights reserved.
//

#include "ShiftLeft.hpp"

// Default constructor
ShiftLeft::ShiftLeft()
{

}

//Method takes in a 26-bit string that represents a binary number.
//The method shifts the binary number left by 2 and adds 2 additional
//bits. The method returns the modifed 28-bit binary string.
string ShiftLeft::shift(string input)
{
    if (debug)
    {
        string printed = "00" + input;

        cout << "ShiftLeft INPUT: " << binaryOperation.getHexFromBin(printed) << endl;
    }
    // Puts 00 at the end to shift the input left by 2 bits
    if(input.length() == 32){
        input.erase(0,2);
    }
    input += "00";
    
    if (debug)
        cout << "ShiftLeft OUTPUT: " << binaryOperation.getHexFromBin(input) << endl << endl;
    
    return input;
}

//Sets debug to true or false controlling print statements
void ShiftLeft::setDebug(bool value)
{
    debug = value;
}
