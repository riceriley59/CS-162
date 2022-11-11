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

WINDOW* Player::get_win(){
    return this->curwin;
}  

void Player::set_win(WINDOW* curwin){
    this->curwin = curwin;
}

void Player::set_alive(bool alive){
    this->alive = alive;
}

void Player::set_x(int x){
    this->x = x;
}

void Player::set_y(int y){
    this->y = y;
}

int Player::get_move(){
    mvwprintw(this->curwin, 0, 0, "Where do you want to move? (w-up, s-down, d-right, a-left): ");
    bool inputg = false;
    
    do{
        char inputc = wgetch(this->curwin);
        int input = int(inputc);

        if(input == 119){
            return input;
            inputg = true;
        } else if(input == 115){
            return input;
            inputg = true;
        } else if(input == 100){
            return input;
            inputg = true;
        } else if(input == 97){
            return input;
            inputg = true;
        } else if(input == 113){
            return input;
            inputg = true;
        }else{
            mvwprintw(this->curwin, 0, 0, "That input is invalid, try again (w-up, s-down, d-right, a-left): ");
            inputg = false;
            wrefresh(this->curwin);
        }
    }while(!inputg);
}