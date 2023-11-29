#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <list>
#include "matrix.h"


int main(int argc, char* argv[]) {
    std::ifstream Matrix1(argv[1]), Matrix2(argv[4]);
    int Row1 = std::stoi(argv[2]);
    int Col1 = std::stoi(argv[3]);
    std::string line1, line2;
    std::vector<std::vector<int>> MatrixVec1;
    std::vector<std::vector<int>> MatrixVec2;

    while (std::getline(Matrix1, line1)) {
        std::cout << line1 << std::endl;
        std::istringstream iss(line1);
        int num;
        std::vector<int> lineNumbers;
        while (iss >> num) {
            lineNumbers.push_back(num);
        }
        MatrixVec1.push_back(lineNumbers);
    }
    Matrix1.close();

    while (std::getline(Matrix2, line2)) {
        std::istringstream iss(line2);
        int num;
        std::vector<int> rows;
        while (iss >> num) {
            rows.push_back(num);
        }
        MatrixVec2.push_back(rows);
    }
    Matrix2.close();


//    for (int i = 0; i < Row1; ++i) {
//        for (int j = 0; j < Col1; ++j) {
//            std::cout << MatrixVec1[i][j] << " ";
//        }
//        std::cout << std::endl;
//    }
    
SparseMatrix matrix;
    matrix.MatrixToLL(MatrixVec1);
    matrix.printList();



}


