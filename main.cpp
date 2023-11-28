#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

int main(int argc, char* argv[]) {
    std::ifstream Matrix1(argv[1]), Matrix2(argv[4]);
    char* row1=argv[2], *col1=argv[3], *row2=argv[5], *col2=(argv[6]), *operation=(argv[7]);
    std::vector<std::vector<int>> numbers;

    std::string line;
    while (std::getline(Matrix1, line)) {
        std::istringstream iss(line);
        int num;
        std::vector<int> lineNumbers;
        while (iss >> num) {
            lineNumbers.push_back(num);
        }
        numbers.push_back(lineNumbers);
    }
    Matrix1.close(); // Close the file

    for (size_t i = 0; i < numbers.size(); ++i) {
        for (size_t j = 0; j < numbers[i].size(); ++j) {
            std::cout << numbers[i][j] << " ";
        }
        std::cout << std::endl;
    }

    switch (*operation) {
        case '+':
            //addition
            break;
        case '-':
            //subtraction
            break;
        case '*':
            //multiplication
            break;
        case '/':
            //division
            break;
    }
    return 0;
    //test

}