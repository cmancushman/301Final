//
//  BinaryOperation.hpp
//  
//
//  Created by Alex Christine on 4/20/17.
//
//

#ifndef BinaryOperation_hpp
#define BinaryOperation_hpp

#include <stdio.h>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <sstream>
using namespace std;

class BinaryOperation
{
    
private:
    
public:
    BinaryOperation();
    
    string getHexFromBin(string sBinary);
    
    /*
     * Takes a hex string as a parameter and returns its integer representation
     */
    int hexToInt(string hexString);
    
    string intToHex(int integer);
};

#endif /* BinaryOperation_hpp */
