#ifndef MATRIX_H
#define MATRIX_H
#pragma once
#include <vector>

#include "Utilities.cpp"

class Matrix {
private:
    int width;
    int height;
    int* matrix = new int[height*width];

public:
    Matrix(int height, int width, int init=0);
    Matrix(const Matrix& m);
    Matrix& operator=(const Matrix& m);
    int getHeight() const;
    int getWidth() const;
    int* getMatrix();

    int& operator()(int value1, int value2);
    const int& operator()(int value1, int value2) const;
    friend std::ostream& operator<<(std::ostream& os, const Matrix& m);
    Matrix operator+(const Matrix& m) const;
    Matrix& operator+=(const Matrix& m);
    Matrix operator*(const Matrix& m) const;
    Matrix operator-(const Matrix& m) const;
    Matrix& operator-();
    Matrix& operator-=(const Matrix& m);
    Matrix operator*(int num) const;
    Matrix& operator*=(const Matrix& m);
    Matrix& operator*=(int num);
    bool operator==(const Matrix& m);
    bool operator!=(const Matrix& m);
    Matrix& rotateClockWise();
    Matrix& rotateCounterClockWise();
    Matrix& transpose();
    static double CalcFrobeniusNorm(const Matrix& m);

    Matrix() = default;
    ~Matrix() = default;

};


#endif //MATRIX_H
