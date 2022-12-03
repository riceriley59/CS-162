/*********************************************************************
** Program Filename:
** Author:
** Date:
** Description:
** Input:
** Output:
*********************************************************************/

#ifndef NODE_H
#define NODE_H

class Node{
	public:
		int val; // the value that this node stores
		Node *next; // a pointer to the next node in the list
		
		Node();
		Node(int);
};

#endif