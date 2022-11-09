#include "player.h"

Player::Player() : x(0), y(0){}

int Player::get_x(){
    return this->x;
}

int Player::get_y(){
    return this->y;
}

void Player::set_x(int x){
    this->x = x;
}

void Player::set_y(int y){
    this->y = y;
}

void Player::print_position(){
    std::cout << "\n\nThis is your position: " << "(" << (this->x + 1) << ", " << (this->y + 1) << ")\n\n";
}