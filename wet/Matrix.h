#ifndef MATRIX_H
#define MATRIX_H
#pragma once
#include <ostream>

#include "Utilities.h"

class Matrix {
private:
    int width = 0;
    int height = 0;
    int* matrix = new int[height*width];

public:
    Matrix(int height, int width, int init=0);
    Matrix() = default;
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
    Matrix& rotateClockwise();
    Matrix& rotateCounterClockwise();
    Matrix& transpose();
    static double CalcFrobeniusNorm(const Matrix& m);

    ~Matrix() = default;

};
Matrix operator*(int num, const Matrix& m);



#endif //MATRIX_H
