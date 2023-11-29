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

std::list<Node> SparseMatrix::multiply(SparseMatrix &matrix1, SparseMatrix &matrix2, int row1, int col2){
    std::vector<std::vector<int>> tempmatrix(row1, std::vector<int>(col2, 0));
    for (Node &node1 : matrix1.matrix) {
        for (Node &node2 : matrix2.matrix) {
            if (node1.col == node2.row) {
                tempmatrix[node1.row][node2.col] += node1.data * node2.data;
            }
        }
    }
    for (int i = 0; i < row1; ++i) {
        for (int j = 0; j < col2; ++j) {
            if (tempmatrix[i][j] != 0) {
                Node node = {i, j, tempmatrix[i][j]};
                matrix.push_back(node);
            }
        }
    }
    return matrix;
}

//std::list<Node> SparseMatrix::power(SparseMatrix &matrix1, int row1, int col1, int op) {
//
//}
//
//std::list<Node> SparseMatrix::inverse(SparseMatrix &matrix1, int row1, int col1) {
//
//}
//std::list<Node> SparseMatrix::determinant(SparseMatrix &matrix1, int row1, int col1) {
//    if (row1 == 1) {
//        int det = matrix1.getElement(0, 0);
////        std::cout << "Determinant of 1x1 matrix: " << det << std::endl;
//        return matrix;
//    } else if (row1 == 2) {
//        int a = matrix1.getElement(0, 0);
//        int b = matrix1.getElement(0, 1);
//        int c = matrix1.getElement(1, 0);
//        int d = matrix1.getElement(1, 1);
//
//        int det = a * d - b * c;
////        std::cout << "Determinant of 2x2 matrix: " << det << std::endl;
//        return matrix;
//    }
//}

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
