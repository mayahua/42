*This project has been created as part of the 42 curriculum by mhua.*

# get_next_line

## Description

`get_next_line` is a C programming project whose goal is to implement a function that reads a file or input stream, returning one line at a time with each call. This function is designed to handle files of any size, lines of arbitrary length, and must manage memory efficiently. The bonus version extends the basic functionality to support reading from multiple file descriptors simultaneously. This means you can read from several files or streams in an interleaved fashion, and the function will keep track of the reading state for each file descriptor independently.

## Instructions

### Compilation

To compile the project, use the following command:

```sh
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line(_bonus).c get_next_line_utils(_bonus).c main.c -o gnl
```
You can set BUFFER_SIZE to any positive integer to control the read buffer size.

### Usage

Include the header in your C file:

```C
#include "get_next_line(_bonus).h"
```
Call the function as follows:

```C
char *line = get_next_line(fd);
```

fd is the file descriptor to read from.

### Algorithm

The core algorithm is designed to efficiently read a file or input stream line by line, regardless of line length or file size. The function reads data in chunks of `BUFFER_SIZE` bytes, appending new data to a buffer (called the "remainder") until a newline character is found or the end of the file is reached.

**Key Steps**
1. **Read and Accumulate:** Read from the file descriptor into a buffer and append this data to the remainder.
2. **Extract Line:** Search the remainder for a newline character. If found, extract and return the line up to and including the newline. If not found, continue reading and accumulating.
3. **Update Remainder:** After extracting a line, update the remainder to contain any leftover data after the newline, to be used in the next call.
4. **Return:** Return the extracted line (including the newline character, if present), or `NULL` if there is nothing left to read or an error occurs.

**Bonus**  
To support reading from multiple file descriptors simultaneously, the bonus version uses a static array of pointers, indexed by file descriptor. This allows the function to maintain a separate remainder for each open file descriptor, ensuring that the reading state for each file is preserved independently.

**Justification**  
This approach is robust and efficient, as it minimizes the number of read operations, handles lines of any length, and ensures proper memory management. Using a static array indexed by file descriptor is a simple and effective way to support multiple files without complex data structures, as file descriptors are small integers.

## Resources

- https://www.geeksforgeeks.org/c/static-variables-in-c/
- man getline

**Use of AI**: All code was written and tested manually; AI was used as a supplementary resource for learning and documentation.
