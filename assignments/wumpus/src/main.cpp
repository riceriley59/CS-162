#include "game.h"
#include <ctime>
#include <cstdlib>

int main(){
    srand(time(NULL));

    Game g;

    g.start();
    g.play();

    return 0;
}