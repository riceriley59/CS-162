#ifndef BATS_H
#define BATS_H

#include "event.h"
#include "player.h"
#include <iostream>

class Bats : public Event{
    public:
        Bats();

        std::string percept() override;
        std::string encounter(Player&) override;

        virtual ~Bats();
};


#endif