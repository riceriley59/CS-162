#include "player.h"

Player::Player(){
    this->books = NULL;
    this->n_books = 0;
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
Hand& Player::get_hand(){
    return this->hand;
}

int* Player::get_books(){
    return this->books;
}

int Player::get_n_books(){
    return this->n_books;
}

//member functions
void Player::add_card_to_hand(Card& card){
    this->hand.add_card(card);
}

//causing bug only removing three cards
void Player::add_book_to_player(int rank){
    int* temp_arr = new int[this->n_books + 1];

    for(int i = 0; i < this->n_books; i++){
        temp_arr[i] = this->books[i];
    }

    if(this->books != NULL){
        delete [] this->books;
        this->books = NULL;
    }

    temp_arr[this->n_books] = rank;
    this->books = temp_arr;
    this->n_books++;
}

void Player::remove_card_from_hand(int rank){
     while(this->get_hand().hasrank(rank)){
            for(int i = 0; i < this->get_hand().get_n_cards(); i++){
                if(this->get_hand().get_cards()[i].get_rank() == rank){
                    this->hand.remove_card_from_hand(this->get_hand().get_cards()[i]);
                }
        }
    }
}

void Player::print_player_books(bool faceup){
    for(int i = 0; i < this->n_books; i++){
        if(faceup){
            cout << (i + 1) << ". "<< this->map_output_rank(this->books[i]) << "s ";
        }else{
            cout << (i + 1) << ". X ";
        }
    }

    cout << "\n";
}

string Player::map_output_rank(int rank){
    if(rank <= 9){
        string str_rank = to_string(rank + 1);
        return str_rank; 
    } else if(rank == 10){
        return "Jack";
    } else if(rank == 11){
        return "Queen";
    } else if(rank == 12){
        return "King";
    } else if(rank == 13){
        return "Ace";
    }

    return "Error";
}