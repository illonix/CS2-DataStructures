// File: fileio2.cpp
//
// CS II: File IO lab
//
// Compile: clang++ -Wall fileio2.cpp -o fileio
// Usage:   ./fileio FILENAME

#include <iostream>
#include <fstream>

//Part 5 
//Read in a integer that is the number of lines to read
//Each line has only one word on it.
//Use data3.txt

int main(int argc, char *argv[]) {
    std::ifstream inFile(argv[1]);
    if (!inFile.is_open()) {
        std::cout << "Unable to open file: " << argv[1] << std::endl;
        exit(1);
    }


        char ch[100];
        int l = 1;
        int sent = 0;
        int wordCount = 0;

        if (!inFile.eof()) inFile >> sent;
        if (!inFile.eof()) inFile >> ch;
        while(!inFile.eof() && l < sent) {
            
                std::cout << l << ": " << ch << std::endl;
                inFile >> ch;
                ++wordCount;
                l++;
            }
            
        
    std::cout << "Total: " << wordCount << std::endl;
    std::cout << "Done with Part 5" << std::endl << std::endl;
    inFile.close();
    return 0;
}
