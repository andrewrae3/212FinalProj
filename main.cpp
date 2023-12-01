#include <iostream>
#include <vector>
#include <sstream>
#include <list>
#include "matrix.h"
#include <windows.h>

void SetOutputText(const std::list<Node>& outputData);
void SaveMatrixFromGUI(HWND matrixEdit, std::vector<std::vector<int>>& matrix);

const char *windowClassName = "Matrix Calculator";
HWND editMatrix1, editMatrix2, output1;
HWND btnMultiply, btnAdd, btnSubtract, btnTranspose, btnClear;
SparseMatrix result;
std::list<Node> temp;
int Row1, Col1, Row2, Col2;
std::ostringstream oss;

LRESULT CALLBACK WindowProcedure(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam) {
    switch (message) {
        case WM_CREATE:
// Create label for Matrix 1
            CreateWindow("STATIC", "Matrix 1:",
                         WS_CHILD | WS_VISIBLE,
                         50, 30, 100, 20,
                         hwnd, NULL, GetModuleHandle(NULL), NULL);

            // Create first matrix input box
            editMatrix1 = CreateWindowEx(WS_EX_CLIENTEDGE, "EDIT", "",
                                         WS_CHILD | WS_VISIBLE | ES_MULTILINE | ES_AUTOVSCROLL | ES_AUTOHSCROLL,
                                         50, 50, 200, 200,
                                         hwnd, NULL, GetModuleHandle(NULL), NULL);

            // Create label for Matrix 2
            CreateWindow("STATIC", "Matrix 2:",
                         WS_CHILD | WS_VISIBLE,
                         300, 30, 100, 20,
                         hwnd, NULL, GetModuleHandle(NULL), NULL);

            // Create second matrix input box
            editMatrix2 = CreateWindowEx(WS_EX_CLIENTEDGE, "EDIT", "",
                                         WS_CHILD | WS_VISIBLE | ES_MULTILINE | ES_AUTOVSCROLL | ES_AUTOHSCROLL,
                                         300, 50, 200, 200,
                                         hwnd, NULL, GetModuleHandle(NULL), NULL);
            // Create 'Multiply' button
            btnMultiply = CreateWindow("BUTTON", "Multiply",
                                       WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
                                       50, 280, 100, 30,
                                       hwnd, (HMENU)1, GetModuleHandle(NULL), NULL);

            // Create 'Add' button
            btnAdd = CreateWindow("BUTTON", "Add",
                                  WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
                                  170, 280, 100, 30,
                                  hwnd, (HMENU)2, GetModuleHandle(NULL), NULL);

            // Create 'Subtract' button
            btnSubtract = CreateWindow("BUTTON", "Subtract",
                                       WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
                                       290, 280, 100, 30,
                                       hwnd, (HMENU)3, GetModuleHandle(NULL), NULL);

            // Create 'Transpose' button
            btnTranspose = CreateWindow("BUTTON", "Transpose",
                                        WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
                                        410, 280, 100, 30,
                                        hwnd, (HMENU)4, GetModuleHandle(NULL), NULL);

            btnClear = CreateWindow("BUTTON", "Clear",
                                         WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
                                         530, 280, 100, 30,
                                         hwnd, (HMENU)5, GetModuleHandle(NULL), NULL);

            CreateWindow("STATIC", "Output:",
                         WS_CHILD | WS_VISIBLE,
                         550, 30, 100, 20,
                         hwnd, NULL, GetModuleHandle(NULL), NULL);
            output1 = CreateWindowEx(WS_EX_CLIENTEDGE, "EDIT", "",
                                     WS_CHILD | WS_VISIBLE | ES_MULTILINE | ES_AUTOVSCROLL | ES_AUTOHSCROLL,
                                     550, 50, 200, 200,
                                     hwnd, NULL, GetModuleHandle(NULL), NULL);
            break;
        case WM_COMMAND:
            switch (LOWORD(wParam)) {
                case 1: // Multiply button clicked
                    // Perform multiplication operation
                    {
                        result.clear();
                        std::vector<std::vector<int>> MatrixVec1;
                        std::vector<std::vector<int>> MatrixVec2;
                        SaveMatrixFromGUI(editMatrix1, MatrixVec1);
                        SaveMatrixFromGUI(editMatrix2, MatrixVec2);

                        // Set Row1, Col1, Row2, Col2 based on the sizes of MatrixVec1 and MatrixVec2
                        Row1 = MatrixVec1.size();
                        Col1 = (Row1 > 0) ? MatrixVec1[0].size() : 0;
                        Row2 = MatrixVec2.size();
                        Col2 = (Row2 > 0) ? MatrixVec2[0].size() : 0;

                        // Perform matrix operations if sizes are valid
                        if (Col1 == Row2) {
                            SparseMatrix smatrix1;
                            SparseMatrix smatrix2;

                            // Convert MatrixVec1 to smatrix1
                            for (size_t i = 0; i < Row1; ++i) {
                                for (size_t j = 0; j < Col1; ++j) {
                                    smatrix1.insert(i, j, MatrixVec1[i][j]);
                                }
                            }

                            // Convert MatrixVec2 to smatrix2
                            for (size_t i = 0; i < Row2; ++i) {
                                for (size_t j = 0; j < Col2; ++j) {
                                    smatrix2.insert(i, j, MatrixVec2[i][j]);
                                }
                            }

                            // Perform multiplication operation
                            temp = result.multiply(smatrix1, smatrix2, Row1, Col2);
                            SetOutputText(temp);
                        } else {
                            // Handle invalid matrix sizes
                            MessageBox(hwnd, "Invalid Matrix Sizes for Multiplication", "Error", MB_ICONERROR | MB_OK);
                        }
                    }
                    break;
                case 2: // Add button clicked
                    // Perform addition operation
                    {
                        result.clear();
                        std::vector<std::vector<int>> MatrixVec1;
                        std::vector<std::vector<int>> MatrixVec2;
                        SaveMatrixFromGUI(editMatrix1, MatrixVec1);
                        SaveMatrixFromGUI(editMatrix2, MatrixVec2);

                        int Row1 = MatrixVec1.size();
                        int Col1 = (Row1 > 0) ? MatrixVec1[0].size() : 0;
                        int Row2 = MatrixVec2.size();
                        int Col2 = (Row2 > 0) ? MatrixVec2[0].size() : 0;

                        if (Row1 != Row2 || Col1 != Col2) {
                            MessageBox(hwnd, "Invalid Input of Matrix Size", "Error", MB_ICONERROR | MB_OK);
                        } else {
                            SparseMatrix smatrix1;
                            SparseMatrix smatrix2;

                            for (size_t i = 0; i < Row1; ++i) {
                                for (size_t j = 0; j < Col1; ++j) {
                                    smatrix1.insert(i, j, MatrixVec1[i][j]);
                                    smatrix2.insert(i, j, MatrixVec2[i][j]);
                                }
                            }

                            temp = result.add(smatrix1, smatrix2, Row1, Col1);
                            SetOutputText(temp);
                        }
                    }
                    break;
                case 3: // Subtract button clicked
                    // Perform subtraction operation
                    {
                        result.clear();
                        std::vector<std::vector<int>> MatrixVec1;
                        std::vector<std::vector<int>> MatrixVec2;
                        SaveMatrixFromGUI(editMatrix1, MatrixVec1);
                        SaveMatrixFromGUI(editMatrix2, MatrixVec2);

                        int Row1 = MatrixVec1.size();
                        int Col1 = (Row1 > 0) ? MatrixVec1[0].size() : 0;
                        int Row2 = MatrixVec2.size();
                        int Col2 = (Row2 > 0) ? MatrixVec2[0].size() : 0;

                        if (Row1 != Row2 || Col1 != Col2) {
                            MessageBox(hwnd, "Invalid Input of Matrix Size", "Error", MB_ICONERROR | MB_OK);
                        } else {
                            SparseMatrix smatrix1;
                            SparseMatrix smatrix2;

                            for (size_t i = 0; i < Row1; ++i) {
                                for (size_t j = 0; j < Col1; ++j) {
                                    smatrix1.insert(i, j, MatrixVec1[i][j]);
                                    smatrix2.insert(i, j, MatrixVec2[i][j]);
                                }
                            }

                            temp = result.subtract(smatrix1, smatrix2, Row1, Col1);
                            SetOutputText(temp);
                        }
                    }
                    break;
                case 4: // Transpose button clicked
                    // Perform transpose operation
                    {
                        result.clear();
                        std::vector<std::vector<int>> MatrixVec1;
                        std::vector<std::vector<int>> MatrixVec2;
                        SaveMatrixFromGUI(editMatrix1, MatrixVec1);
                        SaveMatrixFromGUI(editMatrix2, MatrixVec2);

                        int Row1 = MatrixVec1.size();
                        int Col1 = (Row1 > 0) ? MatrixVec1[0].size() : 0;

                            SparseMatrix smatrix1;

                            // Convert MatrixVec1 to smatrix1
                            for (size_t i = 0; i < Row1; ++i) {
                                for (size_t j = 0; j < Col1; ++j) {
                                    smatrix1.insert(i, j, MatrixVec1[i][j]);
                                }
                            }

                            temp = result.transpose(smatrix1, Row1, Col1);
                            SetOutputText(temp);
                    }
                    break;
                case 5: // Clear button clicked
                    // Clear the values in the output text window
                    SetWindowText(output1, ""); // Clear the text in output1
                    // Clear the values in the output list (temp)
                    temp.clear(); // This line clears the 'temp' list
                    // Clear the values in the stringstream (oss)
                    oss.str(""); // Clear the content in the ostringstream
                    oss.clear(); // Reset error flags in the ostringstream
                    // Clear other lists or data structures if present
                    // For example, clearing the 'result' SparseMatrix
                    result.clear();
                    break;
            }
            break;
        case WM_DESTROY:
            PostQuitMessage(0);
            break;
        default:
            return DefWindowProc(hwnd, message, wParam, lParam);
    }
    return 0;
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    WNDCLASS wc = {0};

    wc.lpfnWndProc = WindowProcedure;
    wc.hInstance = hInstance;
    wc.lpszClassName = windowClassName;
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);

    RegisterClass(&wc);

    HWND hwnd = CreateWindowEx(
            0,
            windowClassName,
            "Matrix Operations",
            WS_OVERLAPPEDWINDOW,
            CW_USEDEFAULT, CW_USEDEFAULT,
            800, 400,
            NULL, NULL, hInstance, NULL);

    if (hwnd == NULL) {
        MessageBox(NULL, "Window creation failed!", "Error", MB_ICONERROR | MB_OK);
        return 0;
    }

    ShowWindow(hwnd, nCmdShow);
    UpdateWindow(hwnd);

    MSG msg = {0};
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return msg.wParam;
}

