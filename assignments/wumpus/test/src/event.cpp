/*********************************************************************
** Filename: event.cpp
** Author: Riley Rice
** Date: 11-18-2022
** Description: 
*********************************************************************/

//include header file
#include "event.h"

/*********************************************************************
** Function: Event::Event()
** Description: This is the defualt constructor for the Event class
** Parameters: NONE
** Pre-Conditions: no Event object
** Post-Conditions: Event object with a name of ' '
*********************************************************************/
Event::Event() : name(' ') {}

/*********************************************************************
** Function: Event::Event()
** Description: This is the paramaterized constructor for the Event
class
** Parameters: char name
** Pre-Conditions: no Event object
** Post-Conditions: Event object with name of char that was passed in
*********************************************************************/
Event::Event(char name) : name(name) {}

/*********************************************************************
** Function: Event::get_name()
** Description: This returns the name value in the Event object
** Parameters: NONE
** Pre-Conditions: name has some value
** Post-Conditions: value of name is returned
*********************************************************************/
char Event::get_name() const{
    return this->name;
}