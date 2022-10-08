/******************************************************
** Program: bowling.cpp
** Author: Riley Rice
** Date: 10/7/2022
** Description: A command line bowling game which mimicks a real game of bowling.
** Input: You have to input your name and press enter for each roll and then whether you want
** to play again or not at the end of your game.
** Output: It outputs your score and how many pins you knocked down at each frame and then your
** total score at the end of the game.
******************************************************/

/* Include basic iostream library and c standard library and 
ctime for generating random numbers for knocking down pins */
#include <iostream>
#include <cstdlib>
#include <ctime>

//functions for data conversion
bool is_string(char name[]);
int char_to_int(char integer);
char itoc(int i);

//functions for filling up arrays so there aren't garbage values
void populate_char_array(char arr[][3]);
void populate_int_array(int arr[]);

//functions for rolling and scoring
void get_started(char pins[][3], int totals[]);
void rolling(int i, char arr[][3], int totals[]);
void press_enter();
char generate_random(int &remainder);
void consecutive_strikes(int i, int j, char arr[][3], int totals[], char knocked);
char scoring(char knocked, char arr[][3], int totals[], int i, int j);
bool handle_last_frame(char arr[][3], int totals[], int i);
void handle_perfect_game(int i, int totals[]);
void last_strike(char arr[][3], int totals[]);
void last_spare(char arr[][3], int totals[]);
char last_scoring(char knocked, char arr[][3], int totals[], int j);
bool check_for_strike(char arr[][3], int totals[], char score, char knocked, bool ready);

/*************************** 
* functions for error handling and user inputs, also includes function for printing 
* out score sheet. 
****************************/
void pin_prompt(char score, char knocked);
void print_frame(char pins[][3], int totals[]);
void format_totals(int totals[]);
void format_extra_frames(int totals[]);
void intro(char name[]);
bool playagain();
bool play_error(bool play, char input);

/*********************************************************************
** Function: is_string()
** Description: A function for indexing through a char array and making sure it
** doesn't contain non integer characters or special characters.
** Parameters: takes in a char array, char name[]
** Pre-Conditions: It will go through the char array
** Post-Conditions: It will return true if there isn't a integer or special character,
** and false if otherwise
*********************************************************************/
bool is_string(char name[]){
    if(name[0] == '\0'){
        return false;
    }

    for(int i = 0; name[i] != '\0'; i++){
        if(!((int(name[i]) >= 65 && int(name[i]) <= 90) || (int(name[i]) >= 97 && int(name[i]) <= 122))){
            return false;
        }
    }

    return true;
}

/*********************************************************************
** Function: char_to_int()
** Description: A function for converting a integer in a char data type 
** to an integer data type.
** Parameters: char integer
** Pre-Conditions: The integer is passed in as a char
** Post-Conditions: The integer is returned as the same value but as an 
** integer data type
*********************************************************************/
int char_to_int(char integer){
    if(integer == '-'){
        return 0;
    }else if(integer == 'X'){
        return 10;
    }
    else if(integer == ':'){
        return 10;
    }
    else{
        return (int(integer) - 48);
    }
}

/*********************************************************************
** Function: itoc()
** Description: It changes an integer into an equivelant char data type
** Parameters: int i
** Pre-Conditions: The integer gets passed in
** Post-Conditions: The integer is returned as a char with the same value 
** as the original integer value
*********************************************************************/
char itoc(int i){
    return char(i + 48);
}

/*********************************************************************
** Function: populate_char_array()
** Description: Meant to populate a 2 dimensional static char array so 
** it doesn't contain garbage values.
** Parameters: char arr[][3]
** Pre-Conditions: The array is passed in unitialized with garbage values stored 
** in it
** Post-Conditions: The array is then filled with space characters
*********************************************************************/
void populate_char_array(char arr[][3]){
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 3; j++){
            arr[i][j] = ' ';
        }
    }
}

/*********************************************************************
** Function: populate_int_array()
** Description: Meant to populate a static 1 dimensional array so it doens't
** contain garbage values
** Parameters: int arr[]
** Pre-Conditions: The array is passed in unitialized with garbage values stored
** in it
** Post-Conditions: The array is then filled with null bytes
*********************************************************************/
void populate_int_array(int arr[]){
    for(int i = 0; i < 11; i++){
        arr[i] = '\0';
    }
}

