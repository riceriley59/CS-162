/*********************************************************************
** Filename: player.h
** Author: Riley Rice
** Date: 11-18-2022
** Description: This is the definition file for my player class
*********************************************************************/

//header guard
#ifndef PLAYER_H
#define PLAYER_H

//inlclude some basic libraries
#include <iostream>
#include <ncurses.h>
#include <string>

//include my helper library
#include "help.h"

//this class handles the player, it's position, and it's movement, and shooting of the arrow
class Player{
    private:
        //x and y position
        int x;
        int y;

        //number of arrows
        int n_arrows;

        //size of the grid
        int grid_cols_player;
        
        //booleans to check if the player has the gold or is alive
        bool alive;
        bool has_gold;

        //this is the string which handles moving and outputting that
        std::string move_string;

        //this the current window object that's being used by ncurses
        WINDOW* curwin;
    public:
        //constructor
        Player();

        //getters
        int get_x() const;
        int get_y() const;
        bool get_has_gold() const;
        bool get_alive() const;
        WINDOW* get_win() const;
        int get_grid_cols() const;
        std::string get_header() const;
        int get_n_arrows() const;

        //setters
        void set_x(int);
        void set_y(int);
        void set_alive(bool);
        void set_win(WINDOW*);
        void set_has_gold(bool);
        void set_grid_cols(int);
        void set_header(std::string);
        void set_n_arrows(int);

        //member functions
        int get_move() const;
};

#endif