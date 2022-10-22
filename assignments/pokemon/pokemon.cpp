/*********************************************************************
** Filename: pokemon.cpp
** Author: Riley Rice
** Date: 10-20-2022
** Description: This is my implementation file for my pokedex program
** Output: has all the function definitions and respective stuff like that
*********************************************************************/

#include "pokemon.h"

/*********************************************************************
** Function: intro()
** Description: Welcomes user and gets the input pokedex file
** Parameters: string& filename
** Pre-Conditions: filename variable is unitialized
** Post-Conditions: filenmae variable is initialized
*********************************************************************/
void intro(string& filename){
    cout << "Welcome to the CLI Pokedex!! Please enter an input file: ";
    cin >> filename;
}

/*********************************************************************
** Function: create_pokemons()
** Description: creates an array pokemon on the heap and then returns that
pointer
** Parameters: int size
** Pre-Conditions: size is inputted
** Post-Conditions: dynamic array of pokemon is created with size of int 
parameter and then that memory address is returned.
*********************************************************************/
Pokemon* create_pokemons(int size){
    Pokemon* p;
    p = new Pokemon[size];
    return p;
}

/*********************************************************************
** Function: populate_pokedex_data()
** Description: goes through the pokedex's pokemon array and populates it
with information from input file
** Parameters: Pokedex& pokedex, ifstream& inputfile
** Pre-Conditions: The pokedex struct and input file is passed in
** Post-Conditions: the pokedex's pokemon array is populated with information
from the file.
*********************************************************************/
void populate_pokedex_data(Pokedex &pokedex, ifstream &inputfile){
    for(int i = 0; i < pokedex.num_pokemon; i++){
        populate_pokemon(pokedex.dex[i], inputfile);
    }
}

/*********************************************************************
** Function: create_moves()
** Description: creates a dynamic array of strings for each pokemon struct 
based on the amount of moves each pokemon has then returns the array pointer.
** Parameters: int size
** Pre-Conditions: the size integer is passed in
** Post-Conditions: it creates a dynamic array of strings with a size of the 
size integer and then returns that pointer.
*********************************************************************/
string* create_moves(int size){
    string* p;
    p = new string[size];
    return p;
}

/*********************************************************************
** Function: populate_pokemon()
** Description: This functions takes each pokemon passsed in and fills that 
information from the inputfile parameter that is passed in.
** Parameters: Pokemon& pokemon, ifstream& inputfile
** Pre-Conditions: the pokemon struct is passed in and the input file is passed in
** Post-Conditions: the pokemon struct is filled with information from the inputfile
*********************************************************************/
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

/*********************************************************************
** Function: delete_info()
** Description: This function takes an initialized pokedex struct and deletes
all the dynamic memory it holds
** Parameters: Pokedex& pokedex
** Pre-Conditions: The initialized pokedex struct is passed in
** Post-Conditions: the pokedex's pointers are deleted and then set to NULL
*********************************************************************/
void delete_info(Pokedex &pokedex){
    for(int i = 0; i < pokedex.num_pokemon; i++){
        delete [] pokedex.dex[i].moves;
        pokedex.dex[i].moves = NULL;
    }

    delete [] pokedex.dex;
    pokedex.dex = NULL;
}

/*********************************************************************
** Function: options()
** Description: This is the user interface which prompts the users with the
different options then gets the option and passes it into the get_options()
function
** Parameters: Pokedex& pokedex, ofstream& outputfile, string input_file_name
** Pre-Conditions: all the information that will be initialized in the main function
are passed into the function
** Post-Conditions: The option is inputted and that gets passed into the get_options()
function
*********************************************************************/
void options(Pokedex& pokedex, ofstream& outputfile, string input_file_name){
    cout << "#######################################################################\n";
    cout << "Here are the available options for searching or adding to the PokeDex: \n";
    cout << "1. Search by Dex number\n" << "2. Search by Name\n" << "3. Search by Type\n";
    cout << "4. Add new Pokemon\n" << "5. Quit\n";
    cout << "#######################################################################\n";

    cout << "what would you like to do: ";
    int option = 0;
    cin >> option;

    get_options(pokedex, outputfile, input_file_name, option);
}

/*********************************************************************
** Function: get_options()
** Description: This takes the option and then calls the respective function
and if it doesn't work then it outputs an error function and restarts
** Parameters: Pokedex& pokedex, ofstream& outputfile, string input_file_name, int option
** Pre-Conditions: The information is passed in along with the option
** Post-Conditions: based on the option the correct function or option happens
*********************************************************************/
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

