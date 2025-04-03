#include <iostream>
#include <fstream>
#include <cstdlib>
#include "bigint.hpp"


int main() {
    std::ifstream in;
    in.open("data1-2.txt");    // Define stream for input
    if(!in) {                           // Make sure it opened correctly.
        std::cerr << "Could not open data1-1.txt, exiting" << std::endl;
        exit(1);
    }

    Bigint biOne;
    Bigint biTwo;
    
    while((in >> biOne && in >> biTwo)&& !in.eof()){ 
        std::cout << "the first Bigint is: " << biOne << std::endl;
        std::cout << "the second Bigint is: " << biTwo << std::endl;

    
        Bigint result = biOne * biTwo;

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