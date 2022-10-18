#include "pokemon.h"

int main(){
    string file_name;
    ifstream inputfile;
    ofstream outputfile;
    Pokedex pokedex;
    
    int number = 0;

    intro(file_name);

    inputfile.open(file_name.c_str(), ios::in);

    if(!inputfile.is_open()){
        cout << "\nERROR that file doesn't exist please try again. Quitting!!\n";
        return 1;
    }

    inputfile >> number;
    pokedex.num_pokemon = number;

    pokedex.dex = create_pokemons(number);

    populate_pokedex_data(pokedex, inputfile);

    options();

    delete_info(pokedex);
    inputfile.close();
    return 0;
}