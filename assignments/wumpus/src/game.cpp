/*********************************************************************
** Filename: game.cpp
** Author: Riley Rice
** Date: 11-18-2022
** Description: This is the implementation file for my game class
*********************************************************************/

//include header file
#include "game.h"

/*********************************************************************
** Function: Game::Game()
** Description: This is the defualt constructor for my game class
** Parameters: NONE
** Pre-Conditions: no Game class
** Post-Conditions: Game class with quit set to false, wumpusdead set to false,
and playagain set to false
*********************************************************************/
Game::Game() : quit(false), wumpusdead(false), playagain(false){
    initscr();
    noecho();
    cbreak();
    keypad(stdscr, TRUE);

    getmaxyx(stdscr, this->y_max, this->x_max);

    this->win = newwin(this->y_max / 1.5f, this->x_max / 1.5f, this->y_max / 6, this->x_max / 6);
    this->player.set_win(this->win); 
    this->input_grid_size();
    this->input_debug_mode();
    this->output = "Welcome to Hunt the Wumpus!!! You can quit the game by pressing q press any key to start!!!";
}

Game::Game(int playerx, int playery){
    initscr();
    noecho();
    cbreak();
    keypad(stdscr, TRUE);

    getmaxyx(stdscr, this->y_max, this->x_max);

    this->win = newwin(this->y_max / 1.5f, this->x_max / 1.5f, this->y_max / 6, this->x_max / 6);
    this->player.set_win(this->win);
    this->input_debug_mode();
    this->escape_x = playerx;
    this->escape_y = playery;
    this->output = "Welcome to Hunt the Wumpus!!! You can quit the game by pressing q press any key to start!!!";
}


//getters
/*********************************************************************
** Function: Game::get_grid_cols()
** Description: This gets the grid cols value in the Game class
** Parameters: NONE
** Pre-Conditions: grid_cols has value
** Post-Conditions: value of grid_cols is returned
*********************************************************************/
int Game::get_grid_cols() const{
    return this->grid_cols;
}

/*********************************************************************
** Function: Game::get_escape_x()
** Description: This gets the escape_x value in the Game class
** Parameters: NONE
** Pre-Conditions: escape_x has value
** Post-Conditions: value of escape_x is returned
*********************************************************************/
int Game::get_escape_x() const{
    return this->escape_x;
}

/*********************************************************************
** Function: Game::get_escape_y()
** Description: This gets the escape_y() value in the Game class
** Parameters: NONE
** Pre-Conditions: escape_y has value
** Post-Conditions: value of escape_y is returned
*********************************************************************/
int Game::get_escape_y() const{
    return this->escape_y;
}

/*********************************************************************
** Function: Game::get_debug_mode()
** Description: This gets the debug_mode value in the Game class
** Parameters: NONE
** Pre-Conditions: debugmode has value
** Post-Conditions: value of debugmode is returned
*********************************************************************/
bool Game::get_debug_mode() const{
    return this->debugmode;
}

/*********************************************************************
** Function: Game::get_quit()
** Description: This gets the quit value in the Game class
** Parameters: NONE
** Pre-Conditions: quit has value
** Post-Conditions: value of quit is returned
*********************************************************************/
bool Game::get_quit() const{
    return this->quit;
}

/*********************************************************************
** Function: Game::get_playagain()
** Description: This gets the playagain value in the Game class
** Parameters: NONE
** Pre-Conditions: playagain has value
** Post-Conditions: value of playagain is returned
*********************************************************************/
bool Game::get_playagain() const{
    return this->playagain;
}

/*********************************************************************
** Function: Game::get_same_cave()
** Description: This gets the samecave value in the Game class
** Parameters: NONE
** Pre-Conditions: samecave has value
** Post-Conditions: value of samecave is returned
*********************************************************************/
bool Game::get_same_cave() const{
    return this->samecave;
}

/*********************************************************************
** Function: Game::get_player()
** Description: This gets the player value in the Game class
** Parameters: NONE
** Pre-Conditions: player has value
** Post-Conditions: value of player is returned
*********************************************************************/
Player Game::get_player() const{
    return this->player;
}

/*********************************************************************
** Function: Game::get_grid()
** Description: This gets the grid value in the Game class
** Parameters: NONE
** Pre-Conditions: grid has value
** Post-Conditions: value of player is returned
*********************************************************************/
std::vector<std::vector<Room>> Game::get_grid() const{
    return this->grid;
}

/*********************************************************************
** Function: Game::get_output()
** Description: This gets the output value in the Game class
** Parameters: NONE
** Pre-Conditions: output has value
** Post-Conditions: value of output is returned
*********************************************************************/
std::string Game::get_output() const {
    return this->output;
}

//setters
/*********************************************************************
** Function: Game::set_grid_cols()
** Description: This sets the grid_cols value in the game class
** Parameters: int grid_cols 
** Pre-Conditions: integer is passed in
** Post-Conditions: grid_cols is set to integer that is passed in
*********************************************************************/
void Game::set_grid_cols(int grid_cols){
    this->grid_cols = grid_cols;
}

