#ifndef GAME_H
#define GAME_H

#include "deck.h"
#include "player.h"

class Game {
    private:
        Deck d;
        Player players[2];
    public:
        Game();
        Game(Deck, Player[]);

        //Big3
        ~Game();
        Game& operator=(const Game&);
        Game(const Game&);

        //getters
        Deck get_deck();
        Player get_player();
        Player get_computer();
        
        //setters
        void set_deck(Deck);
        void set_player(Player, int);

        //member functions
};

#endif