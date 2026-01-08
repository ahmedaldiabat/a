*his activity has been created as part of the 42 curriculum by aaldiaba*

<h2>                Description                 <h2>

<p> get_next_line is a function that reads a file descriptor and returns one line at a time, including the newline character (\n) if it exists. Each call to the function returns the next line from the file until the end of file (EOF) is reached, at which point the function returns NULL.

The function handles files of any size and works independently of the buffer size used for reading. It uses a static variable to store unread data between calls, allowing it to correctly manage cases where lines are split across multiple reads or when multiple lines are read at once.

This project focuses on:

Understanding file descriptors and the read() system call

Managing dynamic memory safely

Handling edge cases such as EOF, empty files, and files without a trailing newline

Writing clean, Norminette-compliant code

The implementation is designed to work with different BUFFER_SIZE values, including very small sizes (e.g. BUFFER_SIZE = 1), without changing the core logic.<p>

<h2>                Instructions                <h2>

<h3>                Compilation                 <h3>

# Compilation
cc -Wall -Wextra -Werror get_next_line.c get_next_line_utils.c

# Compilation with a custom BUFFER_SIZE
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 \
get_next_line.c get_next_line_utils.c

# Example including a test main file
cc -Wall -Wextra -Werror -D BUFFER_SIZE=1 \
get_next_line.c get_next_line_utils.c main.c

<h2>                Resources                   <h2>

For static variables : https://www.geeksforgeeks.org/static-variables-in-c/
For read : The manual & Some resources on GeeksforGeeks
For common mistakes & edge cases : https://github.com/augustobecker/get_next_line
For Buffer Size : GeeksforGeeks