/*********************************************************************
** Function: Game::set_debug_mode()
** Description: This sets the debugmode value in the game class 
** Parameters: bool debugmode
** Pre-Conditions: boolean is passed in 
** Post-Conditions: debugmode is set to boolean that is passed in
*********************************************************************/
void Game::set_debug_mode(bool debugmode){
    this->debugmode = debugmode;
}

/*********************************************************************
** Function: Game::start()
** Description: This starts the game and sets up the variables and grid for a new
game
** Parameters: bool playagain
** Pre-Conditions: matrix is there
** Post-Conditions: set up matrix, events, and players then print it out
*********************************************************************/
void Game::start(){
    this->player.set_grid_cols(this->grid_cols);
    this->create_matrix(this->grid_cols + 2);

    this->escape_x = (rand() % this->grid_cols) + 1;
    this->escape_y = (rand() % this->grid_cols) + 1;

    this->player.set_x(escape_x);
    this->player.set_y(escape_y);

    this->populate_events();

    this->start_print();
}

void Game::same_start(){
    this->player.set_grid_cols(this->grid.size() - 2);

    this->player.set_x(this->escape_x);
    this->player.set_y(this->escape_y);

    this->start_print();
}

/*********************************************************************
** Function: Game::start_print()
** Description: This prints out the matrix for the first time
** Parameters: NONE
** Pre-Conditions: nothing
** Post-Conditions: matrix printed to screen
*********************************************************************/
void Game::start_print(){
    this->print_matrix();
    wgetch(this->win);
    this->output = " ";
    this->header.append("Where do you want to move? (w-up, s-down, d-right, a-left): ");
    this->print_player_position();
    this->check_for_percept();
    this->print_matrix();
}

void Game::get_grid_events(std::vector<std::vector<char>>& grid){
    for(int i = this->grid.size(); i > 0; i--){
        std::vector<char> row;
        for(int j = 0; j < this->grid.size(); j++){
            row.push_back(' ');
        }
        grid.push_back(row);
    }

    for(int i = 0; i < this->grid.size(); i++){
        for(int j = 0; j < this->grid.size(); j++){
            if(this->grid[i][j].get_event() != NULL){
                grid[i][j] = this->grid[i][j].get_event()->get_name();
            }
        }
    }
}

void Game::populate_grid_events(std::vector<std::vector<char>> grid){
    for(int i = 0; i < grid.size(); i++){
        std::vector<Room> row;
        for(int j = 0; j < grid.size(); j++){
            row.push_back(Room(i, j));
        }
        this->grid.push_back(row);
    }

    for(int i = 0; i < this->grid.size(); i++){
        for(int j = 0; j < this->grid.size(); j++){
            if(grid[i][j] != ' '){
                if(grid[i][j] == 'W'){
                    this->grid[i][j].set_event(new Wumpus);
                }else if(grid[i][j] == 'P'){
                    this->grid[i][j].set_event(new Pits);
                }else if(grid[i][j] == 'G'){
                    this->grid[i][j].set_event(new Gold);
                }else if(grid[i][j] == 'B'){
                    this->grid[i][j].set_event(new Bats);
                }
            }
        }
    }
};

/*********************************************************************
** Function: Game::play()
** Description: This function handles the actual gameplay of the game and
this will run until the player dies or runs out of arrows
** Parameters: NONE
** Pre-Conditions: matrix has been set up and populated
** Post-Conditions: Game starts and players can start playing the game
*********************************************************************/
void Game::play(){
    while(this->player.get_alive() == true){
        if(this->quit || this->check_for_win()){
            break;
        }

        this->header = " ";
        this->header.append("Where do you want to move? (w-up, s-down, d-right, a-left): ");
        this->output = " ";
        
        this->move_player();

        this->check_for_encounter();

        if(this->player.get_alive() == false){
            this->print_matrix();
            wgetch(this->win);
            break;
        }

        this->check_for_percept();

        this->print_player_position();
        this->print_matrix();
    }
}

/*********************************************************************
** Function: Game::end()
** Description: This handles the end game after the player dies, and handles
the player wanting to play again
** Parameters: NONE
** Pre-Conditions: game has ended
** Post-Conditions: ask the player if they want to play again
*********************************************************************/
void Game::end(){
    wclear(this->win);
    this->play_again();
}

/*********************************************************************
** Function: void Game::play_again()
** Description: This gets the input from the usr if they want to play again,
and if they want the same cave configuration if they do. 
** Parameters: NONE
** Pre-Conditions: game has ended
** Post-Conditions: if the user wants to play again it will run the program again
*********************************************************************/
void Game::play_again(){
    mvwprintw(this->win, getmaxy(this->win)/4, getmaxx(this->win)/4, "Do you want to play again? (t(true) or f(false)): ");
    bool inputg = false;
    
   this->handle_play_again(inputg);

    werase(this->win);
    wrefresh(this->win);
}

