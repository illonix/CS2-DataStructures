# Infix to Prefix Converter
## Overview
This folder contains a C++ program that converts mathematical expressions from infix notation to prefix notation using a stack and a custom String class. The program reads expressions from a file and outputs the converted prefix expressions.

## Files
- `infix2prefix.cpp`: Main source file for the infix to prefix conversion.
- `data3-1.txt`: Example input file containing infix expressions.
- `README.md`: Documentation for the converter.

## Features
- Reads infix expressions from a file
- Converts infix expressions to prefix notation
- Uses a stack and custom String class for parsing
- Outputs prefix expressions to a file or standard output

## Compilation & Usage
To compile and run the infix to prefix converter:
```
g++ -std=c++11 -o infix2prefix infix2prefix.cpp ../assembler/stack.cpp ../string/string.cpp
./infix2prefix data3-1.txt output.txt
```
If no output file is specified, results are printed to the console.

# Author
## Interface: Dr. J. Maletic

## Implementation: Jude Skrzat