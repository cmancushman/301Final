//
//  Registers.hpp
//  301Final
//
//  Created by MacBook Air on 4/13/17.
//  Copyright © 2017 Ubord, Inc. All rights reserved.
//

#ifndef Registers_hpp
#define Registers_hpp

#include <stdio.h>
#include "LinkedList.h"
#include <iostream>
class Registers{
private:
    /*string register0;
    string register1;
    string register2;
    string register3;
    string register4;
    string register5;
    string register6;
    string register7;
    string register8;
    string register9;
    string register10;
    string register11;
    string register12;
    string register13;
    string register14;
    string register15;
    string register16;
    string register17;
    string register18;
    string register19;
    string register20;
    string register21;
    string register22;
    string register23;
    string register24;
    string register25;
    string register26;
    string register27;
    string register28;
    string register29;
    string register30;
    string register31;*/
    
    //This is the declaration of a linked list of strings
    LinkedList<string> wordListCompare1;
    

public:
    //This is the constructor for the Register() function
    Registers();

    //This method reads in a file
    Registers(string file);
    
    //This method sets the value of the index and the value of a string
    void setRegister(int index, string value);
    
    //This method gets the value of the index of the register
    void getRegister(int index);
    
    //This method prints out the register number
    void print();

   /* string getRegister0();
    
    string getRegister1();

    string getRegister2();
    
    string getRegister3();
    
    string getRegister4();
    
    string getRegister5();
    
    string getRegister6();
    
    string getRegister7();
    
    string getRegister8();
    
    string getRegister9();
    
    string getRegister10();
    
    string getRegister11();
    
    string getRegister();
    
    string getRegister();
    
    string getRegister();
    
    string getRegister();
    
    string getRegister();
    
    string getRegister();
    
    string getRegister();
    
    string getRegister();
    
    string getRegister();
    
    string getRegister();
    
    string getRegister();
    
    string getRegister();*/
    
    
    

};
#endif /* Registers_hpp */
