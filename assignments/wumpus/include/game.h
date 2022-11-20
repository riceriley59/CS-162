/*********************************************************************
** Filename: game.h
** Author: Riley Rice
** Date: 11-18-2022
** Description: This is the defintion file for my main class or game class which
brings all the game logic together.
*********************************************************************/

//header guard
#ifndef GAME_H
#define GAME_H

//include all the classes which the game will have
#include "player.h"
#include "room.h"
#include "help.h"
#include "event.h"
#include "bats.h"
#include "wumpus.h"
#include "pits.h"
#include "gold.h"

//include other standard libraries
#include <vector>
#include <iostream>
#include <string>
#include <ncurses.h>

//this is the main game class which handles all the logic for the actual game. This combines all
//the classes and their functionalities together
class Game{
    private:
        //include player object and a 2D vector of room objects
        Player player;
        std::vector<std::vector<Room>> grid;

        //number cols within our grid
        int grid_cols;

        //booleans for handling some logiv
        bool debugmode;
        bool quit;
        bool playagain;
        bool samecave;

        //y and x max for our ncurses screen
        int y_max;
        int x_max;

        //starting x and y or where the escape rope will be
        int escape_x;
        int escape_y;

        //the x and y of the wumpus event
        int wumpusx;
        int wumpusy;

        //bool which checks if the wumpus is dead
        bool wumpusdead;

        //the two strings for the output and for the header
        std::string output;
        std::string header;

        //window pointer which will hold our window in ncurses
        WINDOW* win;
    public:
        //constructor and deconstructor
        Game();
        Game(int, int);
        ~Game();

        //getters
        int get_grid_cols() const;
        int get_escape_x() const;
        int get_escape_y() const;
        bool get_debug_mode() const;
        bool get_playagain() const;
        bool get_quit() const;
        bool get_same_cave() const;
        Player get_player() const;
        std::vector<std::vector<Room>> get_grid() const;
        std::string get_output() const;

        //setters
        void set_grid_cols(int);
        void set_debug_mode(bool);

        //member functions
        //main loop for implemetation file
        void start();
        void same_start();
        void play();
        void end();

        //this checks to see if player run and returns true if they did
        bool check_for_win();
        void get_grid_events(std::vector<std::vector<char>>&);
        void populate_grid_events(std::vector<std::vector<char>>);

        //this handles all the printing
        void create_matrix(int);
        void print_matrix();
        void print_horizontal_line(int);
        void print_vertical_line(int);
        void print_player();
        void print_player_position();
        void print_events();
        void start_print();
        
        //handles all the user input for game scenarios
        void input_debug_mode();
        void input_grid_size();
        void play_again();
        void handle_play_again(bool);

        //do they want the same cave configuration
        bool get_cave_config();

        //function which moves player
        void move_player();

        //funcitons which handle moving the player without letting them go out of bounds
        void move_up();
        void move_down();
        void move_right();
        void move_left();
        
        //these functions create events at random in the grid
        void populate_events();
        void generate_bats();
        void generate_pits();
        void generate_gold();
        void generate_wumpus(bool);

        //this checks for an encounter or percept
        void check_for_encounter();
        void check_for_percept();
        
        //handles shooting arrow input and actually shooting arrow
        void shoot_arrow();
        bool handle_shoot(int);
        void see_if_out_of_arrows();

        bool shoot_at_event_up(int);
        bool shoot_at_event_down(int);
        bool shoot_at_event_right(int);
        bool shoot_at_event_left(int);
        
        //shooting funcitons
        void shoot_up();
        void shoot_down();
        void shoot_left();
        void shoot_right();

        //functions for handling missing or shooting an arrow
        void hit_wall();
        void miss_shot();
        void relocate_wumpus();
};

#endif