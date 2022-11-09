#ifndef GAME_H
#define GAME_H

#include "player.h"
#include "room.h"
#include <vector>
#include <iostream>

using namespace std;

class Game{
    private:
        Player player;
        vector<vector<int>> grid;
        int grid_cols;
    public:
        Game();

        void start();
        void create_matrix(int);
        void print_matrix();

};

#endif