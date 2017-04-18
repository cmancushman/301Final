//
//  Multiplexer.cpp
//  
//
//  Created by Alex Christine on 4/18/17.
//
//

#include "Multiplexer.hpp"

Multiplexer::Multiplexer()
{
    
}

/*
    Selects an output based on control. If control is true it outputs input1,
    if control is false it outputs input2.
*/
string Multiplexer::multiplex(bool control, string input1, string input2)
{
    if (control == true)
        return input1;
    
    return input2;
}
