#ifndef MATRIX_CPP
#define MATRIX_CPP

#include "../include/Matrix.hpp"

template <typename T>
Matrix<T>::Matrix(int r, int c)
    : rows(r),
      cols(c),
      data(r, std::vector<T>(c, 0)) {}

template <typename T>
int Matrix<T>::getRows() const {
    return rows;
}

template <typename T>
int Matrix<T>::getCols() const {
    return cols;
}

template <typename T>
void Matrix<T>::input() {

    for (int i = 0; i < rows; ++i) {

        for (int j = 0; j < cols; ++j) {

            std::cout
                << "[" << i
                << "][" << j
                << "] = ";

            std::cin >> data[i][j];
        }
    }
}

template <typename T>
void Matrix<T>::print() const {

    for (int i = 0; i < rows; ++i) {

        for (int j = 0; j < cols; ++j) {

            std::cout
                << std::setw(8)
                << data[i][j];
        }

        std::cout << '\n';
    }
}

template <typename T>
T& Matrix<T>::at(int row, int col) {

    if (
        row >= rows ||
        col >= cols
    ) {

        throw std::out_of_range(
            "Index out of range"
        );
    }

    return data[row][col];
}

template <typename T>
const T& Matrix<T>::at(
    int row,
    int col
) const {

    if (
        row >= rows ||
        col >= cols
    ) {

        throw std::out_of_range(
            "Index out of range"
        );
    }

    return data[row][col];
}

template <typename T>
Matrix<T> Matrix<T>::operator+(
    const Matrix<T>& other
) const {

    if (
        rows != other.rows ||
        cols != other.cols
    ) {

        throw std::invalid_argument(
            "Matrix sizes must match"
        );
    }

    Matrix<T> result(rows, cols);

    for (int i = 0; i < rows; ++i) {

        for (int j = 0; j < cols; ++j) {

            result.data[i][j] =
                data[i][j] +
                other.data[i][j];
        }
    }

    return result;
}

template <typename T>
Matrix<T> Matrix<T>::operator-(
    const Matrix<T>& other
) const {

    if (
        rows != other.rows ||
        cols != other.cols
    ) {

        throw std::invalid_argument(
            "Matrix sizes must match"
        );
    }

    Matrix<T> result(rows, cols);

    for (int i = 0; i < rows; ++i) {

        for (int j = 0; j < cols; ++j) {

            result.data[i][j] =
                data[i][j] -
                other.data[i][j];
        }
    }

    return result;
}

template <typename T>
Matrix<T> Matrix<T>::operator*(
    const Matrix<T>& other
) const {

    if (cols != other.rows) {

        throw std::invalid_argument(
            "Invalid matrix dimensions"
        );
    }

    Matrix<T> result(rows, other.cols);

    for (int i = 0; i < rows; ++i) {

        for (int j = 0; j < other.cols; ++j) {

            for (int k = 0; k < cols; ++k) {

                result.data[i][j] +=
                    data[i][k] *
                    other.data[k][j];
            }
        }
    }

    return result;
}

template <typename T>
Matrix<T> Matrix<T>::transpose() const {

    Matrix<T> result(cols, rows);

    for (int i = 0; i < rows; ++i) {

        for (int j = 0; j < cols; ++j) {

            result.data[j][i] =
                data[i][j];
        }
    }

    return result;
}

template <typename T>
Matrix<T> Matrix<T>::identity(
    int size
) {

    Matrix<T> result(size, size);

    for (int i = 0; i < size; ++i) {

        result.data[i][i] = 1;
    }

    return result;
}

#endif