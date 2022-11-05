#ifndef DECK_H
#define DECK_H

#include "card.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

class Deck {
    private:
        Card cards[52]; //A full deck of cards
        int n_cards; // Number of cards remaining in the deck.
    
    public:
        Deck(); //Card default constructor
        Deck(int, int); //card paramaterized constructor
        
        //big 3
        ~Deck(); //card destructor
        Deck& operator=(const Deck&); //AOO
        Deck(const Deck&); //copy construtor

        //setters
        void set_n_cards(int);

        //getters
        int get_n_cards();
        Card& get_card(int);
        
        //member functions
        void shuffle();
        void populate_card_array();
        void print_card_array();
        void swapcards(Card&, Card&);
        Card& pull_from_top();

};

#endif