void SetOutputText(const std::list<Node>& outputData) {
    for (const auto& node : outputData) {
        oss << "Row: " << node.row << ", Column: " << node.col << ", Value: " << node.data << "\r\n";
    }
    // Get the text from the output stream
    std::string outputText = oss.str();

    // Set the text in the output1 window
    SetWindowText(output1, outputText.c_str());
}

// Function to save matrix values from GUI to a double vector
void SaveMatrixFromGUI(HWND matrixEdit, std::vector<std::vector<int>>& matrix) {
    int rows, cols;
    std::vector<int> rowValues;

    // Get the number of rows and columns in the matrix
    rows = SendMessage(matrixEdit, EM_GETLINECOUNT, 0, 0);
    cols = SendMessage(matrixEdit, EM_LINELENGTH, 0, 0);

    // Iterate through each row of the matrix
    for (int i = 0; i < rows; ++i) {
        // Clear the row values vector for the new row
        rowValues.clear();

        // Get the text of the current row
        char buffer[1000];
        SendMessage(matrixEdit, EM_GETLINE, i, (LPARAM)buffer);

        // Tokenize the row text to extract individual values
        std::istringstream iss(buffer);
        int value;
        while (iss >> value) {
            // Store each value in the rowValues vector
            rowValues.push_back(value);
        }

        // Push the rowValues vector (representing a row) into the matrix
        matrix.push_back(rowValues);
    }
}
