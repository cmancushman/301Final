//
//  SignExtend.cpp
//  
//
//  Created by Alex Christine on 4/18/17.
//
//

#include "SignExtend.hpp"

SignExtend::SignExtend()
{
    
}

string SignExtend::extend(string input)
{
    cout << "SignExtend INPUT: " << input << endl;
<<<<<<< HEAD
    if (input.front() == "0")
        input = "0000000000000000" + input;
    
    else
        input = "1111111111111111" + input;
=======
    if (input.substr(0,1) == "0"){
        while(input.length() != 32){
            input = "0" + input;
        }
    }else{
        while(input.length() != 32){
            input = "1" + input;
        }
    }
>>>>>>> cb3ff02b44cdba1ada49f2f1422595a1e118acac
    
    cout << "SignExtend OUTPUT: " << input << endl << endl;
    
    return input;
}

