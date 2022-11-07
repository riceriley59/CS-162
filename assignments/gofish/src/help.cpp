/*********************************************************************
** Filename: help.cpp
** Author: Riley Rice
** Date: 11-6-2022
** Description: This is the implementation file for my helper functions
which make error handling in my program easier.
*********************************************************************/

//include header file
#include "help.h"

using namespace std;

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
int string_to_int(string num) {
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