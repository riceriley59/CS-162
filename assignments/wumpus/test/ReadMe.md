Name: Riley Rice
ONID: 934127342
Section: CS162-010
Hunt the Wumpus, due 11/20/2022

Usage:

I compile this using make, as it makes everything alot easier especially when there are a lot of files.
The main commands for compiling and running this program are:

    make - will just compile all the code
    make run -  will run the binary since it's stored in bin, must be compiled
    make crun - will clear the bin directory, compile it, and then run it
    make clean - will clear out the bin directory
    make valgrind - will clean out the bin directory and recompile then run it with valgrind
    make debug - will clean out the bin directory and recompile then run it with gdb

Description: 

This is the Hunt the Wumpus game, you are exploring the wumpus's cave trying to kill it and get it's gold. 
You need to kill the wumpus, get the gold, and then escape from where you started. Although, you have to be
careful there are also bottomless pits and bats in the cave which can make your adventure even more dangerous.

Instructions:

1. You will move using the wasd keys, w moves you up, s move you down, a moves you left, and d moves you right. 

2. If you want to shoot an arrow to kill the wumpus then press space, and once your press that you 
can choose the direction you want using the wasd keys just like above. If you accidently press the space you can 
cancel your shot by pressing e. 

3. If at any time you want to quit the game you can simply press the 'q' button.

4. You will be prompted for the size of the grid you want, this can only be from 5 to 7

5. You will be prompted for the debug mode you want, press 't' if you want debug mode and want to see where all the
events are, otherwise press 'f'.

6. At the end of each game you will be asked if you want to play again or not press 't' if you want to and 'f' if
you don't. If you do you will also be asked if you want to play with the same cave configuration with the events at 
the same location as last time. Input 't' if you want to and 'f' if you dont want to.
