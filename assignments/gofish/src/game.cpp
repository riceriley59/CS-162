/*********************************************************************
** Filename: game.cpp
** Author: Riley Rice
** Date: 11-6-2022
** Description: This is the implentation file for my Game class
*********************************************************************/

//include game class definition and other libraries for error handling and 
//outputting things to the screen
#include <iostream>
#include "game.h"
#include "help.h"

/*********************************************************************
** Function: Game::Game()
** Description: This is my defualt constructor and it describes what will
happen to the member variables when you create a new game object
** Parameters: NONE
** Pre-Conditions: an unitialized game object
** Post-Conditions: an initialized game object
*********************************************************************/
Game::Game(){
    string bio;
    cout << "Welcome to GoFish!!! Press enter to Begin: ";
    getline(cin, bio, '\n');
}

/*********************************************************************
** Function: Game::Game()
** Description: This is my parameterized constructor and it desribes what
will happen to the member variables when you create a new Game object with
the parameters of a Deck object and a player object array
** Parameters: Deck d, Player players[]
** Pre-Conditions: an unitialized game object
** Post-Conditions: an initiliazed game object with the values you passed
in as arguments
*********************************************************************/
Game::Game(Deck d, Player players[]){
    this->d = d;
    this->players[0] = players[0];
    this->players[1] = players[1];
}

 //Big3
/*********************************************************************
** Function: Game::~Game()
** Description: This is my destructor and it runs when a game object
is out of scope or deleted so it is destroyed. It deletes all dynamic memory
in my game object when it's done being used.
** Parameters: NONE
** Pre-Conditions: a game object is in scope or on the heap
** Post-Conditions: A game object is destroyed and all the dynamic memory
is deleted
*********************************************************************/
Game::~Game(){
    //no dynamic memory to handle on deletion
}

/*********************************************************************
** Function: Game::operator=()
** Description: This is my AOO which handles copying objects to another
when you try to set them equal to each other using the = operator. Prevents
double frees if dynamic memory is involved
** Parameters: const Game& g
** Pre-Conditions: A object that you want to be identical to another object
** Post-Conditions: An initialized object with the same values as the object
you set the object equal to, right side of = sign.
*********************************************************************/
Game& Game::operator=(const Game& g){
    this->d = g.d;
    this->players[0] = g.players[0];
    this->players[1] = g.players[1];

    return *this;
}

/*********************************************************************
** Function: Game::Game()
** Description: This is my copy constructor which handles when you want to 
create a new game object with the same values. Prevents double frees
** Parameters: const Game& g
** Pre-Conditions: an unitialized game object
** Post-Conditions: an initialized game object that is identical to the 
one that was passed in as an argument
*********************************************************************/
Game::Game(const Game& g){
    this->d = g.d;
    this->players[0] = g.players[0];
    this->players[1] = g.players[1];
}

//getters
/*********************************************************************
** Function: Game::get_deck()
** Description: gets the deck member variable of the game class
** Parameters: NONE
** Pre-Conditions: deck is initialized
** Post-Conditions: deck is returned
*********************************************************************/
Deck& Game::get_deck(){
    return this->d;
}

/*********************************************************************
** Function: Game::get_player()
** Description: gets the first index of the players array member variable
of the game class
** Parameters: NONE
** Pre-Conditions: players array is initialized
** Post-Conditions: first index of player array is returned
*********************************************************************/
Player& Game::get_player(){
    return this->players[0];
}

/*********************************************************************
** Function: Game::get_computer()
** Description: Gets the second index of the players array member variable
of the game class
** Parameters: NONE
** Pre-Conditions: players array is initialized
** Post-Conditions: second index of player array is returned
*********************************************************************/
Player& Game::get_computer(){
    return this->players[1];
}

/*********************************************************************
** Function: Game::get_debugmode
** Description: gets the debugmode member variable of the game class
** Parameters: NONE
** Pre-Conditions: debugmode has value
** Post-Conditions: value of debugmode is returned
*********************************************************************/
bool Game::get_debugmode(){
    return this->debug_mode;
}

//setters
/*********************************************************************
** Function: Game::set_deck()
** Description: sets the deck member variable of the game class
** Parameters: Deck d
** Pre-Conditions: deck has value
** Post-Conditions: value of deck is set to deck you passed in
*********************************************************************/
void Game::set_deck(Deck d){
    this->d = d;
}

/*********************************************************************
** Function: Game::set_player()
** Description: sets the specified index of the players array member variable
to the players that is passed in
** Parameters: Player p, int i
** Pre-Conditions: players array has values
** Post-Conditions: specified index of player array is set to value you passed in 
*********************************************************************/
void Game::set_player(Player p, int i){
    this->players[i] = p;
}

