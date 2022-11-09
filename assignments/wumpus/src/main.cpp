#include "game.h"
#include <ctime>
#include <cstdlib>

int main(){
    srand(time(NULL));

    Game g;

    g.start();

    return 0;
}