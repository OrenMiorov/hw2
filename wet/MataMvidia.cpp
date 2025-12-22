#include "MataMvidia.h"

MataMvidia::MataMvidia(std::string movie, std::string author, Matrix *frames, int count) {
    movieName = std::move(movie);
    authorName = std::move(author);
    frameCount = count;
    this->frames = new Matrix[count];
    for (int i = 0; i < count; i++) {
        this->frames[i] = Matrix(frames[i]);
    }
}

MataMvidia::MataMvidia(const MataMvidia &m) {
    movieName = m.authorName;
    authorName = m.authorName;
    frameCount = m.frameCount;
    this->frames = new Matrix[frameCount];
    for (int i = 0; i < frameCount; i++) {
        this->frames[i] = Matrix(m.frames[i]);
    }
}

MataMvidia &MataMvidia::operator=(const MataMvidia &m) {
    if (this == &m) return *this;
    delete[] frames;
    movieName = m.movieName;
    authorName = m.authorName;
    frameCount = m.frameCount;
    this->frames = new Matrix[frameCount];
    for (int i = 0; i < frameCount; i++) {
        this->frames[i] = Matrix(m.frames[i]);
    }
    return *this;
}

Matrix &MataMvidia::operator[](int idx) const {
    return frames[idx];
}

MataMvidia MataMvidia::operator+(const MataMvidia &m) const {
    int newFrames = frameCount + m.frameCount;
    auto temp = new Matrix[newFrames];
    for (int i = 0; i < frameCount; i++) {
        temp[i] = frames[i];
    }
    for (int i = 0; i < m.frameCount; i++) {
        temp[frameCount+i] = m[i];
    }
    MataMvidia res(movieName,authorName,temp,newFrames);
    delete[] temp;
    return res;
}

MataMvidia &MataMvidia::operator+=(const MataMvidia &m) {
    *this = *this + m;
    return *this;
}

MataMvidia &MataMvidia::operator+=(const Matrix &m) {
    Matrix* temp = new Matrix[frameCount+1];
    for (int i = 0; i < frameCount; i++) {
        temp[i] = frames[i];
    }
    temp[frameCount] = m;
    frameCount++;
    delete[] frames;
    frames = temp;
    return *this;
}

std::ostream& operator<<(std::ostream &os, MataMvidia &m) {
    os << "Movie Name: " << m.movieName << std::endl;
    os << "Author: " << m.authorName << std::endl;
    for (int i = 0; i < m.frameCount; i++) {
        os << "Frame " << i << ": " << std::endl;
        os << m[i] << std::endl;
    }
    os << "-----End of Movie-----" << std::endl;
    return os;
}
