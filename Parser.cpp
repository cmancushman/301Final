//
//  Parser.cpp
//  301Final
//
//  Created by MacBook Air on 4/12/17.
//  Copyright © 2017 Ubord, Inc. All rights reserved.
//

#include "Parser.hpp"

Parser::Parser(){
    
}

Parser::Parser(string file){
    cout <<"beginning" << endl;
    ifstream in;
    in.open(file.c_str());
    if(in.bad()){
        cout <<"BAD FILE" << endl;
    }
    else{
        string line;
        while( getline(in, line)){
            cout << "line: " << line << endl;
        }
    }

}

void Parser::setFile(string file){
    
}
