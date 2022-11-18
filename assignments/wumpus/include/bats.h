/*********************************************************************
** Filename: bats.h
** Author: Riley Rice
** Date: 11-18-2022
** Description: This is the deifinition file for my bats class
*********************************************************************/

//header guard
#ifndef BATS_H
#define BATS_H

//inlclude event and player classes
#include "event.h"
#include "player.h"
#include <iostream>

//Bats is a derived class of Event
class Bats : public Event{
    public:
        //constructor
        Bats();

        //member functions
        std::string percept() const override;
        std::string encounter(Player&) const override;

        //destructor
        ~Bats();
};


#endif