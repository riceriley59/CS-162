#include "pits.h"

Pits::Pits() : Event('P') {}

std::string Pits::percept(){
    return "You feel a breeze. ";
}

std::string Pits::encounter(Player& p){
    p.set_alive(false);

    return "You fell in a bottomless pit and died, better luck next time. Press key to continue... ";
}

Pits::~Pits(){
    std::cout << "";
}