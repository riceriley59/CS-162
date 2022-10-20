#ifndef POKEMON_H
#define POKEMON_H

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
void delete_info(Pokedex &);


void intro(string&);
void options(Pokedex&, ofstream&, string);
void get_options(Pokedex&, ofstream&, string);

void search_by_dex(Pokedex&, ofstream&, string);
void search_by_name(Pokedex&, ofstream&, string);
void search_by_type(Pokedex&, ofstream&, string);
void add_new_pokemon(Pokedex&, string, ofstream&);

int get_output_type();

void print_to_screen(Pokedex&, int i);
void print_to_output_file(ofstream&, Pokedex&, int i);
void get_output_file(ofstream&);

void add_one_to_pokedex(Pokedex&);

void handle_going_again(Pokedex&, ofstream&, int, string);
void add_new_pokemon_to_dex(Pokedex&);
void rewrite_dex(Pokedex&, string, ofstream&);

void initialize_last_index(Pokedex&);
bool no_duplicate_dex(Pokedex& pokedex);
bool no_duplicate_name(Pokedex& pokedex);

string to_lowercase(string str);

#endif