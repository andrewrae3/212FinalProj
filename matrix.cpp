#include "matrix.h"

SparseMatrix::SparseMatrix(){

}

SparseMatrix::SparseMatrix(int row, int col, int data){
   this->insert(row, col, data);
}

void SparseMatrix::insert(int row, int col, int data){
    Node node = {row, col, data};
    this->matrix.push_back(node);
}

