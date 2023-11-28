#include "node.h"
#include <vector>
#include <string>

class LinkedList {
private:
    Node *head;
    unsigned int size;

public:
    LinkedList();
    LinkedList(int data);
    LinkedList(std::vector<int> vec);
    ~LinkedList();

    void push_back(int data);

};
