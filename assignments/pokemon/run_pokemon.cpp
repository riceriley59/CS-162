/*********************************************************************
** Program: Pokedex - run_pokemon.cpp
** Author: Riley Rice
** Date: 10-20-2022
** Description: This is my driver file for my pokedex program it takes in a pokedex file and then 
allows the user to search for pokemon based on different parameters like it's name, type, or dex number.
Then it will either output that information to the screen or output it into a file based on the user's 
specification. They can also add pokemon to the original dex file.
** Input: dex file with appropriate formatting
** Output: output the requested pokemon based on given information either in a file or to the screen.
Also add a pokemon to the dex file if requested.
*********************************************************************/

#include "pokemon.h"

/*********************************************************************
** Function: main()
** Description: This is the main control flow program of my file as it controls everything
within the program and uses function from my implementation file.
** Parameters: NONE
** Pre-Conditions: dex file with information
** Post-Conditions: requested information outputted, or information is inputted and stored
*********************************************************************/
int main(){
    //initialize some variables that will need to live throughout the whole scope of the program
    string file_name;
    ifstream inputfile;
    ofstream outputfile;
    Pokedex pokedex;
    
    int number = 0;

    //call intro function to get requested input file name
    intro(file_name);

    //try to open that file
    inputfile.open(file_name.c_str(), ios::in);

    //if the file doens't exist then return an error and quit
    if(!inputfile.is_open()){
        cout << "\nERROR that file doesn't exist please try again. Quitting!!\n";
        return 1;
    }

    //take the first number from the dex file which indicates how many pokemon there are 
    //and store that in number
    inputfile >> number;
    pokedex.num_pokemon = number;

    //create a dynamic array of pokemon structs of num of pokemon and return that pointer to our
    //pokemon pointer in our pokedex struct
    pokedex.dex = create_pokemons(number);
    populate_pokedex_data(pokedex, inputfile);

    //start the main control function which handles all the logic
    options(pokedex, outputfile, file_name);
    
    //at the end of the program delete all dynamic memory and close both the file streams to be
    //safe and make sure there are no memory leaks
    delete_info(pokedex);
    inputfile.close();
    outputfile.close();

    //return 0 and exit program without errors
    return 0;
}