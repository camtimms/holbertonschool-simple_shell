![image](https://github.com/user-attachments/assets/c01ff38b-23cf-4011-a8fe-06f440a77c92)

# Holbertonschool - Simple Shell

A basic UNIX command line interpreter (shell) written in C. This shell accepts and executes user commands similarly to `/bin/sh`.

## Installation:
To run the shell, use `git clone https://github.com/camtimms/holbertonschool-simple_shell.git`

## How to compile

`gcc -Wall -Werror -Wextra -pedantic *.c -o hsh`

## Features

- Interactive mode: prompts for user input with `$ ` and executes if a valid command is entered.
- Built-in commands:
  - `exit`: exits the shell with the last returned status.
  - `env`: prints the current environment.
- Other useful commands:
  - `ls`: lists the current directory files.
  - `pwd`: prints current working directory.
- Parses user input into tokens.
- Locates executables using the `PATH` environment variable.
- Executes valid commands via `fork` and `execve`.
- Memory-safe implementation using dynamic memory allocation and deallocation.

## Exiting the shell
- Exiting can be done via the `exit` builtin functoin.
- Or through `Ctrl + C` shortcut.

## Files

- README.md           |  Readme file, containing information about this project.
- simple_shell.c      |  Main file of the project, uses most functions for executing the program.
- helper_functions.c  |  Contains the helping functions that are called in `main`.
- main.h              |  Header file containing the funciton declarations and libraries used.

## Examples
### Interactive Mode
./hsh
![Screenshot 2025-05-05 083751](https://github.com/user-attachments/assets/9d918994-5861-4316-a39f-d1c16c222d44)


### Non-Interactive Mode
echo "/bin/ls" | ./hsh
<img width="799" alt="image" src="https://github.com/user-attachments/assets/b8fe7bac-858c-4e5b-a28c-72644dbf78ff" />

## Limitations


## Checking the man page
To see the man page for this file type the following into the command line:
`man ./man_1_simple_shell` ++++ Add man page and input command for man page`

## Authors
- Bevan Tan  |  https://github.com/Aldore-88/
- Cam Timms  |  https://github.com/camtimms/

![image](https://github.com/user-attachments/assets/2d01ecb4-ac3b-4a44-8020-4d5c436a3613)
