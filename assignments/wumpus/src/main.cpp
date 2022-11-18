#include "game.h"
#include <ctime>
#include <cstdlib>

int main(){
    srand(time(NULL));
    Game* g = NULL;

    do{
        if(g != NULL){
            delete g;
            g = NULL;
        }

        g = new Game();
        g->start(false);
        g->play();
        
        if(g->get_quit() == false){
            g->end();
        }
    }while(g->get_playagain());

    delete g;
    g = NULL;

    return 0;
}