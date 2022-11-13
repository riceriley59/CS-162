#include "gold.h"

Gold::Gold() : Event('G'){}

std::string Gold::percept(){
    return "You see a glimmer nearby. ";
}

void Gold::encounter(){

}


Gold::~Gold(){
    std::cout << "";
}