/*********************************************************************
** Filename: player.cpp
** Author: Riley Rice
** Date: 11-18-2022
** Description: This is the implementation file for the player class
*********************************************************************/

//include header
#include "player.h"

/*********************************************************************
** Function: Player::Player()
** Description: this is the default constructor for the player
** Parameters: NONE
** Pre-Conditions: no player object
** Post-Conditions: player object with an x and y of 0, 3 arrows, whos 
alive, and doesn't have the gold
*********************************************************************/
Player::Player() : x(0), y(0), n_arrows(3), alive(true), has_gold(false){}

/*********************************************************************
** Function: Player::get_x()
** Description: This gets the x value for the player object
** Parameters: NONE
** Pre-Conditions: x has some value
** Post-Conditions: the value of x is returned
*********************************************************************/
int Player::get_x() const{
    return this->x;
}

/*********************************************************************
** Function: Player::get_y()
** Description: This gets the y value for the player object
** Parameters: NONE 
** Pre-Conditions: y has some value
** Post-Conditions: the value of y is returned
*********************************************************************/
int Player::get_y() const{
    return this->y;
}

/*********************************************************************
** Function: Player::get_alive()
** Description: This gets the alive boolean from the player object
** Parameters: NONE
** Pre-Conditions: alive has some value
** Post-Conditions: value of alive is returned
*********************************************************************/
bool Player::get_alive() const{
    return this->alive;
}

/*********************************************************************
** Function: Player::get_win()
** Description: This gets the window pointer of the player object
** Parameters: NONE
** Pre-Conditions: curwin has some value
** Post-Conditions: value of curwin is returned
*********************************************************************/
WINDOW* Player::get_win() const{
    return this->curwin;
}  

/*********************************************************************
** Function: Player::get_move()
** Description: This gets the move from the player in a char and then returns that in 
an ASCII converted integer value
** Parameters: NONE
** Pre-Conditions: char is inputted
** Post-Conditions: char is casted to integer then returned
*********************************************************************/
int Player::get_move() const {
        char inputc = wgetch(this->curwin);
        int input = int(inputc);

        return input;
}

/*********************************************************************
** Function: Player::get_n_arrows()
** Description: This gets the n_arrows value in the player object
** Parameters: NONE
** Pre-Conditions: n_arrows has value
** Post-Conditions: value of n_arrows is returned
*********************************************************************/
int Player::get_n_arrows() const {
    return this->n_arrows;
}

/*********************************************************************
** Function: Player::get_grid_cols()
** Description: This gets the grid_cols_player value in the player object
** Parameters: NONE
** Pre-Conditions: grid_cols_player has value
** Post-Conditions: value of grid_cols_player is returned
*********************************************************************/
int Player::get_grid_cols() const {
    return this->grid_cols_player;
}

/*********************************************************************
** Function: Player::get_has_gold()
** Description: This gets the has_gold bool in the player object
** Parameters: NONE
** Pre-Conditions: has_gold has value
** Post-Conditions: value of has_gold is returned
*********************************************************************/
bool Player::get_has_gold() const {
    return this->has_gold;
}

/*********************************************************************
** Function: Player::get_header()
** Description: This gets the move_string string in the player object
** Parameters: NONE
** Pre-Conditions: move_string has value 
** Post-Conditions: value of move_string is returned
*********************************************************************/
std::string Player::get_header() const{
    return this->move_string;
}

/*********************************************************************
** Function: Player::set_win()
** Description: This sets the curwin variable in the player object
** Parameters: WINDOW* curwin
** Pre-Conditions: window pointer is passed in 
** Post-Conditions: curwin is set to window pointer that was passed in
*********************************************************************/
void Player::set_win(WINDOW* curwin){
    this->curwin = curwin;
}

/*********************************************************************
** Function: Player::set_grid_cols()
** Description: this sets the grid_cols_player variable in my player object
** Parameters: int cols
** Pre-Conditions: integer is passed in 
** Post-Conditions: grid_cols_player is set to the integer passed in
*********************************************************************/
void Player::set_grid_cols(int cols){
    this->grid_cols_player = cols;
}

/*********************************************************************
** Function: Player::set_has_gold()
** Description: This sets the has_gold boolean in the player object
** Parameters: bool b
** Pre-Conditions: boolean is passed in
** Post-Conditions: has_gold is set to passed in boolean
*********************************************************************/
void Player::set_has_gold(bool b){
    this->has_gold = b;
}

/*********************************************************************
** Function: Player::set_alive()
** Description: This sets the alive variable in the player object
** Parameters: bool alive
** Pre-Conditions: boolean is passed in
** Post-Conditions: alive is set to passed in boolean
*********************************************************************/
void Player::set_alive(bool alive){
    this->alive = alive;
}

/*********************************************************************
** Function: Player::set_x()
** Description: This sets the x variable in the player object
** Parameters: int x
** Pre-Conditions: integer is passed in 
** Post-Conditions: x is set to passed in integer
*********************************************************************/
void Player::set_x(int x){
    this->x = x;
}

/*********************************************************************
** Function: Player::set_y()
** Description: This sets the y variable in the player object
** Parameters: int y
** Pre-Conditions: integer is passed in
** Post-Conditions: y is set to passed in integer
*********************************************************************/
void Player::set_y(int y){
    this->y = y;
}

/*********************************************************************
** Function: Player::set_n_arrows()
** Description: This sets the n_arrows variable in the player object
** Parameters: int arrows
** Pre-Conditions: integer is passed in 
** Post-Conditions: arrows is set to passed in integer
*********************************************************************/
void Player::set_n_arrows(int arrows){
    this->n_arrows = arrows;
}

/*********************************************************************
** Function: Player::set_header()
** Description: This sets the move_string string in the player object
** Parameters: std::string message
** Pre-Conditions: string is passed in 
** Post-Conditions: move_string is set to string that was passed in 
*********************************************************************/
void Player::set_header(std::string message){
    this->move_string = message;
}