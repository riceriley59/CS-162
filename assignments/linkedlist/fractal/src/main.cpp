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

#include "fractal.h"

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

    return 0;
}