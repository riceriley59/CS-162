#ifndef PLAYER_H
#define PLAYER_H

#include "hand.h"

class Player {
    private:
        Hand hand;
        int n_books;
        int* books;
    public:
        Player();
        Player(int);

        //big 3
        Player(const Player&);
        Player& operator=(const Player&);
        ~Player();

        //setters
        void set_n_books(int);
        void set_books(int*);
        void set_hand(Hand);

        //getters
        Hand& get_hand();
        int* get_books();
        int get_n_books();

        //member functions
        void add_card_to_hand(Card&);
};

#endif