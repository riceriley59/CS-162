#include "game.h"

int main(){
    bool playagain = false;

    do{
        srand(time(NULL));
        Game g;

        g.deal();
        g.play();
        g.end();

        playagain = g.playagain();

    }while(playagain);

    return 0;
}