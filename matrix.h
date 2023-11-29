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
    int getElement(int row, int col);
    std::list<Node> add(SparseMatrix &matrix1, SparseMatrix &matrix2, int row, int col);
    std::list<Node> subtract(SparseMatrix &matrix1, SparseMatrix &matrix2, int row, int col);
    SparseMatrix multiply(SparseMatrix &matrix1, SparseMatrix &matrix2);
    SparseMatrix divide(SparseMatrix &matrix1, SparseMatrix &matrix2);
    void print();

};



#endif //FINLA_MATRIX_H
