#ifndef LIST_H
#define LIST_H 


struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(NULL) {}
	ListNode(int x) : val(x), next(NULL) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}

};

#endif