/*********************************************************************
** Function: Game::handle_play_again()
** Description: This error handles the input for the user on whether they
want to play again or not
** Parameters: bool inputg
** Pre-Conditions: user inputs a value
** Post-Conditions: keep on taking in value until user inputs correct value
*********************************************************************/
void Game::handle_play_again(bool inputg){
     do{
        char inputc = wgetch(this->win);
        int input = int(inputc);

        if(input == 116){
            this->samecave = this->get_cave_config();
            this->playagain = true;
            inputg = true;
        } else if(input == 102){
            this->playagain = false;
            inputg = true;
        } else{
            werase(this->win);
            mvwprintw(this->win, getmaxy(this->win)/4, getmaxx(this->win)/4, "That input is invalid, try again (t(true) or f(false)): ");
            inputg = false;
            wrefresh(this->win);
        }
    }while(!inputg);
}

/*********************************************************************
** Function: Game::get_cave_config()
** Description: This gets the error handled value from the player on whether 
they want the same cave configuration or not
** Parameters: NONE
** Pre-Conditions: user inputs a value
** Post-Conditions: user keeps on inputting a value until its a value input
then return that
*********************************************************************/
bool Game::get_cave_config(){
    mvwprintw(this->win, getmaxy(this->win)/4, getmaxx(this->win)/4, "Do you want to play with the same cave configuration? (t(true) or f(false)): ");
    bool inputg = false;
    
    do{
        char inputc = wgetch(this->win);
        int input = int(inputc);

        if(input == 116){
            return true;
        } else if(input == 102){
            return false;
        } else{
            werase(this->win);
            mvwprintw(this->win, getmaxy(this->win)/4, getmaxx(this->win)/4, "That input is invalid, try again (t(true) or f(false)): ");
            inputg = false;
            wrefresh(this->win);
        }
    }while(!inputg);

    werase(this->win);
    wrefresh(this->win);
}

/*********************************************************************
** Function: Game::check_for_win()
** Description: This checks for a win every time the player moves
** Parameters: NONE
** Pre-Conditions: the player moves
** Post-Conditions: if the player has the gold the wumpus is dead and they
are at the escape rope then return true otherwise return false
*********************************************************************/
bool Game::check_for_win(){
    if(this->player.get_has_gold() == true && this->wumpusdead == true && this->player.get_y() == this->escape_y && this->player.get_x() == this->escape_x){
        this->output = " ";
        this->output.append("You killed the wumpus and escaped the cave with the gold, you won!!! Press any key to continue...");
        this->print_matrix();
        wgetch(this->win);
        return true;
    }

    return false;
}

/*********************************************************************
** Function: Game::print_player_position()
** Description: This prints the players position and then appends it to the
header string
** Parameters: NONE
** Pre-Conditions: header has a string
** Post-Conditions: the position of the player is formatted and appended to the
header string
*********************************************************************/
void Game::print_player_position(){
    std::string player = " Your positon is: (";
    player.append(to_string(this->player.get_x()));
    player.append(", ");
    player.append(to_string(this->player.get_y()));
    player.append(")");
    this->header.append(player);
}

/*********************************************************************
** Function: void Game::check_for_encounter()
** Description: This function checks to see if the room the player is in has
an event and if it does then it calls the event's encounter function
** Parameters: NONE
** Pre-Conditions: player moves
** Post-Conditions: if player moves into an event call it's encounter funciton
*********************************************************************/
void Game::check_for_encounter(){
    if(this->grid[this->player.get_y()][this->player.get_x()].get_has_event()){
        if(this->grid[this->player.get_y()][this->player.get_x()].get_event()->get_name() == 'B'){
            this->output.append(this->grid[this->player.get_y()][this->player.get_x()].get_event()->encounter(this->player));
            this->print_matrix();
            wgetch(this->win);
            this->output = " ";
            this->check_for_encounter();
        } else{
            this->output.append(this->grid[this->player.get_y()][this->player.get_x()].get_event()->encounter(this->player));
            if(this->grid[this->player.get_y()][this->player.get_x()].get_event()->get_name() == 'G'){
                delete this->grid[this->player.get_y()][this->player.get_x()].get_event();
                this->grid[this->player.get_y()][this->player.get_x()].set_event(NULL);
            }
        }
    }
}

/*********************************************************************
** Function: Game::check_for_percept()
** Description: This function checks the rooms neighboring the player 
and see's if it has an event, and if it does then it calls the event's
percept function
** Parameters: NONE
** Pre-Conditions: player moves
** Post-Conditions: if neighboring room has an event then call that percept 
function
*********************************************************************/
void Game::check_for_percept(){
    if(this->grid[this->player.get_y() + 1][this->player.get_x()].get_has_event()){
        this->output.append(this->grid[this->player.get_y() + 1][this->player.get_x()].get_event()->percept());
    } 
    if(this->grid[this->player.get_y() - 1][this->player.get_x()].get_has_event()){
        this->output.append(this->grid[this->player.get_y() - 1][this->player.get_x()].get_event()->percept());
    }
    if(this->grid[this->player.get_y()][this->player.get_x() + 1].get_has_event()){
        this->output.append(this->grid[this->player.get_y()][this->player.get_x() + 1].get_event()->percept());
    }
    if(this->grid[this->player.get_y()][this->player.get_x() - 1].get_has_event()){
        this->output.append(this->grid[this->player.get_y()][this->player.get_x() - 1].get_event()->percept());
    }
}

