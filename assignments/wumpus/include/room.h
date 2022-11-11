#ifndef ROOM_H
#define ROOM_H

#include "event.h"
#include <iostream>

class Room{
    private:
        int x;
        int y;

        Event* event;
    public:
        Room(int, int);

        //getters
        bool get_has_event();
        int get_x() const;
        int get_y() const;

        //setters
        
        
        ~Room();
        
};

#endif