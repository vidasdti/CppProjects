#include "../include/Matrix.hpp"

using namespace std;

int main() {

    Matrix<int> A(2, 2);
    Matrix<int> B(2, 2);

    A.at(0,0) = 1;
    A.at(0,1) = 2;
    A.at(1,0) = 3;
    A.at(1,1) = 4;

    B.at(0,0) = 5;
    B.at(0,1) = 6;
    B.at(1,0) = 7;
    B.at(1,1) = 8;

    Matrix<int> C = A + B;

    cout << "Test Addition:\n";
    C.print();

    Matrix<int> D = A * B;

    cout << "\nTest Multiplication:\n";
    D.print();

    return 0;
}