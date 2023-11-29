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

SparseMatrix SparseMatrix::add(SparseMatrix &matrix1, SparseMatrix &matrix2){

}

SparseMatrix SparseMatrix::subtract(SparseMatrix &matrix1, SparseMatrix &matrix2){
    
}

SparseMatrix SparseMatrix::multiply(SparseMatrix &matrix1, SparseMatrix &matrix2){
    
}

SparseMatrix SparseMatrix::divide(SparseMatrix &matrix1, SparseMatrix &matrix2){
    
}

void SparseMatrix::print(SparseMatrix &matrix){
    
}
