/*********************************************************************
** Program Filename: Fractal main.cpp
** Author: Riley Rice
** Date: 12-2-2022
** Description: This is the main function for my fractal progra, it calls my 
pattern function with multiple different parameters. It's meant to show how my pattern
function works.
** Input: Pattern calls with different parameters
** Output: Prints out fractals based on the parameters given
*********************************************************************/

//include fractal header
#include "fractal.h"


/*********************************************************************
** Function: do_again()
** Description: This gets whether the user wants to see another pattern or not
** Parameters: NONE
** Pre-Conditions: user has gone through once and did a pattern
** Post-Conditions: if user inputs t then return true to run again if
the user enters f then return false and don't run again
*********************************************************************/
bool do_again(){
    char a = ' ';

    std::cout << "Do you want to do another pattern? (t-true, f-false): ";
    std::cin >> a;

    if(a == 't'){
        return true;
    }else if (a == 'f'){
        return false;
    }
}

/*********************************************************************
** Function: main()
** Description: This is the entry point for the program
** Parameters: NONE
** Pre-Conditions: The program is compiled and run and then enters into main.
** Post-Conditions: The pattern function is called and then it returns 0 
and exits
*********************************************************************/
int main(){
    std::cout << "This is pattern(3, 2): \n\n";
    pattern(3, 2);
    std::cout << "\n\n";

    std::cout << "This is pattern(5, 1): \n\n";
    pattern(5, 1);
    std::cout << "\n\n";
    
    std::cout << "This is pattern(7, 0): \n\n";
    pattern(7, 0);
    std::cout << "\n\n";

    do{
        char n = 0;
        char col = 0;

        std::cout << "\n\nWhat do you want for n? (positive even number that's greater than 3): ";
        std::cin >> n;
        std::cout << "What do you want for col?: ";
        std::cin >> col;

        std::cout << "\n\nThis is pattern(" << n << ", " << col << "):\n\n";
        pattern(int(n - 48), int(col - 48));
        std::cout << "\n\n";
    }while(do_again());

    return 0;
}