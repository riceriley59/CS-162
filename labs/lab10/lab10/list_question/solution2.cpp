#include <iostream>

#include "list.h"

//Definition for singly-linked list.
/* struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
}; */


ListNode* removeNthFromEnd(ListNode* head, int n) {
    if(head == NULL){
        return NULL;
    }

    int length = 0;
    ListNode* temp = head;

    while(temp != NULL){
        length++;
        temp = temp->next;
    }

    length -= n;

    if(length == 0){
        temp = head->next;
        head->next = NULL;
        delete head;
        head = NULL;
        return temp;
    }

    ListNode* curr = head;
    ListNode* previous = NULL;

    while(length > 0){
        previous = curr;
        curr = curr->next;
        length--;
    }

    previous->next = curr->next;
    curr->next = NULL;

    delete curr;
    curr = NULL;

    return head;
}
