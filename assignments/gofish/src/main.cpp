#include "game.h"

int main(){
    Game g;

    cout << g.get_deck().get_n_cards();

    g.deal();

    cout << g.get_deck().get_n_cards();

    g.get_player().get_hand().print_hand(true);
    g.get_computer().get_hand().print_hand(true);

    return 0;
}