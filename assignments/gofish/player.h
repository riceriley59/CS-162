#ifndef PLAYER_H
#define PLAYER_H

#include "hand.h"

class Player {
    private:
        Hand hand;
        int* books; // Array with ranks for which the player has books.
        int n_books;
    public:
        // must have constructors, destructor, accessors, and mutators
};

#endif