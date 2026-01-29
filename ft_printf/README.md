*This project has been created as part of the 42 curriculum by mhua.*

# ft_printf

## Description

**ft_printf** is a reimplementation of the standard C library function `printf`.  
The goal of this project is to gain a deep understanding of variadic functions, formatted output, and low-level I/O operations in C.

The project consists of writing a function, `ft_printf`, that reproduces the behavior of `printf` for a defined set of format specifiers, while respecting the coding standards and constraints of the 42 curriculum.

Supported conversions typically include:
- `%c` (character)
- `%s` (string)
- `%p` (pointer)
- `%d` / `%i` (signed integer)
- `%u` (unsigned integer)
- `%x` / `%X` (hexadecimal)
- `%%` (percent sign)

The function returns the total number of characters printed, just like the original `printf`. But unlike the standard `printf`, which uses internal buffering mechanisms, ft_printf writes directly to standard output using low-level system calls and does not implement output buffering.

## Instructions

### Compilation

The project is compiled into a static library called `libftprintf.a`.

To compile the library, run: 
```bash
make
```
This will generate the `libftprintf.a` library.

### Usage

1. Include the header file in your source:
```C
#include "ft_printf.h"
```
2. Compile your program with the library:
```C
cc main.c libftprintf.a
```

### Cleaning

```bash
make clean      # removes object files
make fclean     # removes object files and library
make re         # rebuilds the library
```

## Algorithm and Data Structures

### General Algorithm

The format string is processed character by character:

1. Characters that are not `%` are written directly to the output.
2. When `%` is encountered, the following character is interpreted as a format specifier.
3. The corresponding argument is extracted using `va_arg`.
4. A dedicated handler function prints the value.
5. The number of printed characters is accumulated and returned.

### Variadic Arguments

The project uses the `<stdarg.h>` library to manage variadic arguments:
- `va_start` initializes the argument list.
- `va_arg` retrieves each argument according to its type.
- `va_end` cleans up the argument list.

### Data Structures

No complex data structures are required.

The implementation relies on:
- Primitive data types for counters and numeric values
- Pointers for strings and memory addresses
- Recursive or iterative functions for number conversion

### Number Conversion

Numeric values are converted manually without using standard library formatting functions:
- Signed integers handle negative values explicitly
- Unsigned integers are converted in base 10
- Hexadecimal values are converted in base 16

Digits are printed in the correct order using recursion or iterative division.

## Resources

### References

- `man printf`
- `man stdarg`
- https://www.geeksforgeeks.org/c/variadic-functions-in-c/
- https://en.cppreference.com/w/c/variadic
- https://en.cppreference.com/w/c/io/fprintf

These references were used to understand the expected behavior of `printf` and variadic functions in C.

### AI Usage

AI tools were used for:

- Clarifying C standard library function behaviors
- Helping format documentation and comments (including this README)
- Providing code review suggestions and debugging tips

All code implementation and logic were written manually in accordance with 42’s rules.
