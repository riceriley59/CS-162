#include "wumpus.h"

Wumpus::Wumpus() : Event('W'){}

std::string Wumpus::percept(){
    return "You smell a terrible stench. ";
}

void Wumpus::encounter(){

}

Wumpus::~Wumpus(){
    std::cout << "";
}