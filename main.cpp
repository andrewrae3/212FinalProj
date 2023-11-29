#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <list>
#include "matrix.h"


int main(int argc, char* argv[]) {
    std::ifstream Matrix1(argv[1]), Matrix2(argv[5]);
    int Row1 = std::stoi(argv[2]);
    int Col1 = std::stoi(argv[3]);
    int Row2 = std::stoi(argv[6]);
    int Col2 = std::stoi(argv[7]);
    char operation= *argv[4];

    std::string line1, line2;
    std::vector<std::vector<int>> MatrixVec1;
    std::vector<std::vector<int>> MatrixVec2;

    while (std::getline(Matrix1, line1)) {
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

    SparseMatrix smatrix1;
    SparseMatrix smatrix2;

    for (size_t i = 0; i < Row1; ++i) {
        for (size_t j = 0; j < Col1; ++j) {
//            std::cout << MatrixVec1[i][j] << " ";
            smatrix1.insert(i, j, MatrixVec1[i][j]);
        }
        //std::cout << std::endl;
    }

    for (size_t i = 0; i < Row2; ++i) {
        for (size_t j = 0; j < Col2; ++j) {
//            std::cout << MatrixVec2[i][j] << " ";
            smatrix2.insert(i, j, MatrixVec2[i][j]);
        }
        //std::cout << std::endl;
    }


    SparseMatrix result;
    std::list<Node> temp;
    switch (operation) {
        case '+':
            if (Row1 != Row2 || Col1!=Col2){
                std::cout<< "Invalid Input of Matrix Size"<< std::endl;
            }
            temp = result.add(smatrix1,smatrix2,Row1,Col1);
            for (auto &x: temp) {
                std::cout << x.row << " " << x.col << " " << x.data << " \n";
            }
            break;
        case '-':
            if (Row1 != Row2 || Col1!=Col2){
                std::cout<< "Invalid Input of Matrix Size"<< std::endl;
            }
            temp = result.subtract(smatrix1,smatrix2, Row1, Col1);
            for (auto &x: temp) {
                std::cout << x.row << " " << x.col << " " << x.data << " \n";
            }
            break;
        case '.':
            if(Col1==Row2) {
                temp = result.multiply(smatrix1,smatrix2, Row1, Col2);
            }
            else {
                std::cout<< "Invalid Input of Matrix Size"<< std::endl;
            }
            for (auto &x: temp) {
                std::cout << x.row << " " << x.col << " " << x.data << " \n";
            }
            break;
        case 't':
            temp = result.transpose(smatrix1, Row1, Col2);
            for (auto &x: temp) {
                std::cout << x.row << " " << x.col << " " << x.data << " \n";
            }
            break;
//        case 'd':
//            if (Row1 == Col1) {
//                if (Row1 > 2) {
//                    std::cout << "Matrix is too large. Please try with a smaller matrix." << std::endl;
//                } else {
//                    temp = result.determinant(smatrix1, Row1, Col1);
//                }
//            } else if (Row1 != Col1){
//                std::cout << "Matrix has to be square." << std::endl;
//            }
////            std::cout << temp << std::endl;
//            break;
//        case 'i':
//            temp = result.inverse(smatrix1, Row1, Col2);
//            break;
//        default:
//            if(Col1==Row2) {
//                temp = result.power(smatrix1, Row1, Col2, operation);            }
//            else {
//                std::cout<< "Invalid Input of Matrix Size"<< std::endl;
//            }
//            for (auto &x: temp) {
//                std::cout << x.row << " " << x.col << " " << x.data << " \n";
//            }
//            break;
    }
    return 0;
}
