#ifndef WUMPUS_H
#define WUMPUS_H

#include "event.h"
#include <iostream>

class Wumpus : public Event{
    public:
        Wumpus();

        void percept() override;
        void encounter() override;

        virtual ~Wumpus();
};


#endif