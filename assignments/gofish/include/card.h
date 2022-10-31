#ifndef CARD_H
#define CARD_H

#include <string>
#include <iostream>

using namespace std;

class Card {
    private:
        int rank; // Should be in the range 0-12.
        int suit; // Should be in the range 0-3.
    public:
        Card(); //Card default constructor
        Card(int, int); //card paramaterized constructor
        
        //big 3
        ~Card(); //card destructor
        Card& operator=(const Card&); //AOO
        Card(const Card&); //copy construtor

        //setters
        void set_rank(int);
        void set_suit(int);

        //getters
        int get_suit();
        int get_rank();
        
        //member functions
        string map_suit(); //convert the int suit to corresponding string
        string map_rank(); //convert the int rank to corresponding string
        void print_card(); //print the card out
};

#endif