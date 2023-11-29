#include <vector>
#include <iostream>
#include "matrix.h"


SparseMatrix::SparseMatrix(){

}


int SparseMatrix::getsize(){
    return this->matrix.size();
}

void SparseMatrix::printList(){

    for(int i = 0; i < matrix.size(); i++){
        std::cout<<matrix[i].row;
        std::cout<<matrix[i].col;
        std::cout<<matrix[i].data;

    }
}

void SparseMatrix::MatrixToLL(std::vector<std::vector<int>>MatrixVec1){
    Node myNode;
    for (int i = 0; i < MatrixVec1[0].size(); ++i) {
        for (int j = 0; j < MatrixVec1.size(); ++j) {
            if(MatrixVec1[i][j] != 0){
                myNode.row = i;
                myNode.col = j;
                myNode.data = MatrixVec1[i][j];
                matrix.push_back(myNode);

            }
        }

    }
}
