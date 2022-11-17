#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <ncurses.h>
#include <string>

#include "help.h"

class Player{
    private:
        int x;
        int y;
        int n_arrows;
        int grid_cols;

        bool alive;
        bool has_gold;

        std::string move_string;

        WINDOW* curwin;
    public:
        Player();

        int get_x();
        int get_y();
        bool get_has_gold();
        bool get_alive();
        WINDOW* get_win();
        int get_grid_cols();
        std::string get_header();
        int get_n_arrows();

        void set_x(int);
        void set_y(int);
        void set_alive(bool);
        void set_win(WINDOW*);
        void set_has_gold(bool);
        void set_grid_cols(int);
        void set_header(std::string);
        void set_n_arrows(int);

        int get_move();
};

#endif