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
    std::list<Node> multiply(SparseMatrix &matrix1, SparseMatrix &matrix2, int row1, int col2);
    std::list<Node> transpose(SparseMatrix &matrix1, int row1, int col1);
    void clear() {
        matrix.clear(); // Clears the content of the list 'matrix'
    }

};



#endif //FINLA_MATRIX_H
