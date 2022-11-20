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
** Function: new_game_object()
** Description: This creates a new game object and calls the correct method
** Parameters: Game* g, std::vector<std::vector<char>>& grid
** Pre-Conditions: no Game class
** Post-Conditions: Game class with quit set to false, wumpusdead set to false,
and playagain set to false, also sets the char grid to the same layout as it's grid
*********************************************************************/
void new_game_object(Game* g, std::vector<std::vector<char>>& grid){
    g = new Game();
    g->start();
    grid.clear();
    g->get_grid_events(grid);
    g->play();
}

/*********************************************************************
** Function: same_game_object()
** Description: This creates a new Game object with the same layout as the previous game
** Parameters: Game* g, std::vector<std::vector<char>> grid, int playerx, int playery
** Pre-Conditions: No game object
** Post-Conditions: Game class with quit set to false, wumpusdead set to false,
and playagain set to false, and the grid in the same layout as the 2d char array that
was passed, and the same beginning playerx and playery from the previous game
*********************************************************************/
void same_game_object(Game* g, std::vector<std::vector<char>>& grid, int playerx, int playery){
    g = new Game(playerx, playery);
    g->populate_grid_events(grid);
    g->same_start();
    g->play();
}

/*********************************************************************
** Function: get_values()
** Description: This gets values from the game object which is important 
for whether the player wants to play again and what configuration they want
** Parameters: Game* g, bool& playagain, bool& samecave, int& playerx, int& playery
** Pre-Conditions: values set to default values
** Post-Conditions: values initialized with correct values
*********************************************************************/
void get_values(Game* g, bool& playagain, bool& samecave, int& playerx, int& playery){
    playagain = g->get_playagain();
    samecave = g->get_same_cave();
    playerx = g->get_escape_x();
    playery = g->get_escape_y();
}

/*********************************************************************
** Function: handle_quit()
** Description: this handles when the player wants to quit the game
** Parameters: Game* g, bool& playagain
** Pre-Conditions: Game in the play method or has ended
** Post-Conditions: if player wants to quit then break out of loop otherwise, ask
if they want to play again and if they do what cave configuration they want
*********************************************************************/
void handle_quit(Game* g, bool& playagain){
    if(g->get_quit() == false){
        g->end();
    }else{
        playagain = false;
    }
}

/*********************************************************************
** Function: main()
** Description: This is the main entry point for the game and handles creating and playing 
a game, and also handling whether the user wants to play again
** Parameters: NONE
** Pre-Conditions: game is started and keeps on going till the player doesn't want to play anymore
** Post-Conditions: exit and return 0 to tell the computer the program ran correctly.
*********************************************************************/
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
            new_game_object(g, grid);
        }else{
            same_game_object(g, grid, playerx, playery);
        }
        
        handle_quit(g, playagain);

        get_values(g, playagain, samecave, playerx, playery);
    }while(playagain);

    delete g;
    g = NULL;

    return 0;
}