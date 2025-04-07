//chatgpt was used for matrix operations and to figure out which libraries to use and how to use them
//I also went back and forth with it for syntax corrections

#include <iostream> // allows for input output stream access
#include <fstream> // allows for file to be read as a stream aka line by line
#include "Matrix.hpp" // adds the matrix header file that has the predefined functions 

int main() { // starts main 
    std::string filename; //create a variable for the filename
    std::cout << "Enter the filename: "; // output to the terminal in preperation for the filename
    std::cin >> filename;  // Get the filename from the user

    std::ifstream file(filename);  // open the file as a filestream variable type
    if (!file) { // checks if the file exists
        std::cerr << "Failed to open file!" << std::endl; // outputs an error that the file could not be opened
        return 1;  // Return with error code if the file cannot be opened - ends main
    }

    int N;  // integer variable for the size of the matrix
    file >> N;  // get the value of the matrix size from the file
    std::cout << "Matrix size: " << N << std::endl; //output the matrix size to the terminal

    std::vector<std::vector<int>> matrix_data_1(N, std::vector<int>(N)); //declares a new 2d matrix with vectors of size N
    for (int i = 0; i < N; i++) { // this is a loop used until i = N
        for (int j = 0; j < N; j++) { // this is a loop used until j = N
            file >> matrix_data_1[i][j]; // store the data of the file character by character in the ith row and jth column
        }
    }

    // Read the second matrix
    std::vector<std::vector<int>> matrix_data_2(N, std::vector<int>(N)); //declares a new 2d matrix with vectors of size N
    for (int i = 0; i < N; i++) { // this is a loop used until i = N
        for (int j = 0; j < N; j++) { // this is a loop used until j = N
            file >> matrix_data_2[i][j]; // store the data of the file character by character in the ith row and jth column
        }
    }
    
    // create new matrix objects with the data we just got from the file
    Matrix matrix1(matrix_data_1);
    Matrix matrix2(matrix_data_2);

    //the 5 lines below are for printing the matrices
    std::cout << "\nMatrix 1:" << std::endl;
    matrix1.print_matrix();
    
    std::cout << "\nMatrix 2:" << std::endl;
    matrix2.print_matrix();

    // the 3 lines below are for adding the matrices and displaying to the terminal
    Matrix result = matrix1 + matrix2;
    std::cout << "\nMatrix 1 + Matrix 2:" << std::endl;
    result.print_matrix();

    // the 3 lines below are for multiplying the matrices and displaying to the terminal
    result = matrix1 * matrix2;
    std::cout << "\nMatrix 1 * Matrix 2:" << std::endl;
    result.print_matrix();


    size_t row1, row2;//initialize a row1 and row2 size_t variable
    std::cout << "\nEnter two row indices to swap: ";//ask the user for 2 inputs
    std::cin >> row1 >> row2;//store the 2 inputs in row1 and row 2
    
    if (row1 < N && row2 < N) {// check if the row indices are valid
        matrix1.swap_rows(row1, row2);  // swap the rows
        std::cout << "\nMatrix after swapping rows " << row1 << " and " << row2 << ":" << std::endl; //output the rows that were swapped
        matrix1.print_matrix();  // output the updated matrix
    } else {//go here if the row indices are invalid
        std::cerr << "Invalid row indices!" << std::endl;  //lets the user know there was an error with their input
    }

    // Swap columns example
    size_t col1, col2; //initialize a col1 and col2 size_t variable
    std::cout << "\nEnter two column indices to swap: ";//ask the user for 2 inputs
    std::cin >> col1 >> col2; // store the 2 inputs

    if (col1 < N && col2 < N) {//make sure the columns are valid indices
        matrix1.swap_cols(col1, col2);  // swap the columns
        std::cout << "\nMatrix after swapping columns " << col1 << " and " << col2 << ":" << std::endl;//output the columns that were swapped
        matrix1.print_matrix();  // print the finalized matrix
    } else {
        std::cerr << "Invalid column indices!" << std::endl;  // print an error message if the columns are invalid
    }

    // Update matrix element example
    size_t row, col;//initialize new size_t variables row and col
    int new_value;// create an integer new_val for the matrix
    std::cout << "\nEnter row, column, and new value to update the matrix: "; //ask the user for three inputs
    std::cin >> row >> col >> new_value;//get all three inputs from the user
    
    if (row < N && col < N) {// check to make sure the indices are valid
        matrix1.set_value(row, col, new_value);  // update the matrix at the user requested values
        std::cout << "\nMatrix after updating element at (" << row << ", " << col << "):" << std::endl;//let the user know what they changed
        matrix1.print_matrix();  // print the updated matrix
    } else {
        std::cerr << "Invalid row or column index!" << std::endl;  // let the user know there is an error in their input
    }

    return 0;
}