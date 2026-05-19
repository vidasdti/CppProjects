#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <iostream>
#include <vector>
#include <iomanip>
#include <stdexcept>

template <typename T>
class Matrix {

private:

    int rows;
    int cols;

    std::vector<std::vector<T>> data;

public:

    Matrix(int r, int c);

    int getRows() const;
    int getCols() const;

    void input();
    void print() const;

    T& at(int row, int col);
    const T& at(int row, int col) const;

    Matrix<T> operator+(
        const Matrix<T>& other
    ) const;

    Matrix<T> operator-(
        const Matrix<T>& other
    ) const;

    Matrix<T> operator*(
        const Matrix<T>& other
    ) const;

    Matrix<T> transpose() const;

    static Matrix<T> identity(int size);
};

#include "../src/Matrix.cpp"

#endif