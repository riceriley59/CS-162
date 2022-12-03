Grader (I think): Zakarie Leskowsky

Riley Rice 
ONID: 934127342
12-2-2022

Description:

This program highlights recursive functions, which are functions that break a problem
into smaller problems by calling a copy of itself and solve smaller subproblems of the
original problem. In this program there is a recursive function called pattern which 
prints out a pattern given two parameters n and col. The n parameter is supposed to be 
an even positive number and it specifys how long the longest line in the pattern will be.
col specifys in which column of the output that the pattern will start. This comes together
to print out fractals such as this:

pattern(3, 2):

    *
  * * *  <- this line has 3 * and 2 leading white spaces
    *

pattern(5, 1);

     *
   * * *
     *
 * * * * * <- this line has 5 * and 1 leading white space
     *
   * * *
     *

pattern(7, 0):
      
      *
    * * *
      *
  * * * * *
      *
    * * *
      *
* * * * * * *  this line has 7 * and 0 leading white spaces
      *
    * * *
      *
  * * * * *
      *
    * * *
      *

Instructions:

1. I compile this using make, as it makes everything alot easier especially when there are a lot of files. 
   The main commands for compiling and running this program are:
        make - will just compile all the code
        make run -  will run the binary since it's stored in bin, must be compiled
        make crun - will clear the bin directory, compile it, and then run it
        make clean - will clear out the bin directory
        make valgrind - will clean out the bin directory and recompile then run it with valgrind
        make debug - will clean out the bin directory and recompile then run it with gdb
2. All the .cpp files will be in the src folder and all the header files will be in the include folder. The
   object files and binary will be in the bin folder
3. When you run the program you should expect to see the fractals that I demoed above in the output, and it
   will have prompts that tell you what they are and what parameters pattern was called with.

Limitations:

Some limitations of this program is that it doesn't error handle the input from the user for the n parameter
in the pattern function. Also the pattern function doesn't work correctly when n is an odd number, which maybe 
in the future I could make it so that a even number that's passed into n gets turned into an odd number by adding
or subtracting 1. 
