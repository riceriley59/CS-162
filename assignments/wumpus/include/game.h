#ifndef GAME_H
#define GAME_H

#include "player.h"
#include "room.h"
#include "help.h"

#include <vector>
#include <iostream>
#include <string>

class Game{
    private:
        Player player;
        std::vector<std::vector<Room>> grid;

        int grid_cols;
        bool debugmode;
    public:
        Game();

        void start();
        void create_matrix(int);
        void print_matrix();
        void print_top_of_grid();
        void print_cell(int, int, int);
        void print_cell_debug(int, int, int);
        void input_debug_mode();
        void input_grid_size();
};

#endif