/*********************************************************************
** Function: Game::set_debugmode()
** Description: sets the debugmode member variable of the game class
** Parameters: Bool t
** Pre-Conditions: debugmode member variable has value
** Post-Conditions: value of debumode is set to value you passed in
*********************************************************************/
void Game::set_debugmode(bool t){
    this->debug_mode = t;
}

//member functions
/*********************************************************************
** Function: Game::deal()
** Description: deals 7 cards from the top of the deck to each player alternating
like you usually would in a card game
** Parameters: NONE
** Pre-Conditions: both players have empty hands
** Post-Conditions: Each player has 7 cards in their hand
*********************************************************************/
void Game::deal(){
    for(int i = 1; i < 15; i++){
        this->players[i % 2].add_card_to_hand(this->d.pull_from_top());
    } 

    this->get_debug_mode();
    cout << "\nPlayers have been dealt\n";
    this->print_players_hands();
}

/*********************************************************************
** Function: Game::print_players_hands()
** Description: This prints both the players hands and books based on the 
debug mode
** Parameters: NONE
** Pre-Conditions: nothing
** Post-Conditions: players hands are print face up and computers hand and 
books are printed either face up or face down based on the debug mode value
*********************************************************************/
void Game::print_players_hands(){
    cout << "\nHeres the Player's books\n";
    this->get_player().print_player_books(true);
    cout << "\nHere's your hand:\n";
    this->get_player().get_hand().print_hand(true);

    cout << "\nHeres the opponent's books\n";
    this->get_computer().print_player_books(this->debug_mode);
    cout << "Heres the opponents hand: \n";
    this->get_computer().get_hand().print_hand(this->debug_mode);
}

/*********************************************************************
** Function: Game::play_player()
** Description: This handles all the logic for the players turn
** Parameters: int& rank, bool& go_again
** Pre-Conditions: players have been dealt
** Post-Conditions: player has completed one round of their turn
*********************************************************************/
void Game::play_player(int& rank, bool& go_again){
    string input;

    do{
        if((this->get_player().get_n_books() + this->get_computer().get_n_books()) == 13){
            go_again = false;
            continue;
        }
        go_again = false;

        cout << "\nIts your turn.. \n";
        this->players_turn(rank, go_again);

        if(go_again){
            cout << "\n\nThere are " << this->get_deck().get_n_cards() << " cards left.\n";
            this->print_players_hands();
        }

        cout << "\nPress enter to continue\n";
        getline(cin, input);
    }while(go_again);
}

/*********************************************************************
** Function: Game::play_computer()
** Description: This handles all the logic for the computers turn
** Parameters: int& rank, bool& go_again
** Pre-Conditions: players have been dealt
** Post-Conditions: computer has completed one round of their turn
*********************************************************************/
void Game::play_computer(int& rank, bool& go_again){
    string input;

    do{
        if((this->get_player().get_n_books() + this->get_computer().get_n_books()) == 13){
            go_again = false;
            continue;
        }

        go_again = false;
        cout << "\nIts the opponents turn...\n";
        this->computers_turn(rank, go_again);

        if(go_again){
            cout << "\n\nThere are " << this->get_deck().get_n_cards() << " cards left.\n";
            this->print_players_hands();
        }

        cout << "\nPress enter to continue\n";
        getline(cin, input);
    }while(go_again);
}

/*********************************************************************
** Function: Game::play()
** Description: This handles the whole game loop, it runs until all the books
have been found and then also handles printing out the current hands and books
after each round of the player and computers turn
** Parameters: NONE
** Pre-Conditions: The players have been dealt
** Post-Conditions: The game has ended and all books have been obtained by the players
*********************************************************************/
void Game::play(){
    while((this->get_player().get_n_books() + this->get_computer().get_n_books()) != 13){
        int rank = 0;
        bool go_again = false;

        this->play_player(rank, go_again);

        go_again = false;

        this->play_computer(rank, go_again);

        if((this->get_player().get_n_books() + this->get_computer().get_n_books()) != 13){
            cout << "\n\nThere are " << this->get_deck().get_n_cards() << " cards left.\n";
            this->print_players_hands();
        }
    }
}

/*********************************************************************
** Function: Game::get_debug_mode()
** Description: This gets the input from the user on whether or not they
want to run the program in debug mode
** Parameters: NONE
** Pre-Conditions: Game class created
** Post-Conditions: gets the requested debug mode from the user
*********************************************************************/
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

