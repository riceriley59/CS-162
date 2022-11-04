#include <iostream>
#include "game.h"
#include "help.h"

Game::Game(){
    string bio;
    cout << "Welcome to GoFish!!! Press enter to Begin: ";
    getline(cin, bio, '\n');
}

Game::Game(Deck d, Player players[]){
    this->d = d;
    this->players[0] = players[0];
    this->players[1] = players[1];
}

 //Big3
Game::~Game(){
    cout << "\nGame has ended, Thanks for playing! \n";
}

Game& Game::operator=(const Game& g){
    this->d = g.d;
    this->players[0] = g.players[0];
    this->players[1] = g.players[1];

    return *this;
}

Game::Game(const Game& g){
    this->d = g.d;
    this->players[0] = g.players[0];
    this->players[1] = g.players[1];
}

//getters
Deck& Game::get_deck(){
    return this->d;
}

Player& Game::get_player(){
    return this->players[0];
}

Player& Game::get_computer(){
    return this->players[1];
}

bool Game::get_debugmode(){
    return this->debug_mode;
}

//setters
void Game::set_deck(Deck d){
    this->d = d;
}

void Game::set_player(Player p, int i){
    this->players[i] = p;
}

void Game::set_debugmode(bool t){
    this->debug_mode = t;
}

//member functions
void Game::deal(){
    for(int i = 1; i < 15; i++){
        this->players[i % 2].add_card_to_hand(this->d.pull_from_top());
    } 

    this->get_debug_mode();
    cout << "\nPlayers have been dealt\n";
    this->print_players_hands();
}

void Game::print_players_hands(){
    cout << "\nHere's your hand:\n";
    this->get_player().get_hand().print_hand(true);

    cout << "Heres the opponents hand: \n";
    this->get_computer().get_hand().print_hand(this->debug_mode);
}

void Game::play(){
    while((this->get_player().get_n_books() + this->get_computer().get_n_books()) != 13){
        int rank = 0;

        this->players_turn(rank);
        this->computers_turn();

        cout << "\n\nThere are " << this->get_deck().get_n_cards() << " cards left.\n";
        this->print_players_hands();
    }
}

void Game::get_debug_mode(){
    string bio;
    bool good = false;

    cout << "\nDo you want to run this program in Debug mode? (true or false): ";
    
    do{
        getline(cin, bio);
        
        if(bio == "true"){
            this->debug_mode = true;
            good = true;
        } else if(bio == "false"){
            this->debug_mode = false;
            good = true;
        } else{
            cout << "That input is invalid Try again!: ";
            good = false;
        }
    }while(!good);
}

void Game::check_for_chars(string c, bool& input){
    c = to_lowercase(c);

    if(c[0] == 'j'){
        input = true;
    } else if(c[0] == 'q'){
        input = true;
    } else if(c[0] == 'k'){
        input = true;
    } else if(c[0] == 'a'){
        input = true;
    } else if(string_to_int(c) >= 2 && string_to_int(c) <= 10){
        input = true;
    } else {
        cout << "That input is invalid Try again!: ";
        cin.clear();
        input = false;
    }
}

int Game::validate_rank(){
    string c;
    bool input = false;

    cout << "What rank do you want to guess for? (it has to be in your hand):\n"
    << "Input 1-10 (J)Jack (Q)Queen (K)King A(Ace): ";

    do{
        getline(cin, c);

        this->check_for_chars(c, input);

    }while(!input);

    return this->to_int(c);
}

bool Game::validate_rank_in_hand(int rank){
    int c = 0;

    for(int i = 0; i < this->get_player().get_hand().get_n_cards(); i++){
        if(this->get_player().get_hand().get_cards()[i].get_rank() == rank){
            c++;
        }
    }

    if(c > 0){
        return true;
    }else if(c == 0){
        cout << "\nYou can only choose ranks from cards from your hand, Try Again!!!\n";
        return false;
    }
}

void Game::validate_rank_input(int& rank){
    do{
        rank = this->validate_rank();
    }while(!this->validate_rank_in_hand(rank));
}

void Game::handle_guess_cards(int rank){
    int amount = 0;

    for(int i = 0; i < this->get_computer().get_hand().get_n_cards(); i++){
        if(this->get_computer().get_hand().get_cards()[i].get_rank() == rank){
            this->get_player().add_card_to_hand(this->get_computer().get_hand().get_cards()[i]);
            this->get_computer().get_hand().remove_card_from_hand(this->get_computer().get_hand().get_cards()[i]);
            amount++;
        }
    }

    if(amount > 0){
        cout << "\nThey had " << amount << " " << this->map_output_rank(rank) << " in their hand";
    } else if(amount == 0){
        this->go_fish(true);
    }
}

void Game::go_fish(bool player){
    if(this->get_deck().get_n_cards() != 0){
        Card card = this->get_deck().pull_from_top();

        if(player){
            this->get_player().add_card_to_hand(card);
        }else{
            this->get_computer().add_card_to_hand(card);
        }

        cout << "\nGo Fish!! You pulled a ";
        card.print_card();
    }else{
        cout << "\nGo Fish!!, There are no more cards in the deck!!";
    }
}

string Game::map_output_rank(int rank){
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

void Game::check_for_books_player(){
    int c = 0;

    for(int i = 1; i < 14; i++){
        c = 0;
        for(int j = 0; j < this->get_player().get_hand().get_n_cards(); j++){
            if(this->get_player().get_hand().get_cards()[i].get_rank() == i){
                c++;
            }
        }
        if(c == 4){
            //then there is a book
        }
    }
}

void Game::players_turn(int& rank){
    this->validate_rank_input(rank);

    //corresponding action
    this->handle_guess_cards(rank);

    this->check_for_books_player();
}

void Game::computers_turn(){

}

int Game::to_int(string c){
    c = to_lowercase(c);

    if(c[0] == 'j'){
        return 10;
    } else if(c[0] == 'q'){
        return 11;
    } else if(c[0] == 'k'){
        return 12;
    } else if(c[0] == 'a'){
        return 13;
    } else{
        return string_to_int(c) - 1;
    }
}