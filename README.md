# Opsis — Modular Calculator (OS Project in C)

This project demonstrates inter-process communication (IPC) and modular program design in C, as part of an Operating Systems course. Each operation (add, multiply, divide, save) is handled by a separate executable. A central controller (`calculator.c`) coordinates these modules.

## Project Context
- Course: Operating Systems
- Language: C
- Year: 2024–2025
- Authors: [Your Name Here]

## Features
- Modular design: each operation is a standalone executable
- Central calculator that communicates with operation modules
- Outputs results to `results.txt`
- Includes project report and screenshots

## Tech Stack
- C language
- GCC
- Unix-based system (recommended)
- Bash/Makefile

## Build & Run
To compile all modules:
bash
make
./calculator


## File Structure
.
├── add.c / add
├── div.c / div
├── mul.c / mul
├── saver.c / saver
├── calculator.c / calculator
├── results.txt
├── makefile
├── OS_Report.pdf
└── screenshot1.png, screenshot2.png

## Notes
Ensure all compiled binaries (add, div, etc.) are in the same directory as calculator.

This project simulates command routing between processes and demonstrates modular OS-level design.
