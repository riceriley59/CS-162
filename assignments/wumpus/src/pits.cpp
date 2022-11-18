#include "pits.h"

Pits::Pits() : Event('P') {}

std::string Pits::percept() const{
    return "You feel a breeze. ";
}

std::string Pits::encounter(Player& p) const{
    p.set_alive(false);

    return "You fell in a bottomless pit and died, better luck next time. Press key to continue... ";
}

Pits::~Pits(){
    std::cout << "";
}