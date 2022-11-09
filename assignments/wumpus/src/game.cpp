#include "game.h"

Game::Game(){
    this->input_grid_size();
    this->input_debug_mode();
}

void Game::start(){
    this->create_matrix(this->grid_cols);

    this->player.set_x((rand() % this->grid_cols));
    this->player.set_y((rand() % this->grid_cols));

    this->player.print_position();

    this->grid[this->player.get_y()][this->player.get_x()].set_has_player(true);

    this->print_matrix();
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

void Game::print_top_of_grid(){
    for(int i = 0; i < this->grid.size(); i++){
        std::cout << "----------";
    }
}

void Game::print_cell(int j, int k, int i){
    if(j == 0){        
        if(this->grid[j][k].has_player() && i == 2){
            std::cout << "| Player |";
        }
        else{
            std::cout << "|        |";
        }
    }else if(this->grid[j][k].has_player() && i == 2){
        std::cout << "  Player |";
    }else {
        std::cout << "         |"; 
    }
}

void Game::print_cell_debug(int j, int k, int i){
    if(j == 0){
        if(!this->grid[j][k].has_player() && i == 2){
            std::cout << "|        |";        
        }else if(this->grid[j][k].has_player() && i == 2){
            std::cout << "| Player |";
        }
    }else if(this->grid[j][k].has_player() && i == 2){
        std::cout << "  Player |";
    }else {
        std::cout << "         |"; 
    }
}

void Game::print_matrix(){
    this->print_top_of_grid();

    for(int k = 0; k < this->grid.size(); k++){
        std::cout << std::endl;
        for(int i = 0; i < 5; i++){
            for(int j = 0; j < this->grid.size(); j++){
                if(!this->debugmode){
                    this->print_cell(j, k, i);
                }else{
                    this->print_cell_debug(j, k, i);
                }
            }
            std::cout << std::endl;
        }
        this->print_top_of_grid();
    }
    std::cout << std::endl << std::endl;
}

void Game::input_grid_size(){
    std::string input;
    int counter = 0;

    std::cout <<"\nHow big do you want the matrix to be? : ";
    
    do{
        if(counter > 0){
            cout << "That input is invalid Try again!: ";
        }
        std::getline(std::cin, input);

        counter++;
    }while(!is_int(input) || string_to_int(input) > 8);

    this->grid_cols = string_to_int(input);
}

void Game::input_debug_mode(){
    std::string input;
    bool inputg = false;

    std::cout << "\nDo you want to run in Debug Mode: ";
    
    do{
        std::getline(std::cin, input);

        if(input == "true"){
            this->debugmode = true;
            inputg = true;
        } else if(input == "false"){
            this->debugmode = false;
            inputg = true;
        } else{
            std::cout << "\nThat input is invalid Try again!: ";
            std::cin.clear();
            inputg = false;
        }
    }while(!inputg);
}