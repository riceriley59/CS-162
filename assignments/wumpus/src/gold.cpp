/*********************************************************************
** Filename: gold.cpp
** Author: Riley Rice
** Date: 11-18-2022
** Description: This is the implementation file for my Gold class
*********************************************************************/

//include header file
#include "gold.h"

/*********************************************************************
** Function: Gold::Gold()
** Description: This is the default constructor for the Gold class and it 
constructs an Event object and sets the name to G so that the game can tell which 
Event this is when polymorphism is implemented
** Parameters: NONE
** Pre-Conditions: no Gold object
** Post-Conditions: Gold object with a const name of 'G'
*********************************************************************/
Gold::Gold() : Event('G'){}

/*********************************************************************
** Function: Gold::percept()
** Description: This is the percept funciton which handles the output 
for when a player is near an event
** Parameters: NONE
** Pre-Conditions: player is near this event
** Post-Conditions: string for this specific event is returned
*********************************************************************/
std::string Gold::percept() const {
    return "You see a glimmer nearby. ";
}

/*********************************************************************
** Function: Gold::encounter()
** Description: This is the function which sets the player's has gold to true
if the player is in the same room as the event
** Parameters: Player& p
** Pre-Conditions: player walks in same room as event
** Post-Conditions: players has_gold attribute is set to true and then the 
string is returned
*********************************************************************/
std::string Gold::encounter(Player& p) const {
    if(p.get_has_gold()){
        return "";
    }else{
        p.set_has_gold(true);
        return "You found the Gold!!!, now you must escape. ";
    }

    return "";
}

/*********************************************************************
** Function: Gold::~Gold()
** Description: This is the destructor for Gold
** Parameters: NONE
** Pre-Conditions: NONE
** Post-Conditions: NONE
*********************************************************************/
Gold::~Gold(){
    std::cout << "";
}