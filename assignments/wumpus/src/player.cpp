#include "player.h"

Player::Player() : x(0), y(0), n_arrows(3), alive(true), has_gold(false){}

int Player::get_x(){
    return this->x;
}

int Player::get_y(){
    return this->y;
}

bool Player::get_alive(){
    return this->alive;
}

WINDOW* Player::get_win(){
    return this->curwin;
}  

int Player::get_grid_cols(){
    return this->grid_cols;
}

bool Player::get_has_gold(){
    return this->has_gold;
}

std::string Player::get_header(){
    return this->move_string;
}

void Player::set_win(WINDOW* curwin){
    this->curwin = curwin;
}

void Player::set_grid_cols(int cols){
    this->grid_cols = cols;
}

void Player::set_has_gold(bool b){
    this->has_gold = b;
}

void Player::set_alive(bool alive){
    this->alive = alive;
}

void Player::set_x(int x){
    this->x = x;
}

void Player::set_n_arrows(int arrows){
    this->n_arrows = arrows;
}

void Player::set_y(int y){
    this->y = y;
}

void Player::set_header(std::string message){
    this->move_string = message;
}

int Player::get_move(){
        char inputc = wgetch(this->curwin);
        int input = int(inputc);

        return input;
}

int Player::get_n_arrows(){
    return this->n_arrows;
}