/*********************************************************************
** Function: to_lowercase()
** Description: This takes a string and turns it into all lower case
** Parameters: string str
** Pre-Conditions: a string is passed in with only character maybe uppercase,
maybe lowercase, and maybe a mix of both
** Post-Conditions: If the string has a uppercase character I turn it into a lowercase
*********************************************************************/
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

/*********************************************************************
** Function: is_int()
** Description: This takes a string and checks to see if it's an integer
** Parameters: string num
** Pre-Conditions: a string is passed in
** Post-Conditions: if the string is an integer then return true otherwise return false
*********************************************************************/
bool is_int(string num) {
	for (int i = 0; i < num.length(); i++) { //iterate through each character of the string
		//if the character of the string isn't an ASCII integer value or the character is . then return false because it isn't numbers or it's a float with a dot
		if(!((int(num[i]) - 48) <= 9 && (int(num[i] - 48)) >= 0) || num[i] == '.'){
			cout << "\nThat input is invalid please try again!\n";
            return false;
		}
		//if the whole string was iterated and it didn't return false then return true because it's an integer
		else if(i == num.length() - 1) {
			return true;
		}
	}

    return false;
}

/*********************************************************************
** Function: pow()
** Description: This function takes a number and raises it to a specified exponent
** Parameters: int base, int exponent
** Pre-Conditions: the base and exponent is passed in 
** Post-Conditions: the base is raised to the power of the exponent then that number 
is returned
*********************************************************************/
int pow(int base, int exponent){
    int total = 1;

    for(int i = 0; i < exponent; i++){
        total *= base;
    }

    return total;
}

