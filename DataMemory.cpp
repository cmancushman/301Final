//
//  DataMemory.cpp
//  301Final
//
//  Created by MacBook Air on 4/13/17.
//  Copyright © 2017 Ubord, Inc. All rights reserved.
//

#include "DataMemory.hpp"


DataMemory::DataMemory(){
    memoryMap = map<string, string>();
    memoryMap["0xffffffff"] = "0xffffffff";
    cout << " Memory map "<< memoryMap["0xffffffff"] << endl;
}
//This is to read in the file
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


//Step 1: convert binary string into hex
//This method is for converting binary string to hexadecmial values
string DataMemory::getHexFromBin(string sBinary)
{
    std::stringstream ss;
    ss << std::hex << std::stoll(sBinary, NULL, 2);
    std::cout <<"hex test " << ss.str() << std::endl;
    string s = "0x" + ss.str();
    return s;
}

//Step 2: Make a dictionary where the hex is the key, then your dictionary does objectForKey(“ff0d0d0d”) and gets that object
//which should be a hex.

// this is a map, where the keys are hex numbers (strings) and the values are binary strings
string DataMemory::getWord(string address){
    string hex = getHexFromBin(address);
    string searchKey =  hex;
    cout << " Memory map search test "<< memoryMap["0x00000000"] << endl;
    cout <<"search key " << searchKey << " " << memoryMap[searchKey] << endl;
    string returnWord = getBinFromHex(memoryMap[searchKey]);
    return returnWord;
}
//Step 3: Convert the hex to a 32 bit binary string
string DataMemory::getBinFromHex(string sHex)
{
    string s = sHex;
    stringstream ss;
    ss << std::hex << s;
    unsigned n;
    ss >> n;
    bitset<32> b(n);
    cout << "Test Return Hex " << b.to_string() << endl;
    
    return b.to_string();
    
}

//Step 4: Output the binary string
void DataMemory::print(){
    //wordListCompare1 = std::map<key, value> map;<string>();
    //for(int x = 0; x < 32; x++){
      //  cout<<"Binary #"<< x << " : " << wordListCompare1.get(x) << endl;
    //}
}







