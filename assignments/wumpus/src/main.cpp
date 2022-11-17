#include "game.h"
#include <ctime>
#include <cstdlib>

int main(){
    bool playagain = false;
    std::vector<std::vector<Room>> grid;
    Game* g = NULL;

    int playerx = 0;
    int playery = 0;

    do{
        playagain = false;
        srand(time(NULL));

        if(grid.size() == 0){
            g = new Game;
            g->start();
        }else{
            g = new Game(grid, playerx, playery);
            g->same_start();
            grid.clear();
            playerx = 0;
            playery = 0;
        }

        g->play();
        
        if(g->get_quit() == false){
            g->end();
        }

        playagain = g->get_playagain();
        
        if(g->get_same_cave()){
            grid = g->get_grid();
            playerx = g->get_player().get_x();
            playery = g->get_player().get_y();
        }

        delete g;
        g = NULL;
    }while(playagain);

    return 0;
}