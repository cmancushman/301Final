//
//  Registers.cpp
//  301Final
//
//  Created by MacBook Air on 4/13/17.
//  Copyright © 2017 Ubord, Inc. All rights reserved.
//

#include "Registers.hpp"


Registers::Registers(){
    wordListCompare1 = LinkedList<string>();
    for(int x = 0; x < 32; x++){
        wordListCompare1.add("0x00000000");
    }
    
}

Registers::Registers(string file){
    
}

void Registers::setRegister(int index, string value){
    wordListCompare1.set(index, value);
}

void Registers::getRegister(int index){
    wordListCompare1.get(index);
}

void Registers::print(){
    for(int x = 0; x < 32; x++){
        cout<<"Register #"<< x << " : " << wordListCompare1.get(x) << endl;
    }
}
