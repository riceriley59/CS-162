#ifndef GOLD_H
#define GOLD_H

#include "event.h"
#include <iostream>

class Gold : public Event{
    public:
        Gold();

        void percept() override;
        void encounter() override;

        virtual ~Gold();
};


#endif