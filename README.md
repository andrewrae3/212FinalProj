<h2 align = "center" > CSC212 Final Project </h2>

For our final project, we implemented sparse matrices with linked lists. We also implemented a GUI to turn it into somewhat of a matrix calculator. 

Please note that because the GUI was made using the windows.h library, a windows computer is needed to run our code. Also note for some reason (we think it has to do with the CMake) currently our code for the GUI only works on CLion. 

Also note that each matrix operation has specific dimension restrictions for the matrix inputs. For addition and subtraction, the matrices inputted have to be of the same dimensions. For example if matrix1 is a 3x4 matrix, matrix2 must also be a 3x4 matrix. For multiplication, the number of columns in the first matrix must be equal to the number of rows in the second matrix. For example, given matrix1 of size 3x4, matrix2 must be 4x5 matrix. 

<h2 align = "center" > For Windows </h2>

Before you can compile the code, you must add matrix.cpp to the CMake. To do this, in Clion open the project, double click on matrix.cpp, and it should bring up the class file. In a yellow bar above the code, you will see a popup that says "This file does not belong to any project target; code insight features might not work properly." To the right in the popup, in blue it says "Add to CMake Project". Click this, then click OK. There is an image below showing the add to Cmake Project. Now the code will compile correctly. To run our code, you can simply press the Run button in the toolbar. Otherwise, you can run the following terminal commands.

![image](https://github.com/andrewrae3/212FinalProj/blob/e54ee20a2d7efca614e568807c26306e31159836/Images/cmake.png)

To compile our code:

```
g++ main.cpp matrix.cpp -o MatrixCalculator -mwindows
```

To run our code:

```
./MatrixCalculator 
```

This should bring up our GUI, which has two boxes, Matrix 1 and Matrix 2 to input the desired matrices. Below is a picture of the GUI.
![image](https://github.com/andrewrae3/212FinalProj/blob/1ca107973204595ee55dd8d2ba85dc930461f355/Images/Screenshot%202023-12-04%20142838.png)
Each element in the matrice should be separated by a whitespace, eg.

```
0 0 1 2
1 0 2 4
45 3 4 1
```

Once you have input the desired matrices, you can perform one of the operations listed in the GUI: Addition, Subtraction Multiplication, or transpose a matrix. Note that transpose will only transpose the matrix input into Matrix 1. If the operation cannot be performed because of invalid matrix dimensions, an error message will appear. 

After choosing an operation, the output will appear in the output box, showing the row and column of each element of the output. After each operation is performed, click the clear button to reset the calculator. 

<h2 align = "center" > For Mac </h2>

To run our code on Mac, there will be no GUI. Instead, input will be taken in through text files and CLA. Note that you have to enter the 'Iterations' directory. In the cmake-build-debug directory, you will see two text files, matrix1.txt and matrix2.txt. The text files will contain the matrices that you wish to input. When inputting a matrix, each element should be separated by whitespace.
For example:

```
0 0 1 2
1 0 2 4
45 3 4 1
```

To compile our code:

```
g++ main1.cpp matrix1.cpp -o matrix
```

To run our code:

```
./matrix matrix1.txt m1 n1 operation matrix2.txt m2 n2 
```

Where m1 n1 is the number of rows and columns in matrix1, m2 n2 is the number of rows and columns in matrix2, and operation is the matrix operation you wish to perform. 

Valid operations are:

For addition: +

For subtraction: -

For multiplication: .

For transpose: t

Note that transpose will only transpose the input of matrix1.
