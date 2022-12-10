# Random Pass

A simple C++ program to generate pseudo random passwords.

## Building
to build it on linux, make sure you have gcc/c++ installed and run the `build.sh` file.

## Using
To use this. Build the C++ code, and run the generated binary.  
You can specify the length of the password by doing something like this:
```sh
./pass_gen 15
```
If you don't specify a length, or the length is not a number,  
then it will use a default length of 15 ± 5 (10-20).  
