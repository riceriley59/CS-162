#pragma once

#include <fstream>
#include <string>
#include <iostream>

using namespace std;

struct Pokemon {
    int dex_num;
    string name;
    string type;
    int num_moves;
    string* moves;
};

struct Pokedex {
    string trainer;
    int num_pokemon;
    Pokemon* dex;
};

Pokemon* create_pokemons(int);

void populate_pokedex_data(Pokedex & , ifstream &);

string* create_moves(int);

void populate_pokemon(Pokemon &, ifstream &);

void delete_info(Pokemon &);