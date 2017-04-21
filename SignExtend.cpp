//
//  SignExtend.cpp
//  
//
//  Created by Alex Christine on 4/18/17.
//
//

#include "SignExtend.hpp"

// Constructor
SignExtend::SignExtend()
{
    
}

//Method takes in an input string that is a representation of a 16-bit binary string and translates it into an equivalent 32-bit binary string. Returns the 32-bit equivalent string.
string SignExtend::extend(string input)
{
    if (debug)
        cout << "SignExtend INPUT: " << binaryOperation.getHexFromBin(input) << endl;
    
    if (toFile)
        ofile << "SignExtend INPUT: " << binaryOperation.getHexFromBin(input) << endl;

    if (input.substr(0,1) == "0")
    {
        while(input.length() != 32)
        {
            input = "0" + input;
        }
    }
    else
    {
        while(input.length() != 32)
        {
            input = "1" + input;
        }
    }
    
    if (debug)
        cout << "SignExtend OUTPUT: " << binaryOperation.getHexFromBin(input) << endl << endl;
    
    if (toFile)
        ofile << "SignExtend OUTPUT: " << binaryOperation.getHexFromBin(input) << endl << endl;
    
    return input;
}

//Sets debug to true or false controlling print statements
void SignExtend::setDebug(bool value)
{
    debug = value;
}

void SignExtend::setToFile(bool val)
{
    toFile = val;
}

void SignExtend::setOfStream(ofstream& out)
{
    ofile = out;
}