/*********************************************************************
** Function: string_to_int()
** Description: this function takes a string and turns it into an integer and stores
that in an integer value that is passed by reference
** Parameters: string num, int& value
** Pre-Conditions: the string and number are passed in
** Post-Conditions: the string is converted to an integer and then that value is is put
into the integer value passed by reference
*********************************************************************/
void string_to_int(string num, int& value) {
	value = 0; // set the value equal to 0 to get rid of any garbage value stored in there

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

/*********************************************************************
** Function: is_str()
** Description: This function takes in a string and checks to make sure that it
doesn't have any special character or numbers in it
** Parameters: string str
** Pre-Conditions: the string is passed in
** Post-Conditions: returns true if no special characters or numbers and false if
otherwise
*********************************************************************/
bool is_str(string str){
    for(int i = 0; i < str.length(); i++){
        if(!((int(str[i]) >= 65 && int(str[i]) <= 90) || (int(str[i]) >= 97 && int(str[i]) <= 122))){
            cout << "\nYou can't have numbers or special characters in the name or type,\nPlease try again!\n";
            return false;
        }
        if(i == (str.length() - 1)){
            return true;       
        }
    }

    return true;
}

/*********************************************************************
** Function: is_str_with_under()
** Description: This function takes in a string and checks to make sure that it
doesn't have any special character or numbers in it with exception of underscore
** Parameters: string str
** Pre-Conditions: the string is passed in
** Post-Conditions: returns true if no special characters or numbers except for 
underscores and false if otherwise
*********************************************************************/
bool is_str_with_under(string str){
    for(int i = 0; i < str.length(); i++){
        if(!((int(str[i]) >= 65 && int(str[i]) <= 90) || (int(str[i]) >= 97 && int(str[i]) <= 122) || int(str[i]) == 95)){
            cout << "\nYou can't have numbers or special characters in the name or type,\nPlease try again!\n";
            return false;
        }
        if(i == (str.length() - 1)){
            return true;       
        }
    }

    return true;
}

/*********************************************************************
** Function: search_by_dex()
** Description: This function handles searching for a pokemon based on it's
dex number.
** Parameters: Pokedex& pokedex, ofstream& outputfile, string input_file_name
** Pre-Conditions: the pokedex struct output stream and the dex file name is passed
** Post-Conditions: the requested dex number is entered by the user and error handled
then it searches for that dex number in the pokedex pokemon array, and if it is there
it prints it out based on the user's requested output type
*********************************************************************/
void search_by_dex(Pokedex& pokedex, ofstream& outputfile, string input_file_name){
    int output_option = get_output_type(), count = 0, dex_number = 0;
    string dex_number_str;

    do{
        cout << "What dex number do you want to search for: ";
        cin >> dex_number_str;
    }while(!is_int(dex_number_str));  

    string_to_int(dex_number_str, dex_number);

    for(int i = 0; i < pokedex.num_pokemon; i++){
        if(dex_number == pokedex.dex[i].dex_num){
            count++;
            if(output_option == 1){
                print_to_screen(pokedex, i);
            }else if(output_option == 2){
                if(count == 1){
                    get_output_file(outputfile, input_file_name);
                    cout << "\nThese pokemon have been written to that file: \n";
                }
                print_to_output_file(outputfile, pokedex, i, true);
            }
        }
    }

   handle_going_again(pokedex, outputfile, count, input_file_name);
}

/*********************************************************************
** Function: search_by_name()
** Description: This function handles searching for a pokemon based on it's
name.
** Parameters: Pokedex& pokedex, ofstream& outputfile, string input_file_name
** Pre-Conditions: the pokedex struct output stream and the dex file name is passed
** Post-Conditions: the requested name is entered by the user and error handled
then it searches for that name in the pokedex pokemon array, and if it is there
it prints it out based on the user's requested output type
*********************************************************************/
void search_by_name(Pokedex& pokedex, ofstream& outputfile, string input_file_name){
    int output_option = get_output_type(), count = 0;
    string name;

    do{
        cout << "What name do you want to search for: ";
        cin >> name;
    }while(!is_str(name));

    for(int i = 0; i < pokedex.num_pokemon; i++){
        if(to_lowercase(name) == to_lowercase(pokedex.dex[i].name)){
            count++;
            if(output_option == 1){
                print_to_screen(pokedex, i);
            }else if(output_option == 2){
                if(count == 1){
                    get_output_file(outputfile, input_file_name);
                    cout << "\nThese pokemon have been written to that file: \n";
                }
                print_to_output_file(outputfile, pokedex, i, true);
            }
        }
    }

    handle_going_again(pokedex, outputfile, count, input_file_name);
}

/*********************************************************************
** Function: search_by_type()
** Description: This function handles searching for a pokemon based on it's
type.
** Parameters: Pokedex& pokedex, ofstream& outputfile, string input_file_name
** Pre-Conditions: the pokedex struct output stream and the dex file name is passed
** Post-Conditions: the requested type is entered by the user and error handled
then it searches for that type in the pokedex pokemon array, and if it is there
it prints it out based on the user's requested output type
*********************************************************************/
void search_by_type(Pokedex& pokedex, ofstream& outputfile, string input_file_name){
    int output_option = get_output_type(), count = 0;
    string type;

    do{
        cout << "What type do you want to search for: ";
        cin >> type;
    }while(!is_str(type));

    for(int i = 0; i < pokedex.num_pokemon; i++){
        if(to_lowercase(type) == to_lowercase(pokedex.dex[i].type)){
            count++;
            if(output_option == 1){
                print_to_screen(pokedex, i);
            }else if(output_option == 2){
                if(count == 1){
                    get_output_file(outputfile, input_file_name);
                    cout << "\nThese pokemon have been written to that file: \n";
                }
                print_to_output_file(outputfile, pokedex, i, true);
            }
        }
    }

    handle_going_again(pokedex, outputfile, count, input_file_name);
}

/*********************************************************************
** Function: add_new_pokemon()
** Description: this function handles adding a new pokemon to the dex input file
** Parameters: Pokedex& pokedex, string file_name, ofstream& outputfile
** Pre-Conditions: the pokedex struct, output stream, and dex file name are passed in
** Post-Conditions: the old pokedex pokemon array is copied into a new one with identical
structure but with one more pokemon in it, and then that information is inputted by the user
error handled and then the added pokemon struct is filled with that information and then
the dex file is rewritten with this new information
*********************************************************************/
void add_new_pokemon(Pokedex& pokedex, string file_name, ofstream& outputfile){
    add_one_to_pokedex(pokedex);
    
    cout << "\nAdding new Pokemon to the Pokedex...\n";  
    
    add_new_pokemon_to_dex(pokedex);

    rewrite_dex(pokedex, file_name, outputfile);

    output_new_pokemon(pokedex);

    options(pokedex, outputfile, file_name);
}

/*********************************************************************
** Function: output_new_pokemon()
** Description: this handles writing out the new pokemon that is added to
the dex to the screen so the user knows what it looks like in the file
** Parameters: Pokedex& pokedex
** Pre-Conditions: the pokedex struct is passed in 
** Post-Conditions: the last index of the pokedex's pokemon array is 
printed to the screen
*********************************************************************/
void output_new_pokemon(Pokedex& pokedex){
    cout << "\nWrote this pokemon to the Dex: \n\n";

    print_to_screen(pokedex, pokedex.num_pokemon - 1);

    cout << "\n\n";
}

/*********************************************************************
** Function: no_duplicate_dex()
** Description: This checks a user given dex and makes sure the input is 
valid and that they aren't any other pokemon in the dex with the same dex number
** Parameters: Pokedex& pokedex, string dex_str
** Pre-Conditions: The pokedex is passed in along with the dex number the users inputted
** Post-Conditions: If the users input is valid and there isn't another pokemon in the 
dex file with the same dex number then return true otherwise return false
*********************************************************************/
bool no_duplicate_dex(Pokedex& pokedex, string dex_str){
    if(!is_int(dex_str)){
        return false;
    } else{
        string_to_int(dex_str, pokedex.dex[pokedex.num_pokemon - 1].dex_num);
    }

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

/*********************************************************************
** Function: no_duplicate_name()
** Description: This checks a user given name and makes sure the input is 
valid and that they aren't any other pokemon in the dex with the same name
** Parameters: Pokedex& pokedex, string dex_str
** Pre-Conditions: The pokedex is passed in along with the name the users inputted
** Post-Conditions: If the users input is valid and there isn't another pokemon in the 
dex file with the same name then return true otherwise return false
*********************************************************************/
bool no_duplicate_name(Pokedex& pokedex){
    if(!is_str(pokedex.dex[pokedex.num_pokemon - 1].name)){
        return false;
    }

    for(int i = 0; i < pokedex.num_pokemon; i++){
        for(int j = 0; j < pokedex.num_pokemon; j++){
            if(to_lowercase(pokedex.dex[i].name) == to_lowercase(pokedex.dex[j].name) && i != j){
                cout << "\nYou can't have a duplicate name, Try Again!\n";
                return false;
            }
        }
    }

    return true;
}

/*********************************************************************
** Function: error_handle_new_pokemon
** Description: This handles error handling the dex number and name when 
trying to add a new pokemon
** Parameters: Pokedex& pokedex
** Pre-Conditions: the pokedex struct is passed in
** Post-Conditions: It will keep on prompting the users for a dex number 
and name until the user has inputted a valid input for both of them
*********************************************************************/
void error_handle_new_pokemon(Pokedex& pokedex){
    string dex_str;

    do{
        cout << "\nWhats the dex number of the Pokemon: ";
        cin >> dex_str;
    }while(!no_duplicate_dex(pokedex, dex_str));
    do{
        cout << "\nWhats the name of the Pokemon: ";
        cin >> pokedex.dex[pokedex.num_pokemon - 1].name;
    }while(!no_duplicate_name(pokedex));
}

/*********************************************************************
** Function: error_handle_new_type()
** Description: this function error handles getting a type for a pokemon 
when adding a new pokemon
** Parameters: Pokedex& pokedex
** Pre-Conditions: The pokedex struct is passed in
** Post-Conditions: It will keep on prompting the users for a pokemon type
until the user has inputted a valid input
*********************************************************************/
void error_handle_new_type(Pokedex& pokedex){
    bool good = false;

    do{
        cout << "\nWhats the Pokemons's type: ";
        cin >> pokedex.dex[pokedex.num_pokemon - 1].type;

        if(!is_str(pokedex.dex[pokedex.num_pokemon - 1].type)){
            good = false;
        }else{
            good = true;
        }
    }while(!good);
}

/*********************************************************************
** Function: error_handle_new_nummoves()
** Description: this function error handles getting the number of moves 
a pokemon has when adding a new pokemon
** Parameters: Pokedex& pokedex
** Pre-Conditions: The pokedex struct is passed in
** Post-Conditions: It will keep on prompting the users for the number of 
moves a pokemon has until the user has inputted a valid input
*********************************************************************/
void error_handle_new_nummoves(Pokedex& pokedex){
    string num_moves;
    bool good = false;

    do{
        cout << "\nHow many moves does the Pokemon have: ";
        cin >> num_moves;

        if(!is_int(num_moves)){
            good = false;
        }else{
            string_to_int(num_moves, pokedex.dex[pokedex.num_pokemon - 1].num_moves);
            good = true;
        }
    }while(!good);
}

/*********************************************************************
** Function: error_handle_moves()
** Description: this function error handles getting moves for a pokemon 
when adding a new pokemon
** Parameters: Pokedex& pokedex
** Pre-Conditions: The pokedex struct is passed in
** Post-Conditions: It will keep on prompting the users for a pokemon move
until the user has inputted a valid input for every move and this happens a 
certain amount of times based on the users inputted value for the number of moves
*********************************************************************/
void error_handle_moves(Pokedex& pokedex){
    bool good = false;

    cout << "\nWhat are the names of the moves that the Pokemon have: \n";
    pokedex.dex[pokedex.num_pokemon - 1].moves = create_moves(pokedex.dex[pokedex.num_pokemon - 1].num_moves);
    for(int i = 0; i < pokedex.dex[pokedex.num_pokemon - 1].num_moves; i++){
        do{
            cout <<"\nEnter move " << (i + 1) << " of " << pokedex.dex[pokedex.num_pokemon - 1].num_moves << ": ";
            cin >> pokedex.dex[pokedex.num_pokemon - 1].moves[i];

            if(!is_str_with_under(pokedex.dex[pokedex.num_pokemon - 1].moves[i])){
                good = false;
            }else{
                good = true;
            }
        }while(!good);
    }
}

/*********************************************************************
** Function: add_new_pokemon_to_dex()
** Description: This function handles getting and error handling all the information 
needed to add a new pokemon to the pokedex struct
** Parameters: Pokedex& pokedex
** Pre-Conditions: the pokedex struct is passed in
** Post-Conditions: the last index of the pokedex struct is filled with valid inputs
for the new pokemon struct that was added
*********************************************************************/
void add_new_pokemon_to_dex(Pokedex& pokedex){
    error_handle_new_pokemon(pokedex);
    error_handle_new_type(pokedex);
    error_handle_new_nummoves(pokedex);
    error_handle_moves(pokedex);
}

/*********************************************************************
** Function: rewrite_dex()
** Description: This function rewrites the dex file after the new pokemon has
been added with the correct number of pokemon at the top and the same format
as before
** Parameters: Pokedex& pokedex, string file_name, ofstream& outputfile
** Pre-Conditions: The dex file name is passed in along with the output stream 
and the pokedex struct
** Post-Conditions: the new num of pokemon is added to the top of the file then
all the pokemon are written after that then the output stream is closed
*********************************************************************/
void rewrite_dex(Pokedex& pokedex, string file_name, ofstream& outputfile){
    outputfile.open(file_name.c_str(), ios::trunc);

    outputfile << pokedex.num_pokemon << '\n';

    for(int i = 0; i < pokedex.num_pokemon; i++){
        print_to_output_file(outputfile, pokedex, i, false);
    }

    outputfile.close();
}

/*********************************************************************
** Function: add_one_to_pokedex()
** Description: This function handles creating a new pokemon array that's
one size larger than the one passed in and then copies all the information over
then deletes the original array on the heap and points the pokedex to the new 
pokedex array
** Parameters: Pokedex& pokedex
** Pre-Conditions: The pokedex struct is passed in
** Post-Conditions: pokedex will point to a new pokemon array that is one size 
larger
*********************************************************************/
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

/*********************************************************************
** Function: initialize_last_index()
** Description: This function initializes the last index so that there aren't
any garbage values 
** Parameters: Pokedex& pokedex
** Pre-Conditions: the pokedex struct is passed in with an uninitialized pokemon struct
** Post-Conditions: the last pokemon struct is initialized with placeholder values
*********************************************************************/
void initialize_last_index(Pokedex& pokedex){
    pokedex.dex[pokedex.num_pokemon - 1].dex_num = 0;
    pokedex.dex[pokedex.num_pokemon - 1].name = " ";
    pokedex.dex[pokedex.num_pokemon - 1].type = " ";
    pokedex.dex[pokedex.num_pokemon - 1].num_moves = 0;
}

/*********************************************************************
** Function: handle_going_again()
** Description: This function handles going again after the search or adding a new pokemon
is finished, it outputs the amount of items found then closes the output stream, and then it 
calls the options function again
** Parameters: Pokedex& pokedex, ofstream& outputfile, int count, string input_file_name
** Pre-Conditions: all the information needed for outputting the amount of items found,
closing the outputstream, and recalling the options function is passed in
** Post-Conditions: The amount of items found will be printed and the output stream will be closed
and then the options function will be called
*********************************************************************/
void handle_going_again(Pokedex& pokedex, ofstream& outputfile, int count, string input_file_name){
    if(count == 0){
        cout << "\nFound no matches" << endl << endl;
    }else if(count >= 1){
        if(count == 1){
            cout << "\nFound " << count << " match" << endl << endl;
        }else if(count > 1){
            cout << "\nFound " << count << " matches" << endl << endl;
        }
    }

    outputfile.close();
    options(pokedex, outputfile, input_file_name);
}

/*********************************************************************
** Function: print_to_screen()
** Description: This function handles printing a given pokemon struct to the screen
** Parameters: Pokedex& pokemon, int i
** Pre-Conditions: the current iteration along with the pokedex struct is passed in
** Post-Conditions: the pokemon at the index of i is printed to the screen
*********************************************************************/
void print_to_screen(Pokedex& pokemon, int i){
    cout << "\n" << pokemon.dex[i].dex_num << " " << pokemon.dex[i].name << " " << pokemon.dex[i].type << " " << pokemon.dex[i].num_moves << endl;
    for(int j = 0; j < pokemon.dex[i].num_moves; j++){
        cout << pokemon.dex[i].moves[j] << " ";
    }
    cout << "\n";
}

/*********************************************************************
** Function: print_to_output_file()
** Description: This function handles outputting a given pokemon struct to a 
an outputfile and then also print it to the screen so the user know what was outputted
** Parameters: ofstream& outputfile, int i, bool print
** Pre-Conditions: the current iteration along with the pokedex struct is passed in
** Post-Conditions: The pokemon at the index of i is printed to the screen and also outputted
to a user given output file
*********************************************************************/
void print_to_output_file(ofstream& outputfile, Pokedex& pokemon, int i, bool print){
    outputfile << pokemon.dex[i].dex_num << " " << pokemon.dex[i].name << " " << pokemon.dex[i].type << " " << pokemon.dex[i].num_moves << endl;
    for(int j = 0; j < pokemon.dex[i].num_moves; j++){
        outputfile << pokemon.dex[i].moves[j] << " ";
    }
    outputfile << "\n";

    if(print){
        print_to_screen(pokemon, i);
    }
}

/*******************************************************************
** Function: txt()
** Description: Looks at a cstring and returns true if it has .txt at the end and false if otherwise
** Parameters: char str[]
** Pre-conditions: it needs an initialized cstring
** Post-conditions: return a boolean value based on whether there is a .txt extension at the end
*******************************************************************/
bool txt(char str[], int size){
    bool txt = false;

    for(int i = 0; i < size; i++){
        if(str[i] == '.'){
            if(str[i + 1] == 't' && str[i + 2] == 'x' && str[i + 3] == 't') {
                txt = true;
            }
        }
    }

    return txt;
}

/*********************************************************************
** Function: get_output_file()
** Description: This gets an output file from the user and makes sure that it 
has the txt extension and will prompt them until it does
** Parameters: ostream& outputfile
** Pre-Conditions: the output stream is passed and should be closed
** Post-Conditions: the output stream is opened with a valid user specified file name
*********************************************************************/
void get_output_file(ofstream& outputfile, string inputfilename){
    string outputfile_name;
    bool good = false;

    do{
        cout << "Enter an output file name (if you already have a file it will append your search to the end of it) add .txt: ";
        cin >> outputfile_name;

        char outputfile_char[outputfile_name.length()];
        convert_str_to_char(outputfile_name, outputfile_char);

        if(!txt(outputfile_char, outputfile_name.length()) || outputfile_name == inputfilename){
            cout << "\nThat input is invalid you must .txt at the end Try Again!! \n";
            good = false;
        }else{
            good = true;
        }
    }while(!good);

    outputfile.open(outputfile_name.c_str(), ios::app);
}

/*********************************************************************
** Function: convert_str_to_char()
** Description: This copies a string into a char array 
** Parameters: string str, char chr[]
** Pre-Conditions: the char array should be declared with size of str.length()
** Post-Conditions: the char array will be populated with the string values
*********************************************************************/
void convert_str_to_char(string str, char chr[]){
    for(int i = 0; i < str.length(); i++){
        chr[i] = str[i];
    }
}

/*********************************************************************
** Function: get_output_type()
** Description: This gets a valid output type from the user and will reprompt them
untilt he input is valid
** Parameters: NONE
** Pre-Conditions: the option variable is empty
** Post-Conditions: the option variable is filled with a valid correct value
*********************************************************************/
int get_output_type(){
    int option = 0;

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