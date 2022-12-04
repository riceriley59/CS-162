/*********************************************************************
** Filename: linked_list.cpp
** Author: Riley Rice
** Date: 12-2-2022
** Description: This is the implementation file for my linked list class
and is where I add the definitions for all the method protypes.
*********************************************************************/

//include header file for linked list class so the methods can be defined
#include "linked_list.h"

/*********************************************************************
** Function: Linked_List::Linked_List()
** Description: This is my default constructor for my linked list class 
** Parameters: NONE
** Pre-Conditions: Linked_List object is created
** Post-Conditions: length is set to 0 and head is set to a nullptr
*********************************************************************/
Linked_List::Linked_List() : length(0), head(nullptr) {}

/*********************************************************************
** Function: Linked_List::~Linked_List()
** Description: This is the deconstructor for the linked list class. It
clears the list and all the memory using the clear method before it's 
destroyed
** Parameters: NONE
** Pre-Conditions: Linked List has values
** Post-Conditions: values are deleted and linked list is destroyed
*********************************************************************/
Linked_List::~Linked_List(){
    this->clear();
}

/*********************************************************************
** Function: Linked_List::get_head()
** Description: This returns the head Node pointer in the linked list 
object
** Parameters: NONE
** Pre-Conditions: head attribute has value
** Post-Conditions: value of head is returned
*********************************************************************/
Node* Linked_List::get_head(){
    return this->head;
}

/*********************************************************************
** Function: Linked_List::get_length()
** Description: This gets the length of the linked list object
** Parameters: NONE
** Pre-Conditions: length has value
** Post-Conditions: value of length is returned
*********************************************************************/
int Linked_List::get_length(){
    return this->length; 
}

/*********************************************************************
** Function: Linked_List::print()
** Description: This prints out all the values in the linked list
** Parameters: NONE
** Pre-Conditions: linked list is created
** Post-Conditions: every node's value is printed to the screen seperated by 
spaces
*********************************************************************/
void Linked_List::print(){
    Node* temp = this->head;

    while(temp != nullptr){
        std::cout << temp->val << " ";
        temp = temp->next;
    }
}

/*********************************************************************
** Function: Linked_List::clear()
** Description: This deletes all the nodes in the list, or clears it.
** Parameters: NONE
** Pre-Conditions: linked list has nodes or no nodes
** Post-Conditions: all nodes thats in the linked list are removed and deleted
off of the heap
*********************************************************************/
void Linked_List::clear(){
    if(this->length > 0){
        Node* temp = this->head;
        Node* prev = nullptr;

        while(temp != nullptr){
            prev = temp;
            temp = temp->next;

            prev->next = nullptr;
            delete prev;
            prev = nullptr;
        }

        this->length = 0;
    }
}

/*********************************************************************
** Function: Linked_List::push_front()
** Description: This adds a node at the front of the list
** Parameters: int value
** Pre-Conditions: value is passed in
** Post-Conditions: new node with its value being equal to the integer that 
is passed in is put into the front of the list. The head will point to the new
node and the new node will point to the previous head node
*********************************************************************/
void Linked_List::push_front(int value){
    Node* newnode = new Node(value);

    newnode->next = this->head;
    this->head = newnode;

    this->length++;
}

/*********************************************************************
** Function: Linked_List::push_back()
** Description: This puts a node at the back of the list
** Parameters: int value
** Pre-Conditions: value is passed in 
** Post-Conditions: new node with its value being equal to the integer that
is passed in is put into the back of the list. iterate through the list until
we reach the end and then make the last node point to the new node.
*********************************************************************/
void Linked_List::push_back(int value){
    Node* curr = this->head;

    while(curr->next != nullptr){
        curr = curr->next;
    }

    curr->next = new Node(value);
    this->length++;
}

/*********************************************************************
** Function: Linked_List::insert()
** Description: This inserts a new node at the index that is passed in
** Parameters: int val, unsigned int index
** Pre-Conditions: parameters are passed in
** Post-Conditions: new node is created with a value of the value parameter.
if the index is in range of the list then call the push_front() method if 
the index passed in is 0, otherwise iterate through the list until we reach
the desired index and then make the newnode point to the previous node's next
and then make the current node in the index point to the new node. Also add one
to the length.
*********************************************************************/
void Linked_List::insert(int val, unsigned int index){
    if(index <= this->length){
        Node* curr = this->head;

        if(index == 0){
            this->push_front(val);
        }else{
            index--;
            while(index > 0){
                curr = curr->next;
                index--;
            }

            Node* newnode = new Node(val);

            newnode->next = curr->next;
            curr->next = newnode;
            this->length++;
        }
    }
}

