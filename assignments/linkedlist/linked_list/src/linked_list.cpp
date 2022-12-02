#include "linked_list.h"

Linked_List::Linked_List() : length(0), head(nullptr) {}

int Linked_List::get_length(){
    return this->length; 
}

void Linked_List::print(){
    std::cout << "[";
    Node* temp = this->head;

    while(temp != nullptr){
        std::cout << temp->val << ", ";
        temp = temp->next;
    }

    std::cout << "]";
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

}

void Linked_List::sort_descending(){

}

Linked_List::~Linked_List(){
    this->clear();
}

unsigned int count_prime(Linked_List&){

}