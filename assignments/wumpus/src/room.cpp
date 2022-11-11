#include "room.h"

Room::Room(int x, int y) : x(x), y(y), event(NULL){}

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

Room::~Room(){
    if(this->event != NULL){
        delete this->event;
        this->event = NULL;
    }
}