/*********************************************************************
** Function: Linked_List::sort_ascending()
** Description: This sorts the list in ascending order using a recursive 
merge sort algorithm.
** Parameters: NONE
** Pre-Conditions: linked list is created
** Post-Conditions: if the linked list has less than 2 elements then return
becuase you can't sort it otherwise call the merge sort method.
*********************************************************************/
void Linked_List::sort_ascending(){
    if(this->length < 2){
        return;
    }

    this->merge_sort(&this->head);    
}

/*********************************************************************
** Function: Linked_List::merge_sort()
** Description: This handles the recursive merge sort which sorts the 
linked list in ascending order
** Parameters: Node** headref
** Pre-Conditions: linked list has more than 2 elements
** Post-Conditions: keep on splitting up the list until it's split into 
lists of size 1 and then slowly sort them and put them back together. This
algorithm has a time complexity of O(nlog(n)) and a space complexity of O(n)
*********************************************************************/
void Linked_List::merge_sort(Node** headref){
    //get the value of the head reference so that we can have the actual memory address
    //of the head passed in
    Node* head = *headref;

    //create two pointers that will be pointers for each half of the list
    Node* a = nullptr;
    Node* b = nullptr;

    //if head is null or the next value is null then the list is of size 1
    //and we can stop the recursive merge sorts and start calling the m_sort()
    //method on all the lists and put them back together. This is the base case
    if(head == nullptr || head->next == nullptr){
        return;
    }

    //call the split method which splits the list pointed to by head into two 
    //lists and store those in a and b
    this->split(head, &a, &b);

    //recursively call merge_sort method on each new list as the head so that the
    //lists keep splitting until they are of size 1
    this->merge_sort(&a);
    this->merge_sort(&b);

    //then call the m_sort() method with each list passed in. This will sort the two
    //lists entered in and then put them back together
    *headref = this->m_sort(a, b);
}

/*********************************************************************
** Function: Linked_List::m_sort()
** Description: This handles the sorting of the lists. It takes two split lists
and then compares their values and puts them back together in ascending order.
** Parameters: Node* a, Node* b
** Pre-Conditions: merge_sort method has split the lists apart
** Post-Conditions: the two lists a and b that are passed in will be put together
after being sorted by ascending order
*********************************************************************/
Node* Linked_List::m_sort(Node* a, Node* b){
    //create a pointer which will hold the final sorted list
    Node* result = nullptr;

    //if a or b has been exhausted then return the rest of the other list
    //this is the base case for this recursive function
    if(a == nullptr){
        return b;
    }else if(b == nullptr){
        return a;
    }

    /******************
    This checks to see which val is bigger in the b or a pointer
    and then it set the result list equal to the node with the 
    bigger value. It then recursively calls the same function with 
    the next node in the list which had the bigger value and then sets 
    the return value of the recursive call to the next value of the result list. 
    This in the end results in the each of the lists being stepped through one 
    by one and then returning the bigger nodes and adding that to the final result 
    list until it they have been exhausted, and the result list is the sorted products
    of the two lists. 
    *******************/
    if(a->val <= b->val){
        result = a;
        result->next = m_sort(a->next, b);
    }else{
        result = b;
        result->next = m_sort(a, b->next);
    }

    //return the final sorted list
    return result;
}

/*********************************************************************
** Function: Linked_List::split()
** Description: This splits a list into two parts
** Parameters: Node* start, Node** front, Node** back
** Pre-Conditions: merge sort is called on linked list object with more than
1 node.
** Post-Conditions: The original list, which is the start pointer, is split into two
lists, the front and back reference pointers.
*********************************************************************/
void Linked_List::split(Node* start, Node** front, Node** back){
    //both pointers are set to null
    //fast pointer will go to the end of the list and the slow pointer will be
    //in the middle of the list by the end of the function call
    Node* fast = nullptr;
    Node* slow = nullptr;

    //set the slow pointer to the head of the list that's passed in 
    //set the fast pointer to the 2 node of the list that's passed in
    slow = start;
    fast = start->next;

    //while the fast pointer hasn't reached the end of the list iterate the 
    //fast pointer by two and the slow pointer by 1. By the end the if you iterate 
    //fast pointer by two and the slow pointer by 1 then when the fast pointer reaches
    //the end then the slow pointer should point to the middle of the list.
    while(fast != nullptr){
        fast = fast->next;
        if(fast != nullptr){
            slow = slow->next;
            fast = fast->next;

        }
    }

    //now that we have the slow pointer which points to the node that is in
    //the middle of the list. set the front pointer for the front half of the list
    //equal to the start of the list or the head. Then set the start for the back 
    //half of the list equal to the next node of the slow pointer as this pointer is
    //in the middle. Then clear the slow pointer's next pointer so that the front lists
    //last node is null which is how we can tell the list is over.
    *front = start;
    *back = slow->next;
    slow->next = nullptr;
}

