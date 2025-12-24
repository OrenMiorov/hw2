#include "Matrix.h"
#include <iostream>
#include "Utilities.h"
#include "cmath"

Matrix::Matrix(int height, int width, int init) : width(width), height(height) {
    if (height <= 0 || width <= 0)
        exitWithError(MatamErrorType::OutOfBounds);
    int* temp = new int[height*width];
    for (int i = 0; i < height*width; i++) {
        temp[i] = init;
    }
    this->matrix = temp;
}

Matrix::Matrix(const Matrix &m): width(m.width), height(m.height), matrix(new int[m.height * m.width]) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            (*this)(i,j) = m(i,j);
        }
    }
}

Matrix::~Matrix() {
    delete[] matrix;
}

Matrix &Matrix::operator=(const Matrix &m) {
    if (this == &m) return *this;
    delete[] matrix;
    height = m.height;
    width = m.width;
    matrix = new int[height*width];
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            (*this)(i,j) = m(i,j);
        }
    }
    return *this;
}


int Matrix::getHeight() const { return this->height; }

int Matrix::getWidth() const { return this->width; }

int* Matrix::getMatrix() { return this->matrix; }

int& Matrix::operator()(int h, int w) {
    if (h >= height || w >= width || h < 0 || w < 0)
        exitWithError(MatamErrorType::OutOfBounds);
    return this->matrix[h*width+w];
}

const int &Matrix::operator()(int h, int w) const {
    if (h >= height || w >= width || h < 0 || w < 0)
        exitWithError(MatamErrorType::OutOfBounds);
    return this->matrix[h*width+w];
}

std::ostream& operator<<(std::ostream& os, const Matrix& m) {
    for (int i = 0; i < m.height; i++) {
        os << "|";
        for (int j = 0; j < m.width; j++) {
            os << m(i,j) << "|";
        }
        os << std::endl;
    }
    return os;
}

Matrix Matrix::operator+(const Matrix &m) const {
    if (height != m.height || width != m.width)
        exitWithError(MatamErrorType::UnmatchedSizes);
    Matrix res(height,width);
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            res(i,j) = (*this)(i,j) + m(i,j);
        }
    }
    return res;
}

Matrix& Matrix::operator+=(const Matrix &m) {
    *this = *this + m;
    return *this;
}

Matrix Matrix::operator-(const Matrix &m) const {
    if (height != m.height || width != m.width)
        exitWithError(MatamErrorType::UnmatchedSizes);
    Matrix res(height,width);
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            res(i,j) = (*this)(i,j) - m(i,j);
        }
    }
    return res;
}

Matrix Matrix::operator-() const {
    Matrix res(height, width);
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            res(i,j) = -1 * (*this)(i,j);
        }
    }
    return res;
}

Matrix &Matrix::operator-=(const Matrix &m) {
    *this = *this - m;
    return *this;
}

Matrix Matrix::operator*(const Matrix &m) const {
    if (width != m.height)
        exitWithError(MatamErrorType::UnmatchedSizes);
    Matrix res(height,m.width);
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < m.width; j++) {
            for (int k = 0; k < width; k++) {
                res(i,j) += (*this)(i,k) * m(k,j);
            }
        }
    }
    return res;
}

Matrix operator*(int num, const Matrix& m) {
    return m*num;
}

Matrix Matrix::operator*(int num) const {
    Matrix res(height,width);
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            res(i,j) = (*this)(i,j) * num;
        }
    }
    return res;
}

Matrix &Matrix::operator*=(const Matrix &m) {
    *this = *this * m;
    return *this;
}

Matrix &Matrix::operator*=(int num) {
    *this = *this * num;
    return *this;
}

bool Matrix::operator==(const Matrix& m) const {
    if (height != m.height || width != m.width) return false;
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if ((*this)(i,j) != m(i,j)) return false;
        }
    }
    return true;
}

bool Matrix::operator!=(const Matrix& m) const {
    return !(*this == m);
}

Matrix Matrix::rotateClockwise() const {
    Matrix res(width, height);
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            res(j, height - i - 1) = (*this)(i, j);
        }
    }
    return res;
}

Matrix Matrix::rotateCounterClockwise() const {
    Matrix res(width,height);
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            res(i,j) = (*this)(j,width-i-1);
        }
    }
    return res;
}

Matrix Matrix::transpose() const {
    Matrix res(width, height);
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            res(j, i) = (*this)(i, j);
        }
    }
    return res;
}

double Matrix::CalcFrobeniusNorm(const Matrix &m) {
    double result = 0;
    for (int i = 0; i < m.getHeight(); i++) {
        for (int j = 0; j < m.getWidth(); j++) {
            result += std::pow(std::abs(m(i,j)),2);
        }
    }
    return std::sqrt(result);
}