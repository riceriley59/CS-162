/*********************************************************************
** Filename: room.h
** Author: Riley Rice
** Date: 11-18-2022
** Description: This is the definition file for my room class
*********************************************************************/

//header guard
#ifndef ROOM_H
#define ROOM_H

//include event class
#include "event.h"
#include <iostream>

//this is gonna be the object which represents each room in the grid
class Room{
    private:
        //room's position
        int x;
        int y;

        //bool which sees is if it has the player in it
        bool has_player;

        //event pointer which will point to a derived event object if there is an event
        Event* event;
    public:
        //constructor with position
        Room(int, int);

        //getters
        bool get_has_event() const;
        int get_x() const;
        int get_y() const;
        Event* get_event() const;
        bool get_has_player() const;

        //setters
        void set_event(Event*);
        void set_has_player(bool);
        
        //destructor which frees the event pointer if it's pointing to something
        ~Room();
        
};

#endif