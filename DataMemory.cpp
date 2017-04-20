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
    memoryMap["0x00000003"] = "0xffffffff";
    //cout << " Memory map "<< memoryMap["0x00000001"] << endl;
}
//This constructor reads in a file of strings
DataMemory::DataMemory(string file){

}

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
    std::stringstream ss;
    ss << std::hex << std::stoll(sBinary, NULL, 2);
    //std::cout <<"hex test " << ss.str() << std::endl;
    
    string s =  ss.str();
    while (s.length() != 8){
        s = "0" + s;
    }
    s = "0x" + s;
    return s;
}

//This method intakes a boolen called writeToMemory and determines whether or not it can be overwritten
void DataMemory::setShouldWrite(bool writeToMemory){
    cout << "DATA MEMORY CAN BE OVERWRITTEN?: (1 yes, 0 no): " << writeToMemory << endl;
    shouldWrite = writeToMemory;
}

//This method intakes a boolen called readFromMemory and determines whether or not it can be read
void DataMemory::setShouldRead(bool readFromMemory){
    cout << "DATA MEMORY CAN BE READ?: (1 yes, 0 no): " << readFromMemory << endl;
    shouldRead = readFromMemory;
}

//This method intakes a string called word and sets the currentWord variable equal to a hexadecimal number
void DataMemory::storeWord(string word){
    currentWord = getHexFromBin(word);
}

//This method intakes a string called address and sets the currentAddress variable equal to a hexadecimal number
void DataMemory::setCurrentAddress(string address){
    currentAddress = getHexFromBin(address);
}

//This method saves the memory address by setting the currentWord hex number to the address of the memory map
void DataMemory::saveMemory(){
    if(shouldWrite){
        memoryMap[currentAddress] = currentWord;
    }
}

//This method reads the memory address by returning the hex value assocaiated with the memory map key and outputting that hex string
string DataMemory::readMemory(){
    if(shouldRead){
        cout << "MEMORY READ: " << getBinFromHex(memoryMap[currentAddress]) << endl;
        return getBinFromHex(memoryMap[currentAddress]);
    }
    return "";
}
//This method prints
void DataMemory::print(){
    //wordListCompare1 = std::map<key, value> map;<string>();
    //for(int x = 0; x < 32; x++){
      //  cout<<"Binary #"<< x << " : " << wordListCompare1.get(x) << endl;
    //}
}







