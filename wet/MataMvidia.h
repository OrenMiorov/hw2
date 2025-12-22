#pragma once
#ifndef MATAMVIDIA_H
#define MATAMVIDIA_H
#include "Matrix.h"

class MataMvidia {
private:
    int frameCount = 0;
    Matrix* frames = new Matrix[frameCount];
    std::string movieName;
    std::string authorName;
public:
    MataMvidia(std::string movie, std::string author, Matrix* frames, int count);
    MataMvidia(const MataMvidia& m);
    MataMvidia() = default;
    ~MataMvidia() = default;
    MataMvidia& operator=(const MataMvidia& m);
    Matrix& operator[](int idx) const;
    MataMvidia& operator+=(const MataMvidia& m);
    MataMvidia& operator+=(const Matrix& m);
    MataMvidia operator+(const MataMvidia& m) const;
    friend std::ostream& operator<<(std::ostream &os, MataMvidia &m);


};


#endif //MATAMVIDIA_H
