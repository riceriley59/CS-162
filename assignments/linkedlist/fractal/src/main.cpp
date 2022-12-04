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
#include <string>

/*********************************************************************
** Function: do_again()
** Description: This gets whether the user wants to see another pattern or not
** Parameters: NONE
** Pre-Conditions: user has gone through once and did a pattern
** Post-Conditions: if user inputs t then return true to run again if
the user enters f then return false and don't run again
*********************************************************************/
bool do_again(){
    std::string a = "";

    std::cout << "Do you want to do another pattern? (t-true, f-false): ";
    std::getline(std::cin, a);

    if(a[0] == 't'){
        return true;
    }else if (a[0] == 'f'){
        return false;
    }
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
int string_to_int(std::string num) {
	int value = 0; // set the value equal to 0 to get rid of any garbage value stored in there

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

    return value;
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
        std::string n = "";
        std::string col = "";

        std::cout << "\n\nWhat do you want for n? (positive even number that's greater than 3): ";
        std::getline(std::cin, n);
        std::cout << "What do you want for col?: ";
        std::getline(std::cin, col);

        std::cout << "\n\nThis is pattern(" << n << ", " << col << "):\n\n";
        pattern(string_to_int(n), string_to_int(col));
        std::cout << "\n\n";
    }while(do_again());

    return 0;
}