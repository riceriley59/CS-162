#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>

class Player{
    private:
        int x;
        int y;
        int n_arrows;

        bool alive;
    public:
        Player();

        int get_x();
        int get_y();
        bool get_alive();

        void set_x(int);
        void set_y(int);
        void set_alive(bool);

        std::string get_move();
        void handle_move_input(bool&, std::string);
        void handle_arrow_input(bool&, std::string);
        void print_position();
};

#endif