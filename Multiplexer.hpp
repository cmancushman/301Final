//
//  Multiplexer.hpp
//  
//
//  Created by Alex Christine on 4/18/17.
//
//

#ifndef Multiplexer_hpp
#define Multiplexer_hpp

#include <stdio.h>
#include <iostream>

using namespace std;
class Multiplexer
{
    
private:
    
public:
    Multiplexer();
    
    /*
         Selects an output based on control. If control is true it outputs input1,
         if control is false it outputs input2.
     */
    string multiplex(bool control, string input1, string input2);
};

#endif /* Multiplexer_hpp */
