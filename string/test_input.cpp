#include "string.hpp"
#include <cassert>
#include <iostream>
#include <fstream>
//tests input

int main() {
    String s;

    std::ifstream inFile;
    inFile.open("input_test.txt");
    if(!inFile){ std::cerr << "File not found: Exiting..."; 
        exit(1); 
    }
    
    for(int i = 0; i < 3; ++i) {

        inFile >> s;

        if(i == 0) {
            assert(s == "apple");
            std::cout << s << std::endl;
        } else if(i == 1) {
            assert(s == "banana");
            std::cout << s << std::endl;
        } else if(i == 2) {
            assert(s == "creativity");
            std::cout << s << std::endl;
        }


    }

    for(int i = 0; i < 6; ++i) {

        inFile >> s;

        if(i == 0) {
            assert(s == "346364");
            std::cout << s << std::endl;
        } else if(i == 1) {
            assert(s == "sdfsef");
            std::cout << s << std::endl;
        } else if(i == 2) {
            assert(s == "082676");
            std::cout << s << std::endl;
        } else if(i == 3) {
            assert(s == "create");
            std::cout << s << std::endl;
        } else if(i == 4) {
            assert(s == "somethingelse");
            std::cout << s << std::endl;
        } else if(i == 5) {
            assert(s == "tenthousdand1");
            std::cout << s << std::endl;
        }
        


    }

    inFile.close();
    std::cout << "Done testing input operator" << std::endl;
}