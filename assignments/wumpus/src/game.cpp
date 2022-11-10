#include "game.h"

Game::Game(){
    initscr();
    noecho();
    cbreak();
    keypad(stdscr, TRUE);

    getmaxyx(stdscr, this->y_max, this->x_max);

    this->win = newwin(this->y_max/2, this->x_max/2, this->y_max/4, this->x_max/4);
    this->player.set_win(this->win); 
    this->input_grid_size();
    this->input_debug_mode();
}


//getters
int Game::get_grid_cols() const{
    return this->grid_cols;
}

bool Game::get_debug_mode() const{
    return this->debugmode;
}

Player Game::get_player() const{
    return this->player;
}

std::vector<std::vector<Room>> Game::get_grid() const{
    return this->grid;
}

//setters
void Game::set_grid_cols(int grid_cols){
    this->grid_cols = grid_cols;
}

void Game::set_debug_mode(bool debugmode){
    this->debugmode = debugmode;
}


void Game::start(){
    this->create_matrix(this->grid_cols);

    this->player.set_x((rand() % this->grid_cols));
    this->player.set_y((rand() % this->grid_cols));

    this->print_matrix();
}

void Game::play(){
    wgetch(this->win);
    //while(this->player.get_alive() == true){
        //int input = this->player.get_move();

      //  this->print_matrix();
    //}
}

void Game::move_player(int move){
    if(move == 119){
        this->grid[this->player.get_y()][this->player.get_x()].set_has_player(false);
        this->player.set_x(this->player.get_x() - 1);
        this->grid[this->player.get_y()][this->player.get_x()].set_has_player(true);
    }else if(move == 115){
        this->grid[this->player.get_y()][this->player.get_x()].set_has_player(false);
        this->player.set_x(this->player.get_x() + 1);
        this->grid[this->player.get_y()][this->player.get_x()].set_has_player(true);
    }else if (move == 100){
        this->grid[this->player.get_y()][this->player.get_x()].set_has_player(false);
        this->player.set_y(this->player.get_y() + 1);
        this->grid[this->player.get_y()][this->player.get_x()].set_has_player(true);
    }else if(move == 97){
        this->grid[this->player.get_y()][this->player.get_x()].set_has_player(false);
        this->player.set_y(this->player.get_y() - 1);
        this->grid[this->player.get_y()][this->player.get_x()].set_has_player(true);
    }
}

void Game::create_matrix(int size){
    for(int i = size; i > 0; i--){
        std::vector<Room> row;
        for(int j = 0; j < size; j++){
            row.push_back(Room(i, j));
        }
        this->grid.push_back(row);
    }
}

void Game::print_horizontal_line(int y){
    for(int i = 0; i < this->grid_cols * (getmaxx(this->win)/this->grid_cols); i++){
        mvwaddch(this->win, y, i, '-');
    }
}

void Game::print_vertical_line(int x){
    for(int i = 0; i < this->grid_cols * (getmaxy(this->win)/this->grid_cols); i++){
        mvwaddch(this->win, i, x, '|');
    }
}

void Game::print_matrix(){
    wclear(this->win);
    for(int i = 0; i < this->grid_cols; i++){
        this->print_horizontal_line(i * getmaxy(this->win)/this->grid_cols);
        this->print_vertical_line(i * getmaxx(this->win)/this->grid_cols);
    }

    this->print_horizontal_line(getmaxy(this->win) - 1);
    this->print_vertical_line(getmaxx(this->win) - 1);

    mvwaddch(this->win, this->player.get_y() * this->grid_cols, this->player.get_x() * this->grid_cols, 'P');

    mvwprintw(this->win, 0, 0, "Where do you want to move?: ");

    wrefresh(this->win);
}

void Game::input_grid_size(){
    mvwprintw(this->win, 10, 25,"How big do you want the matrix to be? : ");
    bool inputg = false;

    do{
        char inputc = wgetch(this->win);
        int input = int(inputc);

        if(input > 49 && input < 57){
            this->grid_cols = input - 48;
            inputg = true;
        }else{
            werase(this->win);
            mvwprintw(this->win, 10, 25, "That input is invalid, try again: ");
            inputg = false;
            wrefresh(this->win);
        }
    }while(!inputg);

    werase(this->win);
    wrefresh(this->win);
}

void Game::input_debug_mode(){
    mvwprintw(this->win, 10, 25, "Do you want to run in Debug Mode: ");
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
            mvwprintw(this->win, 10, 25, "That input is invalid, try again: ");
            inputg = false;
            wrefresh(this->win);
        }
    }while(!inputg);

    werase(this->win);
    wrefresh(this->win);
}

Game::~Game(){
    endwin();
}