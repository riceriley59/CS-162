#ifndef GAME_H
#define GAME_H

#include "player.h"
#include "room.h"
#include "help.h"
#include "event.h"
#include "bats.h"
#include "wumpus.h"
#include "pits.h"
#include "gold.h"

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
        bool quit;
        bool playagain;
        bool samecave;

        int y_max;
        int x_max;

        int escape_x;
        int escape_y;

        int wumpusx;
        int wumpusy;

        bool wumpusdead;

        std::string output;
        std::string header;

        WINDOW* win;
    public:
        Game();
        Game(std::vector<std::vector<Room>>, int x, int y);

        //getters
        int get_grid_cols() const;
        bool get_debug_mode() const;
        bool get_playagain() const;
        bool get_quit() const;
        bool get_same_cave() const;
        Player get_player() const;
        std::vector<std::vector<Room>> get_grid() const;
        std::string get_output();

        //setters
        void set_grid_cols(int);
        void set_debug_mode(bool);

        //member functions
        void start();
        void same_start();
        void play();
        void end();

        void create_matrix(int);
        void print_matrix();
        void print_horizontal_line(int);
        void print_vertical_line(int);
        void print_player();
        void print_player_position();
        void print_events();
        
        void input_debug_mode();
        void input_grid_size();
        void play_again();

        bool get_cave_config();

        void move_player();

        void move_up();
        void move_down();
        void move_right();
        void move_left();

        void populate_events();
        void generate_bats();
        void generate_pits();
        void generate_gold();
        void generate_wumpus();

        void check_for_encounter();
        void check_for_percept();
        
        void shoot_arrow();
        bool handle_shoot(int);
        
        void shoot_up();
        void shoot_down();
        void shoot_left();
        void shoot_right();

        void hit_wall();
        void miss_shot();
        void relocate_wumpus();

        bool check_for_win();

        ~Game();
};

#endif