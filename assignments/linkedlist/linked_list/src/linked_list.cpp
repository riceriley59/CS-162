#include "linked_list.h"

Linked_List::Linked_List() : length(0), head(nullptr) {}

int Linked_List::get_length(){
    return this->length; 
}

void Linked_List::print(){
    Node* temp = this->head;

    while(temp != nullptr){
        std::cout << temp->val << " ";
        temp = temp->next;
    }
}

void Linked_List::clear(){
    Node* prev = nullptr;
    Node* curr = this->head;

    while(curr != nullptr){
        prev = curr;
        curr = curr->next;

        prev->next = nullptr;
        delete prev;
        prev = nullptr;
    }
}

void Linked_List::push_front(int value){
    Node* newnode = new Node(value);

    newnode->next = this->head;
    this->head = newnode;

    this->length++;
}

void Linked_List::push_back(int value){
    Node* curr = this->head;

    while(curr->next != nullptr){
        curr = curr->next;
    }

    curr->next = new Node(value);
    this->length++;
}

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

void Linked_List::sort_ascending(){
    if(this->length < 2){
        return ;
    }

    this->merge_sort(&this->head);    
}

void Linked_List::merge_sort(Node** headref){
    Node* head = *headref;
    Node* a = nullptr;
    Node* b = nullptr;

    if(head == NULL || head->next == NULL)
        return;

    this->split(head, &a, &b);

    this->merge_sort(&a);
    this->merge_sort(&b);

    *headref = this->sort(a, b);
}

Node* Linked_List::sort(Node* a, Node* b){
    Node* result = nullptr;

    if(a == nullptr){
        return b;
    }else if(b == nullptr){
        return a;
    }

    if(a->val <= b->val){
        result = a;
        result->next = sort(a->next, b);
    }else{
        result = b;
        result->next = sort(a, b->next);
    }

    return result;
}

void Linked_List::split(Node* start, Node** front, Node** back){
    Node* one;
    Node* two;
    one = start;
    two = start->next;

    while(one != nullptr){
        one = one->next;
        if(one != nullptr){
            two = two->next;
            one = one->next;
        }
    }

    *front = start;
    *back = two->next;
    two->next = NULL;
}

void Linked_List::sort_descending(){

}

Linked_List::~Linked_List(){
    this->clear();
}

unsigned int count_prime(Linked_List&){

}