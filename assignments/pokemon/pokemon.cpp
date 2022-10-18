#include "pokemon.h"

void intro(string& filename){
    cout << "Welcome to the CLI Pokedex!! Please enter an input file: ";
    cin >> filename;
}

Pokemon* create_pokemons(int size){
    Pokemon* p;
    p = new Pokemon[size];
    return p;
}

void populate_pokedex_data(Pokedex &pokedex, ifstream &inputfile){
    for(int i = 0; i < pokedex.num_pokemon; i++){
        populate_pokemon(pokedex.dex[i], inputfile);
    }
}

string* create_moves(int size){
    string* p;
    p = new string[size];
    return p;
}

void populate_pokemon(Pokemon &pokemon, ifstream &inputfile){
    inputfile >> pokemon.dex_num >> pokemon.name >> pokemon.type;
    inputfile >> pokemon.type >> pokemon.num_moves;

    pokemon.moves = create_moves(pokemon.num_moves);
    
    for(int i = 0; i < pokemon.num_moves; i++){
        inputfile >> pokemon.moves[i];
    }
}

void delete_info(Pokedex &pokedex){
    for(int i = 0; i < pokedex.num_pokemon; i++){
        delete [] pokedex.dex[i].moves;
        pokedex.dex[i].moves = NULL;
    }

    delete [] pokedex.dex;
    pokedex.dex = NULL;
}

void get_options(){
    int option = 0;
    cin >> option;

    if(option == 1){
        search_by_dex();
    }else if(option == 2){
        search_by_name();
    }else if(option == 3){
        search_by_type();
    }else if(option == 4){
        add_new_pokemon();
    }else if(option == 5){
        cout << "\nQuitting...\n";
    }else{
        cout << "\nThat input is invalid Try again! \n\n";
        cin.clear();
        cin.ignore();
        options();
    }
}

void search_by_dex(){

}

void search_by_name(){

}

void search_by_type(){

}

void add_new_pokemon(){

}

void options(){
    cout << "Here are the available options for searching or adding to the PokeDex: \n";
    cout << "1. Search by Dex number\n" << "2. Search by Name\n" << "3. Search by Type\n";
    cout << "4. Add new Pokemon\n" << "5. Quit\n" << "what would you like to do: ";

    get_options();
}