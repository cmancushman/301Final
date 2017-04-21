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
    if (debug)
        cout << "SETTING MULTIPLEXER CONTROL TO "<< newControl << endl;

    control = newControl;
    
    execute();
}

void Multiplexer::setInput0(string input){
    if (debug)
        cout << "SETTING MULTIPLEXER INPUT0: "<< binaryOperation.getHexFromBin(input) << endl;
    
    input0 = input;
    
    execute();
}

void Multiplexer::setInput1(string input){
    if (debug)
        cout << "SETTING MULTIPLEXER INPUT1: "<< binaryOperation.getHexFromBin(input) << endl;
    
    input1 = input;
    
    execute();
}

string Multiplexer::getOutput(){
    if (debug)
        cout << "MULTIPLEXER OUTPUT: "<< binaryOperation.getHexFromBin(output) << endl;
    
    return output;

}

void Multiplexer::execute(){
    if(!control){
        output = input0;
    }else{
        output = input1;
    }
}

void Multiplexer::setDebug(bool value)
{
    debug = value;
}
