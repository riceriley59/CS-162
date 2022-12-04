/*********************************************************************
** Filename: fractal.cpp
** Author: Riley Rice
** Date: 12-2-2022
** Description: implementation file for fractal.h and defines the 
recursive pattern function
*********************************************************************/

//include header
#include "fractal.h"

/*********************************************************************
** Function: pattern()
** Description: This prints out a fractal of "*" characters in the console
where the longest line of the pattern has n stars beginning in the col column
in the output. It uses recursion.
** Parameters: int n, int col
** Pre-Conditions: n is a positive odd number
** Post-Conditions: pattern that is described above in description is outputted
into console 
*********************************************************************/
void pattern(int n, int col){
    //base case: if n is less than 1 then exit
    if(n < 1)
        return;
    
    //recursively calls the same funtion with n-2 and col + 1
    //until it hits base case
    pattern(n - 2, col + 1);

    //print out col + 1 spaces and n number of stars after that
    for(int i = 0; i < col + 1; i++) std::cout << "  ";
    for(int i = 0; i < n; i++) std::cout << "* ";
    
    //add newline after we have printed out a line so we can go to the next line
    std::cout << "\n";

    //recursively calls the same function again with n-2 and col+1
    //until it hits base case
    pattern(n - 2, col + 1);
}