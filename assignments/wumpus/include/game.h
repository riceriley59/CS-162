#ifndef GAME_H
#define GAME_H

#include "player.h"
#include "room.h"
#include "help.h"

#include <vector>
#include <iostream>
#include <string>
#include <ncurses.h>

class Game{
    private:
        Player player;
        std::vector<std::vector<Room>> grid;

        int grid_cols;
        bool debugmode;

        int y_max;
        int x_max;

        WINDOW* win;
    public:
        Game();

        //getters
        int get_grid_cols() const;
        bool get_debug_mode() const;
        Player get_player() const;
        std::vector<std::vector<Room>> get_grid() const;

        //setters
        void set_grid_cols(int);
        void set_debug_mode(bool);

        //member functions
        void start();
        void play();

        void create_matrix(int);
        void print_matrix();
        void print_horizontal_line(int);
        void print_vertical_line(int);
        
        void input_debug_mode();
        void input_grid_size();

        void move_player(int);

        ~Game();
};

#endif