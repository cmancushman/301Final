//
//  Registers.cpp
//  301Final
//
//  Created by MacBook Air on 4/13/17.
//  Copyright © 2017 Ubord, Inc. All rights reserved.
//

#include "Registers.hpp"

//This method is the constructor and puts values in a linked list
Registers::Registers(){
    wordListCompare1 = LinkedList<string>();
    
    for(int x = 0; x < 32; x++){
        
        wordListCompare1.add("0x00000000");
    }
    
}

//Im assuming this method will read in a file of strings
Registers::Registers(string file){
    
}

//This method sets the value of the index and the value of a string
void Registers::setRegister(int index, string value){
    cout << "setRegister INPUT: " << "index: " << index << "  value " << value << endl;
    wordListCompare1.set(index, value);
}

//This method gets the value of the index of the register
string Registers::getRegister(int index){
    cout << "getRegister INPUT: " << "index: " << index << endl;
    string result = wordListCompare1.get(index);
    cout << "getRegister OUTPUT: " <<  result << endl;
    return result;
}

//This method prints out the register number
void Registers::print(){
    for(int x = 0; x < 32; x++){
        cout<<"Register #"<< x << " : " << wordListCompare1.get(x) << endl;
    }
}
