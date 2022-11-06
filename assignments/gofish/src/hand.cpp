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
    return this->cards;
}

int Hand::get_n_cards(){
    return this->n_cards;
}

//setters
void Hand::set_cards(Card* cards){
    this->cards = cards;
}

void Hand::set_n_cards(int n_cards){
    this->n_cards = n_cards;
}

Hand::~Hand(){
    if(this->cards != NULL){
        delete [] this->cards;
        this->cards = NULL;
    }
}

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

bool Hand::has_rank(int rank){
    for(int i = 0; i < this->n_cards; i++){
        if(this->cards[i].get_rank() == rank){
            return true;
        }
    }

    return false;
}