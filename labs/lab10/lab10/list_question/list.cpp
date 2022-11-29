#include <iostream>

#include "list.h"

using namespace std;

ListNode* removeNthFromEnd(ListNode* head, int n);

string print_list_to_str(ListNode* head){
	string temp = "";
	ListNode* current = head;
	while (current!=NULL){
		temp += to_string(current->val);
		temp += "->";
		current = current->next;
	}
	temp += "NULL" ;
	return temp;
}

void print_list(ListNode* head){
	ListNode* current = head;
	while (current!=NULL){
		cout << current->val << "->";
		current = current->next;
	}
	cout << "NULL" << endl;
}

ListNode* add_node(ListNode* head, int val){
	ListNode* new_node = new ListNode(val);
	ListNode* current = head;
	if (current == NULL){
		head = new_node;
		return head;
	}
	while (current->next != NULL){
		current = current ->next;
	}
	current->next = new_node;

	return head;

}

void delete_list(ListNode** head){
	ListNode* current = *head;
	ListNode* temp = NULL;
	while (current != NULL){
		temp = current->next;
		delete current;
		current = temp; 
	}
	*head = NULL;
}


void print_result (string actual, string expected, int num){
	if (actual == expected)
		cout << "Test " << num << " pass" << endl;
	else{
		cout << "Test " << num << " failed." << endl;
		cout << "Your answer: " << actual << endl;
		cout << "Expected   : " << expected << endl;
		exit(1);
	}
}

void test1(string expected){
	ListNode* l = NULL;
	for (int i = 0; i < 4; i++)
		l = add_node(l, i+1);

	l = removeNthFromEnd(l, 4);
	string actual = print_list_to_str(l);
	delete_list(&l);

	print_result(actual, expected, 1);
}


void test2(string expected){
	ListNode* l = NULL;
	for (int i = 0; i < 4; i++)
		l = add_node(l, i+1);

	l = removeNthFromEnd(l, 1);
	string actual = print_list_to_str(l);
	delete_list(&l);

	print_result(actual, expected, 2);
	
}

void test3(string expected){
	ListNode* l = NULL;
	l = add_node(l, 5);

	l = removeNthFromEnd(l, 1);
	string actual = print_list_to_str(l);
	delete_list(&l);

	print_result(actual, expected, 3);
	
}

void test4(string expected){
	ListNode* l = NULL;
	l = add_node(l, 25);
	l = add_node(l, 28);

	l = removeNthFromEnd(l, 1);
	string actual = print_list_to_str(l);
	delete_list(&l);

	print_result(actual, expected, 4);
	
}

void test5(string expected){
	ListNode* l = NULL;
	l = add_node(l, 15);
	l = add_node(l, 81);

	l = removeNthFromEnd(l, 2);
	string actual = print_list_to_str(l);
	delete_list(&l);
	print_result(actual, expected, 5);
	
}

void test6(string expected){
	ListNode* l = NULL;
	for (int i = 0; i < 50000; i++)
		l = add_node(l, i+1);

	l = removeNthFromEnd(l, 25000);
	string actual = print_list_to_str(l);
	delete_list(&l);
	print_result(actual, expected, 6);
	
}


