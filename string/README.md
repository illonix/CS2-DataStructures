# String Class Implementation
## Overview
This repository contains the implementation of a String class in C++. The class provides fundamental string operations and is designed for use with specific test oracles. The implementation includes constructors, operator overloading, utility functions, and additional helper methods.

## Files
`string.hpp`: Interface definition for the `String` class.

`string.cpp`: Implementation of the `String` class methods.

## Features
### Constructors:

- Default constructor

- Character-based constructor

- C-string constructor

- Copy constructor

### Operators:

- `=` (Assignment)

- `+` (Concatenation)

- `==`, `!=`, `<`, `<=`, `>`, `>=` (Comparison)

- `[]` (Indexing)

- `<<`, `>>` (Stream operators)

### Utility Methods:

- `length()`, `capacity()`

- `swap()`

- `substr(start, end)`

- `findch(start, ch)`, `findstr(start, s)`

- `empty()`

- `toInt()`

- `split(delimiter)`

# Compilation & Usage
To compile and use the `String` class:
```
g++ -std=c++11 -o test string.cpp main.cpp
./test
```

# Author
## Interface: Dr. J. Maletic

## Implementation: Jude Skrzat
