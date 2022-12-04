/*********************************************************************
** Filename: node.h
** Author: Riley Rice
** Date: 12-2-2022
** Description: This is the header file for my node class
*********************************************************************/

//header guard
#ifndef NODE_H
#define NODE_H

//this is the node class which has a int value and then a Node pointer
//so it can point to another node creating a linked list
class Node{
	public:
		int val; // the value that this node stores
		Node *next; // a pointer to the next node in the list
		
		Node(); //default constructor
		Node(int); //parameterized constructor
};

#endif