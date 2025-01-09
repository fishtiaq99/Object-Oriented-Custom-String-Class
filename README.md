# Object-Oriented Custom String Class

This repository contains an implementation of a custom `String` class in C++ that mimics and extends the functionality of traditional C++ string handling. The class demonstrates object-oriented programming principles, operator overloading, and robust unit testing.

## Features
- **Custom Constructors**: Multiple constructors for flexibility, including default, parameterized, and copy constructors.
- **Operator Overloading**: Supports a variety of operators, including:
  - `+` for concatenation (with other `String` objects, C-strings, or characters).
  - `-` for substring removal.
  - `[]` for accessing characters by index.
  - `()` for finding characters or substrings.
  - `!` to check if the string is empty.
  - `==` for equality comparison.
  - Implicit conversion to `int` for the string's length.
- **Dynamic Memory Management**: Handles dynamic allocation and deallocation efficiently.
- **Friend Functions**: Overloaded `<<` and `>>` operators for console input and output.
- **Unit Tests**: Comprehensive tests using Google Test Framework to ensure functionality.

## Files in the Repository
- **`String.h`**: Header file defining the `String` class and its member functions.
- **`CustomString.cpp`**: Implementation file containing the logic for the `String` class.
- **`test.cpp`**: Unit tests for verifying the correctness of the class's functionality.
- **`Custom String Class Guidelines.pdf`**: Documentation outlining the class design, features, and usage.
- **`Object-Oriented Custom String Class Report.pdf`**: Detailed report on the project, including design decisions and implementation details.

## Getting Started

### Prerequisites
- **C++ Compiler**: Ensure you have a modern C++ compiler (e.g., GCC, Clang, or MSVC) that supports C++11 or later.
- **Google Test Framework**: Install the Google Test framework for running unit tests.
