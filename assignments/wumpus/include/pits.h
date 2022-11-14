#ifndef PITS_H
#define PITS_H

#include "event.h"
#include "player.h"
#include <iostream>

class Pits : public Event{
    public:
        Pits();

        std::string percept() override;
        std::string encounter(Player&) override;

        virtual ~Pits();
};


#endif