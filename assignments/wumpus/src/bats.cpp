#include "bats.h"

Bats::Bats() : Event("bat"){}

void Bats::percept(){
    std::cout << "You hear wings flapping.";
}

void Bats::encounter(){

}

Bats::~Bats(){
    std::cout << "";
}