# CLittleMachine

# Ekip
This project is developed by myself.

# Purpose
The purpose of the project is to interpret a predefined language with its rules and provide the appropriate written output.

# Content
**Src klasörü iç yapısı**

_Text generation is done here._
-generator
 -textGenerator.c

_libfdr source codes_
-lfdr
 -dllist.c
 -fields.c
 -jrb.c
 -jval.c


_Code splitting methods are done here._
-parser 
 -operatorEnum.c
 -parser.c

_Data types, file operations and input controls are done here._
-utils 
 -dataTypes
  -Boolean.c
  -CodeLine.c
  -String.c
 -fileOperations
  -createFile.c
  -readFile.c
 -Ihandler
  -ihandler.c

_main dosyası_
-main.c

# Compile
unix: make
windows: mingw32-make

# Run
After compilation, all project libraries are combined into the ./bin/output file path.

To run the output in the ./bin/output file path, it must take two parameters from the command line.

parameter1: input file path
parameter2: output file path

Recommendation: The 'data' folder is allocated for input and output files, use it.

usage: ./bin/output ./data/input.dat ./data/output.dat

## Output
The program output is printed to the screen as well as written to the output.dat file.