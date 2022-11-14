#include "gold.h"

Gold::Gold() : Event('G'){}

std::string Gold::percept(){
    return "You see a glimmer nearby. ";
}

std::string Gold::encounter(Player& p){
    if(p.get_has_gold()){
        return "";
    }else{
        p.set_has_gold(true);
        return "You found the Gold!!!, now you must escape ";
    }

    return "";
}


Gold::~Gold(){
    std::cout << "";
}