/*********************************************************************
** Function: Game::check_for_chars()
** Description: this error handles the input from the user when they are
requesting a rank
** Parameters: string c, bool& input
** Pre-Conditions: get string c inputted by the user
** Post-Conditions: c is converted to lowercase and then check to make sure 
the input the user gave is good
*********************************************************************/
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

/*********************************************************************
** Function: Game::validate_rank()
** Description: This validates the users the rank and then once its validated
returns the input as an integer
** Parameters: NONE
** Pre-Conditions: players have been dealt
** Post-Conditions: the players rank is validated and then returned
*********************************************************************/
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

/*********************************************************************
** Function: Game::validate_rank_in_hand()
** Description: This takes the validated input and then checks to make sure
that the rank they inputted is in their hand
** Parameters: int rank
** Pre-Conditions: players have to have been dealt
** Post-Conditions: returns true if their input is valid and they have that
rank in their hand and false if otherwise
*********************************************************************/
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

/*********************************************************************
** Function: Game::validate_rank_input()
** Description: This handles getting a valid rank guess from the user until
the rank they inputted is valid
** Parameters: int& rank
** Pre-Conditions: players have to have been dealt
** Post-Conditions: a valid rank is inputted by the user for their guess
*********************************************************************/
void Game::validate_rank_input(int& rank){
    do{
        rank = this->validate_rank();
    }while(!this->validate_rank_in_hand(rank));
}

/*********************************************************************
** Function: Game::handle_guess_cards()
** Description: Once the user has inputted a valid rank input for their guess
this function checks the computers hand for cards of that rank, and if they have
a card with that rank then they add that card to the player's hand and then remove
the card from the computers hand and then increment amount so they know how many of 
that rank they had. if they don't have any of that rank then the go_fish_player method is called
** Parameters: int rank, bool& go_again
** Pre-Conditions: Players have to have cards in their hand
** Post-Conditions: Player either gets all card of requested rank from computers hand or they
have to go fish
*********************************************************************/
void Game::handle_guess_cards(int rank, bool& go_again){
    int amount = 0;

    for(int i = 0; i < this->get_computer().get_hand().get_n_cards(); i++){
        if(this->get_computer().get_hand().get_cards()[i].get_rank() == rank){
            this->get_player().add_card_to_hand(this->get_computer().get_hand().get_cards()[i]);
            this->get_computer().remove_card_from_hand(this->get_computer().get_hand().get_cards()[i]);
            
            amount++;
        }
    }

    if(amount > 0){
        cout << "\nThey had " << amount << " " << this->map_output_rank(rank) << "s in their hand\n";

        go_again = true;
        cout << "\nYou get another turn!!!\n";
    } else if(amount == 0){
        this->go_fish_player(rank, go_again);
    }
}

/*********************************************************************
** Function: Game::go_fish_computer()
** Description: This handles when the computer has to go_fish and a card
is pulled from the top of the deck and then is added to the computers hand,
and if the card they pulled is the same rank of which they requested then 
they get another turn
** Parameters: int rank, bool& go_again
** Pre-Conditions: Game::handle_guess_cards_computer() has to have been called
** Post-Conditions: the computer pulls a card from the top of the deck
*********************************************************************/
void Game::go_fish_computer(int rank, bool& go_again){
    if(this->get_deck().get_n_cards() != 0){
        Card card = this->get_deck().pull_from_top();

        this->get_computer().add_card_to_hand(card);
        cout << "\nGo Fish!! the computer pulled a "; 
        if(this->debug_mode){
            card.print_card();
        }else{
                cout << "card";
        }

        if(card.get_rank() == rank){
            cout << "\nThey get another turn!!!\n";
            go_again = true;
        }
    }else{
        cout << "\nGo Fish!!, There are no more cards in the deck!!";
    }
}

/*********************************************************************
** Function: Game::go_fish_player()
** Description: This handles when the player has to go_fish and a card
is pulled from the top of the deck and then is added to the player's hand.
If the card they pulled is the same rank of which they requested then they 
get another turn.
** Parameters: int rank, bool& go_again
** Pre-Conditions: Game::handle_guess_cards has to have been called
** Post-Conditions: the player pulls a card from the top of the deck
*********************************************************************/
void Game::go_fish_player(int rank, bool& go_again){
    if(this->get_deck().get_n_cards() != 0){
        Card card = this->get_deck().pull_from_top();

        this->get_player().add_card_to_hand(card);
        cout << "\nGo Fish!! you pulled a ";
        card.print_card();

        if(card.get_rank() == rank){
            cout << "\nYou get another turn!!!\n";
            go_again = true;
        }

    }else{
        cout << "\nGo Fish!!, There are no more cards in the deck!!";
    }
}

