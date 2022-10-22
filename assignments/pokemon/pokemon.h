/*********************************************************************
** Filename: pokemon.h
** Author: Riley Rice
** Date: 10-20-2022
** Description: my header file for my implementation file
*********************************************************************/

//header guard
#ifndef POKEMON_H
#define POKEMON_H

//include libraries
#include <fstream>
#include <string>
#include <iostream>

using namespace std;

//Pokemon struct for storing all the data about a single pokemon
struct Pokemon {
    int dex_num;
    string name;
    string type;
    int num_moves;
    string* moves;
};

//Pokedex struct which holds the pokemon array and the number of the pokemon
struct Pokedex {
    string trainer;
    int num_pokemon;
    Pokemon* dex;
};

//function prototypes for handling dynamic memory and memory allocation
Pokemon* create_pokemons(int);
void populate_pokedex_data(Pokedex & , ifstream &);
string* create_moves(int);
void populate_pokemon(Pokemon &, ifstream &);
void delete_info(Pokedex &);

//user interface function
void intro(string&);
void options(Pokedex&, ofstream&, string);
void get_options(Pokedex&, ofstream&, string, int);

//searching and adding functions
void search_by_dex(Pokedex&, ofstream&, string);
void search_by_name(Pokedex&, ofstream&, string);
void search_by_type(Pokedex&, ofstream&, string);
void add_new_pokemon(Pokedex&, string, ofstream&);

//get the output type and output file if needed
int get_output_type();
void get_output_file(ofstream&, string);

//printing functions
void print_to_screen(Pokedex&, int i);
void print_to_output_file(ofstream&, Pokedex&, int, bool);

//handles recursive option function call
void handle_going_again(Pokedex&, ofstream&, int, string);

//functions for adding new pokemon to pokedex array
void add_one_to_pokedex(Pokedex&);
void add_new_pokemon_to_dex(Pokedex&);
void rewrite_dex(Pokedex&, string, ofstream&);

//error handling for adding a new pokemon
void initialize_last_index(Pokedex&);
bool no_duplicate_dex(Pokedex&);
bool no_duplicate_name(Pokedex&);
void error_handle_new_pokemon(Pokedex&);
void error_handle_moves(Pokedex&);
void error_handle_new_nummoves(Pokedex&);
void error_handle_new_type(Pokedex&);
void output_new_pokemon(Pokedex& pokedex);

//error handling and data conversion helper functions
bool is_str(string);
string to_lowercase(string);
void string_to_int(string, int&);
int pow(int, int);
bool is_str_with_under(string);
bool is_int(string);
bool txt(char[], int);
void convert_str_to_char(string, char[]);

#endif