/*********************************************************************
** Filename: pits.h
** Author: Riley Rice
** Date: 11-18-2022
** Description: This is the definition for the pits class
*********************************************************************/

//header guard
#ifndef PITS_H
#define PITS_H

//include event and player class
#include "event.h"
#include "player.h"
#include <iostream>

//this class inherits the event class and represents the pit event
class Pits : public Event{
    public:
        //constructor
        Pits();
        
        //these methods handle when player is in or near room with pits event object in it
        std::string percept() const override;
        std::string encounter(Player&) const override;

        ~Pits();
};


#endif