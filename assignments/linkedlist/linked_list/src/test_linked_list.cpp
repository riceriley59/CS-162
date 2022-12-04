/*********************************************************************
** Program Filename: Linked_List, test_linked_list.cpp
** Author: Riley Rice
** Date: 12-2-2022
** Description: This is my linked list program where I have to write a 
linked list class along with methods that users can use to do stuff with the
linked list like sorting, printing, adding nodes, etc., and this file tests
to make sure those functionalities work properly
*********************************************************************/

//include linked list class and iostream
#include <iostream>
#include "linked_list.h"

//makes using standard library elements like cout easier
using namespace std;

/*********************************************************************
** Function: pause()
** Description: This function pauses program execution until a button is pressed
** Parameters: NONE
** Pre-Conditions: program is executing
** Post-Conditions: program execution is stopped until button press
*********************************************************************/
void pause() {
        cout << "\n\nPress <enter> to continue...";
        cin.clear();
        cin.ignore(256, '\n');
}

/*********************************************************************
** Function: int main()
** Description: This is the main entry point for the program and this conducts
all the tests needed for making sure my linked list class works properly
** Parameters: int argc, char const *argv[]
** Pre-Conditions: program isn't running
** Post-Conditions: program enters at main and runs tests on linked list class
*********************************************************************/
int main(int argc, char const *argv[])
{
	Linked_List l;
	cout << "\n\nList successfully created!!\n\n";;

	cout << "**********Test 1***********\n";
	cout << "Before adding nodes...\n";
	cout << "Testing get_length()\n";
	cout << "Expected: 0\n";
	cout << "Actual  : " << l.get_length() << "\n";
	if (l.get_length() == 0)
		cout << "Test 1 PASSED\n\n";
	else
		cout << "Test 1 FAILED\n\n";


	cout << "**********Test 2***********\n";
	cout << "Adding nodes...\n";
	cout << "Test 2.1: Testing push_front()\n";
	l.push_front(5);
	l.push_front(100);
	l.push_front(0);
	l.push_front(-8);
	l.push_front(16);
	cout << "Expected: 16 -8 0 100 5\n";
	cout << "Actual  : "; 
	l.print();
	cout << "Expected length: 5\n";
	cout << "Actual length  : " << l.get_length() << "\n";
	cout << "Test 2.1 completed.\n";
	pause();

	cout << "Test 2.2: Testing push_back()\n";
	l.push_back(5);
	l.push_back(1);
	l.push_back(2);
	l.push_back(7);
	l.push_back(7919);
	cout << "Expected: 16 -8 0 100 5 5 1 2 7 7919\n";
	cout << "Actual  : "; 
	l.print();
	cout << "Expected length: 10\n";
	cout << "Actual length  : " << l.get_length() << "\n";
	cout << "Test 2.2 completed.\n";
	pause();

	cout << "Test 2.3: Testing insert()\n";
	l.insert(11, 0);   // insert 11 at the front of the list
	l.insert(20, 100); // 100 is not a valid index, therefore 20 is not inserted
	l.insert(50, l.get_length()); // insert 50 at the end of the list
	l.insert(9, 5); // insert 9 at index 5 
	cout << "Expected: 11 16 -8 0 100 9 5 5 1 2 7 7919 50\n";
	cout << "Actual  : "; 
	l.print();
	cout << "Expected length: 13\n";
	cout << "Actual length  : " << l.get_length() << "\n";
	cout << "Test 2.3 completed.\n";
	pause();

	cout << "**********Test 3***********\n";
	cout << "Sorting...\n";
	cout << "Test 3.1: Testing sort_ascending()\n";
	l.sort_ascending();
	cout << "Expected: -8 0 1 2 5 5 7 9 11 16 50 100 7919\n";
	cout << "Actual  : "; 
	l.print();
	cout << "Test 3.1 completed.\n";
	pause();

	cout << "Test 3.2: Testing sort_descending()\n";
	l.sort_descending();
	cout << "Expected: 7919 100 50 16 11 9 7 5 5 2 1 0 -8\n";
	cout << "Actual  : "; 
	l.print();
	cout << "Test 3.2 completed.\n";
	pause();

	cout << "**********Test 4***********\n";
	cout << "Tesing count_prime()\n";
	cout << "Expected: 6\n"; //7919 11 7 5 5 2
	cout << "Actual  : " << count_prime(l) << "\n";
	if (count_prime(l) == 6)
		cout << "Test 4 PASSED\n";
	else
		cout << "Test 4 FAILED\n";


	cout << "**********Test 5***********\n";
	cout << "Tesing clear()\n";
	l.clear();
	cout << "Expected length: 0\n";
	cout << "Actual length  : " << l.get_length() << "\n";
	if (l.get_length() == 0)
		cout << "Test 5 PASSED\n";
	else
		cout << "Test 5 FAILED\n";

	return 0;
}
