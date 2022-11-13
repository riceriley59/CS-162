#ifndef ROOM_H
#define ROOM_H

#include "event.h"
#include <iostream>

class Room{
    private:
        int x;
        int y;

        bool has_player;

        Event* event;
    public:
        Room(int, int);

        //getters
        bool get_has_event();
        int get_x() const;
        int get_y() const;
        Event* get_event();
        bool get_has_player();

        //setters
        void set_event(Event*);
        void set_has_player(bool);
        
        ~Room();
        
};

#endif