#include "node.h"

Node::Node(){
    this->val = 0;
    this->next = nullptr;
}

Node::Node(int x){
    this->val = x;
    this->next = nullptr;
}
