#pragma once

class Node{
private:
    int row;
    int col;
    int data;
    Node* next;

    friend class LinkedList;
public:
    Node();
    // Overloading
    Node(int row, int col, int data);
    Node(int data, Node* next);
    ~Node();
};

//test
//another test