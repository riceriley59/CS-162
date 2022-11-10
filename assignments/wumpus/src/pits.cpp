#include "pits.h"

Pits::Pits() : Event("pit") {}

void Pits::percept(){
    std::cout << "You feel a breeze.";
}

void Pits::encounter(){

}

Pits::~Pits(){
    std::cout << "";
}