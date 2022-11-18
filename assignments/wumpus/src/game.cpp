#include "game.h"

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

Game::Game(std::vector<std::vector<Room>> grid, int x, int y) : grid(grid), quit(false), wumpusdead(false), playagain(false){
    initscr();
    noecho();
    cbreak();
    keypad(stdscr, TRUE);

    getmaxyx(stdscr, this->y_max, this->x_max);

    this->win = newwin(this->y_max / 1.5f, this->x_max / 1.5f, this->y_max / 6, this->x_max / 6);
    this->player.set_win(this->win);
    this->player.set_x(x);
    this->player.set_y(y);
    this->set_grid_cols(this->grid.size() - 2);
    this->input_debug_mode();
    this->output = "Welcome to Hunt the Wumpus!!! You can quit the game by pressing q press any key to start!!!";
}


//getters
int Game::get_grid_cols() const{
    return this->grid_cols;
}

int Game::get_escape_x() const{
    return this->escape_x;
}

int Game::get_escape_y() const{
    return this->escape_y;
}

bool Game::get_debug_mode() const{
    return this->debugmode;
}

bool Game::get_quit() const{
    return this->quit;
}

bool Game::get_playagain() const{
    return this->playagain;
}

bool Game::get_same_cave() const{
    return this->samecave;
}

Player Game::get_player() const{
    return this->player;
}

std::vector<std::vector<Room>> Game::get_grid() const{
    return this->grid;
}

std::string Game::get_output() const {
    return this->output;
}

//setters
void Game::set_grid_cols(int grid_cols){
    this->grid_cols = grid_cols;
}

void Game::set_debug_mode(bool debugmode){
    this->debugmode = debugmode;
}


void Game::start(bool playagain){
    this->player.set_grid_cols(this->grid_cols);
    if(!playagain){
        this->create_matrix(this->grid_cols + 2);

        this->escape_x = (rand() % this->grid_cols) + 1;
        this->escape_y = (rand() % this->grid_cols) + 1;
    }else{
        this->escape_x = this->player.get_x();
        this->escape_y = this->player.get_y();
    }

    this->player.set_x(escape_x);
    this->player.set_y(escape_y);

    if(!this->playagain){
        this->populate_events();
    }

    this->print_matrix();
    wgetch(this->win);
    this->output = " ";
    this->header.append("Where do you want to move? (w-up, s-down, d-right, a-left): ");
    this->print_player_position();
    this->check_for_percept();
    this->print_matrix();
}

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

void Game::end(){
    wclear(this->win);
    this->play_again();
}

