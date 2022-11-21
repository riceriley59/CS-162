/*********************************************************************
** Filename: bats.cpp
** Author: Riley Rice
** Date: 11-18-2022
** Description: This is the implementation file for the Bats class
*********************************************************************/

//include header file
#include "bats.h"

/*********************************************************************
** Function: Bats::Bats()
** Description: This is the default constructor for the Bats class and it 
constructs an Event object and sets the name to B so that the game can tell which 
Event this is when polymorphism is implemented
** Parameters: NONE
** Pre-Conditions: no Bats object
** Post-Conditions: Bats object with a const name of 'B'
*********************************************************************/
Bats::Bats() : Event('B'){}

/*********************************************************************
** Function: Bats::percept()
** Description: This is the percept funciton which handles the output 
for when a player is near an event
** Parameters: NONE
** Pre-Conditions: player is near this event
** Post-Conditions: string for this specific event is returned
*********************************************************************/
std::string Bats::percept() const{
    return "You hear wings flapping. ";
}

/*********************************************************************
** Function: Bats::encounter()
** Description: This is the function which sets the player's x and y position
to a random spot on the grid if the player is in the same room as the event
** Parameters: Player& p
** Pre-Conditions: player walks in same room as event
** Post-Conditions: players x and y attributes are set to random spots in the
grid and then the string is returned
*********************************************************************/
std::string Bats::encounter(Player& p) const{
    int randplayerx = (rand() % p.get_grid_cols()) + 1;
    int randplayery = (rand() % p.get_grid_cols()) + 1;

    p.set_x(randplayerx);
    p.set_y(randplayery);

    return "You walked into a bat cave it picked you up and moved you. Press any key to Contiue... ";
}

/*********************************************************************
** Function: Bats::~Bats()
** Description: This is the destructor for Bats
** Parameters: NONE
** Pre-Conditions: NONE
** Post-Conditions: NONE
*********************************************************************/
Bats::~Bats(){
    std::cout << "";
}