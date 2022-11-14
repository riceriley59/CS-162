#ifndef WUMPUS_H
#define WUMPUS_H

#include "event.h"
#include "player.h"
#include <iostream>

class Wumpus : public Event{
    public:
        Wumpus();

        std::string percept() override;
        std::string encounter(Player&) override;

        virtual ~Wumpus();
};


#endif