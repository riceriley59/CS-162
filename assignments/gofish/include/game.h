/*********************************************************************
** Filename: game.h
** Author: Riley Rice
** Date: 11-6-2022
** Description: This is my header file for my game class
*********************************************************************/

//header guard
#ifndef GAME_H
#define GAME_H

//include my deck and player classes as thats what the game has
#include "deck.h"
#include "player.h"

//This is the main class for the gofish game is brings all the other classes together
class Game {
    private:
        Deck d; //deck object
        Player players[2]; //two players
        bool debug_mode; //whether the game is in debug mode or not
    public:
        //default and paramaterized constructors
        Game();
        Game(Deck, Player[]);

        //Big3
        ~Game(); //destructor
        Game& operator=(const Game&); //AOO
        Game(const Game&); //copy constructor

        //getters
        Deck& get_deck();
        Player& get_player();
        Player& get_computer();
        bool get_debugmode();
        
        //setters
        void set_deck(Deck);
        void set_player(Player, int);
        void set_debugmode(bool);

        //member functions
        void deal();
        void play();
        void end();
        void print_players_hands();
        void get_debug_mode();
        void players_turn(int&, bool&);
        void computers_turn(int&, bool&);
        int to_int(string);
        string map_output_rank(int);
        void validate_rank_input(int&);
        int validate_rank();
        bool validate_rank_in_hand(int);
        void check_for_chars(string, bool&);
        void handle_guess_cards(int, bool&);
        void go_fish_computer(int, bool&);
        void go_fish_player(int, bool&);
        void check_for_books_player();
        int guess_rank(int);
        void handle_guess_cards_computer(int, bool&);
        void check_for_books_computer();
        bool playagain();
        void play_computer(int&, bool&);
        void play_player(int&, bool&);
};

#endif