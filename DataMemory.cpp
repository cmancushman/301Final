//
//  DataMemory.cpp
//  301Final
//
//  Created by MacBook Air on 4/13/17.
//  Copyright © 2017 Ubord, Inc. All rights reserved.
//

#include "DataMemory.hpp"

//This is to read in the file 
DataMemory::DataMemory(string file){
	cout << "GetInstruction: INPUT:  " << binary strings << "    OUTPUT " << binary strings;
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
    }
}


//Step 1: convert binary string into hex
//This method is for converting binary string to hexadecmial values
DataMemory::GetHexFromBin(string sBinary)
{
	string rest("0x"),tmp,chr = "0000";
	int len = sBinary.length()/4;
	chr = chr.substr(0,len);
	sBinary = chr+sBinary;
	for (int i=0;i<sBinary.length();i+=4)
	{
		tmp = sBinary.substr(i,4);
		if (!tmp.compare("0000"))
		{
			rest = rest + "0";
		}
		else if (!tmp.compare("0001"))
		{
			rest = rest + "1";
		}
		else if (!tmp.compare("0010"))
		{
			rest = rest + "2";
		}
		else if (!tmp.compare("0011"))
		{
			rest = rest + "3";
		}
		else if (!tmp.compare("0100"))
		{
			rest = rest + "4";
		}
		else if (!tmp.compare("0101"))
		{
			rest = rest + "5";
		}
		else if (!tmp.compare("0110"))
		{
			rest = rest + "6";
		}
		else if (!tmp.compare("0111"))
		{
			rest = rest + "7";
		}
		else if (!tmp.compare("1000"))
		{
			rest = rest + "8";
		}
		else if (!tmp.compare("1001"))
		{
			rest = rest + "9";
		}
		else if (!tmp.compare("1010"))
		{
			rest = rest + "A";
		}
		else if (!tmp.compare("1011"))
		{
			rest = rest + "B";
		}
		else if (!tmp.compare("1100"))
		{
			rest = rest + "C";
		}
		else if (!tmp.compare("1101"))
		{
			rest = rest + "D";
		}
		else if (!tmp.compare("1110"))
		{
			rest = rest + "E";
		}
		else if (!tmp.compare("1111"))
		{
			rest = rest + "F";
		}
		else
		{
			continue;
		}
	}
	return rest;
}

//Step 2: Make a dictionary where the hex is the key, then your dictionary does objectForKey(“ff0d0d0d”) and gets that object 
//which should be a hex.

// this is a map, where the keys are hex numbers (strings) and the values are binary strings
DataMemory::Mapping(string rest)
std::map<string, string> result;
NSArray* keys = [dictionary allKeys];
for(id key in keys)
{        
    id value = [dictionary objectForKey: key];
    string fValue = [value stringValue];
    string index = [key stringValue];
    result[index] = fValue;
}


//Step 3: Convert the hex to a 32 bit binary string
DataMemory::GetBinFromHex(string sHex)
{
	string hexRest("0x"),tmp,chr = "0000";
	int len = sHex.length()/1;
	chr = chr.substr(0,len);
	sHex = chr+sHex;
	for (int i=0;i<sHex.length();i+=1)
	{
		tmpHex = sHex.substr(i,1);
		if (!tmpHex.compare("0"))
		{
			hexRest = hexRest + "0000";
		}
		else if (!tmpHex.compare("1"))
		{
			hexRest = hexRest + "0001";
		}
		else if (!tmpHex.compare("2"))
		{
			hexRest = hexRest + "0010";
		}
		else if (!tmpHex.compare("3"))
		{
			hexRest = hexRest + "0011";
		}
		else if (!tmpHex.compare("4"))
		{
			hexRest = hexRest + "0100";
		}
		else if (!tmpHex.compare("5"))
		{
			hexRest = hexRest + "0101";
		}
		else if (!tmpHex.compare("6"))
		{
			hexRest = hexRest + "0110";
		}
		else if (!tmpHex.compare("7"))
		{
			hexRest = hexRest + "0111";
		}
		else if (!tmpHex.compare("8"))
		{
			hexRest = hexRest + "1000";
		}
		else if (!tmpHex.compare("9"))
		{
			hexRest = hexRest + "1001";
		}
		else if (!tmpHex.compare("A"))
		{
			hexRest = hexRest + "1010";
		}
		else if (!tmpHex.compare("B"))
		{
			hexRest = hexRest + "1011";
		}
		else if (!tmpHex.compare("C"))
		{
			hexRest = hexRest + "1100";
		}
		else if (!tmpHex.compare("D"))
		{
			hexRest = hexRest + "1101";
		}
		else if (!tmpHex.compare("E"))
		{
			hexRest = hexRest + "1110";
		}
		else if (!tmpHex.compare("F"))
		{
			hexRest = hexRest + "1111";
		}
		else
		{
			continue;
		}
	}
	return hexRest;
}

//Step 4: Output the binary string
void DataMemory::print(){
	wordListCompare1 = std::map<key, value> map;<string>();
    for(int x = 0; x < 32; x++){
        cout<<"Binary #"<< x << " : " << wordListCompare1.get(x) << endl;
    }
}







