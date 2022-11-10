#include "player.h"

Player::Player() : x(0), y(0), n_arrows(3), alive(true){}

int Player::get_x(){
    return this->x;
}

int Player::get_y(){
    return this->y;
}

bool Player::get_alive(){
    return this->alive;
}

void Player::set_x(int x){
    this->x = x;
}

void Player::set_y(int y){
    this->y = y;
}

void Player::print_position(){
    std::cout << "\n\nThis is your position: " << "(" << (this->y + 1) << ", " << (this->x + 1) << ")\n\n";
}

std::string Player::get_move(){
    std::string input;
    bool inputg = false;

    std::cout << "\nWhat move do you want to do? (You can go up w, down s, left a, and right d\n";
    std::cout << "You can also shoot an arrow by entering a space then a direction wasd: ";

    do{
        std::getline(std::cin, input);

        this->handle_move_input(inputg, input);
    }while(!inputg);

    return input;
}

void Player::handle_move_input(bool& inputg, std::string input){
    if(input == "w"){
        inputg = true;
    }else if(input == "s"){
        inputg = true;
    }else if (input == "d"){
        inputg = true;
    }else if(input == "a"){
        inputg = true;
    }else{
        handle_arrow_input(inputg, input);
    }
}

void Player::handle_arrow_input(bool& inputg, std::string input){
    if(input == " w"){
        inputg = true;
    }else if(input == " s"){
        inputg = true;
    }else if (input == " d"){
        inputg = true;
    }else if(input == " a"){
        inputg = true;
    }else{
        std::cout << "\nInput is invalid Try Again: ";
        std::cin.clear();
        inputg = false;
    }
}