/*********************************************************************
** Function: Game::map_output_rank()
** Description: This function takes a rank as an integer and outputs the 
corresponding string
** Parameters: int rank
** Pre-Conditions: There needs to be a rank to be passed
** Post-Conditions: the corresponding string for the rank that is passed 
in is returned
*********************************************************************/
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

/*********************************************************************
** Function: Game::check_for_books_player()
** Description: This checks for books within the players hand
** Parameters: NONE
** Pre-Conditions: The player's hand has to have some sort of cards
** Post-Conditions: if there is a book then all cards of that rank is 
removed form the players hand and the book is added to their books array
*********************************************************************/
void Game::check_for_books_player(){
    int c = 0;

    for(int i = 1; i < 14; i++){
        c = 0;
        for(int j = 0; j < this->get_player().get_hand().get_n_cards(); j++){
            if(this->get_player().get_hand().get_cards()[j].get_rank() == i){
                c++;
            }
        }

        if(c == 4){
            //then there is a book
            cout << "\n\nYou got a book of " << this->map_output_rank(i) << "s!!! \n";
            this->get_player().add_book_to_player(i);
        }
    }
}

/*********************************************************************
** Function: Game::players_turn()
** Description: This handles the players turn and gets a valid rank input, 
either takes the rank from the computer or go fishs and then handles pulling from 
the deck if the player or computer run out of cards during their turn
** Parameters: int& rank, bool& go_again
** Pre-Conditions: Players have to have been initialized
** Post-Conditions: One iteration of the players turn occurs
*********************************************************************/
void Game::players_turn(int& rank, bool& go_again){
    if(this->get_player().get_hand().get_n_cards() < 1 && this->d.get_n_cards() != 0){
        Card pulled = this->d.pull_from_top();
        this->get_player().add_card_to_hand(pulled);

        cout << "\npulled a card\n";
        cout << "\n\nThere are " << this->get_deck().get_n_cards() << " cards left.\n";
        this->print_players_hands();
    }

    if(this->get_computer().get_hand().get_n_cards() < 1 && this->d.get_n_cards() != 0){
        Card pulled = this->d.pull_from_top();
        this->get_computer().add_card_to_hand(pulled);

        cout << "\nThe computer pulled a card\n";
        cout << "\n\nThere are " << this->get_deck().get_n_cards() << " cards left.\n";
        this->print_players_hands();
    }

    this->validate_rank_input(rank);

    //corresponding action
    this->handle_guess_cards(rank, go_again);
    this->check_for_books_player();
}

/*********************************************************************
** Function: Game::computers_turn()
** Description: this handles the computers turn and gets a valid rank input,
either takes the rank from the player or go fishs and then handles pulling from
the deck if the computer or player run out of cards during their turn
** Parameters: int& rank, bool& go_again
** Pre-Conditions: Players have to have been initialized
** Post-Conditions: One iteration of the computer's turn occurs
*********************************************************************/
void Game::computers_turn(int& rank, bool& go_again){
    if(this->get_computer().get_hand().get_n_cards() < 1 && this->d.get_n_cards() != 0){
        Card pulled = this->d.pull_from_top();
        this->get_computer().add_card_to_hand(pulled);

        cout << "\npulled a card\n";
        cout << "\n\nThere are " << this->get_deck().get_n_cards() << " cards left.\n";
        this->print_players_hands();
    }

    if(this->get_player().get_hand().get_n_cards() < 1 && this->d.get_n_cards() != 0){
        Card pulled = this->d.pull_from_top();
        this->get_player().add_card_to_hand(pulled);

        cout << "\nThey pulled a card\n";
        cout << "\n\nThere are " << this->get_deck().get_n_cards() << " cards left.\n";
        this->print_players_hands();
    }

    int guess = this->guess_rank(rank);
    cout << "\nThe computer asked for " << this->map_output_rank(guess) << "s\n";
    this->handle_guess_cards_computer(guess, go_again);
    this->check_for_books_computer();
}

/*********************************************************************
** Function: Game::to_int()
** Description: This takes a string for a rank and then returns the corresponding
integer
** Parameters: string c
** Pre-Conditions: Needs a string passed in
** Post-Conditions: corresponding rank integer will be returned
*********************************************************************/
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

