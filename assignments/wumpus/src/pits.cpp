#include "pits.h"

Pits::Pits() : Event('P') {}

std::string Pits::percept(){
    return "You feel a breeze. ";
}

void Pits::encounter(){

}

Pits::~Pits(){
    std::cout << "";
}