#ifndef ROOM_H
#define ROOM_H

#include "event.h"
#include <iostream>

class Room{
    private:
        int x;
        int y;

        bool player_in_room;
        Event* event;
    public:
        Room(int, int);

        //getters
        bool get_has_player();
        bool get_has_event();
        int get_x() const;
        int get_y() const;

        //setters
        void set_has_player(bool);
        
        ~Room();
        
};

#endif