/*********************************************************************
** Function: Game::generate_bats()
** Description: Puts two Bats objects in a random empty room 
** Parameters: NONE
** Pre-Conditions: no Bat objects in matrix
** Post-Conditions: Two random empty rooms with Bat objects in their event pointers
*********************************************************************/
void Game::generate_bats(){
    for(int i = 0; i < 2; i++){
        int batx = 0;
        int baty = 0;
        bool location = false;

        do{
            batx = (rand() % this->grid_cols) + 1;
            baty = (rand() % this->grid_cols) + 1;

            if(batx == this->escape_x && baty == this->escape_y){
                location = false;
            }else if(this->grid[baty][batx].get_has_event()){
                location = false;
            }else{
                location = true;
            }
        }while(!location);

        this->grid[baty][batx].set_event(new Bats);
    }
}

/*********************************************************************
** Function: Game::generate_pits()
** Description: Puts two Pits objects in a random empty room 
** Parameters: NONE
** Pre-Conditions: no Pits objects in matrix
** Post-Conditions: Two random empty rooms with Pit objects in their event pointers
*********************************************************************/
void Game::generate_pits(){
    for(int i = 0; i < 2; i++){
        int pitx = 0;
        int pity = 0;
        bool location = false;

        do{
            pitx = (rand() % this->grid_cols) + 1;
            pity = (rand() % this->grid_cols) + 1;

            if(pitx == this->escape_x && pity == this->escape_y){
                location = false;
            }else if(this->grid[pity][pitx].get_has_event()){
                location = false;
            }else{
                location = true;
            }
        }while(!location);

        this->grid[pity][pitx].set_event(new Pits);
    }
}

/*********************************************************************
** Function: Game::generate_gold()
** Description: Puts a gold object in a random empty room 
** Parameters: NONE
** Pre-Conditions: no Gold object in matrix
** Post-Conditions: random empty room with Gold object in it's event pointer
*********************************************************************/
void Game::generate_gold(){
    int goldx = 0;
    int goldy = 0;
    bool glocation = false;
    
    do{
        goldx = (rand() % this->grid_cols) + 1;
        goldy = (rand() % this->grid_cols) + 1;

        if(goldx == this->escape_x && goldy == this->escape_y){
            glocation = false;
        } else if(this->grid[goldy][goldx].get_has_event()){
            glocation = false;
        } else {
            glocation = true;
        }
    }while(!glocation);

    this->grid[goldy][goldx].set_event(new Gold);
}

/*********************************************************************
** Function: Game::generate_wumpus()
** Description: Puts a wumpus object in a random empty room 
** Parameters: bool player
** Pre-Conditions: No wumpus object in matrix
** Post-Conditions: random empty room with wumpus in it's event pointer
*********************************************************************/
void Game::generate_wumpus(bool player){
    int wumpusx = 0;
    int wumpusy = 0;
    bool wlocation = false;
    
    do{
        wumpusx = (rand() % this->grid_cols) + 1;
        wumpusy = (rand() % this->grid_cols) + 1;

        if(wumpusx == this->escape_x && wumpusy == this->escape_y && player == false){
            wlocation = false;
        } else if(this->grid[wumpusy][wumpusx].get_has_event()){
            wlocation = false;
        } else {
            wlocation = true;
        }
    }while(!wlocation);

    this->wumpusx = wumpusx;
    this->wumpusy = wumpusy;
    this->grid[wumpusy][wumpusx].set_event(new Wumpus);
}

/*********************************************************************
** Function: Game::populate_events()
** Description: This fills the matrix with all the appropriate events for a game
** Parameters: NONE
** Pre-Conditions: empty matrix with player and no events
** Post-Conditions: events are put in random empty spots
*********************************************************************/
void Game::populate_events(){
    //generate bats
    this->generate_bats();

    //generate pits
    this->generate_pits();

    //generate gold
    this->generate_gold();

    //generate wumpus
    this->generate_wumpus(false);
}

/*********************************************************************
** Function: Game::move_player()
** Description: This actually moves the player on the matrix, shoots an arrow
based on the user input, or quits the game based on user input, this function is over
15 lines because it has to handle mutiple outputs which is very hard to do under 15, 
although it only goes over by a little bit
** Parameters: NONE
** Pre-Conditions: got error handled input from the user
** Post-Conditions: do corresponging action based on that input
*********************************************************************/
void Game::move_player(){
    int move = 0;

    do{
        this->header = "Where do you want to move? (w-up, s-down, d-right, a-left): ";
        move = this->player.get_move();

        if(move == 119){
            this->move_up();
        }else if(move == 115){
            this->move_down();
        }else if (move == 100){
            this->move_right();
        }else if(move == 97){
            this->move_left();
        }else if(move == 113){
            this->quit = true;
        }else if(move == 32){
            this->header = "";
            this->shoot_arrow();
        }else{
            this->header = "";
            this->header.append("That input is invalid, try again (w-up, s-down, d-right, a-left): ");
            this->print_matrix();
        }
    }while(move != 115 && move != 119 && move != 100 && move != 97 && move != 32 && move != 113);
}

