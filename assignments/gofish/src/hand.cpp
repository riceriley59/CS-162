/*********************************************************************
** Filename: hand.cpp
** Author: Riley Rice
** Date: 11-6-2022
** Description: This is the implementation file for my hand class
*********************************************************************/

//include my class definition
#include "hand.h"

/*********************************************************************
** Function: Hand::Hand()
** Description: this is the default constructor for my Hand class which
describes what happens to the member variables when you create a new Hand object
** Parameters: NONE
** Pre-Conditions: an unitialized Hand object
** Post-Conditions: an initialized Hand object
*********************************************************************/
Hand::Hand(){
    this->cards = NULL;
    this->n_cards = 0;
}

/*********************************************************************
** Function: Hand::Hand()
** Description: This is my parameterized constructor for my hand class
which describes what will happen when you create a new Hand object, but 
if you add an argument
** Parameters: int n_cards
** Pre-Conditions: an unitialized Hand object
** Post-Conditions: an initialized Hand object
*********************************************************************/
Hand::Hand(int n_cards){
    this->cards = new Card[n_cards];
    this->n_cards = n_cards;
}

/*********************************************************************
** Function: Hand::Hand()
** Description: This is my copy constructor for my hand class and handles
when you want to create a new Hand object which is identical to another
Hand object, also removes the chance of double frees
** Parameters: const Hand& h
** Pre-Conditions: an unitialized Hand object
** Post-Conditions: an initialized Hand object which is identical in values
to the object that you passed in.
*********************************************************************/
Hand::Hand(const Hand& h){
    this->n_cards = h.n_cards;

    this->cards = new Card[this->n_cards];
    for(int i = 0; i < this->n_cards; i++){
        this->cards[i] = h.cards[i];
    }
}

/*********************************************************************
** Function: Hand::operator=()
** Description: This is my AOO and handles double frees and setting two
objects equal to each other
** Parameters: const Hand& h
** Pre-Conditions: an unitialized Hand object
** Post-Conditions: an initialized Hand object with is identical in values
to the object you put on the right side of the equal sign.
*********************************************************************/
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
/*********************************************************************
** Function: Hand::get_cards()
** Description: This gets my cards member variable in my Hand class
** Parameters: NONE
** Pre-Conditions: cards has value
** Post-Conditions: value of cards is returned
*********************************************************************/
Card* Hand::get_cards(){
    return this->cards;
}

/*********************************************************************
** Function: Hand::get_n_cards()
** Description: This gets my n_cards member variable in my Hand class
** Parameters: NONE
** Pre-Conditions: n_cards has value
** Post-Conditions: value of n_cards is returned
*********************************************************************/
int Hand::get_n_cards(){
    return this->n_cards;
}

//setters
/*********************************************************************
** Function: Hand::set_cards()
** Description: This sets my cards member variable in my Hand class
** Parameters: Card* cards
** Pre-Conditions: cards has another value
** Post-Conditions: cards is set to the value you passed in
*********************************************************************/
void Hand::set_cards(Card* cards){
    this->cards = cards;
}

/*********************************************************************
** Function: Hand::set_n_cards()
** Description: This sets my n_cards member variable in my Hand class
** Parameters: int n_cards
** Pre-Conditions: n_cards has another value
** Post-Conditions: n_cards is set to the value you passed in
*********************************************************************/
void Hand::set_n_cards(int n_cards){
    this->n_cards = n_cards;
}

/*********************************************************************
** Function: Hand::~Hand()
** Description: This is my destructor for my Hand class and handles the
destruction of a Hand object
** Parameters: NONE
** Pre-Conditions: Hand object is in scope or on heap
** Post-Conditions: Hand object is out of scope or deleted and so this 
function is run and dynamic memory is deleted and freed.
*********************************************************************/
Hand::~Hand(){
    if(this->cards != NULL){
        delete [] this->cards;
        this->cards = NULL;
    }
}

/*********************************************************************
** Function: Hand::print_hand()
** Description: This prints all the cards in the Hand's cards array
** Parameters: bool faceup
** Pre-Conditions: parameter is passed in
** Post-Conditions: if face up then print the cards in Hand's card array
otherwise print an X for every card in the card array
*********************************************************************/
void Hand::print_hand(bool faceup){
    if(faceup){
        for(int i = 0; i < this->n_cards; i++){
            cout << (i + 1) << ". ";
            this->cards[i].print_card();
        }
    } else{
        for(int i = 0; i < this->n_cards; i++){
            cout << (i + 1) << ". X \n";
        }
    }

    cout << "\n\n";
}

/*********************************************************************
** Function: Hand::add_card()
** Description: This function adds a card to the card array
** Parameters: Card& card
** Pre-Conditions: card is passed by reference
** Post-Conditions: that card is added to the cards array on the heap
*********************************************************************/
void Hand::add_card(Card& card){
    Card* temp_arr = new Card[this->n_cards + 1];

    for(int i = 0; i < this->n_cards; i++){
        temp_arr[i] = this->cards[i];
    }

    if(this->cards != NULL){
        delete [] this->cards;
        this->cards = NULL;
    }

    temp_arr[this->n_cards] = card;
    this->cards = temp_arr;
    this->n_cards++;
}

/*********************************************************************
** Function: Hand::remove_card_from_hand()
** Description: This function removes a card from the card array
** Parameters: Card& c
** Pre-Conditions: card is passed by reference
** Post-Conditions: that card is removed from the card array on the heap
*********************************************************************/
void Hand::remove_card_from_hand(Card& c){
    Card* temp_arr = new Card[this->n_cards - 1];
    bool found_card = false;

    for(int i = 0; i < this->n_cards; i++){
        if((this->cards[i].get_rank() == c.get_rank()) && (this->cards[i].get_suit() == c.get_suit())){
            found_card = true;
            continue;
        } else{
            if(found_card){
                temp_arr[i - 1] = this->cards[i];
            }else{
                temp_arr[i] = this->cards[i];
            }
        }
    }

    if(this->cards != NULL){
        delete [] this->cards;
        this->cards = NULL;
    }

    this->cards = temp_arr;
    this->n_cards--;
}

/*********************************************************************
** Function: Hand::has_rank()
** Description: This function returns whether there is a card with the specified
rank in the cards array
** Parameters: int rank
** Pre-Conditions: rank is passed in 
** Post-Conditions: if card with that rank is in the cards array then return true
otherwise return false
*********************************************************************/
bool Hand::has_rank(int rank){
    for(int i = 0; i < this->n_cards; i++){
        if(this->cards[i].get_rank() == rank){
            return true;
        }
    }

    return false;
}