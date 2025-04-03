// File:  add.cpp
//
// Programmer:  Jude Skrzat
// Description: Finished product of opening files for Bigint
//              
//

#include <iostream>
#include <fstream>
#include <cstdlib>
#include "bigint.hpp"


int main() {
    std::ifstream in;
    in.open("data1-1.txt");    // Define stream for input
    if(!in) {                           // Make sure it opened correctly.
        std::cerr << "File not found: data1-1.txt" << std::endl;
        exit(1);
    }

    Bigint x;
    Bigint y;
    
    while((in >> x && in >> y)&& !in.eof()){ 
        std::cout << "the first Bigint is: " << x << std::endl;
        std::cout << "the second Bigint is: " << y << std::endl;

    
        Bigint result = x + y;

        std::cout << "the sum of the Bigints are: " << result << std::endl;
        std::cout << std::endl;
    }
    
    
    //Until end of file
       //Read two Bigints
       //Print them out
       //Add them together
       //Print out results
 
    in.close();
    return 0;
}