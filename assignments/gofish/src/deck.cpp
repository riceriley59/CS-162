/*********************************************************************
** Filename: deck.cpp
** Author: Riley Rice
** Date: 11-6-2022
** Description: implentation file for my deck class
*********************************************************************/

//include my class definition
#include "deck.h"

/*********************************************************************
** Function: Deck::Deck()
** Description: this is the default constructor for my Deck class which
describes what happens to the member variables when you create a new Deck object
** Parameters: NONE
** Pre-Conditions: an unitialized Deck object
** Post-Conditions: an initialized Deck object
*********************************************************************/
Deck::Deck(){
    this->n_cards = 52;
    this->populate_card_array();

    for(int i = 0; i < 3; i++){
        this->shuffle();
    }
}

//big 3
/*********************************************************************
** Function: Deck::~Deck()
** Description: This is my destructor and it runs when a deck object
is out of scope or deleted so it is destroyed. It deletes all dynamic memory
in my deck object when it's done being used.
** Parameters: NONE
** Pre-Conditions: a deck object is in scope or on the heap
** Post-Conditions: A deck object is destroyed and all the dynamic memory
is deleted
*********************************************************************/
Deck::~Deck(){
    //Don't need to delete any memory or do anything on the destruction of this
    //object
}

/*********************************************************************
** Function: Deck::operator=()
** Description: This is my AOO which handles copying objects to another
when you try to set them equal to each other using the = operator. Prevents
double frees if dynamic memory is involved
** Parameters: const Deck& deck
** Pre-Conditions: A object that you want to be identical to another object
** Post-Conditions: An initialized object with the same values as the object
you set the object equal to, right side of = sign.
*********************************************************************/
Deck& Deck::operator=(const Deck& deck){
    this->n_cards = deck.n_cards;

    for(int i = 0; i < this->n_cards; i++){
        this->cards[i] = deck.cards[i];
    }

    return *this; 
}

/*********************************************************************
** Function: Deck::Deck()
** Description: This is my copy constructor which handles when you want to 
create a new deck object with the same values. Prevents double frees
** Parameters: const Deck& deck
** Pre-Conditions: an unitialized deck object
** Post-Conditions: an initialized deck object that is identical to the 
one that was passed in as an argument
*********************************************************************/
Deck::Deck(const Deck& deck){
    this->n_cards = deck.n_cards;

    for(int i = 0; i < this->n_cards; i++){
        this->cards[i] = deck.cards[i];
    }
}

//setters
/*********************************************************************
** Function: Deck::set_n_cards()
** Description: This sets the ncards member variable in my Deck class
** Parameters: int ncards
** Pre-Conditions: ncards has value
** Post-Conditions: ncards has value that you passed in
*********************************************************************/
void Deck::set_n_cards(int ncards){
    this->n_cards = ncards;
}

//getters
/*********************************************************************
** Function: Deck::get_n_cards()
** Description: This gets the n_cards member variable in my Deck class 
** Parameters: NONE
** Pre-Conditions: n_cards has value
** Post-Conditions: value of n_cards is returned
*********************************************************************/
int Deck::get_n_cards(){
    return this->n_cards;
}

//member functions
/*********************************************************************
** Function: Deck::swapcards
** Description: This function swaps the values of two cards
** Parameters: Card& card1, Card& card2
** Pre-Conditions: card1 and card2 is passed in 
** Post-Conditions: card1 has values of card2 and card2 has values of card1
*********************************************************************/
void Deck::swapcards(Card& card1, Card& card2){
    Card temp;

    temp = card1;
    card1 = card2;
    card2 = temp;
}

/*********************************************************************
** Function: Deck::shuffle()
** Description: This shuffles my deck's card array
** Parameters: NONE
** Pre-Conditions: sorted deck
** Post-Conditions: randomly shuffled deck
*********************************************************************/
void Deck::shuffle(){
    for(int i = 0; i < this->n_cards; i++){
        swapcards(this->cards[rand() % (this->n_cards - 1)], this->cards[rand() % (this->n_cards - 1)]);
    }
}

/*********************************************************************
** Function: Deck::populate_card_array()
** Description: This intializes the card array when the deck is first created
** Parameters: NONE
** Pre-Conditions: unitialized card array
** Post-Conditions: initialized card array with correct amount of ranks and suits
*********************************************************************/
void Deck::populate_card_array(){
    for(int i = 0; i < this->n_cards; i++){
        int rank = i % 13 + 1;
        int suit = i / 13 + 1;

        this->cards[i].set_rank(rank);
        this->cards[i].set_suit(suit);
    }
}

/*********************************************************************
** Function: Deck::print_card_array()
** Description: this prints all the cards in the card array
** Parameters: NONE
** Pre-Conditions: card array is initialized
** Post-Conditions: card array is outputted to screen
*********************************************************************/
void Deck::print_card_array(){
    for(int i = 0; i < this->n_cards; i++){
        this->cards[i].print_card();
    }
    cout << "\n";
}

/*********************************************************************
** Function: Deck::get_card()
** Description: get a specific card in the i index
** Parameters: int i
** Pre-Conditions: cards array is initialized
** Post-Conditions: specified card is returned from deck
*********************************************************************/
Card Deck::get_card(int i){
    return this->cards[i];
}

/*********************************************************************
** Function: Deck::pull_from_top()
** Description: This pulls the card from the top of the deck
** Parameters: NONE
** Pre-Conditions: initialized Deck object
** Post-Conditions: card from the top of deck is returned and then removed
*********************************************************************/
Card& Deck::pull_from_top(){
    this->n_cards--;
    return this->cards[this->n_cards];
}