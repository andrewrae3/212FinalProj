#include "node.h"
#include <vector>
#include <string>

class LinkedList {
private:
    Node *head;
    unsigned int size;

public:
    LinkedList(); // this->head = nullptr;
    LinkedList(int data);
    LinkedList(std::vector<int> vec);
    ~LinkedList();

    void push_back(int data);

};