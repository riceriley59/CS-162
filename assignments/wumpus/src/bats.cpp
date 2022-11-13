#include "bats.h"

Bats::Bats() : Event('B'){}

std::string Bats::percept(){
    return "You hear wings flapping. ";
}

void Bats::encounter(){

}

Bats::~Bats(){
    std::cout << "";
}