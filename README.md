# Multi-Currency Coin Change Calculator

> **Author:** Rohit Malik | **Language:** C | **Purpose:** Portfolio & Educational

***

## Overview

A modular **C-based application** that calculates optimal coin change for multiple currencies - USD, AUD, and EUR. The project demonstrates structured procedural programming, file I/O handling, and modular code design across both a console-based and a file-driven implementation.

***

## Features

| Feature | Description |
|---|---|
| **Multi-Currency Support** | Handles USD, AUD, and EUR coin denominations |
| **Optimal Coin Change** | Calculates the minimum number of coins for any amount |
| **File-Based Processing** | Reads multiple user records from an input file |
| **Customer Record Search** | Search and retrieve specific user records |
| **CSV Output Generation** | Exports processed results in structured CSV format |
| **Input Validation** | Handles invalid inputs and edge cases gracefully |
| **Modular Design** | Separated `.c` and `.h` files for clean architecture |

***

## Project Structure

```
multi-currency-coin-change/
│
├── basic-version/
│   ├── main.c                  # Entry point for console-based version
│   └── coin_calculator.c/.h    # Core coin change logic
│
└── advanced-version/
    ├── main.c                  # Entry point for file-driven version
    ├── coin_calculator.c/.h    # Core logic with multi-record support
    ├── coins.txt               # Input file with user records
    └── output.csv              # Generated CSV output
```

***

## How to Run

### Basic Version

```bash
# Compile
gcc main.c coin_calculator.c -o calculator

# Run on Windows
calculator

# Run on macOS / Linux
./calculator
```

### Advanced Version

>  Ensure `coins.txt` is placed in the same directory before running.

```bash
# Compile
gcc main.c coin_calculator.c -o calculator_advanced

# Run on Windows
calculator_advanced

# Run on macOS / Linux
./calculator_advanced
```

***

## Technologies Used






- **Language:** C
- **Concepts:** Structs, Arrays, Pointers, File Handling (Text & CSV)
- **Design:** Modular programming with `.c` and `.h` separation
- **Algorithm:** Greedy coin change with input validation

***

## Key Concepts Demonstrated

| Concept | Application |
|---|---|
| **Procedural Programming** | Structured logic using functions and modular files |
| **Data Structures** | Arrays and structs for storing coin and user data |
| **File I/O** | Reading from `.txt` input files, writing to `.csv` output |
| **Algorithmic Thinking** | Greedy algorithm for optimal coin selection |
| **Input Validation** | Error handling for invalid amounts and unsupported currencies |

***

## Future Improvements

- [ ] Graphical user interface (GUI) using a C library (e.g., GTK)
- [ ] Support for additional currencies (GBP, AED, INR)
- [ ] Dynamic currency configuration via external config file
- [ ] Integration with real-time exchange rate APIs

***

## Usage & Credit

This project is shared for **portfolio and educational purposes**. If you use or reference this work, please provide appropriate credit to the author.

***

## Author

**Rohit Malik**
-  rohitmalik180904@gmail.com
-  [GitHub](https://github.com/RohitMalik7)
