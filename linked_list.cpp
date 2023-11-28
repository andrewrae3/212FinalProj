#include "linked_list.h"

LinkedList::LinkedList(){
    this->size = 0;
    this->head = nullptr;
}

LinkedList::LinkedList(int data){
    this->size = 1;
    this->head = new Node(data);
}

LinkedList::LinkedList(std::vector<int> vec){
    this->size=0;
    head = nullptr;
    for (int i = 0; i < vec.size(); ++i) {
        push_back(vec[i]);
    }
}

LinkedList::~LinkedList() {
    while (head != nullptr){
        Node *temp = head;
        head = head->next;
        delete temp;
    }
}

void LinkedList::push_back(int data) {
    Node *newNode = new Node(data);
    if (head == nullptr) {
        head = newNode;
    }
    else {
        Node *temp = head;

        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}