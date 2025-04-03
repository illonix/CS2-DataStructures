# Bigint Class Implementation
## Overview
This repository contains the implementation of a Bigint class in C++. The class provides fundamental operations for handling large integers and is designed for use with specific test oracles. The implementation includes constructors, operator overloading, utility functions, and additional helper methods.

## Files
`bigint.hpp`: Interface definition for the `Bigint` class.

`bigint.cpp`: Implementation of the `Bigint` class methods.

## Features
### Constructors:

- Default constructor

- Integer-based constructor

- C-string constructor

### Operators:

- `=` (Assignment)

- `+` (Addition)

- `*` (Multiplication)

- `==` (Equality)

- `[]` (Indexing)

- `<<`, `>>` (Stream operators)

### Utility Methods:

- `debugPrint(std::ostream&)`

- `timesDigit(int)`

- `times10(int)`

# Compilation & Usage
To compile and use the `Bigint` class:
``` g++ -std=c++11 -o test bigint.cpp main.cpp ./test ```

# Author
## Interface: Dr. J. Maletic

## Implementation: Jude Skrzat
