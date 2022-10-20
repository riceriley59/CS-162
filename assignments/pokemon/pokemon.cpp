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
    inputfile >> pokemon.dex_num; 
    inputfile >> pokemon.name; 
    inputfile >> pokemon.type;
    inputfile >> pokemon.num_moves;

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

void options(Pokedex& pokedex, ofstream& outputfile, string input_file_name){
    cout << "Here are the available options for searching or adding to the PokeDex: \n";
    cout << "1. Search by Dex number\n" << "2. Search by Name\n" << "3. Search by Type\n";
    cout << "4. Add new Pokemon\n" << "5. Quit\n" << "what would you like to do: ";

    get_options(pokedex, outputfile, input_file_name);
}

void get_options(Pokedex& pokedex, ofstream& outputfile, string input_file_name){
    int option = 0;
    cin >> option;

    if(option == 1){
        search_by_dex(pokedex, outputfile, input_file_name);
    }else if(option == 2){
        search_by_name(pokedex, outputfile, input_file_name);
    }else if(option == 3){
        search_by_type(pokedex, outputfile, input_file_name);
    }else if(option == 4){
        add_new_pokemon(pokedex, input_file_name, outputfile);
    }else if(option == 5){
        cout << "\nQuitting...\n";
    }else{
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "\nThat input is invalid Try again! \n\n";
        options(pokedex, outputfile, input_file_name);
    }
}

void search_by_dex(Pokedex& pokedex, ofstream& outputfile, string input_file_name){
    int output_option = get_output_type();
    int dex_number;
    int count = 0;

    cout << "What dex number do you want to search for:";
    cin >> dex_number;
    cout << "\n";

    if(output_option == 2){
        get_output_file(outputfile);
    }

    for(int i = 0; i < pokedex.num_pokemon; i++){
        if(dex_number == pokedex.dex[i].dex_num){
            if(output_option == 1){
                print_to_screen(pokedex, i);
            }else if(output_option == 2){
                print_to_output_file(outputfile, pokedex, i);
            }
            count++;
        }
    }

   handle_going_again(pokedex, outputfile, count, input_file_name);
}

void search_by_name(Pokedex& pokedex, ofstream& outputfile, string input_file_name){
    int output_option = get_output_type();
    string name;
    int count = 0;

    cout << "What name do you want to search for: ";
    cin >> name;
    cout << '\n';

    if(output_option == 2){
        get_output_file(outputfile);
    }

    for(int i = 0; i < pokedex.num_pokemon; i++){
        if(name == pokedex.dex[i].name){
            if(output_option == 1){
                print_to_screen(pokedex, i);
            }else if(output_option == 2){
                print_to_output_file(outputfile, pokedex, i);
            }
            count++;
        }
    }

    handle_going_again(pokedex, outputfile, count, input_file_name);
}

void search_by_type(Pokedex& pokedex, ofstream& outputfile, string input_file_name){
    int output_option = get_output_type();
    string type;
    int count = 0;

    cout << "What type do you want to search for: ";
    cin >> type;
    cout << '\n';

    if(output_option == 2){
        get_output_file(outputfile);
    }

    for(int i = 0; i < pokedex.num_pokemon; i++){
        if(type == pokedex.dex[i].type){
            if(output_option == 1){
                print_to_screen(pokedex, i);
            }else if(output_option == 2){
                print_to_output_file(outputfile, pokedex, i);
            }
            count++;
        }
    }

    handle_going_again(pokedex, outputfile, count, input_file_name);
}

void add_new_pokemon(Pokedex& pokedex, string file_name, ofstream& outputfile){
    int count = 0;
    
    add_one_to_pokedex(pokedex);

    handle_going_again(pokedex, outputfile, count, file_name);
}

void add_one_to_pokedex(Pokedex& pokedex){
    Pokemon* temp = create_pokemons((pokedex.num_pokemon + 1));

    for(int i = 0; i < pokedex.num_pokemon; i++){
        temp[i].dex_num = pokedex.dex[i].dex_num;
        temp[i].name = pokedex.dex[i].name;
        temp[i].type = pokedex.dex[i].type;
        temp[i].num_moves = pokedex.dex[i].num_moves;

        temp[i].moves = create_moves(temp[i].num_moves);

        for(int j = 0; j < pokedex.dex[i].num_moves; j++){
            temp[i].moves[j] = pokedex.dex[i].moves[j];
        }
    }
    
    delete_info(pokedex);

    pokedex.dex = temp;
}

void handle_going_again(Pokedex& pokedex, ofstream& outputfile, int count, string input_file_name){
    if(count == 0){
        cout << "\nFound no matches" << endl << endl;
    }else if(count >= 1){
        cout << "\nFound " << count << " matches" << endl << endl;
    }

    outputfile.close();
    options(pokedex, outputfile, input_file_name);
}

void print_to_screen(Pokedex& pokemon, int i){
    cout << pokemon.dex[i].dex_num << " " << pokemon.dex[i].name << " " << pokemon.dex[i].type << " " << pokemon.dex[i].num_moves << endl;
    for(int j = 0; j < pokemon.dex[i].num_moves; j++){
        cout << pokemon.dex[i].moves[j] << " ";
    }
    cout << "\n";
}

void print_to_output_file(ofstream& outputfile, Pokedex& pokemon, int i){
    outputfile << pokemon.dex[i].dex_num << " " << pokemon.dex[i].name << " " << pokemon.dex[i].type << " " << pokemon.dex[i].num_moves << endl;
    for(int j = 0; j < pokemon.dex[i].num_moves; j++){
        outputfile << pokemon.dex[i].moves[j] << " ";
    }
    outputfile << "\n";
}

void get_output_file(ofstream& outputfile){
    string outputfile_name;

    cout << "Enter an output file name (if you already have a file it will append your search to the end of it): ";
    cin >> outputfile_name;

    outputfile.open(outputfile_name.c_str(), ios::app);
}

int get_output_type(){
    int option;

    cout << "\nDo you want your information: \n1. Printed to the screen\n2. Outputted to a file\nInput: ";
    cin >> option;

    if(option == 1){
        cout << "\nPrinting to the Screen... \n";
        return 1;
    } else if(option == 2){
        cout << "\nWill output to a file...\n";
        return 2;
    }else{
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "\nThat input is invalid Try Again!\n";
        get_output_type();
    }

    return 0;
}