#include "player.h"

Player::Player(){
    this->books = NULL;
}

Player::Player(int n_books){
    this->n_books = n_books;
    this->books = new int[n_books];
}

//big 3
Player::Player(const Player& p){
    this->n_books = p.n_books;;

    this->books = new int[this->n_books];
    for(int i = 0; i < this->n_books; i++){
        this->books[i] = p.books[i];
    }
}

Player& Player::operator=(const Player& p){
    this->n_books = p.n_books;

    if(this->books != NULL){
        delete [] this->books;
        this->books = NULL;
    }

    this->books = new int[this->n_books];
    for(int i = 0; i < this->n_books; i++){
        this->books[i] = p.books[i];
    }

    return *this;
}

Player::~Player(){
    if(this->books != NULL){
        delete [] this->books;
        this->books = NULL;
    }
}

//setters
void Player::set_n_books(int n_books){
    this->n_books = n_books;
}

void Player::set_books(int* books){
    this->books = books;
}

void Player::set_hand(Hand h){
    this->hand = h;
}

//getters
Hand Player::get_hand(){
    return this->hand;
}

int* Player::get_books(){
    return this->books;
}

int Player::get_n_books(){
    return this->n_books;
}

//member functions
