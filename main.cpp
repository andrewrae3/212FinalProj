#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

int main(int argc, char* argv[]) {
    std::ifstream inputFile(argv[1]);
    std::vector<std::vector<int>> numbers;

    std::string line;
    while (std::getline(inputFile, line)) {
        std::istringstream iss(line);
        double num;
        std::vector<int> lineNumbers;
        while (iss >> num) {
            lineNumbers.push_back(num);
        }
        numbers.push_back(lineNumbers);
    }
    inputFile.close(); // Close the file

}