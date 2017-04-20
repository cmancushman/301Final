//
//  Instruction.cpp
//  301Final
//
//  Created by MacBook Air on 4/13/17.
//  Copyright © 2017 Ubord, Inc. All rights reserved.
//

#include "ShiftLeft.hpp"

ShiftLeft::ShiftLeft()
{

}

string ShiftLeft::shift(string input)
{
    cout << "ShiftLeft INPUT: " << input << endl;
    
    // Puts 00 at the end to shift the input left by 2 bits
    input += "00";
    
    cout << "ShiftLeft OUTPUT: " << input << endl << endl;
    return input;
}

