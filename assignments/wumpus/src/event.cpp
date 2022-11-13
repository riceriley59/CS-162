#include "event.h"

Event::Event() : name(' ') {}

Event::Event(char name) : name(name) {}

char Event::get_name() const{
    return this->name;
}