void Game::play_again(){
    mvwprintw(this->win, getmaxy(this->win)/4, getmaxx(this->win)/4, "Do you want to play again? (t(true) or f(false)): ");
    bool inputg = false;
    
    do{
        char inputc = wgetch(this->win);
        int input = int(inputc);

        if(input == 116){
            this->samecave = this->get_cave_config();
            this->playagain = true;
            inputg = true;
        } else if(input == 102){
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

void Game::print_player_position(){
    std::string player = " Your positon is: (";
    player.append(to_string(this->player.get_x()));
    player.append(", ");
    player.append(to_string(this->player.get_y()));
    player.append(")");
    this->header.append(player);
}

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

void Game::generate_wumpus(){
    int wumpusx = 0;
    int wumpusy = 0;
    bool wlocation = false;
    
    do{
        wumpusx = (rand() % this->grid_cols) + 1;
        wumpusy = (rand() % this->grid_cols) + 1;

        if(wumpusx == this->escape_x && wumpusy == this->escape_y){
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

void Game::populate_events(){
    //generate bats
    this->generate_bats();

    //generate pits
    this->generate_pits();

    //generate gold
    this->generate_gold();

    //generate wumpus
    this->generate_wumpus();
}

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

void Game::move_up(){
    if(!(this->player.get_y() == 1)){
        this->player.set_y(this->player.get_y() - 1);
    }
}

void Game::move_down(){
    if(!(this->player.get_y() == this->grid_cols)){
        this->player.set_y(this->player.get_y() + 1);
    }
}

void Game::move_right(){
    if(!(this->player.get_x() == this->grid_cols)){
        this->player.set_x(this->player.get_x() + 1);
    }
}

void Game::move_left(){
    if(!(this->player.get_x() == 1)){
        this->player.set_x(this->player.get_x() - 1);
    }
}

void Game::shoot_arrow(){
    if(this->player.get_n_arrows() > 0){
        this->header = "";
        this->header.append("What direction do you want to shoot your arrow, or press e to cancel (w-up, s-down, d-right, a-left): ");
        this->print_matrix();

        int move = 0;

        do{
            char inputc = wgetch(this->win);
            move = int(inputc);
        }while(!this->handle_shoot(move));

        this->header = "";
        this->header.append("Where do you want to move? (w-up, s-down, d-right, a-left): ");
    }else {
        this->header = "";
        this->header.append("Where do you want to move? (w-up, s-down, d-right, a-left): ");
        this->output = " ";
        this->output.append("You have no more arrows to shoot. Press any key to continue... ");
        this->print_matrix();
        wgetch(this->win);
        this->output = " ";
    }
}

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
        this->header = "";
        this->header.append("That input is invalid, try again. What direction do you want to shoot in (w-up, s-down, d-right, a-left, e-don't shoot): ");
        this->print_matrix();
        return false;
    }
}

void Game::shoot_up(){
    for(int i = 1; i < 4; i++){
        if(this->player.get_y() - i == 0){
            this->hit_wall();
            this->relocate_wumpus();
            break;
        } else{
            if(this->grid[this->player.get_y() - i][this->player.get_x()].get_has_event()){
                if(this->grid[this->player.get_y() - i][this->player.get_x()].get_event()->get_name() == 'W'){
                    delete this->grid[this->player.get_y() - i][this->player.get_x()].get_event();
                    this->grid[this->player.get_y() - i][this->player.get_x()].set_event(NULL);

                    this->output = " ";
                    this->output.append("You Killed the Wumpus!!! find the gold and escape");
                    this->print_matrix();
                    this->wumpusdead = true;
                    break;
                } else if(this->grid[this->player.get_y() - i][this->player.get_x()].get_event()->get_name() != 'W' && i == 3){
                    this->miss_shot();
                }
            } else if(i == 3){
                this->miss_shot();
            }
        }
    }

    this->player.set_n_arrows(this->player.get_n_arrows() - 1);

    if(this->player.get_n_arrows() == 0 && this->wumpusdead == false){
        this->output = " ";
        this->output.append("You ran out of arrows, and the wumpus is still alive so you lost. press any key to continue...");
        this->player.set_alive(false);
    }
}

void Game::shoot_down(){
    for(int i = 1; i < 4; i++){
        if(this->player.get_y() + i == this->grid_cols + 2){
            this->hit_wall();
            this->relocate_wumpus();
            break;
        } else{
            if(this->grid[this->player.get_y() + i][this->player.get_x()].get_has_event()){
                if(this->grid[this->player.get_y() + i][this->player.get_x()].get_event()->get_name() == 'W'){
                    delete this->grid[this->player.get_y() + i][this->player.get_x()].get_event();
                    this->grid[this->player.get_y() + i][this->player.get_x()].set_event(NULL);

                    this->output = " ";
                    this->output.append("You Killed the Wumpus!!! find the gold and escape");
                    this->print_matrix();
                    this->wumpusdead = true;
                    break;
                } else if(this->grid[this->player.get_y() + i][this->player.get_x()].get_event()->get_name() != 'W' && i == 3){
                    this->miss_shot();
                }
            } else if(i == 3){
                this->miss_shot();
            }
        }
    }

    this->player.set_n_arrows(this->player.get_n_arrows() - 1);

    if(this->player.get_n_arrows() == 0 && this->wumpusdead == false){
        this->output = " ";
        this->output.append("You ran out of arrows, and the wumpus is still alive so you lost. press any key to continue...");
        this->player.set_alive(false);
    }
}

void Game::shoot_left(){
    for(int i = 1; i < 4; i++){
        if(this->player.get_x() - i == 0){
            this->hit_wall();
            this->relocate_wumpus();
            break;
        } else{
            if(this->grid[this->player.get_y()][this->player.get_x() - i].get_has_event()){
                if(this->grid[this->player.get_y()][this->player.get_x() - i].get_event()->get_name() == 'W'){
                    delete this->grid[this->player.get_y()][this->player.get_x() - i].get_event();
                    this->grid[this->player.get_y()][this->player.get_x() - i].set_event(NULL);

                    this->output = " ";
                    this->output.append("You Killed the Wumpus!!! find the gold and escape");
                    this->print_matrix();
                    this->wumpusdead = true;
                    break;
                } else if(this->grid[this->player.get_y()][this->player.get_x() - i].get_event()->get_name() != 'W' && i == 3){
                    this->miss_shot();
                }
            } else if(i == 3){
                this->miss_shot();
            }
        }
    }

    this->player.set_n_arrows(this->player.get_n_arrows() - 1);

    if(this->player.get_n_arrows() == 0 && this->wumpusdead == false){
        this->output = " ";
        this->output.append("You ran out of arrows, and the wumpus is still alive so you lost. press any key to continue...");
        this->player.set_alive(false);
    }
}

void Game::shoot_right(){
    for(int i = 1; i < 4; i++){
        if(this->player.get_x() + i == this->grid_cols + 2){
            this->hit_wall();
            this->relocate_wumpus();
            break;
        } else{
            if(this->grid[this->player.get_y()][this->player.get_x() + i].get_has_event()){
                if(this->grid[this->player.get_y()][this->player.get_x() + i].get_event()->get_name() == 'W'){
                    delete this->grid[this->player.get_y()][this->player.get_x() + i].get_event();
                    this->grid[this->player.get_y()][this->player.get_x() + i].set_event(NULL);

                    this->output = " ";
                    this->output.append("You Killed the Wumpus!!! find the gold and escape. ");
                    this->print_matrix();
                    this->wumpusdead = true;
                    break;
                } else if(this->grid[this->player.get_y()][this->player.get_x() + i].get_event()->get_name() != 'W' && i == 3){
                    this->miss_shot();
                    this->relocate_wumpus();
                }
            } else if(i == 3){
                this->miss_shot();
                this->relocate_wumpus();
            }
        }
    }

    this->player.set_n_arrows(this->player.get_n_arrows() - 1);

    if(this->player.get_n_arrows() == 0 && this->wumpusdead == false){
        this->output = " ";
        this->output.append("You ran out of arrows, and the wumpus is still alive so you lost. press any key to continue...");
        this->player.set_alive(false);
    }
}

void Game::hit_wall(){
    this->output = " ";
    this->output.append("Your arrow Hit the Wall. ");
    this->print_matrix();
}

void Game::miss_shot(){
    this->output = " ";
    this->output.append("You missed your shot. ");
    this->print_matrix();
}

void Game::relocate_wumpus(){
    int randnum = rand() % 100;

    if(randnum < 75 && this->wumpusdead == false){
        delete this->grid[this->wumpusy][this->wumpusx].get_event();
        this->grid[this->wumpusy][this->wumpusx].set_event(NULL);

        this->generate_wumpus();
        this->output.append("You woke up the wumpus and he moved!!! ");
        this->print_matrix();
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
    mvwprintw(this->win, getmaxy(this->win) - 1, 8, this->output.c_str());
    mvwprintw(this->win, 0, 0, this->header.c_str());
    wrefresh(this->win);
}

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

void Game::print_player(){
    mvwaddch(this->win, ((this->player.get_y() - 1) * (getmaxy(this->win)/this->grid_cols)) + (((getmaxy(this->win)/this->grid_cols)/2) - 1), ((this->player.get_x() - 1) * (getmaxx(this->win)/this->grid_cols)) + (getmaxx(this->win)/this->grid_cols)/2, '*');
}

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

Game::~Game(){
    endwin();
}