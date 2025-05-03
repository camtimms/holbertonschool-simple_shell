# holbertonschool-simple_shell

A basic UNIX command line interpreter (shell) written in C. This shell accepts and executes user commands similarly to `/bin/sh`.

## Installation:
To run the shell, use `git clone https://github.com/camtimms/holbertonschool-simple_shell.git`

## How to Compile

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

README.md           |  Readme file, containing information about this project
simple_shell.c      |  
helper_functions.c  |  
main.h              |  

## Authors
- Bevan Tan  |  https://github.com/Aldore-88/
- Cam Timms  |  https://github.com/camtimms/
