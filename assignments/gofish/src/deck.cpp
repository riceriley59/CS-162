#include "deck.h"

Deck::Deck(){
    this->n_cards = 52;
    this->populate_card_array();

    for(int i = 0; i < 3; i++){
        this->shuffle();
    }
}

//big 3
Deck::~Deck(){
    //Don't need to delete any memory or do anything on the destruction of this
    //object
}

Deck& Deck::operator=(const Deck& deck){
    this->n_cards = deck.n_cards;

    for(int i = 0; i < this->n_cards; i++){
        this->cards[i] = deck.cards[i];
    }

    return *this; 
}

Deck::Deck(const Deck& deck){
    this->n_cards = deck.n_cards;

    for(int i = 0; i < this->n_cards; i++){
        this->cards[i] = deck.cards[i];
    }
}

//setters
void Deck::set_n_cards(int ncards){
    this->n_cards = ncards;
}

//getters
int Deck::get_n_cards(){
    return this->n_cards;
}

//member functions
void Deck::swapcards(Card& card1, Card& card2){
    Card temp;

    temp = card1;
    card1 = card2;
    card2 = temp;
}

void Deck::shuffle(){
    srand(time(NULL));

    for(int i = 0; i < this->n_cards; i++){
        swapcards(this->cards[rand() % (this->n_cards - 1)], this->cards[rand() % (this->n_cards - 1)]);
    }
}

void Deck::populate_card_array(){
    for(int i = 0; i < this->n_cards; i++){
        int rank = i % 13 + 1;
        int suit = i / 13 + 1;

        this->cards[i].set_rank(rank);
        this->cards[i].set_suit(suit);
    }
}

void Deck::print_card_array(){
    for(int i = 0; i < this->n_cards; i++){
        this->cards[i].print_card();
    }
    cout << "\n";
}