# Get_Next_Line
get_next_line() is a c function that reads a file, and return one line, that was terminated by '\n', per one function call.
If the program calls it in loop, get_next_line() will read whole file, unless there is an error. 

## get_next_line() returns: 

  0 - if the file was read and EOF was found;
  
  1 - if the whole string was read('\n' was found);
  
  -1 - in case of any error.

## Instructions

  Open terminal in project folder (or any you think it should be) and clone this repository
  ```
    https://github.com/CatBraddinton/get_next_line.git
  ```
  Change to get_next_line directory
  ```
    cd get_next_line
  ```
  Change to libft directory
  ```
    cd libft
  ```
  Initialize libft as submodule 
  ```
    git submodule init
  ```
  Clone libft submodule
  ```
    git submodule update
  ```
  And change directory to get_next_line
  ```
    cd ..
  ```
  
  In order to compile the program you can use Makefile.
  ```
    make
  ```
  And finaly execute the program
  ```
    ./test_gnl
  ```
  
## Makefile

### Makefile can do following:

  make all:  will compile test_gnl executable
  
  make get_next_line.o: will compile get_next_line object file
  
  make main.o: will will compile main object file
  
  make clean: removes all oblect files and executable itself

![EVALUATION](https://github.com/CatBraddinton/get_next_line/raw/master/Screen%20Shot%202019-03-17%20at%201.15.20%20PM.png)
