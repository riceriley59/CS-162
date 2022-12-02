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

    if(head == nullptr || head->next == nullptr){
        return;
    }

    this->split(head, &a, &b);

    this->merge_sort(&a);
    this->merge_sort(&b);

    *headref = this->m_sort(a, b);
}

Node* Linked_List::m_sort(Node* a, Node* b){
    Node* result = nullptr;

    if(a == nullptr){
        return b;
    }else if(b == nullptr){
        return a;
    }

    if(a->val <= b->val){
        result = a;
        result->next = m_sort(a->next, b);
    }else{
        result = b;
        result->next = m_sort(a, b->next);
    }

    return result;
}

void Linked_List::split(Node* start, Node** front, Node** back){
    Node* fast = nullptr;
    Node* slow = nullptr;

    slow = start;
    fast = start->next;

    while(fast != nullptr){
        fast = fast->next;
        if(fast != nullptr){
            slow = slow->next;
            fast = fast->next;

        }
    }

    *front = start;
    *back = slow->next;
    slow->next = nullptr;
}

void Linked_List::sort_descending(){
    if(this->length < 2){
        return;
    }

    this->head = this->selection_sort(this->head);
}

Node* Linked_List::selection_sort(Node* head){
    if (head->next == nullptr){
        return head;
    }

    Node* max = head;
    Node* beforeMax = nullptr;
    Node* ptr = nullptr;

    for (ptr = head; ptr->next != nullptr; ptr = ptr->next) {
        if (ptr->next->val > max->val) {
            max = ptr->next;
            beforeMax = ptr;
        }
    }

    if (max != head)
        this->swapNodes(&head, head, max, beforeMax);

    head->next = this->selection_sort(head->next);

    return head;
}

void Linked_List::swapNodes(Node** href, Node* curr1, Node* curr2, Node* prev2){
    *href = curr2;

    prev2->next = curr1;

    Node* temp = curr2->next;
    curr2->next = curr1->next;
    curr1->next = temp;
}

Node* Linked_List::get_head(){
    return this->head;
}

Linked_List::~Linked_List(){
    this->clear();
}

unsigned int count_prime(Linked_List& list){
    unsigned int count = 0;

    if(list.get_length() == 0){
        return count;
    }

    Node* temp = list.get_head();

    for(int i = 0; i < list.get_length(); i++){
        if(temp->val < 1){
            continue;
        }

        for(int j = 2; j <= temp->val/2; j++){
            if(temp->val % j == 0){
                continue;
            }else{
                count++;
            }
        }

        temp = temp->next;
    }

    return count;
}