/*********************************************************************
** Function: Linked_List::sort_descending()
** Description: This sorts the list in descending order using a recursive 
selection sort algorithm
** Parameters: NONE
** Pre-Conditions: linked_list object has more than 1 node
** Post-Conditions: linked list is sorted in descending order
*********************************************************************/
void Linked_List::sort_descending(){
    if(this->length < 2){
        return;
    }
    
    //set the head pointer to the new sorted list
    this->head = this->selection_sort(this->head);
}

/*********************************************************************
** Function: Linked_List::selection_sort()
** Description: The selection sort algorithm works by splitting the list 
into two sections one being the sorted section and the other being the unsorted
section. It sets the first list to the potential max and then iterates through the 
list and if the node's val is bigger than the current max value then set the max value
equal to that node's index. Then once you have gone through the list swap the head or 
the first index of the unsorted section with the max node that you found through your
iteration. Then you step the head pointer forward once and then repeat until you have
done this for the whole list and sorted the whole thing. This algorithm has a time
complexity of O(n^2), but a space complexity of constant space O(1).
** Parameters: Node* head
** Pre-Conditions: linked list is not sorted
** Post-Conditions: linked list is sorted in descending order
*********************************************************************/
Node* Linked_List::selection_sort(Node* head){
    //if we have exhausted through the whole list then return the head or the last node
    //this is the base case
    if (head->next == nullptr){
        return head;
    }

    //set the max to the first node in the unsorted section of the list
    Node* max = head;

    //make two pointers for storing the ptr to iterate through the list 
    //and a pointer to the node before the max 
    Node* beforeMax = nullptr;
    Node* ptr = nullptr;

    //iterate through the entire list
    for (ptr = head; ptr->next != nullptr; ptr = ptr->next) {
        //if there is a val that in the list that is bigger than the current max
        //then set the max to point to the new max and the before max to the node 
        //before the new max
        if (ptr->next->val > max->val) {
            max = ptr->next;
            beforeMax = ptr;
        }
    }

    //if the max isn't the head in which you wouldn't have to swap positions
    //then don't swap the nodes other wise swap the positons of the head of the 
    //unsorted list and the max we found after iterating through the list
    if (max != head){
        this->swapNodes(&head, head, max, beforeMax);
    }

    //step over one in the list to the unsorted section, then recursively call selection_sort
    //which will sort the new list until you have stepped through the same thing.
    head->next = this->selection_sort(head->next);

    //return the node* pointer which points to the sorted list
    return head;
}

/*********************************************************************
** Function: Linked_List::swapNodes()
** Description: This swaps two nodes positions in a linked list
** Parameters: Node** href, Node* head, Node* max, Node* beforeMax
** Pre-Conditions: linked list has had the selection sort called on it 
and it found a max
** Post-Conditions: the max node is swapped with the head node or the front of the list 
*********************************************************************/
void Linked_List::swapNodes(Node** href, Node* head, Node* max, Node* beforeMax){
    //set the head equal to the max node
    *href = max;

    //set the previous node's next pointer equal to the head 
    beforeMax->next = head;

    //create a temp variable which holds the max's next pointer
    Node* temp = max->next;

    //set the max next pointer equal to the head's next pointer 
    max->next = head->next;
    
    //Then set the head's next pointer equal to the max's old next pointer
    head->next = temp;
}

/*********************************************************************
** Function: isprime()
** Description: This takes a number and determines if it's prime or not
** Parameters: int num
** Pre-Conditions: int num is passed in
** Post-Conditions: if num is prime then return true otherwise return false
*********************************************************************/
bool isprime(int num){
    //1 isn't prime so return false if it's 1
    if(num <= 1){
        return false;
    }

    //2 and 3 are prime which means that if it's less than or equal to 3 
    //but greater than 1, because of the if statement above, then return true 
    //cause it's prime
    if(num <= 3){
        return true;
    }

    //if the number is divisible by 2 or 3 then the number isn't prime
    //so return false
    if(num % 2 == 0 || num % 3 == 0){
        return false;
    }

    //if it isn't divisible by 2 or 3 and it's greater than 3 then the number
    //is prime and return true
    return true;
}

/*********************************************************************
** Function: count_prime()
** Description: This function counts the number of primes in a linked list
This function has a time complexity of O(n) and a space complexity of constant
space or O(1).
** Parameters: Linked_List& list
** Pre-Conditions: list has been created
** Post-Conditions: the number of primes in the list is returned.
*********************************************************************/
unsigned int count_prime(Linked_List& list){
    unsigned int count = 0;

    //get the head of the list
    Node* ptr = list.get_head();

    //iterate through the whole list
    while(ptr != nullptr){
        //call the isprime function and pass in the value of the list index 
        //as the parameter
        if(isprime(ptr->val)){
            //if it is prime then iterate the count by 1
            count++;
        }

        //go to the next node in the list
        ptr = ptr->next;
    }

    //return the amount of primes in the list
    return count;
}