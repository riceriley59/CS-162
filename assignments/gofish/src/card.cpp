/*********************************************************************
** Filename: card.cpp
** Author: Riley Rice
** Date: 11-6-2022
** Description: This is the implementation file for my card class
*********************************************************************/

//include my card class definition
#include "card.h"

//defualt and parameterized constructors
/*********************************************************************
** Function: Card::Card()
** Description: this is the default constructor for my Card class which
describes what happens to the member variables when you create a new Card object
** Parameters: NONE
** Pre-Conditions: an unitialized Card object
** Post-Conditions: an initialized Card object
*********************************************************************/
Card::Card(){
    this->rank = 0;
    this->suit = 0;
}

/*********************************************************************
** Function: Card::Card()
** Description: This is my parameterized constructor and it desribes what
will happen to the member variables when you create a new Card object with
the parameters of rank and suit
** Parameters: int rank, int suit
** Pre-Conditions: an unitialized player object
** Post-Conditions: an initiliazed player object with the values you passed
in as arguments
*********************************************************************/
Card::Card(int rank, int suit){
    this->rank = rank;
    this->suit = suit;
}

//Big 3
//destructor
/*********************************************************************
** Function: Card::~Card()
** Description: This is my destructor and it runs when a card object
is out of scope or deleted so it is destroyed. It deletes all dynamic memory
in my card object when it's done being used.
** Parameters: NONE
** Pre-Conditions: a card object is in scope or on the heap
** Post-Conditions: A card object is destroyed and all the dynamic memory
is deleted
*********************************************************************/
Card::~Card(){
    //no dynamic memory to free or anything that needs to be done
}

//Assignment Operator Overload (AOO)
/*********************************************************************
** Function: Card::operator=()
** Description: This is my AOO which handles copying objects to another
when you try to set them equal to each other using the = operator. Prevents
double frees if dynamic memory is involved
** Parameters: const Card& card
** Pre-Conditions: A object that you want to be identical to another object
** Post-Conditions: An initialized object with the same values as the object
you set the object equal to, right side of = sign.
*********************************************************************/
Card& Card::operator=(const Card& card){
    this->rank = card.rank;
    this->suit = card.suit;

    return *this;
}

//Copy Constructor
/*********************************************************************
** Function: Card::Card()
** Description: This is my copy constructor which handles when you want to 
create a new card object with the same values. Prevents double frees
** Parameters: const Card& card
** Pre-Conditions: an unitialized card object
** Post-Conditions: an initialized card object that is identical to the 
one that was passed in as an argument
*********************************************************************/
Card::Card(const Card& card){
    this->rank = card.rank;
    this->suit = card.suit;
}

//setters
/*********************************************************************
** Function: Card::set_rank()
** Description: sets the rank member variable in my card class
** Parameters: int rank
** Pre-Conditions: rank has a value
** Post-Conditions: rank is set to the value you passed in 
*********************************************************************/
void Card::set_rank(int rank){
    this->rank = rank;
}

/*********************************************************************
** Function: Card::set_suit()
** Description: sets the suit member variable in my card class
** Parameters: int suit
** Pre-Conditions: suit has a value
** Post-Conditions: suit is set to the value you passed in
*********************************************************************/
void Card::set_suit(int suit){
    this->suit = suit;
}

//getters
/*********************************************************************
** Function: Card::get_rank()
** Description: gets the rank member variable in my Card class
** Parameters: NONE
** Pre-Conditions: rank has value
** Post-Conditions: value of rank is returned
*********************************************************************/
int Card::get_rank(){
    return this->rank;
}

/*********************************************************************
** Function: Card::get_suit()
** Description: gets the suit member variable in my Card class
** Parameters: NONE
** Pre-Conditions: suit has value
** Post-Conditions: value of suit is returned
*********************************************************************/
int Card::get_suit(){
    return this->suit;
}


//member functions
/*********************************************************************
** Function: Card::map_suit()
** Description: This turns the suit integer into the corresponding string
** Parameters: NONE
** Pre-Conditions: suit integer is passed in 
** Post-Conditions: corresponding string for that suit is returned
*********************************************************************/
string Card::map_suit(){
    switch (this->suit) {
        case 1:
            return "Diamonds";
            break;
        case 2:
            return "Spades";
            break;
        case 3: 
            return "Clubs";
            break;
        case 4:
            return "Hearts";
            break;
        default:
            return "Error";
    }
}

/*********************************************************************
** Function: Card::map_rank()
** Description: This turns the rank integer into the corresponding string
** Parameters: NONE
** Pre-Conditions: rank integer is passed in 
** Post-Conditions: corresponding string for that rank is returned
*********************************************************************/
string Card::map_rank(){
    if(this->rank <= 9){
        string str_rank = to_string(this->rank + 1);
        return str_rank; 
    } else if(this->rank == 10){
        return "Jack";
    } else if(this->rank == 11){
        return "Queen";
    } else if(this->rank == 12){
        return "King";
    } else if(this->rank == 13){
        return "Ace";
    }

    return "Error";
}

/*********************************************************************
** Function: Card::print_card()
** Description: This prints the card objects rank and suit as a easy to read string
** Parameters: NONE
** Pre-Conditions: initialized card with rank and suit
** Post-Conditions: rank and suit is outputted to the screen in a readable string
*********************************************************************/
void Card::print_card(){
    cout << this->map_rank() << " of " << this->map_suit() << '\n'; 
}