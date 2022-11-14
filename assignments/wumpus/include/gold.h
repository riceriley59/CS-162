#ifndef GOLD_H
#define GOLD_H

#include "event.h"
#include "player.h"
#include <iostream>

class Gold : public Event{
    public:
        Gold();

        std::string percept() override;
        std::string encounter(Player&) override;

        virtual ~Gold();
};


#endif