/*********************************************************************
** Filename: Event.h
** Author: Riley Rice
** Date: 11-18-2022
** Description: This is the definition file for my abstract event class
*********************************************************************/

//header guard
#ifndef EVENT_H
#define EVENT_H

//include player object
#include <string>
#include "player.h"

//this is the abstract or interface class for the events in the game
class Event{
    protected:
        //event type identifier
        char const name;
    public:
        //allow child classes to call constructor with specfic name to identify type
        //of event
        Event();
        Event(char);

        //pure virtual funcitons
        virtual std::string percept() const = 0;
        virtual std::string encounter(Player&) const = 0;

        //this is the getter which gets the name or type of the inherited class
        char get_name() const;

        //virtual destructor so the derived destructors are called
        virtual ~Event() = default;
};


#endif