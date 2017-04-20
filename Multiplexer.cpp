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


void Multiplexer::setControl(bool newControl){
    control = newControl;
    
    execute();
}

void Multiplexer::setInput1(string input){
    input1 = input;
    
    execute();
}

void Multiplexer::setInput2(string input){
    input2 = input;
    
    execute();
}

string Multiplexer::getOutput(){
    return output;

}

void Multiplexer::execute(){
    if(control){
        output = input1;
    }else{
        output = input2;
    }
}
