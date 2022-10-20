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

    int option = 0;
    cin >> option;

    get_options(pokedex, outputfile, input_file_name, option);
}

void get_options(Pokedex& pokedex, ofstream& outputfile, string input_file_name, int option){
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

string to_lowercase(string str){
    for(int i = 0; i < str.length(); i++){
        if(int(str[i]) >= 97 && int(str[i]) <= 122){
            continue;
        }else if(int(str[i]) >= 65 && int(str[i]) <= 90){
            str[i] = char(int(str[i]) + 32);
        }
    }

    return str;
}

bool is_int(string num) {
	for (int i = 0; i < num.length(); i++) { //iterate through each character of the string
		//if the character of the string isn't an ASCII integer value or the character is . then return false because it isn't numbers or it's a float with a dot
		if(!((int(num[i]) - 48) <= 9 && (int(num[i] - 48)) >= 0) || num[i] == '.'){
			cout << "That dex number is invalid please try again!\n";
            return false;
		}
		//if the whole string was iterated and it didn't return false then return true because it's an integer
		else if(i == num.length() - 1) {
			return true;
		}
	}

    return false;
}

int pow(int base, int exponent){
    int total = 1;

    for(int i = 0; i < exponent; i++){
        total *= base;
    }

    return total;
}

void string_to_int(string num, int& value) {
	value = 0; // set the value equal to 0 to get rid of any garbage value stored in their

	//iterate through each character of the given string
   	for(int i = 0; i < num.length(); i++){
	   	//if the character is a valid ASCII integer value
		if((int(num[i]) - 48) >= 0 && (int(num[i]) - 48) <= 9){
	   		//as the string is iterated multiply the integer value by a power of 10 that is decremented as the for loop increments then add that to value variable	   
	   		value += pow(10, (num.length() - 1) - i) * (int(num[i]) - 48);
			//if the first character is a - value and the whole string has already been converted then multiply the value by -1 to make the integer a negative
			if(num[0] == '-' && i == num.length() - 1){
				value *= -1;
			}
		}
	}
}

bool is_str(string str){
    for(int i = 0; i < str.length(); i++){
        if(!((int(str[i]) >= 65 && int(str[i]) <= 90) || (int(str[i]) >= 97 && int(str[i]) <= 122))){
            cout << "You can't have numbers or special characters in the name or type,\nPlease try again!\n";
            return false;
        }
        if(i == (str.length() - 1)){
            return true;       
        }
    }

    return true;
}

void search_by_dex(Pokedex& pokedex, ofstream& outputfile, string input_file_name){
    int output_option = get_output_type(), count = 0, dex_number = 0;
    string dex_number_str;

    do{
        cout << "What dex number do you want to search for: ";
        cin >> dex_number_str;
        cout << "\n"; 
    }while(!is_int(dex_number_str));  

    string_to_int(dex_number_str, dex_number);

    for(int i = 0; i < pokedex.num_pokemon; i++){
        if(dex_number == pokedex.dex[i].dex_num){
            count++;
            if(output_option == 1){
                print_to_screen(pokedex, i);
            }else if(output_option == 2){
                if(count == 1){
                    get_output_file(outputfile);
                }
                print_to_output_file(outputfile, pokedex, i);
            }
        }
    }

   handle_going_again(pokedex, outputfile, count, input_file_name);
}

void search_by_name(Pokedex& pokedex, ofstream& outputfile, string input_file_name){
    int output_option = get_output_type(), count = 0;
    string name;

    do{
        cout << "What name do you want to search for: ";
        cin >> name;
        cout << '\n';
    }while(!is_str(name));

    for(int i = 0; i < pokedex.num_pokemon; i++){
        if(to_lowercase(name) == to_lowercase(pokedex.dex[i].name)){
            count++;
            if(output_option == 1){
                print_to_screen(pokedex, i);
            }else if(output_option == 2){
                if(count == 1){
                    get_output_file(outputfile);
                }
                print_to_output_file(outputfile, pokedex, i);
            }
        }
    }

    handle_going_again(pokedex, outputfile, count, input_file_name);
}

void search_by_type(Pokedex& pokedex, ofstream& outputfile, string input_file_name){
    int output_option = get_output_type(), count = 0;
    string type;

    do{
        cout << "What type do you want to search for: ";
        cin >> type;
        cout << '\n';
    }while(!is_str(type));

    for(int i = 0; i < pokedex.num_pokemon; i++){
        if(to_lowercase(type) == to_lowercase(pokedex.dex[i].type)){
            count++;
            if(output_option == 1){
                print_to_screen(pokedex, i);
            }else if(output_option == 2){
                if(count == 1){
                    get_output_file(outputfile);
                }
                print_to_output_file(outputfile, pokedex, i);
            }
        }
    }

    handle_going_again(pokedex, outputfile, count, input_file_name);
}

void add_new_pokemon(Pokedex& pokedex, string file_name, ofstream& outputfile){
    add_one_to_pokedex(pokedex);
    
    cout << "\nAdding new Pokemon to the Pokedex...\n";  
    
    add_new_pokemon_to_dex(pokedex);

    rewrite_dex(pokedex, file_name, outputfile);

    cout << "\nWrote that pokemon to the Dex!!\n\n";

    options(pokedex, outputfile, file_name);
}

bool no_duplicate_dex(Pokedex& pokedex){
    for(int i = 0; i < pokedex.num_pokemon; i++){
        for(int j = 0; j < pokedex.num_pokemon; j++){
            if(pokedex.dex[i].dex_num == pokedex.dex[j].dex_num && i != j){
                cout << "\nYou can't have a duplicate dex number, Try Again!\n";
                return false;
            }
        }
    }

    return true;
}

bool no_duplicate_name(Pokedex& pokedex){
    for(int i = 0; i < pokedex.num_pokemon; i++){
        for(int j = 0; j < pokedex.num_pokemon; j++){
            if(to_lowercase(pokedex.dex[i].name) == to_lowercase(pokedex.dex[j].name) && i != j){
                cout << "\nYou can't have a duplicate name, Try Again!\n";
                return false;
            }
        }
    }

    if(!is_str(pokedex.dex[pokedex.num_pokemon - 1].name)){
        return false;
    }

    return true;
}

void error_handle_new_pokemon(Pokedex& pokedex){
    do{
        cout << "\nWhats the dex number of the Pokemon: ";
        cin >> pokedex.dex[pokedex.num_pokemon - 1].dex_num;
    }while(!no_duplicate_dex(pokedex));
    do{
        cout << "\nWhats the name of the Pokemon: ";
        cin >> pokedex.dex[pokedex.num_pokemon - 1].name;
    }while(!no_duplicate_name(pokedex));
}

void add_new_pokemon_to_dex(Pokedex& pokedex){
    error_handle_new_pokemon(pokedex);
    cout << "\nWhats the Pokemons's type: ";
    cin >> pokedex.dex[pokedex.num_pokemon - 1].type;
    cout << "\nHow many moves does the Pokemon have: ";
    cin >> pokedex.dex[pokedex.num_pokemon - 1].num_moves;
    cout << "\nWhat are the names of the moves that the Pokemon have: \n";
    pokedex.dex[pokedex.num_pokemon - 1].moves = create_moves(pokedex.dex[pokedex.num_pokemon - 1].num_moves);
    for(int i = 0; i < pokedex.dex[pokedex.num_pokemon - 1].num_moves; i++){
        cout <<"Enter move " << (i + 1) << " of " << pokedex.dex[pokedex.num_pokemon - 1].num_moves << ": ";
        cin >> pokedex.dex[pokedex.num_pokemon - 1].moves[i];
    }
}

void rewrite_dex(Pokedex& pokedex, string file_name, ofstream& outputfile){
    outputfile.open(file_name.c_str(), ios::trunc);

    outputfile << pokedex.num_pokemon << '\n';

    for(int i = 0; i < pokedex.num_pokemon; i++){
        print_to_output_file(outputfile, pokedex, i);
    }

    outputfile.close();
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

    pokedex.num_pokemon += 1;
    pokedex.dex = temp;
    initialize_last_index(pokedex);
}

void initialize_last_index(Pokedex& pokedex){
    pokedex.dex[pokedex.num_pokemon - 1].dex_num = 0;
    pokedex.dex[pokedex.num_pokemon - 1].name = " ";
    pokedex.dex[pokedex.num_pokemon - 1].type = " ";
    pokedex.dex[pokedex.num_pokemon - 1].num_moves = 0;
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