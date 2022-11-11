#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <ncurses.h>

#include "help.h"

class Player{
    private:
        int x;
        int y;
        int n_arrows;

        bool alive;

        WINDOW* curwin;
    public:
        Player();

        int get_x();
        int get_y();
        bool get_alive();
        WINDOW* get_win();

        void set_x(int);
        void set_y(int);
        void set_alive(bool);
        void set_win(WINDOW*);

        int get_move();
};

#endif