/*********************************************************************
** Function: Game::move_up()
** Description: moves the player up and makes sure they don't go out of bounds
** Parameters: NONE
** Pre-Conditions: player is at normal posiiton
** Post-Conditions: player is moved up one spot in the grid
*********************************************************************/
void Game::move_up(){
    if(!(this->player.get_y() == 1)){
        this->player.set_y(this->player.get_y() - 1);
    }
}

/*********************************************************************
** Function: Game::move_down()
** Description: moves the player down and makes sure they don't go out of bounds
** Parameters: NONE
** Pre-Conditions: player is at normal position
** Post-Conditions: player is moved down one spot in the grid
*********************************************************************/
void Game::move_down(){
    if(!(this->player.get_y() == this->grid_cols)){
        this->player.set_y(this->player.get_y() + 1);
    }
}

/*********************************************************************
** Function: Game::move_right()
** Description: moves the player right and makes sure they don't go out of bounds
** Parameters: NONE
** Pre-Conditions: player is at normal position
** Post-Conditions: player moved right one spot in the grid
*********************************************************************/
void Game::move_right(){
    if(!(this->player.get_x() == this->grid_cols)){
        this->player.set_x(this->player.get_x() + 1);
    }
}

/*********************************************************************
** Function: Game::move_left()
** Description: moves the player left and makes sure they don't go out of bounds
** Parameters: NONE
** Pre-Conditions: player is at normal position
** Post-Conditions: player moved left one spot in the grid
*********************************************************************/
void Game::move_left(){
    if(!(this->player.get_x() == 1)){
        this->player.set_x(this->player.get_x() - 1);
    }
}

/*********************************************************************
** Function: Game::shoot_arrow()
** Description: This handles getting the input from the user on where they want to shoot
and then shooting the arrow
** Parameters: NONE
** Pre-Conditions: player presses space
** Post-Conditions: player shoots arrow in specified direction or doesn't shoot at all
*********************************************************************/
void Game::shoot_arrow(){
    if(this->player.get_n_arrows() > 0){
        this->header = "What direction do you want to shoot your arrow, or press e to cancel (w-up, s-down, d-right, a-left): ";
        this->print_matrix();

        int move = 0;

        do{
            char inputc = wgetch(this->win);
            move = int(inputc);
        }while(!this->handle_shoot(move));

        this->header = "Where do you want to move? (w-up, s-down, d-right, a-left): ";
    }else {
        this->header = "Where do you want to move? (w-up, s-down, d-right, a-left): ";
        this->output = "You have no more arrows to shoot. Press any key to continue... ";
        this->print_matrix();
        wgetch(this->win);
        this->output = " ";
    }
}

/*********************************************************************
** Function: Game::handle_shoot()
** Description: this handles the shooting by calling the corresponging shoot
function after getting the error handled user input
** Parameters: int move
** Pre-Conditions: user inputs what direction they want to shoot the arrow
** Post-Conditions: the corresponding shoot funciton is called
*********************************************************************/
bool Game::handle_shoot(int move){
    if(move == 119){
        this->shoot_up();
        return true;
    }else if(move == 115){
        this->shoot_down();
        return true;
    }else if (move == 100){
        this->shoot_right();
        return true;
    }else if(move == 97){
        this->shoot_left();
        return true;
    }else if(move == 101){
        return true;
    }else{
        this->header = "That input is invalid, try again. What direction do you want to shoot in (w-up, s-down, d-right, a-left, e-don't shoot): ";
        this->print_matrix();
        return false;
    }
}

/*********************************************************************
** Function: Game::see_if_out_of_arrows()
** Description: if the wumpus isn't killed and the player is out of arrows then
set the player to not alive and end game
** Parameters: NONE
** Pre-Conditions: player runs out of arrows without killing wumpus
** Post-Conditions: player dies
*********************************************************************/
void Game::see_if_out_of_arrows(){
    if(this->player.get_n_arrows() == 0 && this->wumpusdead == false){
        this->output = " ";
        this->output.append("You ran out of arrows, and the wumpus is still alive so you lost. press any key to continue...");
        this->player.set_alive(false);
    }
}

/*********************************************************************
** Function: Game::shoot_at_event_up();
** Description: checks if the event that was hit by an arrow was the wumpus and 
does the corresponding action
** Parameters: int i
** Pre-Conditions: arrow hits event
** Post-Conditions: if event is wumpus do corresponding action otherwise keep on going
*********************************************************************/
bool Game::shoot_at_event_up(int i){
    if(this->grid[this->player.get_y() - i][this->player.get_x()].get_event()->get_name() == 'W'){
        delete this->grid[this->player.get_y() - i][this->player.get_x()].get_event();
        this->grid[this->player.get_y() - i][this->player.get_x()].set_event(NULL);

        this->output = " ";
        this->output.append("You Killed the Wumpus!!! find the gold and escape");
        this->print_matrix();
        this->wumpusdead = true;
        return true;
    } else if(this->grid[this->player.get_y() - i][this->player.get_x()].get_event()->get_name() != 'W' && i == 3){
        this->miss_shot();
        this->relocate_wumpus();
        return false;
    }
}

