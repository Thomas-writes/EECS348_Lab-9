#ifndef __MATRIX_HPP__
#define __MATRIX_HPP__

#include <vector>

template <typename T>
class Matrix {
public:
    std::vector<std::vector<T>> data; // creates a member variable that stores all the matrix data - not sure why this wasn't included in the code we were given
    Matrix(std::size_t N);
    Matrix(std::vector<std::vector<T>> nums);

    Matrix operator+(const Matrix &rhs) const;
    Matrix operator*(const Matrix &rhs) const;
    void set_value(std::size_t i, std::size_t j, T n);
    T get_value(std::size_t i, std::size_t j) const;
    int get_size() const;
    T sum_diagonal_major() const;
    T sum_diagonal_minor() const;
    void swap_rows(std::size_t r1, std::size_t r2);
    void swap_cols(std::size_t c1, std::size_t c2);
    void print_matrix() const;
};

#include "matrix.tpp"
#endif // __MATRIX_HPP__