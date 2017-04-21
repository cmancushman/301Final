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

    
}

//This method pads the string values in the linked list with zeros
void Registers::init(){
    wordListCompare1 = LinkedList<string>();
    
    for(int x = 0; x < 32; x++){
        
        wordListCompare1.add("00000000000000000000000000000000");
    }
}

//Im assuming this method will read in a file of strings
Registers::Registers(string file){
    
}

void Registers::setFile(string file){
     if (debug) cout << "Registers INPUT 1: " << file << endl;

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
void Registers::setWriteIndex(string value){
    if (debug) cout << "setWriteIndex INPUT: " << "  value " << value << endl;
    writeIndex = value;
}

//This method sets the write value of the register by intaking a string called value and setting it equal to a value called writeValue
void Registers::setWriteValue(string value){
    if (debug) cout << "setWriteValue INPUT: " << "  value " << value << endl;
    writeValue = value;
}

//This method intakes a boolean value called write and sets it equal to the value shouldWrite after determining if register memory can be overwritten
void Registers::setWrite(bool write){
    if (debug) cout << "REGISTER MEMORY CAN BE OVERWRITTEN?: (1 yes, 0 no): " << write << endl;
    shouldWrite = write;
}

//This method sets the value of the readRegister1
void Registers::setReadRegister1(string registerNumber){
    if (debug) cout << "setReadRegister1 INPUT: " << "index: " << registerNumber << endl;
    readRegister1 = registerNumber;
}

//This method sets the value of the readRegister2
void Registers::setReadRegister2(string registerNumber){
    if (debug) cout << "setReadRegister2 INPUT: " << "index: " << registerNumber << endl;
    readRegister2 = registerNumber;
}

//This method gets a hex value from a binary string, and if it should write, it sets the values of the index and the writeValue
void Registers::write(){
    if (debug) cout << "writing " << getHexFromBin(writeValue) << " to register $" <<  writeIndex << endl;

    int overwriteIndex;
    if(writeIndex != ""){
        overwriteIndex = stoi(writeIndex);
    }else{
        overwriteIndex = 0;
    }
    if(shouldWrite){
        wordListCompare1.set(overwriteIndex, writeValue);
    }
}

//This method gets the value of the readRegister1
string Registers::getReadRegister1(){
    int searchInt;
    if(readRegister1 != ""){
        searchInt = stoi(readRegister1);
    }else{
        searchInt = 0;
    }
    if (debug) cout << "getReadRegister1 INPUT: " << "index: " << readRegister1 << endl;
    string result = wordListCompare1.get(searchInt);
    if (debug) cout << "getReadRegister1 OUTPUT: " <<  getHexFromBin(result) << endl;
    return result;
}

//This method gets the value of the readRegister2
string Registers::getReadRegister2(){
    int searchInt;
    if(readRegister2 != ""){
        searchInt = stoi(readRegister2);
    }else{
        searchInt = 0;
    }
    if (debug) cout << "getReadRegister2 INPUT: " << "index: " << readRegister2 << endl;
    string result = wordListCompare1.get(searchInt);
    if (debug) cout << "getReadRegister2 OUTPUT: " <<  getHexFromBin(result) << endl;
    return result;
}



//This method prints out the register number
void Registers::print(){
    for(int x = 0; x < 32; x++){
        cout<<"Register #"<< x << " : " << getHexFromBin(wordListCompare1.get(x)) << endl;
    }
}

//This method is for converting hexadecmial string to binary values
//It receives a hexadecimal string and returns a binary string
string Registers::getBinFromHex(string sHex)
{
    string s = sHex;
    stringstream ss;
    ss << std::hex << s;
    unsigned n;
    ss >> n;
    bitset<32> b(n);
    
    return b.to_string();
    
}

//This method is for converting binary string to hexadecmial values
//It receives a binary string and returns a hexadecimal string
string Registers::getHexFromBin(string sBinary)
{
    std::stringstream ss;
    ss << std::hex << std::stoll(sBinary, NULL, 2);
    
    string s =  ss.str();
    while (s.length() != 8){
        s = "0" + s;
    }
    s = "0x" + s;
    return s;
}

/*
* Sets the debug instance variable to true
*/
void Registers::setDebug() {
    debug = true;
}