/*********************************************************************
** Function: get_started()
** Description: Meant to call the rolling function ten times or for each frame,
** makes it easier to keep track what frame the program is currently on.
** Parameters: char pins[][3], int totals[]
** Pre-Conditions: The arrays are passed in after being initialized and then they are
** passed into the rolling function everytime for each frame, or in other words ten times
** Post-Conditions: The rolling function is invoked 10 times for each frame. 
*********************************************************************/
void get_started(char pins[][3], int totals[]){
    for(int i = 0; i < 10; i++){
        rolling((i + 1), pins, totals);
    }
}

/*********************************************************************
** Function: rolling()
** Description: This is the main control function for each frame where the rolling is done
** it's a combination of functions and makes the rolling actually work for the game.
** Parameters: int i, char arr[][3], int totals[]
** Pre-Conditions: The arrays are passed in and the current frame
** Post-Conditions: The function iterates and rolls 2 times for each frame. Before each iteration
** the press_enter() function is invoked which stops the flow until enter is pressed and then the 
** next roll continues. It then generates a random number, checks for consecutive strikes, and then 
** scores based on the random number that was generated. It then checks if it's the last frame in case
** you rolling a strike or spare on the 10th frame which means you can get 1 to 2 extra rolls. It also 
** breaks and doens't iterate a second time if a strike is scored since you don't want to roll twice in 
** one frame if a strike is scored.
*********************************************************************/
void rolling(int i, char arr[][3], int totals[]){
    int remainder = 0;

    for(int j = 0; j < 2; j++){
        if(j == 0){
            std::cout << "Frame " << i << "...\n";
        }

        char score = '\0';

        press_enter();

        char knocked = generate_random(remainder);

        consecutive_strikes(i, j, arr, totals, knocked);

        score = scoring(knocked, arr, totals, i, j);

        bool ready = handle_last_frame(arr, totals, i);

        if(check_for_strike(arr, totals, score, knocked, ready)){
            break;
        };

        if(ready){
            j++;
        }
    } 
}

/*********************************************************************
** Function: press_enter()
** Description: A function which stops the code execution until enter key is pressed
** in which then it will continue code execution.
** Parameters: None
** Pre-Conditions: it prompts the user to press enter to roll and then waits until
** the enter key is pressed
** Post-Conditions: After the enter key is pressed the code execution continues
*********************************************************************/
void press_enter(){
    std::cout << "Press enter to roll.\n";

    char input[255];
    std::cin.getline(input, 255, '\n');
}

/*********************************************************************
** Function: generate_random()
** Description: This is the function which generates the random number between
** 0 and 10 the first roll and then 0 to 10 - (what you rolled the first time).
** Parameters: int &remainder
** Pre-Conditions: The remainder is passed in by reference because if you already
** rolled once then you need to know the new range of random numbers you should be
** generating.
** Post-Conditions: A random number within the appropriate range is converted to a char
** and then returned. 
*********************************************************************/
char generate_random(int &remainder){

    int random = rand() % (11 - remainder);

    remainder += random;

    return itoc(random); 
}

/*********************************************************************
** Function: consecutive_strikes()
** Description: This is the function which does the math for strikes, consecutive
** strikes, and spares. 
** Parameters: int i, int j, char arr[][3], int totals[], char knocked
** Pre-Conditions: The current frame(i) and the current roll(j) are passed in along
** with current roll's knocked pins and the arrays.
** Post-Conditions: check to to see if the last roll or two rolls were a strike and 
** if so then add 10 to each frame that had that. If the last one wasn't a strike then 
** it also checks to see if the last roll was a spare and makes sure your on the first roll, 
** in which it adds the next roll's score
*********************************************************************/
void consecutive_strikes(int i, int j, char arr[][3], int totals[], char knocked){
    if(arr[i - 2][0] == 'X'){
        totals[i - 2] += char_to_int(knocked);
        totals[10] += char_to_int(knocked);
        if(arr[i - 3][0] == 'X' && char_to_int(knocked) == 10){
            totals[i - 3] += 10;
            totals[10] += 10;
        } 
    }
    else if(arr[i - 2][1] == '/' && j == 0){
        totals[i - 2] += char_to_int(knocked);
        totals[10] += char_to_int(knocked);
    }

    handle_perfect_game(i, totals);
}

