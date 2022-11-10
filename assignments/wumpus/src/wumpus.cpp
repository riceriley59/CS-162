#include "wumpus.h"

Wumpus::Wumpus() : Event("wumpus"){}

void Wumpus::percept(){
    std::cout << "You smell a terrible stench.";
}

void Wumpus::encounter(){

}

Wumpus::~Wumpus(){
    std::cout << "";
}