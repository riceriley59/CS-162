#include "gold.h"

Gold::Gold() : Event("gold"){}

void Gold::percept(){
    std::cout << "You see a glimmer nearby.";
}

void Gold::encounter(){

}


Gold::~Gold(){
    std::cout << "";
}