/*********************************************************************
** Function: Game::shoot_up()
** Description: This handles shooting an arrow up and doing the correspoding action
** Parameters: NONE
** Pre-Conditions: user wants to shoot up
** Post-Conditions: go through three rooms above the player if it hits wumpus then delete
it and remove arrow if it hits nothing remove arrow and give corresponding message
*********************************************************************/
void Game::shoot_up(){
    for(int i = 1; i < 4; i++){
        if(this->player.get_y() - i == 0){
            this->hit_wall();
            this->relocate_wumpus();
            break;
        } else{
            if(this->grid[this->player.get_y() - i][this->player.get_x()].get_has_event()){
                if(this->shoot_at_event_up(i)){
                    break;
                }
            } else if(i == 3){
                this->miss_shot();
            }
        }
    }

    this->player.set_n_arrows(this->player.get_n_arrows() - 1);

    this->see_if_out_of_arrows();
}

/*********************************************************************
** Function: Game::shoot_at_event_down();
** Description: checks if the event that was hit by an arrow was the wumpus and 
does the corresponding action
** Parameters: int i
** Pre-Conditions: arrow hits event
** Post-Conditions: if event is wumpus do corresponding action otherwise keep on going
*********************************************************************/
bool Game::shoot_at_event_down(int i){
    if(this->grid[this->player.get_y() + i][this->player.get_x()].get_event()->get_name() == 'W'){
        delete this->grid[this->player.get_y() + i][this->player.get_x()].get_event();
        this->grid[this->player.get_y() + i][this->player.get_x()].set_event(NULL);

        this->output = " ";
        this->output.append("You Killed the Wumpus!!! find the gold and escape");
        this->print_matrix();
        this->wumpusdead = true;
        return true;
    } else if(this->grid[this->player.get_y() + i][this->player.get_x()].get_event()->get_name() != 'W' && i == 3){
        this->miss_shot();
        this->relocate_wumpus();
        return false;
    }
}

/*********************************************************************
** Function: Game::shoot_down()
** Description: This handles shooting an arrow down and doing the corresponding action
** Parameters: NONE
** Pre-Conditions: user wants to shoot down
** Post-Conditions: go through three rooms below the player if it hits wumpus then delete it
and remove arrow if it hits nothing remove arrow and give corresponding message
*********************************************************************/
void Game::shoot_down(){
    for(int i = 1; i < 4; i++){
        if(this->player.get_y() + i == this->grid_cols + 2){
            this->hit_wall();
            this->relocate_wumpus();
            break;
        } else{
            if(this->grid[this->player.get_y() + i][this->player.get_x()].get_has_event()){
                if(this->shoot_at_event_down(i)){
                    break;
                }
            } else if(i == 3){
                this->miss_shot();
            }
        }
    }

    this->player.set_n_arrows(this->player.get_n_arrows() - 1);

    this->see_if_out_of_arrows();
}

/*********************************************************************
** Function: Game::shoot_at_event_left();
** Description: checks if the event that was hit by an arrow was the wumpus and 
does the corresponding action
** Parameters: int i
** Pre-Conditions: arrow hits event
** Post-Conditions: if event is wumpus do corresponding action otherwise keep on going
*********************************************************************/
bool Game::shoot_at_event_left(int i){
    if(this->grid[this->player.get_y()][this->player.get_x() - i].get_event()->get_name() == 'W'){
        delete this->grid[this->player.get_y()][this->player.get_x() - i].get_event();
        this->grid[this->player.get_y()][this->player.get_x() - i].set_event(NULL);

        this->output = " ";
        this->output.append("You Killed the Wumpus!!! find the gold and escape");
        this->print_matrix();
        this->wumpusdead = true;
        return true;
    } else if(this->grid[this->player.get_y()][this->player.get_x() - i].get_event()->get_name() != 'W' && i == 3){
        this->miss_shot();
        this->relocate_wumpus();
        return false;
    }
}

/*********************************************************************
** Function: Game::shoot_left()
** Description: This handles shooting an arrow to the left and doing the corresponding action
** Parameters: NONE
** Pre-Conditions: user wants to shoot left
** Post-Conditions: go through three to the left of the player if it hits wumpus then delete it
and remove arrow if it hits nothing remove arrow and give corresponding message
*********************************************************************/
void Game::shoot_left(){
    for(int i = 1; i < 4; i++){
        if(this->player.get_x() - i == 0){
            this->hit_wall();
            this->relocate_wumpus();
            break;
        } else{
            if(this->grid[this->player.get_y()][this->player.get_x() - i].get_has_event()){
                if(this->shoot_at_event_left(i)){
                    break;
                }
            } else if(i == 3){
                this->miss_shot();
            }
        }
    }

    this->player.set_n_arrows(this->player.get_n_arrows() - 1);

    this->see_if_out_of_arrows();
}

