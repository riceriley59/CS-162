/*********************************************************************
** Filename: player.cpp
** Author: Riley Rice
** Date: 11-6-2022
** Description: This is the implementation file for my player class
it holds my class definition of all the member functions
*********************************************************************/

#include "player.h"

/*********************************************************************
** Function: Player::Player()
** Description: This is my defualt constructor and it describes what will
happen to the member variables when you create a new player object
** Parameters: NONE
** Pre-Conditions: an unitialized player object
** Post-Conditions: an initialized player object
*********************************************************************/
Player::Player(){
    this->books = NULL;
    this->n_books = 0;
}

/*********************************************************************
** Function: Player::Player()
** Description: This is my parameterized constructor and it desribes what
will happen to the member variables when you create a new Player object with
the parameters of n_books
** Parameters: int n_books
** Pre-Conditions: an unitialized player object
** Post-Conditions: an initiliazed player object with the values you passed
in as arguments
*********************************************************************/
Player::Player(int n_books){
    this->n_books = n_books;
    this->books = new int[n_books];
}

//big 3
/*********************************************************************
** Function: Player::Player()
** Description: This is my copy constructor which handles when you want to 
create a new player object with the same values. Prevents double frees
** Parameters: const Player& p
** Pre-Conditions: an unitialized player object
** Post-Conditions: an initialized player object that is identical to the 
one that was passed in as an argument
*********************************************************************/
Player::Player(const Player& p){
    this->n_books = p.n_books;;

    this->books = new int[this->n_books];
    for(int i = 0; i < this->n_books; i++){
        this->books[i] = p.books[i];
    }
}

/*********************************************************************
** Function: Player::operator=()
** Description: This is my AOO which handles copying objects to another
when you try to set them equal to each other using the = operator. Prevents
double frees if dynamic memory is involved
** Parameters: const Player& p
** Pre-Conditions: A object that you want to be identical to another object
** Post-Conditions: An initialized object with the same values as the object
you set the object equal to, right side of = sign.
*********************************************************************/
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

/*********************************************************************
** Function: Player::~Player()
** Description: This is my destructor and it runs when a player object
is out of scope or deleted so it is destroyed. It deletes all dynamic memory
in my player object when it's done being used.
** Parameters: NONE
** Pre-Conditions: a player object is in scope or on the heap
** Post-Conditions: A player object is destroyed and all the dynamic memory
is deleted
*********************************************************************/
Player::~Player(){
    if(this->books != NULL){
        delete [] this->books;
        this->books = NULL;
    }
}

//setters
/*********************************************************************
** Function: Player::set_n_books()
** Description: This sets my n_books member variable in my player class
** Parameters: int n_books
** Pre-Conditions: n_books has another value
** Post-Conditions: n_books has value that you passed in
*********************************************************************/
void Player::set_n_books(int n_books){
    this->n_books = n_books;
}

/*********************************************************************
** Function: Player::set_books()
** Description: This sets my books member variable in my player class
** Parameters: int* books
** Pre-Conditions: books has another value
** Post-Conditions: books has value that you passed in
*********************************************************************/
void Player::set_books(int* books){
    this->books = books;
}

/*********************************************************************
** Function: Player::set_hand()
** Description: This sets my hand member variable in my player class
** Parameters: Hand h
** Pre-Conditions: hand has another value
** Post-Conditions: hand has value that you passed in
*********************************************************************/
void Player::set_hand(Hand h){
    this->hand = h;
}

//getters
/*********************************************************************
** Function: Player::get_hand()
** Description: This gets my hand member variable in my player class
** Parameters: NONE
** Pre-Conditions: hand has value
** Post-Conditions: value of hand is returned
*********************************************************************/
Hand& Player::get_hand(){
    return this->hand;
}

/*********************************************************************
** Function: Player::get_books()
** Description: This gets my books member variable in my player class
** Parameters: NONE
** Pre-Conditions: books has value
** Post-Conditions: value of books is returned
*********************************************************************/
int* Player::get_books(){
    return this->books;
}

/*********************************************************************
** Function: Player::get_n_books()
** Description: This gets my n_books member variable in my player class
** Parameters: NONE
** Pre-Conditions: n_books has value
** Post-Conditions: value of n_books is returned
*********************************************************************/
int Player::get_n_books(){
    return this->n_books;
}

//member functions
/*********************************************************************
** Function: Player::add_card_to_hand()
** Description: This function handles adding a card to the player's hand
** Parameters: Card& card
** Pre-Conditions: the card parameter is passed in by reference
** Post-Conditions: that card is added to the player's hand
*********************************************************************/
void Player::add_card_to_hand(Card& card){
    this->hand.add_card(card);
}

/*********************************************************************
** Function: Player::remove_card_from_hand()
** Description: This function handles removing a card from the player's hand
** Parameters: Card& card
** Pre-Conditions: the card parameter is passed in by reference
** Post-Conditions: that card is removed from the player's hand
*********************************************************************/
void Player::remove_card_from_hand(Card& card){
    this->hand.remove_card_from_hand(card);
}

/*********************************************************************
** Function: Player::add_book_to_player()
** Description: This function handles adding a book to the player and 
then removing those cards from it's hand
** Parameters: int rank
** Pre-Conditions: the rank of which the player has a book is passed in
** Post-Conditions: the rank is added to the books array and all cards
of that rank are removed from the player's hand
*********************************************************************/
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

    while(this->hand.has_rank(rank)){
        for(int i = 0; i < this->hand.get_n_cards(); i++){
            if(this->hand.get_cards()[i].get_rank() == rank){
                this->hand.remove_card_from_hand(this->hand.get_cards()[i]);
            }
        }
    }
}

/*********************************************************************
** Function: Player::print_player_books()
** Description: This function prints all of the books that the player has
** Parameters: bool faceup
** Pre-Conditions: The parameter is passed in 
** Post-Conditions: if faceup is true then print all the books the player has
otherwise print the number of books they have but not the value, use X's instead
*********************************************************************/
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

/*********************************************************************
** Function: Player::map_output_rank()
** Description: This function takes a rank and then turns it into a string
so it can be outputted easier
** Parameters: int rank
** Pre-Conditions: the rank is passed in
** Post-Conditions: depending on the rank the corresponding string is returned
*********************************************************************/
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