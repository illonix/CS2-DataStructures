# Assembler Project
## Overview
This folder contains C++ source files for various assembler-related utilities and examples. The code demonstrates data structure manipulation, sorting algorithms, profiling, and AST (Abstract Syntax Tree) usage. Example programs and supporting documentation are included.

## Files
- `ASTree.hpp`, `ASTree.cpp`: Interface and implementation for an Abstract Syntax Tree.
- `main.cpp`: Main entry point for assembler-related tasks.
- `sort.cpp`, `sort_lib.cpp`, `sort_lib.h`: Sorting algorithms and supporting library.
- `profile.cpp`, `profile.hpp`: Profiling utilities.
- `simple.cpp`, `foo.cpp`: Example programs for testing and demonstration.
- `example-ast.cpp`: Example usage of ASTree.
- `Makefile`: Build instructions for the assembler programs.
- `Lecture-project4.pdf`: Project documentation.
- `*.xml`: SrcML XML representations of C++ source files.

## Features
- Abstract Syntax Tree construction and traversal
- Sorting algorithms (with library support)
- Profiling and performance measurement
- Example programs for demonstration and testing

## Compilation & Usage
To compile and run the assembler programs:
```
make
./main
```
Or compile individual files as needed:
```
g++ -std=c++11 -o simple simple.cpp
./simple
```

# Author
## Interface: Dr. J. Maletic

## Implementation: Jude Skrzat