/*********************************************************************
** Function: handle_perfect_game()
** Description: It does some adding in the chance that you roll a perfect game
** to make sure you get the right score.
** Parameters: int i, int totals[]
** Pre-Conditions: The current frame and totals array is passed in
** Post-Conditions: If the first three frames were strikes then add 10 as my previous
** scoring method didn't work for this condition. Also checks for the 7th frame also.
*********************************************************************/
void handle_perfect_game(int i, int totals[]){
    if(totals[0] == 30 && i == 3){
        totals[1] += 10;
        totals[10] += 10;
    } 
    
    if(totals[7] == 240 && i == 10){
        totals[8] += 10;
    }
}

/*********************************************************************
** Function: scoring()
** Description: This is the scoring function for when there isn't a strike
** or spare.
** Parameters: char knocked, char arr[][3], int totals[], int i, int j
** Pre-Conditions: The pins and totals array are passed in along with the current
** frame and roll in that frame along with the amount of pins knoecked for this roll
** Post-Conditions: based on the amount of pins knocked down the array is updated 
** appropriately and if the roll was a strike, gutter, or spare was rolled then 
** a corresponding char is returned. 
*********************************************************************/
char scoring(char knocked, char arr[][3], int totals[], int i, int j){
    totals[10] += char_to_int(knocked);
    totals[i - 1] = totals[10];
    
    if(char_to_int(knocked) == 10 && j == 0){
        arr[(i - 1)][j] = 'X';
        return 'x';
    }else if(char_to_int(knocked) + char_to_int(arr[i - 1][j - 1]) == 10 && j == 1){
        arr[(i - 1)][j] = '/';
        return 's';
    }else if(char_to_int(knocked) == 0){
         arr[(i - 1)][j] = '-';
         return 'g';
    }else{
         arr[(i - 1)][j] = knocked;
    }

    return ' ';
}

/*********************************************************************
** Function: handle_last_frame()
** Description: This handles the last frame in case there was a spare or strike
** on the 10th frame and you need to have an extra roll.
** Parameters: char arr[][3], int totals[], int i
** Pre-Conditions: The current frame and pin and totals array are passed in
** so that we can check.
** Post-Conditions: If the last roll was a strike or spare and it's the tenth frame
** then call the corresponding function and return true, otherwise return false.
*********************************************************************/
bool handle_last_frame(char arr[][3], int totals[], int i){
    if(arr[9][0] == 'X' && i == 10){
        last_strike(arr, totals);
        return true;
    }
    else if(arr[9][1] == '/' && i == 10){
        last_spare(arr, totals);
        return true;
    }

    return false;
}

/*********************************************************************
** Function: last_strike()
** Description: If there was a strike on the last frame then give the user two more rolls
** Parameters: char arr[][3], int totals[]
** Pre-Conditions: The pins and totals array are passed in 
** Post-Conditions: The function goes through and does two more rolls mimicking the scoring()
** function but uses a different scoring function. Will end with 3 rolls on the 10th frame
*********************************************************************/
void last_strike(char arr[][3], int totals[]){
    int remainder = 0;
    char xscore = '\0';

    std::cout << "You got a strike and two more rolls!!\n";
    print_frame(arr, totals);
    
    for(int k = 0; k < 2; k++){
        press_enter();

        char knocked = generate_random(remainder);

        xscore = last_scoring(knocked, arr, totals, (k+1));
        
        if(xscore == 'x'){
            std::cout << "You knocked down 10 pins. You got a Strike!\n\n";
            print_frame(arr, totals);
        }
        else {
            pin_prompt(xscore, knocked);
            print_frame(arr, totals);
        }
    }
}

/*********************************************************************
** Function: last_spare()
** Description: If there was a spare in the last frame then give the user one more roll
** Parameters: char arr[][3], int totals[]
** Pre-Conditions: the pins and totals array is passed in
** Post-Conditions: The function goes through and does on more roll mimicking the scoring()
** function without the for loop and also uses a different scoring function. Will end with 3 
** rolls on the 10th frame
*********************************************************************/
void last_spare(char arr[][3], int totals[]){
    int remainder = 0;
    char score = '\0';

    std::cout << "You got a spare and one more roll!!\n";
    print_frame(arr, totals);
    
    press_enter();

    char knocked = generate_random(remainder);

    score = last_scoring(knocked, arr, totals, 2);
    
    if(score == 'x'){
        std::cout << "You knocked down 10 pins. You got a Strike!\n\n";
        print_frame(arr, totals);
    }
    else {
        pin_prompt(score, knocked);
        print_frame(arr, totals);
    }
}

