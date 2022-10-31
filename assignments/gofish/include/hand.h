#ifndef HAND_H
#define HAND_H

#include "card.h"

class Hand {
    private:
        Card* cards; // An array of cards in hand
        int n_cards; // Number of cards in the hand.
    public:
        Hand();
        Hand(int n_cards);

        //big 3
        ~Hand(); //destructor
        Hand(const Hand&); //copy constructor
        Hand& operator=(const Hand&); //AOO

        //getters
        Card* get_cards();
        int get_n_cards();

        //setters
        void set_cards();
        void set_n_cards();

        //member functions
};

#endif