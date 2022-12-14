/*********************************************************************
** Filename: player.h
** Author: Riley Rice
** Date: 11-6-2022
** Description: This is the header file for my player class
*********************************************************************/

//header guard
#ifndef PLAYER_H
#define PLAYER_H

//include my hand class
#include "hand.h"

//player class for each player in gofish
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
        void remove_card_from_hand(Card&);
        void add_book_to_player(int);
        void print_player_books(bool);
        string map_output_rank(int);
};

#endif