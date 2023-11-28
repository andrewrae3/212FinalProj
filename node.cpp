#include "node.h"

// Default constructor
Node::Node(){
    this->data = 0;
    this->next = nullptr;
}

Node::Node(int row, int col, int data){
    this->row = row;
    this->col = col;
    this->data = data;
    this->next = nullptr;
}

Node::Node(int data, Node* next){
    this->data = data;
    this->next = next;
}

Node::~Node(){
    if(this->next != nullptr){
        delete this->next;
    }
}

