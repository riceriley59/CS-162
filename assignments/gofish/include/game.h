#ifndef GAME_H
#define GAME_H

#include "deck.h"
#include "player.h"

class Game {
    private:
        Deck d;
        Player players[2];
    public:
        // must have constructors, destructor, accessors, and mutators

        //getters
        Deck get_deck();
};

#endif