/*********************************************************************
** Function: last_scoring()
** Description: This is a special scoring function for use when there is a strike
** or spare on the 10th frame
** Parameters: char knocked, char arr[][3], int totals[], int j
** Pre-Conditions: The current roll and knocked pins are passed in, along with the 
** pins and totals array
** Post-Conditions: If there was a strike then return x and if there was a gutter 
** then return 0, and if none of those happen then just set the score and total, 
** and return a space.
*********************************************************************/
char last_scoring(char knocked, char arr[][3], int totals[], int j){
    totals[10] += char_to_int(knocked);
    totals[9] = totals[10];
    
    if(char_to_int(knocked) == 10){
        arr[9][j] = 'X';
        return 'x';
    }else if(char_to_int(knocked) == 0){
         arr[9][j] = '-';
         return 'g';
    }else{
         arr[9][j] = knocked;
    }

    return ' ';
}

/*********************************************************************
** Function: check_for_strike()
** Description: This function checks if there was a strike or not and makes sure
** that they aren't on the 10th frame and if it is then return true which will break 
** the scoring function
** Parameters: char arr[][3], int totals[], char score, char knocked, bool ready
** Pre-Conditions: The current score from the scoring funciton is passed in along with the
** pins and totals array, and also the current amount of pins knocked for this roll, and 
** whether or not there was a spare or strike on the 10th frame.
** Post-Conditions: If there wasn a strike and its not the 10th frame then print the frame
** and cout that you got a strike then return false. If you didn't get a strike, and you 
** aren't on the 10th frame then print_frame and print out the corresponding prompt using
** pin_prompt() function
*********************************************************************/
bool check_for_strike(char arr[][3], int totals[], char score, char knocked, bool ready){
     if(score == 'x' && !ready){
            std::cout << "You knocked down 10 pins. You got a Strike!\n\n";
            print_frame(arr, totals);
            return true;
        }
        else if(score != 'x' && !ready) {
            pin_prompt(score, knocked);
            print_frame(arr, totals);
            return false;
        }

        return false;
}

/*********************************************************************
** Function: pin_prompt()
** Description: This is the function responsible for printing out the right prompt
** depending on whether or not the user got a spare, gutter, or neither
** Parameters: char score, char knocked
** Pre-Conditions: It takes in the score value returned by the scoring() function, 
** and the current knocked for this roll
** Post-Conditions: It will print out the corresponding prompt with the amount of pins 
** you knocked down
*********************************************************************/
void pin_prompt(char score, char knocked){
    if(score == 's'){
        if(char_to_int(knocked) == 10){
            std::cout << "You knocked down 10 pins. You got a spare!\n\n";
        }else{
            std::cout << "You knocked down " << knocked << " pins. You got a spare!\n\n";
        }
    }else if(score == 'g'){
        std::cout << "You knocked down " << knocked << " pins. You guttered the ball.\n\n";
    } else{
        std::cout << "You knocked down " << knocked << " pins.\n\n";
    }
}

/*********************************************************************
** Function: print_frame()
** Description: This is the function which is used to print out the score card
** so that the user can easily tell what frame and roll they are on and what score
** they have.
** Parameters: char pins[][3], int totals[]
** Pre-Conditions: The current pins array and totals array is passed in
** Post-Conditions: It then prints the values in this array in a formatted and 
** meaningful way. It prints out the bowling scoresheet.
*********************************************************************/
void print_frame(char pins[][3], int totals[]){
    std::cout << "Name    |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  |   10   | Total\n";
    std::cout << "------------------------------------------------------------------------------\n" << "Player1 | ";

    for(int k = 0; k < 10; k++){
        if(k == 9){
            std::cout << pins[k][0] << " " << pins[k][1] << " " << pins[k][2] << "  | ";
        }
        else{
            std::cout << pins[k][0] << " " << pins[k][1] << " | ";
        }
    }
    
    std::cout << " " << totals[10] << "\n" << "        |";

    format_totals(totals);

    std::cout << "      \n------------------------------------------------------------------------------\n\n";
}

