#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>

class Player{
    private:
        int x;
        int y;
    public:
        Player();

        int get_x();
        int get_y();

        void set_x(int);
        void set_y(int);

        void print_position();
};

#endif