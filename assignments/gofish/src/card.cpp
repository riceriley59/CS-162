#include "card.h"


//defualt and parameterized constructors
Card::Card(){
    this->rank = 0;
    this->suit = 0;
}

Card::Card(int rank, int suit){
    this->rank = rank;
    this->suit = suit;
}

//Big 3
//destructor
Card::~Card(){

}

//Assignment Operator Overload (AOO)
Card& Card::operator=(const Card& card){
    this->rank = card.rank;
    this->suit = card.suit;

    return *this;
}

//Copy Constructor
Card::Card(const Card& card){
    this->rank = card.rank;
    this->suit = card.suit;
}

//setters
void Card::set_rank(int rank){
    this->rank = rank;
}

void Card::set_suit(int suit){
    this->suit = suit;
}

//getters
int Card::get_rank(){
    return this->rank;
}

int Card::get_suit(){
    return this->suit;
}


//member functions
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

void Card::print_card(){
    cout << this->map_rank() << " of " << this->map_suit() << '\n'; 
}