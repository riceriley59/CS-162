/*********************************************************************
** Filename: wumpus.h
** Author: Riley Rice
** Date: 11-18-2022
** Description: This is the definition file for my derived wumpus class
*********************************************************************/

//header guard
#ifndef WUMPUS_H
#define WUMPUS_H

//inlcude my event and player
#include "event.h"
#include "player.h"
#include <iostream>

//this class inherits the event and represents the wumpus
class Wumpus : public Event{
    public:
        //constructor
        Wumpus();

        //these funciton override the event virtual functions and handle walking into the 
        //wumpus's room
        std::string percept() const override;
        std::string encounter(Player&) const override;

        //destructor
        ~Wumpus();
};


#endif