/*********************************************************************
** Function: format_totals()
** Description: This is the function used in the print_frame() function
** to format the totals array based on the size of the number.
** Parameters: int totals[]
** Pre-Conditions: takes in the totals array
** Post-Conditions: will cout the number with more or less spaces in between the bars
** based on the size of the number
*********************************************************************/
void format_totals(int totals[]){
     for(int j = 0; j < 10; j++){
        if(j == 9){
           format_extra_frames(totals);
        }
        else if(totals[j] == 0){
            std::cout << "     |";
        }
        else if(totals[j] <= 9){
            std::cout << "  " << totals[j] << "  |";
        }
        else if(totals[j] > 9 && totals[j] <= 99){
            std::cout << " " << totals[j] << "  |";
        }
        else if(totals[j] >= 100){
            std::cout << " " << totals[j] << " |";
        }
    }
}

/*********************************************************************
** Function: format_extra_frames()
** Description: this formats the 10th frame as it has to be a little bigger
** since there can be three rolls.
** Parameters: int totals[]
** Pre-Conditions: Takes in the totals array
** Post-Conditions: will cout the number with more or less spaces in between the bars
** based on the size of the number
*********************************************************************/
void format_extra_frames(int totals[]){
     if(totals[9] != 0){
        if(totals[9] > 9 && totals[9] <= 99){
            std::cout << " " << totals[9] << "     |";
        }
        else if(totals[9] >= 100){
            std::cout << " " << totals[9] << "    |";
        }
    }
    else if(totals[9] == 0){
        std::cout << "        |";
    }
}

/*********************************************************************
** Function: intro()
** Description: This is the intro function which welcomes the user and asks
** for their name and then also does some error handling
** Parameters: char name[]
** Pre-Conditions: Takes in a name array
** Post-Conditions: If the users name is valid it will welcome them and if it 
** isn't it will prompt them until it is.
*********************************************************************/
void intro(char name[]){
    bool input = true;

    std::cout << "Welcome to Bowling!! \n";
    
    do{
        std::cout << "Enter your name: ";
        std::cin.getline(name, 255, '\n');

        if(!is_string(name)){
            input = false;
            std::cin.clear();
            std::cout << "That input is invalid, Try Again! \n";
        }else{
            input = true;
        }
    }while(!input);

    std::cout << "\nHello, " << name << "!\n\n";
}

/*********************************************************************
** Function: playagain()
** Description: This is the function which handles the playing again function
** after the game is over.
** Parameters: NONE
** Pre-Conditions: It will occur after the 10th frame has occurred
** Post-Conditions: It will call the play_error() function and return that functions output.
*********************************************************************/
bool playagain(){
    bool play = false;
    char input = '\0';

    std::cout << "\n\nDo you want to play again(y/n)?: ";

    return play_error(play, input);
}

/*********************************************************************
** Function: play_error()
** Description: This handles the error handling for the play again prompt
** Parameters: bool play, char input
** Pre-Conditions: it will take in a boolean used for handling the do-while loop
** and the char input wich will hold the users input.
** Post-Conditions: If the input is valid it will do the corresponding action like playing
** again or not and if it isn't it will keep prompting until the input is valid.
*********************************************************************/
bool play_error(bool play, char input){
    do{
        std::cin >> input;
        if(input == 'y' ){
            std::cout << "\n\nPlaying Again! \n\n";
            std::cin.ignore(1000, '\n');
            return true;
        }else if(input == 'n'){
            std::cout << "\n\nThanks for playing!\n";
            return false;   
        }else{
            std::cout << "\n\nInvalid Input, Try Again: ";
            std::cin.ignore(1000, '\n');
            play = false;
        }
    }while(!play);

    return false;
}

/*********************************************************************
** Function: main()
** Description: This is the main function where everything is called and controlled
** Parameters: NONE
** Pre-Conditions: It will initiate the program and arrays needed for the other functions to work.
** Post-Conditions: It will keep on running the bowling program until the user doesn't want to in 
** which it will break out the loop and return 0 because there were no errors.
*********************************************************************/
int main(){
    srand(time(NULL));

    char pins[10][3];
    int totals[11];
    char name[255];

    do{
        populate_char_array(pins);
        populate_int_array(totals);

        intro(name);
        
        get_started(pins, totals);

        std::cout << name << "'s total score was: " << totals[10];
    }while(playagain());

    return 0;
}