/*********************************************************************
** Function: Game::shoot_at_event_right();
** Description: checks if the event that was hit by an arrow was the wumpus and 
does the corresponding action
** Parameters: int i
** Pre-Conditions: arrow hits event
** Post-Conditions: if event is wumpus do corresponding action otherwise keep on going
*********************************************************************/
bool Game::shoot_at_event_right(int i){
    if(this->grid[this->player.get_y()][this->player.get_x() + i].get_event()->get_name() == 'W'){
        delete this->grid[this->player.get_y()][this->player.get_x() + i].get_event();
        this->grid[this->player.get_y()][this->player.get_x() + i].set_event(NULL);

        this->output = " ";
        this->output.append("You Killed the Wumpus!!! find the gold and escape. ");
        this->print_matrix();
        this->wumpusdead = true;
        return true;
    } else if(this->grid[this->player.get_y()][this->player.get_x() + i].get_event()->get_name() != 'W' && i == 3){
        this->miss_shot();
        this->relocate_wumpus();
        return false;
    }
}

/*********************************************************************
** Function: Game::shoot_right()
** Description: This handles shooting an arrow to the right and doing the corresponding action
** Parameters: NONE
** Pre-Conditions: user wants to shoot right
** Post-Conditions: go through three to the right of the player if it hits wumpus then delete it
and remove arrow if it hits nothing remove arrow and give corresponding message
*********************************************************************/
void Game::shoot_right(){
    for(int i = 1; i < 4; i++){
        if(this->player.get_x() + i == this->grid_cols + 2){
            this->hit_wall();
            this->relocate_wumpus();
            break;
        } else{
            if(this->grid[this->player.get_y()][this->player.get_x() + i].get_has_event()){
                if(this->shoot_at_event_right(i)){
                    break;
                }
            } else if(i == 3){
                this->miss_shot();
                this->relocate_wumpus();
            }
        }
    }

    this->player.set_n_arrows(this->player.get_n_arrows() - 1);

    this->see_if_out_of_arrows();
}

/*********************************************************************
** Function: Game::hit_wall()
** Description: This handles outputting when the user hit the wall with their
arrow
** Parameters: NONE
** Pre-Conditions: arrow hits the wall
** Post-Conditions: the outcome is outputted
*********************************************************************/
void Game::hit_wall(){
    this->output = " ";
    this->output.append("Your arrow Hit the Wall. ");
    this->print_matrix();
}

/*********************************************************************
** Function: Game::miss_shot()
** Description: This handles outputting when the user missed their shot
** Parameters: NONE
** Pre-Conditions: arrow doesn't hit wumpus
** Post-Conditions: the outcome is outputted
*********************************************************************/
void Game::miss_shot(){
    this->output = " ";
    this->output.append("You missed your shot. ");
    this->print_matrix();
}

/*********************************************************************
** Function: Game::relocate_wumpus()
** Description: evertime an arrow is shot and it doesn't hit the wumpus there
is a 75 percent chance the wumpus will go to a random empty room and this handles that
** Parameters: NONE
** Pre-Conditions: arrow doesn't hit wumpus
** Post-Conditions: if random number is below 75, or 75% chance, then move wumpus to 
random empty room object
*********************************************************************/
void Game::relocate_wumpus(){
    int randnum = rand() % 100;

    if(randnum < 75 && this->wumpusdead == false){
        delete this->grid[this->wumpusy][this->wumpusx].get_event();
        this->grid[this->wumpusy][this->wumpusx].set_event(NULL);

        this->generate_wumpus(true);
        this->output.append("You woke up the wumpus and he moved!!! ");
        this->print_matrix();
    }
}

/*********************************************************************
** Function: Game::create_matrix()
** Description: This handles creating a 2d vector of rooms given a size
** Parameters: int size
** Pre-Conditions: size is passed in
** Post-Conditions: 2d array grid is created with size of passed in integer
*********************************************************************/
void Game::create_matrix(int size){
    for(int i = size; i > 0; i--){
        std::vector<Room> row;
        for(int j = 0; j < size; j++){
            row.push_back(Room(i, j));
        }
        this->grid.push_back(row);
    }
}

/*********************************************************************
** Function: Game::print_horizontal_line()
** Description: prints a horizontal line of dashes at given y
** Parameters: int y
** Pre-Conditions: integer is passed
** Post-Conditions: horizontal line is printed at y value that was passed
*********************************************************************/
void Game::print_horizontal_line(int y){
    for(int i = 0; i < this->grid_cols * (getmaxx(this->win)/this->grid_cols); i++){
        mvwaddch(this->win, y, i, '-');
    }
}

/*********************************************************************
** Function: Game::print_vertical_line()
** Description: prints a vertical line of | at given x
** Parameters: int x
** Pre-Conditions: integer is passed
** Post-Conditions: vertical line is printed at x value that was passed
*********************************************************************/
void Game::print_vertical_line(int x){
    for(int i = 0; i < (this->grid_cols * (getmaxy(this->win) /this->grid_cols)); i++){
        mvwaddch(this->win, i, x, '|');
    }
}

