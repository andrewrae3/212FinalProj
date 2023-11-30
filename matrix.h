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
    void MatrixToLL(std::vector<std::vector<int>>MatrixVec1);
    std::list<Node> add(SparseMatrix &matrix1, SparseMatrix &matrix2, int row, int col);
    std::list<Node> subtract(SparseMatrix &matrix1, SparseMatrix &matrix2, int row, int col);
    std::list<Node> multiply(SparseMatrix &matrix1, SparseMatrix &matrix2, int row1, int col2);
    std::list<Node> transpose(SparseMatrix &matrix1, int row1, int col1);
//    std::list<Node> power(SparseMatrix &matrix1, int row1, int col1, int op);
//    std::list<Node> inverse(SparseMatrix &matrix1, int row1, int col1);
//    std::list<Node> determinant(SparseMatrix &matrix1, int row1, int col1);
    void print(std::list<Node> &matrix);

};



#endif //FINLA_MATRIX_H
