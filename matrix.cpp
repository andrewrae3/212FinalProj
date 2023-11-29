#include<vector>
#include <iostream>
#include "matrix.h"


SparseMatrix::SparseMatrix(){

}


int SparseMatrix::getsize(){
    return this->matrix.size();
}

//void SparseMatrix::printList(){
//    Node *newNode = new Node;
//    newNode = matrix.front();
//    while(newNode != matrix.back()){
//        std::cout << newNode->row;
//        std::cout << newNode->col;
//        std::cout << newNode->data;
//    }
//}

void SparseMatrix::printList() {
    for (const auto& node : matrix) {
        std::cout << "Row: " << node.row << ", Col: " << node.col << ", Value: " << node.data << std::endl;
    }
}


void SparseMatrix::MatrixToLL(std::vector<std::vector<int>>MatrixVec1){
    Node myNode;
    for (int i = 0; i < MatrixVec1.size(); ++i) {
        for (int j = 0; j < MatrixVec1[i].size(); ++j) {
            if(MatrixVec1[i][j] != 0){
                myNode.row = i;
                myNode.col = j;
                myNode.data = MatrixVec1[i][j];
                matrix.push_back(myNode);

            }
        }

    }


}
