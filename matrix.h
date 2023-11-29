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
    SparseMatrix add(SparseMatrix &matrix1, SparseMatrix &matrix2);
    SparseMatrix subtract(SparseMatrix &matrix1, SparseMatrix &matrix2);
    SparseMatrix multiply(SparseMatrix &matrix1, SparseMatrix &matrix2);
    SparseMatrix divide(SparseMatrix &matrix1, SparseMatrix &matrix2);
    void print();

};



#endif //FINLA_MATRIX_H
