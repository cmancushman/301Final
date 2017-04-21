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

//Selects an output based on control. If control is true it outputs input1, if control is false it outputs input2.
void Multiplexer::setControl(bool newControl){
    if (debug)
        cout << "SETTING MULTIPLEXER CONTROL TO "<< newControl << endl;

    if (toFile)
        ofile << "SETTING MULTIPLEXER CONTROL TO "<< newControl << endl;
    
    control = newControl;
    
    execute();
}

//This method intakes a string called input, converts it to a hexadecimal number, and sets it equal to input0
void Multiplexer::setInput0(string input){
    if (debug)
        cout << "SETTING MULTIPLEXER INPUT0: " << binaryOperation.getHexFromBin(input) << endl;
    
    if (toFile)
        ofile << "SETTING MULTIPLEXER INPUT0: " << binaryOperation.getHexFromBin(input) << endl;
    
    input0 = input;
    
    execute();
}

//This method intakes a string called input, converts it to a hexadecimal number, and sets it equal to input1
void Multiplexer::setInput1(string input){
    if (debug)
        cout << "SETTING MULTIPLEXER INPUT1: "<< binaryOperation.getHexFromBin(input) << endl;
    
    if (toFile)
        ofile << "SETTING MULTIPLEXER INPUT1: "<< binaryOperation.getHexFromBin(input) << endl;
    
    input1 = input;
    
    execute();
}

//This method returns the output, which is just a string of hexadecimal numbers
string Multiplexer::getOutput()
{
    if (debug)
        cout << "MULTIPLEXER OUTPUT: "<< binaryOperation.getHexFromBin(output) << endl;
    
    if (toFile)
        ofile << "MULTIPLEXER OUTPUT: "<< binaryOperation.getHexFromBin(output) << endl;
    
    return output;
}

//For this method if control is not true, output is set equal to input0, otherwise output is set equal to input1
void Multiplexer::execute(){
    if(!control){
        output = input0;
    }else{
        output = input1;
    }
}

//This method sets the debug value and is used for debugging purposes
void Multiplexer::setDebug(bool value)
{
    debug = value;
}

void Multiplexer::setToFile(bool val)
{
    toFile = val;
}

void Multiplexer::setOfStream(ofstream& out)
{
    ofile = out;
}