/*********************************************************************
** Function: Game::guess_rank()
** Description: This handles guessing a rank for the computer, and if the rank
the player requested before them is in their hand they will ask for that, and if not
then it will choose randomly from their hand and ask for the random card's rank
** Parameters: int rank
** Pre-Conditions: need to have a player guess first
** Post-Conditions: a valid rank will be returned for the game to guess
*********************************************************************/
int Game::guess_rank(int rank){
    for(int i = 0; i < this->get_computer().get_hand().get_n_cards(); i++){
        if(rank == this->get_computer().get_hand().get_cards()[i].get_rank()){
            return rank;
        }
    }

    return this->get_computer().get_hand().get_cards()[rand() % (this->get_computer().get_hand().get_n_cards() - 1)].get_rank();
}

/*********************************************************************
** Function: Game::handle_guess_cards_computer()
** Description: This gets the guess from the computer and checks to see if the player 
has cards of the requested rank in their hand and if they do then give remove it from their hand
and add to the computers hand, and if they don't have that rank then they go fish
** Parameters: int rank, bool& go_again
** Pre-Conditions: Computer needs to guess
** Post-Conditions: the cards of the requested rank in the players hand will be given to the 
computer's hand, and if not then the computer will go fish
*********************************************************************/
void Game::handle_guess_cards_computer(int rank, bool& go_again){
    int amount = 0;

    for(int i = 0; i < this->get_player().get_hand().get_n_cards(); i++){
        if(this->get_player().get_hand().get_cards()[i].get_rank() == rank){
            this->get_computer().add_card_to_hand(this->get_player().get_hand().get_cards()[i]);
            this->get_player().remove_card_from_hand(this->get_player().get_hand().get_cards()[i]);
            amount++;
        }
    }

    if(amount > 0){
        cout << "\nThe computer got " << amount << " " << this->map_output_rank(rank) << " in your hand";

        go_again = true;
        cout << "\nThey get another turn!!!\n";
    } else if(amount == 0){
        this->go_fish_computer(rank, go_again);
    }
}

/*********************************************************************
** Function: Game::check_for_books_computer()
** Description: This checks the computers hand for books and if there is one
then it will add that book to the computers book array and remove all cards of 
that rank from their hand
** Parameters: NONE
** Pre-Conditions: computer needs to be initialized
** Post-Conditions: if the computer has a book then the book will be added to 
their array and then the cards of that rank will be removed from their hand.
*********************************************************************/
void Game::check_for_books_computer(){
    int c = 0;

    for(int i = 1; i < 14; i++){
        c = 0;
        for(int j = 0; j < this->get_computer().get_hand().get_n_cards(); j++){
            if(this->get_computer().get_hand().get_cards()[j].get_rank() == i){
                c++;
            }
        }

        if(c == 4){
            //then there is a book
            cout << "\n\nComputer got a book of " << this->map_output_rank(i) << "s!!! \n";
            this->get_computer().add_book_to_player(i);
        }
    }
}

/*********************************************************************
** Function: Game::end()
** Description: This is the end function which takes the books the player 
and computer got and then print out each players score and who won
** Parameters: NONE
** Pre-Conditions: the game has to have finished meaing the players got all 
the books for a total of 13
** Post-Conditions: score and winner is outputted
*********************************************************************/
void Game::end(){
    if(this->get_player().get_n_books() > this->get_computer().get_n_books()){
        cout << "\nYou won!! you got " << this->get_player().get_n_books() << " books\n";
        cout << "The computer got " << this->get_computer().get_n_books() << " books\n";
    }else if(this->get_computer().get_n_books() > this->get_player().get_n_books()){
        cout << "\nYou lost. You got " << this->get_player().get_n_books() << " books\n";
        cout << "The computer got " << this->get_computer().get_n_books() << " books\n";
    }
}

/*********************************************************************
** Function: Game::playagain()
** Description: This handles getting and error handling input from the user
on whether they want to play again or not
** Parameters: NONE
** Pre-Conditions: the game has to have ended 
** Post-Conditions: if the user says yes then it will return true and the game
will run again, otherwise it will return false and the game will end
*********************************************************************/
bool Game::playagain(){
    string input;
    bool inputg;

    cout << "\nDo you want to play again? (yes or no): ";
    do{
        getline(cin, input);
        if(input == "yes"){
            inputg = true;
            return true;
        }else if(input == "no"){
            cout << "\nThe game has ended, Thanks for playing! \n";
            inputg = true;
            return false;
        }else{
            cout << "\nThis input is invalid, Try Again: ";
            cin.clear();
            inputg = false;
        }
    }while(!inputg);
}