#include "game.h"

Game::Game(){
    cout <<"\nHow big do you want the matrix to be? : ";
    cin >> this->grid_cols;
    cout << endl;
}

void Game::start(){
    this->create_matrix(this->grid_cols);
    
    cout << this->grid.size() << "\n";

    for(int i = 0; i < this->grid_cols; i++){
        cout << this->grid[i][3];
    }
    this->print_matrix();
}

void Game::create_matrix(int size){
    for(int i = 0; i < size; i++){
        vector<int> row;
        for(int j = 0; j < size; j++){
            row.push_back(j);
        }
        this->grid.push_back(row);
    }
}

void Game::print_matrix(){
    for(int i = 0; i < this->grid.size(); i++){
        for(int j = 0; j < this->grid.size(); i++){
            cout << "\n" << this->grid[i][j] << "\n";
        }
    }
}