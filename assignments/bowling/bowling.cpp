#define MAX 255

#include <iostream>
#include <cstdlib>
#include <ctime>

void print_frame(char pins[][2], int totals[]);

bool is_string(char name[]){
    for(int i = 0; name[i] != '\0'; i++){
        if(!((int(name[i]) >= 65 && int(name[i]) <= 90) || (int(name[i]) >= 97 && int(name[i]) <= 122))){
            return false;
        }
    }

    return true;
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

void populate_char_array(char arr[][2]){
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 2; j++){
            arr[i][j] = ' ';
        }
    }
}

void populate_int_array(int arr[]){
    for(int i = 0; i < 11; i++){
        arr[i] = '\0';
    }
}

int char_to_int(char integer){
    int stoint = (int(integer) - 48);
    return stoint;
}

char itoc(int i){
    return char(i + 48);
}

char generate_random(int &remainder){

    int random = rand() % (11 - remainder);

    remainder += random;

    return itoc(random);
}

void rolling(int i, char arr[][2], int totals[]){
    int remainder = 0;

    for(int j = 0; j < 2; j++){
        if(j == 0){
            std::cout << "Frame " << i << "...\n";
        }

        std::cout << "Press enter to roll.\n";

        char knocked = generate_random(remainder);

        arr[(i - 1)][j] = knocked;

        print_frame(arr, totals);
    } 
}

void print_frame(char pins[][2], int totals[]){
    std::cout << "Name    |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  |  10  |Total\n";
    std::cout << "---------------------------------------------------------------------------\n";
    std::cout << "Player1 | " 

    << pins[0][0] << " " << pins[0][1] << " | " << pins[1][0] << " " << pins[1][1] << " | " 
    << pins[2][0] << " " << pins[2][1] << " | " << pins[3][0] << " " << pins[3][1] << " | " 
    << pins[4][0] << " " << pins[4][1] << " | " << pins[5][0] << " " << pins[5][1] << " | " 
    << pins[6][0] << " " << pins[6][1] << " | " << pins[7][0] << " " << pins[7][1] << " | " 
    << pins[8][0] << " " << pins[8][1] << " | " << pins[9][0] << " " << pins[9][1] << "  |  " << totals[10] << "\n";

    std::cout << "        |   " << totals[0] << " |   " << totals[1] << 
    " |   " << totals[2] << " |   " << totals[3] << " |   " << totals[4] << 
    " |   " << totals[5] << " |   " << totals[6] << " |   " << totals[7] << 
    " |   " << totals[8] << " |   " << totals[9] << "  |  \n";
    std::cout << "---------------------------------------------------------------------------\n\n";
}

int main(){
    srand(time(NULL));

    char pins[10][2];
    populate_char_array(pins);

    int totals[11];
    populate_int_array(totals);

    char name[MAX];
    intro(name);
    
    for(int i = 0; i < 10; i++){
        rolling((i + 1), pins, totals);
    }

    return 0;
}