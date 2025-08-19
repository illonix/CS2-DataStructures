# Profiler Project
## Overview
This folder contains C++ programs and utilities for profiling source code using srcML XML files. The profiler instruments C++ code to count function and line invocations, and generates reports for performance analysis. Example programs and documentation are included.

## Files
- `main.cpp`: Main entry point for the profiler tool.
- `ASTree.hpp`, `ASTree.cpp`: Interface and implementation for Abstract Syntax Tree manipulation.
- `profile.hpp`, `profile.cpp`: Profile class for tracking function and line counts.
- `sort.cpp`, `sort_lib.cpp`, `sort_lib.h`: Sorting algorithms and supporting library.
- `simple.cpp`, `foo.cpp`: Example programs for testing and demonstration.
- `example-ast.cpp`: Example usage of ASTree.
- `Makefile`: Build instructions for the profiler and related programs.
- `Lecture-project4.pdf`: Project documentation.
- `*.xml`: SrcML XML representations of C++ source files.

## Features
- Instruments C++ code to count function and line invocations
- Generates reports for performance analysis
- Supports profiling multiple source files
- Includes sorting and AST manipulation examples

## Compilation & Usage
To compile the profiler and run it on srcML files:
```
make profiler
./profiler main.cpp.xml utils.cpp.xml
```
This will generate instrumented files prefixed with `p-`, e.g., `p-main.cpp`.

To compile and run example programs:
```
make simple
./simple
make sort
./sort
```

# Author
## Interface: Dr. J. Maletic

## Implementation: Jude Skrzat