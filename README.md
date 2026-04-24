# Multi-Currency Coin Change Calculator (C)

## Overview
This project is a modular C-based application designed to calculate optimal coin change for multiple currencies, including USD, AUD, and EUR.

The application demonstrates structured programming and problem-solving using procedural programming principles. It includes both a basic console-based version and an advanced file-driven implementation that processes multiple user records and generates structured output.

## Key Features
- Multi-currency support (USD, AUD, EUR)
- Optimal coin change calculation
- Modular program structure using header and source files
- File-based input processing
- Customer record search functionality
- CSV output generation for processed data
- Input validation and error handling

## Project Structure

basic-version/
- Console-based version for single user interaction  
- Implements core logic for coin change calculation  

advanced-version/
- File-driven version using structured records  
- Processes multiple users from input file  
- Generates output in CSV format  

## Technologies Used
- C Programming Language
- File Handling (Text and CSV)
- Structs and Arrays
- Modular Programming (.c and .h separation)

## How to Run

### Compile
gcc main.c coin_calculator.c -o calculator
### Run
./calculator

For the advanced version, ensure that the input file (coins.txt) is placed in the same directory before running the program.

## Key Concepts Demonstrated
- Procedural programming in C
- Modular code design
- Data structures (arrays and structs)
- File input/output operations
- Algorithmic problem solving

## Future Improvements
- Graphical user interface (GUI)
- Support for additional currencies
- Dynamic currency configuration
- Integration with real-time exchange rate APIs

## Author
Rohit Malik

## Note
This project represents a foundational and intermediate-level implementation of C programming concepts, focusing on modular design, structured logic, and real-world problem-solving.
