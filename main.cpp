#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <list>


int main(int argc, char* argv[]) {
    std::ifstream Matrix1(argv[1]), Matrix2(argv[4]);
    char* Row1 = argv[2];
    char* Col1 = argv[3];
    char* Row2 = argv[5];
    char* Col2 = argv[6];   
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

}
