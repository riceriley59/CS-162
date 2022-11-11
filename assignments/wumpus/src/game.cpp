#include "game.h"

Game::Game(){
    initscr();
    noecho();
    cbreak();
    keypad(stdscr, TRUE);

    getmaxyx(stdscr, this->y_max, this->x_max);

    this->win = newwin(this->y_max/1.5f, this->x_max/1.5f, this->y_max/6, this->x_max/6);
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
    while(this->player.get_alive() == true){
        int input = this->player.get_move();

        if(input == 113){
            break;
        }
        
        this->move_player(input);

        this->print_matrix();
        wrefresh(this->win);
    }
}

void Game::move_player(int move){
    if(move == 119){
        this->player.set_y(this->player.get_y() - 1);
    }else if(move == 115){
        this->player.set_y(this->player.get_y() + 1);
    }else if (move == 100){
        this->player.set_x(this->player.get_x() + 1);
    }else if(move == 97){
        this->player.set_x(this->player.get_x() - 1);
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
    for(int i = 0; i < (this->grid_cols * (getmaxy(this->win) /this->grid_cols)); i++){
        mvwaddch(this->win, i, x, '|');
    }
}

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
    wrefresh(this->win);
}

void Game::print_events(){

}

void Game::print_player(){
    mvwaddch(this->win, (this->player.get_y() * (getmaxy(this->win)/this->grid_cols)) + (((getmaxy(this->win)/this->grid_cols)/2) - 1), (this->player.get_x() * (getmaxx(this->win)/this->grid_cols)) + (getmaxx(this->win)/this->grid_cols)/2, 'P');
}

void Game::input_grid_size(){
    mvwprintw(this->win, 10, 25,"How big do you want the matrix to be? (5-7): ");
    bool inputg = false;

    do{
        char inputc = wgetch(this->win);
        int input = int(inputc);

        if(input > 52 && input < 56){
            this->grid_cols = input - 48;
            inputg = true;
        }else{
            werase(this->win);
            mvwprintw(this->win, 10, 25, "That input is invalid, try again (5-7): ");
            inputg = false;
            wrefresh(this->win);
        }
    }while(!inputg);

    werase(this->win);
    wrefresh(this->win);
}

void Game::input_debug_mode(){
    mvwprintw(this->win, 10, 25, "Do you want to run in Debug Mode (t(true) or f(false)): ");
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
            mvwprintw(this->win, 10, 25, "That input is invalid, try again (t(true) or f(false)): ");
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