/*********************************************************************
** Function: game::print_matrix()
** Description: this handles printing the matrix on the screen along with
the player and all the events, if in debug mode
** Parameters: NONE
** Pre-Conditions: player has position and debugmode is set
** Post-Conditions: matrix is printed out with player's position, and also
events if in debug mode
*********************************************************************/
void Game::print_matrix(){
    int xsection = getmaxx(this->win)/this->grid_cols;
    int ysection = getmaxy(this->win)/this->grid_cols;
    wclear(this->win);
    
    for(int i = 0; i < this->grid_cols + 1; i++){
        if(i == 0){
            this->print_horizontal_line(i * ysection);
            this->print_vertical_line(i * xsection);
        }else{
            this->print_horizontal_line(i * ysection - 1);
            this->print_vertical_line(i * xsection - 1);
        }
    }

    this->print_player();

    if(this->debugmode){
        this->print_events();
    }

    mvwprintw(this->win, getmaxy(this->win) - 1, 0, "Output: ");
    mvwprintw(this->win, getmaxy(this->win) - 1, 8, this->output.c_str());
    mvwprintw(this->win, 0, 0, this->header.c_str());
    wrefresh(this->win);
}

/*********************************************************************
** Function: Game::print_events()
** Description: this prints out all the events and escape location on the grid
** Parameters: NONE
** Pre-Conditions: debug mode is true so this is caled
** Post-Conditions: events are printed on the matrix alongside the player
*********************************************************************/
void Game::print_events(){
    if(!((this->player.get_x() == this->escape_x) && (this->player.get_y() == this->escape_y))){
        mvwaddch(this->win, ((this->escape_y - 1) * (getmaxy(this->win)/this->grid_cols)) + ((getmaxy(this->win)/this->grid_cols/2) - 1), ((this->escape_x - 1) * (getmaxx(this->win)/this->grid_cols)) + (getmaxx(this->win)/this->grid_cols)/2, 'E');
    }

    for(int i = 0; i < this->grid_cols + 2; i++){
        for(int j = 0; j < this->grid_cols + 2; j++){
            if(this->grid[i][j].get_has_event()){
                if(!(this->grid[i][j].get_event()->get_name() == 'G' && this->player.get_has_gold() == true)){
                    mvwaddch(this->win, ((i - 1) * (getmaxy(this->win)/this->grid_cols)) + (((getmaxy(this->win)/this->grid_cols)/2) - 1), ((j - 1) * (getmaxx(this->win)/this->grid_cols)) + (getmaxx(this->win)/this->grid_cols)/2, this->grid[i][j].get_event()->get_name());
                }
            }
        }
    }
}

/*********************************************************************
** Function: Game::print_player()
** Description: This prints out the player on the matrix
** Parameters: NONE
** Pre-Conditions: player has postion
** Post-Conditions: P is printed in the matrix and player location
*********************************************************************/
void Game::print_player(){
    mvwaddch(this->win, ((this->player.get_y() - 1) * (getmaxy(this->win)/this->grid_cols)) + (((getmaxy(this->win)/this->grid_cols)/2) - 1), ((this->player.get_x() - 1) * (getmaxx(this->win)/this->grid_cols)) + (getmaxx(this->win)/this->grid_cols)/2, '*');
}

/*********************************************************************
** Function: Game::input_grid_size()
** Description: This gets a valid input from the user on the grid size that they want
** Parameters: NONE
** Pre-Conditions: user inputs value
** Post-Conditions: grid size is set to error handled user inputted value
*********************************************************************/
void Game::input_grid_size(){
    mvwprintw(this->win, getmaxy(this->win)/4, getmaxx(this->win)/4,"How big do you want the matrix to be? (5-7): ");
    bool inputg = false;

    do{
        char inputc = wgetch(this->win);
        int input = int(inputc);

        if(input > 52 && input < 56){
            this->grid_cols = input - 48;
            inputg = true;
        }else{
            werase(this->win);
            mvwprintw(this->win, getmaxy(this->win)/4, getmaxx(this->win)/4, "That input is invalid, try again (5-7): ");
            inputg = false;
            wrefresh(this->win);
        }
    }while(!inputg);

    werase(this->win);
    wrefresh(this->win);
}

/*********************************************************************
** Function: Game::input_debug_mode()
** Description: This gets a valid input from the user on the debug mode that they want
** Parameters: NONE
** Pre-Conditions: user inputs value
** Post-Conditions: debug mode is set to error handled user inputted value
*********************************************************************/
void Game::input_debug_mode(){
    mvwprintw(this->win, getmaxy(this->win)/4, getmaxx(this->win)/4, "Do you want to run in Debug Mode (t(true) or f(false)): ");
    bool inputg = false;
    
    do{
        char inputc = wgetch(this->win);
        int input = int(inputc);

        if(input == 116){
            this->debugmode = true;
            inputg = true;
        } else if(input == 102){
            this->debugmode = false;
            inputg = true;
        } else{
            werase(this->win);
            mvwprintw(this->win, getmaxy(this->win)/4, getmaxx(this->win)/4, "That input is invalid, try again (t(true) or f(false)): ");
            inputg = false;
            wrefresh(this->win);
        }
    }while(!inputg);

    werase(this->win);
    wrefresh(this->win);
}

/*********************************************************************
** Function: Game::~Game()
** Description: This is the destructor for the game and it calls the standard
ncurses endwin() method to finish up the winows that we created
** Parameters: NONE
** Pre-Conditions: ncurses window is open
** Post-Conditions: ncurses window is closed
*********************************************************************/
Game::~Game(){
    endwin();
}