/*********************************************************************
** Filename: linked_list.h
** Author: Riley Rice
** Date: 12-2-2022
** Description: This is the header file for my linked list class
*********************************************************************/

//header guard
#ifndef LINKED_LIST
#define LINKED_LIST

//this includes my node class and iostream so the methods can output to the console
#include "node.h"
#include <iostream>

//this is the class for my linked list and has all the methods required to do what you want with the list 
class Linked_List {
private:
	unsigned int length; // the number of nodes contained in the list
	Node* head; // a pointer to the first node in the list

	//private functions to do a merge sort
	void merge_sort(Node**);
	void split(Node*, Node**, Node**);
	Node* m_sort(Node*, Node*);

	//private functions to do a selection sort
	Node* selection_sort(Node*);
	void swapNodes(Node**, Node*, Node*, Node*);
public:
	Linked_List();

	Node* get_head();
	int get_length();
	// note: there is no set_length(unsigned int) (the reasoning should be intuitive)
   
	void print(); // output a list of all integers contained within the list
	void clear(); // delete the entire list (remove all nodes and reset length to 0)
   
	void push_front(int); // insert a new value at the front of the list 
	void push_back(int); // insert a new value at the back of the list 
	void insert(int val, unsigned int index); // insert a new value in the list at the specified index 

	void sort_ascending(); // sort the nodes in ascending order. You must implement the recursive Merge Sort algorithm
	// Note: it's okay if sort_ascending() calls a recursive private function to perform the sorting.
	void sort_descending(); // sort the nodes in descending order

	// you can add extra member variables or functions as desired
	~Linked_List();
};

unsigned int count_prime(Linked_List&); //count and return the number of prime numbers within the list

#endif
