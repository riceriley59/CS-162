#ifndef BATS_H
#define BATS_H

#include "event.h"
#include <iostream>

class Bats : public Event{
    public:
        Bats();

        std::string percept() override;
        void encounter() override;

        virtual ~Bats();
};


#endif