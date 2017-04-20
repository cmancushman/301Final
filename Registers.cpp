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

    //need to add memoryMap to this class
    //need to alter anything to account for greater number of lines in file?
    
    fstream in;
    in.open(file.c_str());
    
    if(in.bad()){
        cout <<"BAD FILE" << endl;
    }
    else{
        string line;

        
        while(getline(in, line)){
            //cout  << line << endl;
            
            //replace the colon in input file with a space
            std::replace( line.begin(), line.end(), ':', ' ');
            
            //string array holds register number and accompanying 8-bit hex number
            string stringArray[2];
            int counter = 0;
            for (short i = 0; i<line.length(); i++){
                if (line[i] == ' '){
                    counter++;
                    //move to next index in array to hold hex number
                }else{
                    stringArray[counter] += line[i];
                    //array[0] contains register number
                    //array[1] contains hex value
                }
            }
            //array[0] is the register
            //array[1] is the object

            //make all hex numbers uniform - add 0x to all
            if(stringArray[1].substr(0,2)!="0x"){
                stringArray[1] = "0x" + stringArray[1];
            }

            cout <<"Process check " << stringArray[0] << " " << stringArray[1] << endl; 
            //set LinkedList, pass register as index and hex string as element
            wordListCompare1.set(stoi(stringArray[0]),stringArray[1]);
            
        }
    }

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
