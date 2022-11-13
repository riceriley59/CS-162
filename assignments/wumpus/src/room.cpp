#include "room.h"

Room::Room(int x, int y) : x(x), y(y), event(NULL), has_player(false){}

int Room::get_x() const{
    return this->x;
}

int Room::get_y() const{
    return this->y;
}

bool Room::get_has_event(){
    if(this->event != NULL){
        return true;
    }

    return false;
}

bool Room::get_has_player(){
    return this->has_player;
}

Event* Room::get_event(){
    return this->event;
}

void Room::set_event(Event* e){
    this->event = e;
}

void Room::set_has_player(bool has_player){
    this->has_player = has_player;
}

Room::~Room(){
    if(this->event != NULL){
        delete this->event;
        this->event = NULL;
    }
}