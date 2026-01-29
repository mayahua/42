*This project has been created as part of the 42 curriculum by mhua.*

## Description

libft is a custom C library that replicates and extends a selection of standard C library functions. The goal of this project is to deepen understanding of C programming by re-implementing essential functions for memory management, string manipulation, character checks, and linked list operations. This library serves as a foundational toolkit for future C projects at 42 and beyond.

## Instructions

### Compilation

To compile the library, run: 
```bash
make
```
This will generate a `libft.a` static library file in the root directory.

### Usage

To use libft in your project, include the header file and link the library:
```C
#include "libft.h"
```
### Cleaning
```bash
make clean      # removes object files
make fclean     # removes object files and library
make re         # rebuilds the library
```
## Detailed Library Description

Libft is composed of several groups of functions:

### **1. Standard C Library Re-implementations (Libc Functions)**
A set of functions that mimic the behavior of standard `<ctype.h>`, `<string.h>`, and `<stdlib.h>` utilities.  
Examples include:
- Character checks: `ft_isalpha`, `ft_isdigit`, `ft_isalnum`, `ft_isascii`, `ft_isprint`
- Memory operations: `ft_memset`, `ft_memcpy`, `ft_memmove`, `ft_memchr`, `ft_memcmp`, `ft_bzero`
- String operations: `ft_strlen`, `ft_strlcpy`, `ft_strlcat`, `ft_strncmp`, `ft_strchr`, `ft_strrchr`, `ft_strnstr`
- Conversion: `ft_atoi`
- Dynamic memory: `ft_calloc`, `ft_strdup`

### **2. Additional Utility Functions**
Useful helpers for manipulating strings and memory beyond the libc re-implementations:
- String creators: `ft_substr`, `ft_strjoin`, `ft_strtrim`
- String iteration/mapping: `ft_striteri`, `ft_strmapi`
- Splitting: `ft_split`
- Integer to ASCII: `ft_itoa`

### **3. Linked List Utilities**
A full implementation of a singly linked list API, built around `t_list`:
- Node creation: `ft_lstnew`
- Adding nodes: `ft_lstadd_front`, `ft_lstadd_back`
- List inspection: `ft_lstsize`, `ft_lstlast`
- Node deletion: `ft_lstdelone`, `ft_lstclear`
- Iteration and mapping: `ft_lstiter`, `ft_lstmap`

## Resources

- **C Standard Library Documentation**  
  https://cplusplus.com/reference/clibrary/
- **The GNU C Library Documentation**  
  https://www.gnu.org/software/libc/manual/

### AI Usage

AI tools (such as ChatGPT) were used for:

- Clarifying C standard library function behaviors
- Helping format documentation and comments (including this README)
- Providing code review suggestions and debugging tips

All code implementation and logic were written manually in accordance with 42’s rules.
