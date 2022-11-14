#include "bats.h"

Bats::Bats() : Event('B'){}

std::string Bats::percept(){
    return "You hear wings flapping. ";
}

std::string Bats::encounter(Player& p){
    int randplayerx = (rand() % p.get_grid_cols()) + 1;
    int randplayery = (rand() % p.get_grid_cols()) + 1;

    p.set_x(randplayerx);
    p.set_y(randplayery);

    return "You walked into a bat cave it picked you up and moved you. Press any key to Contiue... ";
}

Bats::~Bats(){
    std::cout << "";
}