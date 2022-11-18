/*********************************************************************
** Filename: gold.h
** Author: Riley Rice
** Date: 11-18-2022
** Description: This is the definition file for my gold class
*********************************************************************/

//header guard
#ifndef GOLD_H
#define GOLD_H

//inlcude event and player class
#include "event.h"
#include "player.h"
#include <iostream>

//This class inherits the Event class and is supposed to represent the gold
class Gold : public Event{
    public:
        //constructor for event
        Gold();

        //this handles walking in or being near the room with the gold event in it
        //overrides virtual functions in Event class
        std::string percept() const override;
        std::string encounter(Player&) const override;

        //destructor
        ~Gold();
};


#endif