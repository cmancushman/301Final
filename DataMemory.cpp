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
//This method reads in a file of strings
DataMemory::DataMemory(string file){
    /*cout << "GetInstruction: INPUT:  " << binary strings << "    OUTPUT " << binary strings;
     fstream in;
     in.open(file.c_str());
     
     instructionList = LinkedList<Instruction>();
     if(in.bad()){
     cout <<"BAD FILE" << endl;
     }
     else{
     string line;
     
     
     while( getline(in, line)){
     //cout  << line << endl;
     
     line.erase(std::remove(line.begin(), line.end(), ','), line.end());
     
     std::replace( line.begin(), line.end(), '(', ' ');
     
     std::replace( line.begin(), line.end(), ')', ' ');
     
     string stringArray[10];
     int counter = 0;
     for (short i = 0; i<line.length(); i++){
     if (line[i] == ' '){
     counter++;
     }
     else{
     stringArray[counter] += line[i];
     }
     }
     instructionList.add(toInstruction(stringArray));
     }
     }*/
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



//This method uses dictionary pairing in order to get an object that is associated with a key
// It receives a string address in the form of a binary string, converts it t hex, finds the key, and converts it back to binary
string DataMemory::getWord(string address){
    string hex = getHexFromBin(address);
    string searchKey =   hex;
    //cout << " Memory map search test "<< memoryMap["0x00000000"] << endl;
    //cout <<"search key " << searchKey << " " << memoryMap[searchKey] << endl;
    string returnWord = getBinFromHex(memoryMap[searchKey]);
    return returnWord;
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


//This method prints
void DataMemory::print(){
    //wordListCompare1 = std::map<key, value> map;<string>();
    //for(int x = 0; x < 32; x++){
      //  cout<<"Binary #"<< x << " : " << wordListCompare1.get(x) << endl;
    //}
}







