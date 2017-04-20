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
    cout <<" WHAT THE FUCK IS GOING ON" << endl;
    wordListCompare1 = LinkedList<string>();
    
    for(int x = 0; x < 32; x++){
        
        wordListCompare1.add("0x00000000");
        cout << "x : " << x << " " << wordListCompare1.getLast() << endl;
    }
    
}

//Im assuming this method will read in a file of strings
Registers::Registers(string file){
    
}

//This method sets the value of the index and the value of a string
void Registers::setRegister(int index, string value){
    cout << "test begin " << index << " " << value << endl;
    wordListCompare1.set(index, value);
    cout << "test end" << endl;
}

//This method gets the value of the index of the register
void Registers::getRegister(int index){
    wordListCompare1.get(index);
}

//This method prints out the register number
void Registers::print(){
    for(int x = 0; x < 32; x++){
        cout<<"Register #"<< x << " : " << wordListCompare1.get(x) << endl;
    }
}
