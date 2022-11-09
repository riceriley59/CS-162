#include "room.h"

Room::Room(int x, int y) : x(x), y(y), event(NULL), player_in_room(false){}

int Room::get_x(){
    return this->x;
}

int Room::get_y(){
    return this->y;
}

void Room::set_has_player(bool is){
    this->player_in_room = is;
}

bool Room::has_player(){
    return this->player_in_room;
}

bool Room::has_event(){
    if(this->event != NULL){
        return true;
    }

    return false;
}

Room::~Room(){
    if(this->event != NULL){
        delete this->event;
        this->event = NULL;
    }
}