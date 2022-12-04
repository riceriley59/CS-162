/*********************************************************************
** Filename: node.cpp
** Author: Riley Rice
** Date: 12-2-2022
** Description: This is the implementation file for my node class
*********************************************************************/

//include the node class definition
#include "node.h"

/*********************************************************************
** Function: Node::Node()
** Description: This is the default constructor for my Node class
** Parameters: NONE
** Pre-Conditions: Node object is created
** Post-Conditions: val is set to 0 and next is set to a null pointer
*********************************************************************/
Node::Node(){
    this->val = 0;
    this->next = nullptr;
}

/*********************************************************************
** Function: Node::Node()
** Description: This is my parameterized constructor for my Node class
** Parameters: int x
** Pre-Conditions: Node object is created and x is passed in
** Post-Conditions: val is set to the parameter x and next is set to a 
null pointer
*********************************************************************/
Node::Node(int x){
    this->val = x;
    this->next = nullptr;
}
