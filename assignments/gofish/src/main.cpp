#include "game.h"

int main(){
    srand(time(NULL));
    Game g;

    g.deal();
    g.play();
    g.end();

    return 0;
}