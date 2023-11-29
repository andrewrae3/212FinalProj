#include "matrix.h"
#include <iostream>
#include <vector>

SparseMatrix::SparseMatrix(){

}

SparseMatrix::SparseMatrix(int row, int col, int data){
    this->insert(row, col, data);
}

void SparseMatrix::insert(int row, int col, int data){
    Node node = {row, col, data};
    this->matrix.push_back(node);
}

std::list<Node> SparseMatrix::add(SparseMatrix &matrix1, SparseMatrix &matrix2, int row, int col){
    for (int i = 0; i <= row; i++) {
        for (int j = 0; j <= col; j++) {
            int value = matrix1.getElement(i, j) + matrix2.getElement(i, j);
            Node node = {i,j,value};
            if (value != 0) {
                matrix.push_back(node);
//                std::cout << "Added: Matrix1[" << i << "][" << j << "] + Matrix2[" << i << "][" << j << "] = " << value << std::endl;
            }
        }
    }
    return matrix;
}

std::list<Node> SparseMatrix::subtract(SparseMatrix &matrix1, SparseMatrix &matrix2, int row, int col){
    for (int i = 0; i <= row; i++) {
        for (int j = 0; j <= col; j++) {
            int value = matrix1.getElement(i, j) - matrix2.getElement(i, j);
            Node node = {i,j,value};
            if (value != 0) {
                matrix.push_back(node);
//                std::cout << "Subtracted: Matrix1[" << i << "][" << j << "] + Matrix2[" << i << "][" << j << "] = " << value << std::endl;
            }
        }
    }
    return matrix;
}

std::list<Node> SparseMatrix::multiply(SparseMatrix &matrix1, SparseMatrix &matrix2, int row1, int col1, int row2, int col2){

}

std::list<Node> SparseMatrix::transpose(SparseMatrix &matrix1, int row1, int col1){
    for (int j = 0; j <= col1; j++) {
        for (int i = 0; i <= row1; i++) {
            int value = matrix1.getElement(j, i);
            if (value != 0) {
                Node node = {i,j,value};
                matrix.push_back(node);
            }
        }
    }
    return matrix;
}

int SparseMatrix::getElement(int row, int col) {
    for (Node &node : matrix) {
        if (node.row == row && node.col == col) {
            return node.data;
        }
    }
    return 0;
}

void SparseMatrix::print(){

}
