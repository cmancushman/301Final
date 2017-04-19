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


string Multiplexer::multiplex(bool control, string input1, string input2)
{
    cout << "Multiplexer INPUT 1: " << input1 << endl;
    cout << "Multiplexer INPUT 2: " << input2 << endl;
    cout << "Multiplexer CONTROL: " << control << endl;
    
    if (control == true)
    {
        cout << "Multiplexer OUTPUT: " << input1 << endl << endl;
        return input1;
    }
    
    cout << "Multiplexer OUTPUT: " << input2 << endl << endl;
    return input2;
}
