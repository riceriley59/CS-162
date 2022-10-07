#define MAX 255

#include <iostream>
#include <cstdlib>
#include <ctime>

void print_frame(char pins[][3], int totals[]);
void get_started(char pins[][3], int totals[]);
bool playagain();
bool play_error(bool play, char input);
void print_frame(char pins[][3], int totals[]);
void format_totals(int totals[]);
void format_extra_frames(int totals[]);
void rolling(int i, char arr[][3], int totals[]);
bool check_for_strike(char arr[][3], int totals[], char score, char knocked, bool ready);
void consecutive_strikes(int i, int j, char arr[][3], int totals[], char knocked);
bool handle_last_frame(char arr[][3], int totals[], int i);
void last_spare(char arr[][3], int totals[]);
void last_strike(char arr[][3], int totals[]);
void press_enter();
void pin_prompt(char score, char knocked);
char last_scoring(char knocked, char arr[][3], int totals[], int j);
char scoring(char knocked, char arr[][3], int totals[], int i, int j);
char generate_random(int &remainder);
char itoc(int i);
int char_to_int(char integer);
void populate_int_array(int arr[]);
void populate_char_array(char arr[][3]);
void intro(char name[]);
bool is_string(char name[]);



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

char itoc(int i){
    return char(i + 48);
}

void populate_char_array(char arr[][3]){
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 3; j++){
            arr[i][j] = ' ';
        }
    }
}

void populate_int_array(int arr[]){
    for(int i = 0; i < 11; i++){
        arr[i] = '\0';
    }
}

void get_started(char pins[][3], int totals[]){
    for(int i = 0; i < 10; i++){
        rolling((i + 1), pins, totals);
    }
}

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

void press_enter(){
    std::cout << "Press enter to roll.\n";

    char input[MAX];
    std::cin.getline(input, MAX, '\n');
}

char generate_random(int &remainder){

    int random = rand() % (11 - remainder);

    remainder += random;

    return itoc(random);
    //return itoc(10);  
}

void consecutive_strikes(int i, int j, char arr[][3], int totals[], char knocked){
    if(arr[i - 2][0] == 'X' && i <= 9){
        totals[i - 2] += char_to_int(knocked);
        totals[10] += char_to_int(knocked);
        if(arr[i - 3][0] == 'X'){
            totals[i - 3] += 10;
            totals[10] += 10;
        } 
    }
    else if(arr[i - 2][1] == '/' && j == 0){
        totals[i - 2] += char_to_int(knocked);
        totals[10] += char_to_int(knocked);
    }
}

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

void intro(char name[]){
    bool input = true;

    std::cout << "Welcome to Bowling!! \n";
    
    do{
        std::cout << "Enter your name: ";
        std::cin.getline(name, MAX, '\n');

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

bool playagain(){
    bool play = false;
    char input = '\0';

    std::cout << "\n\nDo you want to play again(y/n)?: ";

    return play_error(play, input);
}

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

int main(){
    srand(time(NULL));

    char pins[10][3];
    int totals[11];
    char name[MAX];

    do{
        populate_char_array(pins);
        populate_int_array(totals);

        intro(name);
        
        get_started(pins, totals);

        std::cout << name << "'s total score was: " << totals[10];
    }while(playagain());

    return 0;
}