// File:        main.cpp   
//
// KSU CS 23001 Project 2
//
// Version:     1.1
// Date:       
// Author:    
//
// Description: Main body for logview application
//
 
#include "string.hpp"
#include "logentry.hpp"
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <vector>


int main(int argc, char *argv[]) {
    std::vector<String> option(3);
    option[0] = "all";
    option[1] = "bytes";
    option[2] = "host";
    if (argc != 3) {                                //3 things should be on the command line
        std::cerr << "Error" << std::endl;
        std::cerr << "Usage: " << argv[0] << " [ "
        << option[0] << " | "
        << option[1] << " | "
        << option[2] << " ] log_file" << std::endl;
        exit(1);                                     //Exit with error
    }

    std::ifstream in(argv[2]);                       //Open file
    if (!in) {                                       //Quit if open fails
        std::cerr << "Error: Can not open file: " << argv[2] << std::endl;
        exit(2);
    }
    std::vector<LogEntry> log_entries = parse(in);   //Process the log file
    in.close();

    if (argv[1] == option[0]) {                      //Handle the specified option
        output_all(std::cout, log_entries);
    } else if (argv[1] == option[1]) {
        std::cout << "Total number of bytes sent: "
                  << byte_count(log_entries) << std::endl;
    } else if (argv[1] == option[2]) {
        by_host(std::cout, log_entries);
    } else {                                          //Error, bad option
        std::cerr << "Invalid option: " << argv[1] << std::endl;
        std::cerr << "Valid options: "
             << option[0] << " "
             << option[1] << " "
             << option[2] << std::endl;
        exit(3);
    }
    return 0;
}
