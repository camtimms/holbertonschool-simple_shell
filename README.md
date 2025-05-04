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
```
root@b70cfa2306fa492baafbd47714396e87-2377118072:~/holbertonschool-simple_shell# ./hsh
$ pwd
/root/holbertonschool-simple_shell
$ ls
README.md  complete_shell  exercises  helper_functions.c  hsh  main.h  simple_shell  simple_shell.c  tests
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
env
```
root@b70cfa2306fa492baafbd47714396e87-2377118072:~/holbertonschool-simple_shell# ./hsh
$ env
SHELL=/bin/bash
PWD=/root/holbertonschool-simple_shell
LOGNAME=root
MOTD_SHOWN=pam
HOME=/root
LS_COLORS=rs=0:di=01;34:ln=01;36:mh=00:pi=40;33:so=01;35:do=01;35:bd=40;33;01:cd=40;33;01:or=40;31;01:mi=00:su=37;41:sg=30;43:ca=30;41:tw=30;42:ow=34;42:st=37;44:ex=01;32:*.tar=01;31:*.tgz=01;31:*.arc=01;31:*.arj=01;31:*.taz=01;31:*.lha=01;31:*.lz4=01;31:*.lzh=01;31:*.lzma=01;31:*.tlz=01;31:*.txz=01;31:*.tzo=01;31:*.t7z=01;31:*.zip=01;31:*.z=01;31:*.dz=01;31:*.gz=01;31:*.lrz=01;31:*.lz=01;31:*.lzo=01;31:*.xz=01;31:*.zst=01;31:*.tzst=01;31:*.bz2=01;31:*.bz=01;31:*.tbz=01;31:*.tbz2=01;31:*.tz=01;31:*.deb=01;31:*.rpm=01;31:*.jar=01;31:*.war=01;31:*.ear=01;31:*.sar=01;31:*.rar=01;31:*.alz=01;31:*.ace=01;31:*.zoo=01;31:*.cpio=01;31:*.7z=01;31:*.rz=01;31:*.cab=01;31:*.wim=01;31:*.swm=01;31:*.dwm=01;31:*.esd=01;31:*.jpg=01;35:*.jpeg=01;35:*.mjpg=01;35:*.mjpeg=01;35:*.gif=01;35:*.bmp=01;35:*.pbm=01;35:*.pgm=01;35:*.ppm=01;35:*.tga=01;35:*.xbm=01;35:*.xpm=01;35:*.tif=01;35:*.tiff=01;35:*.png=01;35:*.svg=01;35:*.svgz=01;35:*.mng=01;35:*.pcx=01;35:*.mov=01;35:*.mpg=01;35:*.mpeg=01;35:*.m2v=01;35:*.mkv=01;35:*.webm=01;35:*.webp=01;35:*.ogm=01;35:*.mp4=01;35:*.m4v=01;35:*.mp4v=01;35:*.vob=01;35:*.qt=01;35:*.nuv=01;35:*.wmv=01;35:*.asf=01;35:*.rm=01;35:*.rmvb=01;35:*.flc=01;35:*.avi=01;35:*.fli=01;35:*.flv=01;35:*.gl=01;35:*.dl=01;35:*.xcf=01;35:*.xwd=01;35:*.yuv=01;35:*.cgm=01;35:*.emf=01;35:*.ogv=01;35:*.ogx=01;35:*.aac=00;36:*.au=00;36:*.flac=00;36:*.m4a=00;36:*.mid=00;36:*.midi=00;36:*.mka=00;36:*.mp3=00;36:*.mpc=00;36:*.ogg=00;36:*.ra=00;36:*.wav=00;36:*.oga=00;36:*.opus=00;36:*.spx=00;36:*.xspf=00;36:
SSH_CONNECTION=10.43.196.100 44870 10.42.60.64 22
LESSCLOSE=/usr/bin/lesspipe %s %s
TERM=xterm-256color
LESSOPEN=| /usr/bin/lesspipe %s
USER=root
SHLVL=1
SSH_CLIENT=10.43.196.100 44870 22
DEBUGINFOD_URLS=
PATH=/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games:/snap/bin
SSH_TTY=/dev/pts/3
_=./hsh
OLDPWD=/root
$
```

exit
```
root@b70cfa2306fa492baafbd47714396e87-2377118072:~/holbertonschool-simple_shell# ./hsh
$ exit
root@b70cfa2306fa492baafbd47714396e87-2377118072:~/holbertonschool-simple_shell#
```

### Non-Interactive Mode
echo "/bin/ls -la /root" | ./hsh
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
This is a project from Holberton School to create a simple shell, full functionalities are not all fleshed out and are following the below critera:

### Project Requirements
#### General
- Allowed editors: vi, vim, emacs
- All your files will be compiled on Ubuntu 20.04 LTS using gcc, using the options -Wall -Werror -Wextra -pedantic -std=gnu89
- All your files should end with a new line
- A README.md file, at the root of the folder of the project is mandatory
- Your code should use the Betty style. It will be checked using betty-style.pl and betty-doc.pl
- Your shell should not have any memory leaks
- No more than 5 functions per file
- All your header files should be include guarded
- Use system calls only when you need to (why?)

### Project Tasks

#### 0. README, man, AUTHORS

Write a README
Write a man for your shell.
You should have an AUTHORS file at the root of your repository, listing all individuals having contributed content to the repository. Format, see Docker

#### 1. Betty would be proud

Write a beautiful code that passes the Betty checks

#### 2. Simple shell 0.1

Write a UNIX command line interpreter.

Usage: simple_shell
Your Shell should:

Display a prompt and wait for the user to type a command. A command line always ends with a new line.
The prompt is displayed again each time a command has been executed.
The command lines are simple, no semicolons, no pipes, no redirections or any other advanced features.
The command lines are made only of one word. No arguments will be passed to programs.
If an executable cannot be found, print an error message and display the prompt again.
Handle errors.
You have to handle the “end of file” condition (Ctrl+D)
You don’t have to:

use the PATH
implement built-ins
handle special characters : ", ', `, \, *, &, #
be able to move the cursor
handle commands with arguments
execve will be the core part of your Shell, don’t forget to pass the environ to it…

#### 3. Simple shell 0.2

Handle command lines with arguments
#### 4. Simple shell 0.3

Handle the PATH
fork must not be called if the command doesn’t exist

#### 5. Simple shell 0.4

Implement the exit built-in, that exits the shell
Usage: exit
You don’t have to handle any argument to the built-in exit

#### 6. Simple shell 1.0

Implement the env built-in, that prints the current environment

## Checking the man page
To see the man page for this file type the following into the command line:
`man ./man_1_simple_shell` ++++ Add man page and input command for man page`

## Authors
- Bevan Tan  |  https://github.com/Aldore-88/
- Cam Timms  |  https://github.com/camtimms/

![image](https://github.com/user-attachments/assets/2d01ecb4-ac3b-4a44-8020-4d5c436a3613)
