# File IO Lab
## Overview
This folder contains C++ programs demonstrating various file input/output operations. The code covers character counting, word counting, line counting, and reading structured data from files.

## Files
- `fileio.cpp`: Main source file with multiple parts for different file IO tasks.
- `fileio2.cpp`: Reads a specified number of lines from a file, each containing one word.
- `data1.txt`, `data2.txt`, `data3.txt`: Example data files for testing file IO operations.
- `a.out`: Compiled binary (may be generated after building).
- `README.md`: Documentation for the lab.

## Features
- Count every character in a file
- Count non-whitespace characters
- Count words in a file
- Count lines in a file
- Read a specified number of words from a file

## Compilation & Usage
To compile and run the file IO programs:
```
g++ -std=c++11 -o fileio fileio.cpp
./fileio data1.txt
```
Or for the second program:
```
g++ -std=c++11 -o fileio2 fileio2.cpp
./fileio2 data3.txt
```

# Author
## Interface: Dr. J. Maletic

## Implementation: Jude Skrzat