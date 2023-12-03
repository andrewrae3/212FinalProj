# 212FinalProj

For our final project, we implemented sparse matrices with linked lists. We also implemented a GUI to turn it into somewhat of a matrix calculator. 

Please note that because the GUI was made using the windows.h library, a windows computer is needed to run our code.

To run our code, you need to add windows.h to your external libraries. 

To compile our code:
g++ main.cpp matrix.cpp -o MatrixCalculator -mwindows

To run our code:
./MatrixCalculator 

This should bring up our GUI, which has two boxes, Matrix 1 and Matrix 2 to input the desired matrices. Each element in the matrice should be separated by a whitespace, eg.
0 0 1 2
1 0 2 4
45 3 4 1

Once you have input the desired matrices, you can perform one of the operations listed in the GUI: Addition, Subtraction Multiplication, or transpose a matrix. Note that transpose will only transpose the matrix input into Matrix 1. If the operation cannot be performed because of invalid matrix dimensions, an error message will appear. 

After choosing an operation, the output will appear in the output box, showing the row and column of each element of the output. After each operatio is performed, click the clear button to reset the calculator. 