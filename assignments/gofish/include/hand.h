/*********************************************************************
** Filename: hand.h
** Author: Riley Rice
** Date: 11-6-2022
** Description: This is the header file for my hand class
*********************************************************************/

//header guard
#ifndef HAND_H
#define HAND_H

//include my card class
#include "card.h"

//each player has a hand which has a card
class Hand {
    private:
        Card* cards; // An array of cards in hand
        int n_cards; // Number of cards in the hand.
    public:
        //default and paramaterized constructors
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
        void set_cards(Card*);
        void set_n_cards(int);

        //member functions
        void print_hand(bool);
        void add_card(Card&);
        void remove_card_from_hand(Card&);
        bool has_rank(int);
};

#endif