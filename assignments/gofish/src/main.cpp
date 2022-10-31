#include "game.h"

int main(){
    Game g;

    //g.get_deck().print_card_array();

    Player p1(10);
    Player p2(5);

    p1 = p2;

    return 0;
}