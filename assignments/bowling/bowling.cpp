#define MAX 255

#include <iostream>
#include <cstdlib>

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

void print_frame(){
    std::cout << "Name    |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  |  10  |Total\n";
    std::cout << "---------------------------------------------------------------------------\n";
    std::cout << "Player1 |     |     |     |     |     |     |     |     |     |      | 0\n";
    std::cout << "        |     |     |     |     |     |     |     |     |     |      | 0\n";
    std::cout << "---------------------------------------------------------------------------\n\n";
}

int main(){
    char name[MAX];
    intro(name);

    print_frame();

    return 0;
}