//chatgpt was used for matrix operations and to figure out which libraries to use and how to use them
//I also went back and forth with it for syntax corrections
//it also helped with erros because I had not used stdexcept before
#include "matrix.hpp" //include the header file so no errors relating to function declarations occur
#include <vector> //include vectors since they are the basis for matrices
#include <stdexcept> //include an exceptions library for errors
#include <iostream> // include iostream for the print_matrix() function

// implementation of functions declared in matrix.hpp goes here
// function definitions for a class have their names prefixed with
// the class name and "::"

template <typename T>
Matrix<T>::Matrix(std::size_t N) { // creates a variable that stores a vector of vectors of ints
    if (N <= 0) { //checks if the size of the matrix is valid
        throw std::invalid_argument("Matrix size must be greater than 0."); //throws an error that the matrix is invalud
    }
    data.resize(N, std::vector<T>(N, 0)); // initialized an empty vector of vectors of size N with 0 in all places
}

template <typename T>
Matrix<T>::Matrix(std::vector<std::vector<T>> nums) { //initialize the values of the matrix
    data = nums; // sets the member variable data to the input nums 
}

template <typename T>
Matrix<T> Matrix<T>::operator+(const Matrix &rhs) const {// this is called when it is Matrix Object + Matrix Object
    int N = get_size(); // gets the size of this.matrix

    Matrix result(N);//create a new empty matix of size N for the result
    //this is 2 loops used to access every element of the 2d array and add each individual one and store in the corresponding value
    for (int i = 0; i < N; i++){ 
        for (int j = 0; j < N; j++){
            result.data[i][j] = data[i][j] + rhs.data[i][j];
        }
    }
    return result; //returns the result matrix 
}

template <typename T>
Matrix<T> Matrix<T>::operator*(const Matrix &rhs) const {// this is called when it is Matrix Object * Matrix Object
    int N = get_size(); // gets the size of this.matrix

    Matrix result(N); // create a new matrix of size N for the result
    //the loops below is the formula for multiplying matrices
    //I looked this up because there are a million resources that have it
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            for (int k = 0; k < N; k++){
                result.data[i][j] += data[i][k] * rhs.data[k][j];
            }
        }
    }
    return result;//returns the resulting matrix from the multiplication
}

template <typename T>
void Matrix<T>::set_value(size_t i, size_t j, T n){//this is to set a value in the matrix
    if (i >= get_size() || j >= get_size()) { // this is error checking for the matrix
        throw std::out_of_range("Index out of bounds.");//raise an error for indices being invalid
    }
    data[i][j] = n; //update the value at the user input values
}

template <typename T>
T Matrix<T>::get_value(size_t i, size_t j) const{// get the value at the requested inputs
    if (i >= get_size() || j >= get_size()) { // make sure the indices are valid
        throw std::out_of_range("Index out of bounds."); //if the indices are invalid output that to the terminal
    }
    return data[i][j];// return the value at the indices provided
}

template <typename T>
int Matrix<T>::get_size() const{//returns the size of the matrix
    return data.size();//returns the size of the matrix
}

template <typename T>
T Matrix<T>::sum_diagonal_major() const {//adds the sum of the major diagonal of the matrix
    int sum = 0;//new variable sum is 0
    int N = get_size(); // n is the size of the object
    //the loop below adds all the values of the major diagonal
    for (int i = 0; i < N; i++) {
        sum += data[i][i];
    }
    return sum;//returns the major diagonal sum
};

template <typename T>
T Matrix<T>::sum_diagonal_minor() const {//adds the sum of the minor diagonal of the matrix
    int sum = 0;//new variable sum is 0
    int N = get_size();// n is the size of the object
    //the loop below adds all the valued of the minor diagonal
    for (int i = 0; i < N; i++) {
        sum += data[i][N - i - 1];
    }
    return sum;//returns the minor diagonal sum
};


//chatgpt taught me about the swap function used for these
template <typename T>
void Matrix<T>::swap_rows(std::size_t r1, std::size_t r2){//takes two size_t inputs and swaps the rows
    int N = get_size();// stores the size of the matrix in N
    if (r1 >= N || r2 >= N) { // makes sure the rows are valid
        throw std::out_of_range("Row index out of bounds."); // raises an error if the rows are invalid
    }
    std::swap(data[r1], data[r2]);//swaps row 1 and row 2 variables using the build in swap
};

template <typename T>    
void Matrix<T>::swap_cols(std::size_t c1, std::size_t c2){//takes two size_t inputs and swaps the cols
    int N = get_size(); // stores the size of the matrix in N
    if (c1 >= N || c2 >= N) {// makes sure the cols are valid
        throw std::out_of_range("Column index out of bounds."); // raises an error if the cols are invalid
    }
    //uses a loop to go to each element in the column and swap each one individually using the swap function
    for (int i = 0; i < N; i++) {
        std::swap(data[i][c1], data[i][c2]);
    }
};

template <typename T>
void Matrix<T>::print_matrix() const {//outputs the matrix to the terminal
    //this was done with the help of chatgpt
    //this iterates over each row in data
    for (const auto &row : data) {// const insures row is not modified in the loop auto makes sure the compiler recognizes it as a vector data is the entire matrix and row is passed as a reference
        for (const T& val : row) {//this iterates over each val in a row
            std::cout << val << " ";//this outputs the val to the terminal
        }
        std::cout << "\n";//this makes it so each row is on a differnt line
    }
}
