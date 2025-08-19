# Object Construction Lab
## Overview
This folder contains C++ programs demonstrating object construction, destruction, copy construction, and assignment operator overloading. The code is designed to illustrate the order and behavior of constructors and destructors in C++ classes.

## Files
- `object_construction.hpp`: Interface for the Object class.
- `object_construction.cpp`: Implementation of constructors, destructor, and assignment operator.
- `object_test.cpp`: Test program for object construction and copy behavior.
- `array_bounds_check.cpp`: Demonstrates dynamic memory allocation and array bounds checking.
- `a.out`: Compiled binary (may be generated after building).
- `README.md`: Documentation for the lab.

## Features
- Default constructor, copy constructor, destructor, and assignment operator for Object class
- Demonstrates object creation, copying, and assignment
- Array bounds checking and dynamic memory management example

## Compilation & Usage
To compile and run the object construction tests:
```
g++ -std=c++11 -o object_test object_construction.cpp object_test.cpp
./object_test
```
To compile and run the array bounds check example:
```
clang++ -Wall array_bounds_check.cpp -o bounds_check
./bounds_check
```

# Author
## Interface: Dr. J. Maletic

## Implementation: Jude Skrzat