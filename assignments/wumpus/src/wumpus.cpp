#include "wumpus.h"

Wumpus::Wumpus() : Event('W'){}

std::string Wumpus::percept(){
    return "You smell a terrible stench. ";
}

std::string Wumpus::encounter(Player& p){
    p.set_alive(false);

    return "You walked into the wumpus's room and he ate you. Press key to Continue... ";
}

Wumpus::~Wumpus(){
    std::cout << "";
}