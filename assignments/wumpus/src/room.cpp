/*********************************************************************
** Filename: room.cpp
** Author: Riley Rice
** Date: 11-18-2022
** Description: This is the implementation file for my room class
*********************************************************************/

//inlcude header
#include "room.h"

/*********************************************************************
** Function: Room::Room()
** Description: This is the constructor for my room object
** Parameters: int x, int y
** Pre-Conditions: No object
** Post-Conditions: Room object intialized with x and y that was passed in,
the event pointer set to NULL, and the the has_player to false
*********************************************************************/
Room::Room(int x, int y) : x(x), y(y), event(NULL), has_player(false){}

/*********************************************************************
** Function: Room::get_x()
** Description: This returns the x value of a room object
** Parameters: NONE
** Pre-Conditions: x has value
** Post-Conditions: value of x is returned
*********************************************************************/
int Room::get_x() const{
    return this->x;
}

/*********************************************************************
** Function: Room::get_y()
** Description: This returns the y value of a room object
** Parameters: NONE
** Pre-Conditions: y has value
** Post-Conditions: value of y is returned
*********************************************************************/
int Room::get_y() const{
    return this->y;
}

/*********************************************************************
** Function: Room::get_has_event()
** Description: This returns whether a room has an event or not
** Parameters: NONE
** Pre-Conditions: room has event pointer
** Post-Conditions: if event pointer isn't null then return true, otherwise
return false
*********************************************************************/
bool Room::get_has_event() const {
    if(this->event != NULL){
        return true;
    }

    return false;
}

/*********************************************************************
** Function: Room::get_has_player()
** Description: This returns whether a room has the player in it
** Parameters: NONE
** Pre-Conditions: has_player bool is set by player
** Post-Conditions: return value of has_player
*********************************************************************/
bool Room::get_has_player() const {
    return this->has_player;
}

/*********************************************************************
** Function: Room::get_event()
** Description: This returns the event pointer of the room object
** Parameters: NONE
** Pre-Conditions: event pointer has value
** Post-Conditions: return value of event pointer
*********************************************************************/
Event* Room::get_event() const {
    return this->event;
}

/*********************************************************************
** Function: Room::set_event()
** Description: This sets the event pointer of my object
** Parameters: Event* e
** Pre-Conditions: event pointer is passed in 
** Post-Conditions: the objects event pointer is set equal to the pointer
that was passed in
*********************************************************************/
void Room::set_event(Event* e){
    this->event = e;
}

/*********************************************************************
** Function: Room::set_has_player()
** Description: This set's the has_player value in the room object
** Parameters: bool has_player
** Pre-Conditions: has_player is passed in
** Post-Conditions: has_player is changed to the boolean that was passed in
*********************************************************************/
void Room::set_has_player(bool has_player){
    this->has_player = has_player;
}

/*********************************************************************
** Function: Room::~Room()
** Description: This is the destructor for the room object and it deletes 
it's event pointer if it's not equal to null so there are no memory leaks
** Parameters: NONE
** Pre-Conditions: the event pointer has value
** Post-Conditions: if event pointer does not equal NULL then delete that pointer
and set it equal to NULL
*********************************************************************/
Room::~Room(){
    if(this->event != NULL){
        delete this->event;
        this->event = NULL;
    }
}