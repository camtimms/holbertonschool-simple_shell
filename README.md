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
./hsh /
```
root@b70cfa2306fa492baafbd47714396e87-2377118072:~/holbertonschool-simple_shell# ./hsh
$ ls -la
total 84
drwxr-xr-x 6 root root  4096 May  4 22:35 .
drwx------ 1 root root  4096 May  4 15:27 ..
drwxr-xr-x 8 root root  4096 May  4 22:35 .git
-rw-r--r-- 1 root root    30 May  4 22:35 README.md
drwxr-xr-x 2 root root  4096 May  4 22:35 complete_shell
drwxr-xr-x 2 root root  4096 May  4 07:00 exercises
-rw-r--r-- 1 root root  3719 May  4 22:35 helper_functions.c
-rwxr-xr-x 1 root root 17320 May  4 22:35 hsh
-rw-r--r-- 1 root root   421 May  4 22:35 main.h
-rwxr-xr-x 1 root root 17288 May  4 22:35 simple_shell
-rw-r--r-- 1 root root  3607 May  4 22:35 simple_shell.c
drwxr-xr-x 2 root root  4096 May  4 22:35 tests
$ exit
root@b70cfa2306fa492baafbd47714396e87-2377118072:~/holbertonschool-simple_shell# 
```

### Non-Interactive Mode
echo "/bin/ls" | ./hsh /
```
root@b70cfa2306fa492baafbd47714396e87-2377118072:~/holbertonschool-simple_shell# echo "/bin/ls -la /root" | ./hsh
total 52
drwx------ 1 root root 4096 May  4 15:27 .
drwxr-xr-x 1 root root 4096 May  4 04:17 ..
-rw------- 1 root root  625 May  4 16:28 .bash_history
-rw-r--r-- 1 root root 3106 Oct 15  2021 .bashrc
drwxr-xr-x 1 root root 4096 May  4 06:54 .cache
-rw-r--r-- 1 root root   52 May  4 15:27 .gitconfig
drwx------ 4 root root 4096 May  4 04:17 .openvscode-server
-rw-r--r-- 1 root root  161 Jul  9  2019 .profile
-rw------- 1 root root 1840 May  4 07:22 .viminfo
drwxr-xr-x 2 root root 4096 Mar  7 11:23 empty_directory
drwxr-xr-x 6 root root 4096 May  4 22:35 holbertonschool-simple_shell
-rw-r--r-- 1 root root    0 Mar  7 11:23 not_here
-rw-r--r-- 1 root root    0 Mar  7 11:23 old_school
-rw-r--r-- 1 root root    0 Mar  7 11:23 ready_to_be_removed
-rw-r--r-- 1 root root   13 Mar  7 11:23 school
root@b70cfa2306fa492baafbd47714396e87-2377118072:~/holbertonschool-simple_shell#
```

## Limitations


## Checking the man page
To see the man page for this file type the following into the command line:
`man ./man_1_simple_shell` ++++ Add man page and input command for man page`

## Authors
- Bevan Tan  |  https://github.com/Aldore-88/
- Cam Timms  |  https://github.com/camtimms/

![image](https://github.com/user-attachments/assets/2d01ecb4-ac3b-4a44-8020-4d5c436a3613)
