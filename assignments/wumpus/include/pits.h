#ifndef PITS_H
#define PITS_H

#include "event.h"
#include <iostream>

class Pits : public Event{
    public:
        Pits();

        std::string percept() override;
        void encounter() override;

        virtual ~Pits();
};


#endif