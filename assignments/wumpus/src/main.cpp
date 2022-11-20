/*********************************************************************
** Program: Hunt the Wumpus main.cpp
** Author: Riley Rice
** Date: 11-18-2022
** Description: This is the hunt the wumpus game where you are an adventurer who goes
into the wumpus's cave to get gold. You win by killing the wumpus with an arrow, grabbing
the gold, and then escaping where you came in. You have to be careful though, there are bats
and bottomless pits which will make your exploration very dangerous!!!
*********************************************************************/

//include my game class and then some other libraries
#include "game.h"
#include <ctime>
#include <cstdlib>

/*********************************************************************
** Function: main()
** Description: This is the main entry point for the game and handles creating and playing 
a game, and also handling whether the user wants to play again
** Parameters: NONE
** Pre-Conditions: game is started and keeps on going till the player doesn't want to play anymore
** Post-Conditions: exit and return 0 to tell the computer the program ran correctly.
*********************************************************************/
/* int main(){
    srand(time(NULL));
    Game* g = NULL;

    do{
        if(g != NULL){
            delete g;
            g = NULL;
        }

        g = new Game();
        g->start();
        g->play();
        
        if(g->get_quit() == false){
            g->end();
        }
    }while(g->get_playagain());

    delete g;
    g = NULL;

    return 0;
} */

int main(){
    srand(time(NULL));
    Game* g = NULL;
    std::vector<std::vector<char>> grid;

    bool playagain = false;
    bool samecave = false;

    int playerx = 0;
    int playery = 0;

    do{
        if(g != NULL){
            delete g;
            g = NULL;
        }

        if(!samecave){
            g = new Game();
            g->start();
            grid.clear();
            g->get_grid_events(grid);
            g->play();
        }else{
            g = new Game(playerx, playery);
            g->populate_grid_events(grid);
            g->same_start();
            g->play();
        }
        
        if(g->get_quit() == false){
            g->end();
        }

        playagain = g->get_playagain();
        samecave = g->get_same_cave();
        playerx = g->get_escape_x();
        playery = g->get_escape_y();
    }while(playagain);

    delete g;
    g = NULL;

    return 0;
}