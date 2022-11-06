#ifndef GAME_H
#define GAME_H

#include "deck.h"
#include "player.h"

class Game {
    private:
        Deck d;
        Player players[2];
        bool debug_mode;
    public:
        Game();
        Game(Deck, Player[]);

        //Big3
        ~Game();
        Game& operator=(const Game&);
        Game(const Game&);

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
        void computers_turn(int, bool&);
        
        int to_int(string);
        string map_output_rank(int);

        void validate_rank_input(int&);
        int validate_rank();
        bool validate_rank_in_hand(int);
        void check_for_chars(string, bool&);
        void handle_guess_cards(int, bool&);
        void go_fish(bool, int, bool&);
        void check_for_books_player();
        int guess_rank(int);
        void handle_guess_cards_computer(int, bool&);
        void check_for_books_computer();
};

#endif