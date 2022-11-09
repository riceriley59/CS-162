#ifndef ROOM_H
#define ROOM_H

#include "event.h"
#include <cstddef>
#include <iostream>

class Room{
    private:
        int x;
        int y;

        bool player_in_room;
        Event* event;
    public:
        Room(int, int);

        int get_x();
        int get_y();
        bool has_player();
        bool has_event();
        void set_has_player(bool);
        ~Room();
        
};

#endif