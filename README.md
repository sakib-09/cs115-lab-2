# CS 115 Lab 2 — Linked List in C++

An interactive, menu-driven ordered linked list written in C++.

## Files
- `main.cpp` — menu driver (insert, append, delete, print, quit)
- `LinkedList.cpp` / `LinkedList.h` — ordered linked list implementation
- `text.txt` — sample input sequence for quick testing
- `Makefile` — build with `make`, clean with `make clean`

## What I learned
- Singly linked list node management (insert ordered, append, delete)
- Header/implementation separation in C++
- Makefiles with separate compilation of objects

## How to run
```bash
make
./main < text.txt   # or run ./main interactively
make clean
```
