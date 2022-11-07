/*********************************************************************
** Filename Program: main.cpp GoFish
** Author: Riley Rice
** Date: 11-6-2022
** Description: This is the driver file for my GoFish program. It's the common
GoFish game but on the command line. You ask for a rank, that you must also have 
in your hand and if the other player has that rank in their hand then they have to 
give you all of their cards of that rank then you get another turn. If they don't have 
that rank in their hand then you go fish and you take a card from the deck, and then vice 
versa when it's the other players turn. Once you get all of the ranks in the deck in your 
hand so 4 then you get a book and they go down. Whoever finishs the game with the most books wins. 
** Input: You input your guess for a rank
** Output: If they have that rank in their hand then they give all of those to you, and you get 
another turn. otherwise you go fish and take a card from the deck and it's the other player's turn.
Although if the card you pull from the deck is the same rank of the one you requested then you get 
another turn.  
*********************************************************************/

//include game class definition
#include "game.h"

/*********************************************************************
** Function: Main entry point for the program
** Description: This is the where the program begins and ends, it's the 
main function
** Parameters: NONE
** Pre-Conditions: No program is running
** Post-Conditions: Gofish program is run and corresponding game methods
are called so that the game runs how it was intended
*********************************************************************/
int main(){
    bool playagain = false; //boolean for handling if they want to play again

    //do while they want to play and redo if they want to play again
    do{
        //set seed for rand() function using time
        srand(time(NULL));

        //create a new game object
        Game g;

        //deal the players then play and then end the game
        g.deal();
        g.play();
        g.end();

        //set playagain to the value of the playagain method for the game class
        playagain = g.playagain();

    }while(playagain); //if playagain is true then redo

    //return 0 to show the program finished with no errors
    return 0;
}