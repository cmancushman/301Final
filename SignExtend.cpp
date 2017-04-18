//
//  SignExtend.cpp
//  
//
//  Created by Alex Christine on 4/18/17.
//
//

#include "SignExtend.hpp"

SignExtend()
{
    
}

string SignExtend::extend(string input)
{
    cout << "SignExtend INPUT: " << input << endl;
    if (input.front == "0")
        input = "0000000000000000" + input;
    
    else
        input = "1111111111111111" + input;
    
    cout << "SignExtend OUTPUT: " << input << endl << endl;
    
    return input;
}
