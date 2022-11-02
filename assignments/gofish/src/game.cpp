#include <iostream>
#include "game.h"

Game::Game(){

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
Deck Game::get_deck(){
    return this->d;
}

Player Game::get_player(){
    return this->players[0];
}

Player Game::get_computer(){
    return this->players[1];
}

//setters
void Game::set_deck(Deck d){
    this->d = d;
}

void Game::set_player(Player p, int i){
    this->players[i] = p;
}

//member functions
void Game::deal(){
    for(int i = 1; i < 15; i++){
        this->players[i % 2].add_card_to_hand(this->d.pull_from_top());
    }
}