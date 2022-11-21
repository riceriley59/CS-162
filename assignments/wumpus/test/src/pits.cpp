/*********************************************************************
** Filename: pits.cpp 
** Author: Riley Rice
** Date: 11-18-2022
** Description: This is the implementation file for my pits class
*********************************************************************/

//include header file
#include "pits.h"

/*********************************************************************
** Function: Pits::Pits()
** Description: This is the default constructor for the Pits class and it 
constructs an Event object and sets the name to P so that the game can tell which 
Event this is when polymorphism is implemented
** Parameters: NONE
** Pre-Conditions: no Pits object
** Post-Conditions: Pits object with a const name of 'P'
*********************************************************************/
Pits::Pits() : Event('P') {}

/*********************************************************************
** Function: Pits::percept()
** Description: This is the percept funciton which handles the output 
for when a player is near an event
** Parameters: NONE
** Pre-Conditions: player is near this event
** Post-Conditions: string for this specific event is returned
*********************************************************************/
std::string Pits::percept() const{
    return "You feel a breeze. ";
}

/*********************************************************************
** Function: Pits::encounter()
** Description: This is the function which sets the player's alive to false
if the player is in the same room as the event
** Parameters: Player& p
** Pre-Conditions: player walks in same room as event
** Post-Conditions: players alive attribute is set to false and then the 
string is returned
*********************************************************************/
std::string Pits::encounter(Player& p) const{
    p.set_alive(false);

    return "You fell in a bottomless pit and died, better luck next time. Press key to continue... ";
}

/*********************************************************************
** Function: Pits::~Pits()
** Description: This is the destructor for Pits objects
** Parameters: NONE
** Pre-Conditions: NONE
** Post-Conditions: NONE
*********************************************************************/
Pits::~Pits(){
    std::cout << "";
}