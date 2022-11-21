/*********************************************************************
** Filename: wumpus.cpp
** Author: Riley Rice
** Date: 11-18-2022
** Description: This is the implementation file for the wumpus class
*********************************************************************/

//include header file
#include "wumpus.h"

/*********************************************************************
** Function: Wumpus::Wumpus()
** Description: This is the default constructor for the Wumpus class and it 
constructs an Event object and sets the name to W so that the game can tell which 
Event this is when polymorphism is implemented
** Parameters: NONE
** Pre-Conditions: no Wumpus object
** Post-Conditions: Wumpus object with a const name of 'W'
*********************************************************************/
Wumpus::Wumpus() : Event('W'){}

/*********************************************************************
** Function: Wumpus::percept()
** Description: This is the percept funciton which handles the output 
for when a player is near an event
** Parameters: NONE
** Pre-Conditions: player is near this event
** Post-Conditions: string for this specific event is returned
*********************************************************************/
std::string Wumpus::percept() const {
    return "You smell a terrible stench. ";
}

/*********************************************************************
** Function: Wumpus::encounter()
** Description: This is the function which sets the player's alive to false
if the player is in the same room as the event
** Parameters: Player& p
** Pre-Conditions: player walks in same room as event
** Post-Conditions: player's alive attribute is set to false and then the 
string is returned
*********************************************************************/
std::string Wumpus::encounter(Player& p) const {
    p.set_alive(false);

    return "You walked into the wumpus's room and he ate you. Press key to Continue... ";
}

/*********************************************************************
** Function: Wumpus::~Wumpus()
** Description: This is the destructor for Wumpus objects
** Parameters: NONE
** Pre-Conditions: NONE
** Post-Conditions: NONE
*********************************************************************/
Wumpus::~Wumpus(){
    std::cout << "";
}