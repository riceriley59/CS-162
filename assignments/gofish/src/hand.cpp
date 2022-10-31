#include "hand.h"

Hand::Hand(){
    this->cards = NULL;
    this->n_cards = 0;
}

Hand::Hand(int n_cards){
    this->cards = new Card[n_cards];
    this->n_cards = n_cards;
}

Hand::Hand(const Hand& h){
    this->n_cards = h.n_cards;

    this->cards = new Card[this->n_cards];
    for(int i = 0; i < this->n_cards; i++){
        this->cards[i] = h.cards[i];
    }
}

Hand& Hand::operator=(const Hand& h){
    this->n_cards = h.n_cards;

    if(this->cards != NULL){
        delete [] this->cards;
        this->cards = NULL;
    }   

    this->cards = new Card[this->n_cards];
    for(int i = 0; i < this->n_cards; i++){
        this->cards[i] = h.cards[i];
    }

    return *this;
}

//getters
Card* Hand::get_cards(){

}

int Hand::get_n_cards(){

}

//setters
void Hand::set_cards(){

}

void Hand::set_n_cards(){

}

Hand::~Hand(){
    if(this->cards != NULL){
        delete [] this->cards;
        this->cards = NULL;
    }
}