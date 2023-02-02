# myStdlib.c
Mock version of stdlib.c for educational purposes

Aaron Quino, University of Illinois at Chicago
Basic string and memory manipulation library

To run tests, first run 'make mem.o', 'make main.o' then 'make run_tests' and then run the generated executable.
The command line for these arguments includes the -fno-builtin option for 
the compiler. All tests pass(1)/fail(-1) as indicated in the output of 
'make run_tests'

Citations

https://www.youtube.com/watch?v=PThPm24wGEo 

used this code in memcpy and memset functions. 
Particularly for the casting of the void arrays.

https://www.cs.auckland.ac.nz/references/unix/digital/AQTLTBTE/DOCU_094.HTM                                              

Used this source as a reference in working with varargs.

https://stackoverflow.com/questions/3982320/convert-integer-to-string-without-access-to-libraries

Looked at this thread to get an idea of how to convert ints to string representations using the modulo operator