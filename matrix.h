#ifndef FINLA_MATRIX_H
#define FINLA_MATRIX_H

#include <list>
struct Node{
        int row;
        int col;
        int data;
};

class SparseMatrix{
    private:
    std::list<Node> matrix;

    public:
    SparseMatrix();
    SparseMatrix(int row, int col, int data);
    void insert(int row, int col, int data);
    void add(std::list<Node> &matrix1, std::list<Node> &matrix2);
    void subtract(std::list<Node> &matrix1, std::list<Node> &matrix2);
    void multiply(std::list<Node> &matrix1, std::list<Node> &matrix2);
    void divide(std::list<Node> &matrix1, std::list<Node> &matrix2);
    void print(std::list<Node> &matrix);

};



#endif //FINLA_MATRIX_H