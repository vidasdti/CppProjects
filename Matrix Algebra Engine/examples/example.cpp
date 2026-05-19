#include "../include/Matrix.hpp"

using namespace std;

int main() {

    Matrix<int> A(2, 2);
    Matrix<int> B(2, 2);

    cout << "Enter Matrix A:\n";
    A.input();

    cout << "\nEnter Matrix B:\n";
    B.input();

    cout << "\nMatrix A:\n";
    A.print();

    cout << "\nMatrix B:\n";
    B.print();

    Matrix<int> C = A + B;

    cout << "\nA + B:\n";
    C.print();

    Matrix<int> D = A * B;

    cout << "\nA * B:\n";
    D.print();

    Matrix<int> T = A.transpose();

    cout << "\nTranspose of A:\n";
    T.print();

    return 0;
}