//
//  DataMemory.cpp
//  301Final
//
//  Created by MacBook Air on 4/13/17.
//  Copyright © 2017 Ubord, Inc. All rights reserved.
//

#include "DataMemory.hpp"

//This is the constructor for DataMemory
DataMemory::DataMemory(){
    memoryMap = map<string, string>();
    //cout << " Memory map "<< memoryMap["0x00000001"] << endl;
}
//This constructor reads in a file of strings
DataMemory::DataMemory(string file){
    
}

//This method reads in a file of strings
void DataMemory::setFile(string file){
    
    
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
            
            //string array holds address and data value, both hex strings
            string stringArray[10];
            int counter = 0;
            for (short i = 0; i<line.length(); i++){
                if (line[i] == ' '){
                    counter++;
                    //move to next index in array to hold data value
                }else{
                    stringArray[counter] += line[i];
                }
            }
            //array[0] is the key/address
            //array[1] is the object/data value
            
            //make all hex numbers uniform - add 0x to all
            if(stringArray[0].substr(0,2)!="0x"){
                stringArray[0] = "0x" + stringArray[0];
            }
            if(stringArray[1].substr(0,2)!="0x"){
                stringArray[1] = "0x" + stringArray[1];
            }
            
            //cout <<"Process check " << stringArray[0] << " " << stringArray[1] << endl;
            memoryMap[stringArray[0]] = stringArray[1];
            
            
        }
    }
    
    //cout << "Memory map test " << memoryMap["0x44578224"] << endl;
}





//This method uses dictionary pairing in order to get an object that is associated with a key
// It receives a string address in the form of a binary string, converts it t hex, finds the key, and converts it back to binary
string DataMemory::getWord(string address){
    
    string hex = getHexFromBin(address);
    cout << "INPUT: " << hex << endl;
    string searchKey =   hex;
    //cout << " Memory map search test "<< memoryMap["0x00000000"] << endl;
    //cout <<"search key " << searchKey << " " << memoryMap[searchKey] << endl;
    string returnWord = getBinFromHex(memoryMap[searchKey]);
    return returnWord;
    
    cout << "OUTPUT: " << hex << endl;
}

//This method is for converting hexadecmial string to binary values
//It receives a hexadecimal string and returns a binary string
string DataMemory::getBinFromHex(string sHex)
{
    string s = sHex;
    stringstream ss;
    ss << std::hex << s;
    unsigned n;
    ss >> n;
    bitset<32> b(n);
    //cout << "Test Return Hex " << b.to_string() << endl;
    
    return b.to_string();
    
}

//This method is for converting binary string to hexadecmial values
//It receives a binary string and returns a hexadecimal string
string DataMemory::getHexFromBin(string sBinary)
{
    if(sBinary != ""){
        std::stringstream ss;
        ss << std::hex << std::stoll(sBinary, NULL, 2);
        //std::cout <<"hex test " << ss.str() << std::endl;
        
        string s =  ss.str();
        while (s.length() != 8){
            s = "0" + s;
        }
        s = "0x" + s;
        return s;
    }else{
        return "0x";
    }
}

//This method intakes a boolen called writeToMemory and determines whether or not it can be overwritten
void DataMemory::setShouldWrite(bool writeToMemory){
    if(debug)
        cout << "DATA MEMORY CAN BE OVERWRITTEN?: (1 yes, 0 no): " << writeToMemory << endl;
    if(tofile);
        //ofile << "DATA MEMORY CAN BE OVERWRITTEN?: (1 yes, 0 no): " << writeToMemory << endl;

    shouldWrite = writeToMemory;
}

//This method intakes a boolen called readFromMemory and determines whether or not it can be read
void DataMemory::setShouldRead(bool readFromMemory){
    if(debug)
        cout << "DATA MEMORY CAN BE READ?: (1 yes, 0 no): " << readFromMemory << endl;

    if(tofile);
        //ofile << "DATA MEMORY CAN BE READ?: (1 yes, 0 no): " << readFromMemory << endl;

    shouldRead = readFromMemory;
}

//This method intakes a string called word and sets the currentWord variable equal to a hexadecimal number
void DataMemory::storeWord(string word){
    if(debug)
        cout << "DATA MEMORY SET WRITE DATA: " << word << endl;
    if(toFile);
        //ofile << "DATA MEMORY SET WRITE DATA: " << word << endl;
    if(word == ""){
        currentWord = "0x";
    }else{
        currentWord = getHexFromBin(word);
        
    }
}

//This method intakes a string called address and sets the currentAddress variable equal to a hexadecimal number
void DataMemory::setCurrentAddress(string address){
    if(debug)
        cout << "DATA MEMORY SET ADDRESS: " << address << endl;
    if(toFile);
        //ofile << "DATA MEMORY SET ADDRESS: " << address << endl;
    if(address == ""){
        currentWord = "0x";
    }else{
        currentAddress = getHexFromBin(address);
    }
}

//This method saves the memory address by setting the currentWord hex number to the address of the memory map
void DataMemory::saveMemory(){
    if(shouldWrite){
        if(debug)
            cout << "DATA MEMORY SAVING:  " << currentWord << "  AT ADDRESS  " << currentAddress << endl;
        if(toFile);
            //ofile << "DATA MEMORY SAVING:  " << currentWord << "  AT ADDRESS  " << currentAddress << endl;
        memoryMap[currentAddress] = currentWord;
    }else{
        if(debug)
            cout << "DATA MEMORY OVERWRITE NOT ENABLED" << endl;
    }
}

//This method reads the memory address by returning the hex value assocaiated with the memory map key and outputting that hex string
string DataMemory::readMemory(){
    if(shouldRead){
        if(debug)
            cout << "MEMORY READ: " << getBinFromHex(memoryMap[currentAddress]) << endl;
        if(tofile);
            //ofile << "MEMORY READ: " << getBinFromHex(memoryMap[currentAddress]) << endl;

        return getBinFromHex(memoryMap[currentAddress]);
    }else{
        if(debug)
            cout << "MEMORY READ NOT ENABLED " <<  endl;

        if(tofile);
            //ofile << "MEMORY READ NOT ENABLED " <<  endl;


    }
    return "";
}
//This method prints
void DataMemory::print(){
    for (const auto &p : memoryMap) {
        std::cout << "memoryMap[" << p.first << "] = " << p.second << '\n';
    }
}

//This is for the debugger, intakes a boolean value
void DataMemory::setDebug(bool value){
    debug = value;
}

void DataMemory::setToFile(bool val){
    tofile = val;
}

/*void DataMemory::setOfStream(ofstream& out){
    ofile = out;
}
*/
