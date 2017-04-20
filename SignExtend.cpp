//
//  SignExtend.cpp
//  
//
//  Created by Alex Christine on 4/18/17.
//
//

#include "SignExtend.hpp"

SignExtend::SignExtend()
{
    
}

string SignExtend::extend(string input)
{
    cout << "SignExtend INPUT: " << BinaryOperation.getHexFromBin(input) << endl;

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
    
    cout << "SignExtend OUTPUT: " << BinaryOperation.getHexFromBin(input) << endl << endl;
    
    return input;
}

