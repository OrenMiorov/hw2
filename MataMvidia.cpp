#include "MataMvidia.h"

MataMvidia::MataMvidia(std::string movie, std::string author, Matrix *frames, int count) {
    movieName = std::move(movie);
    authorName = std::move(author);
    if (count <= 0) {
        this->frames = nullptr;
        frameCount = 0;
        return;
    }
    frameCount = count;
    Matrix* temp = new Matrix[count];
    for (int i = 0; i < count; i++) {
        temp[i] = Matrix(frames[i]);
    }
    this->frames = temp;
}

MataMvidia::MataMvidia(const MataMvidia &m) {
    movieName = m.movieName;
    authorName = m.authorName;
    frameCount = m.frameCount;
    Matrix* temp = new Matrix[frameCount];
    for (int i = 0; i < frameCount; i++) {
        temp[i] = Matrix(m.frames[i]);
    }
    this->frames = temp;
}

MataMvidia::~MataMvidia() {
    delete[] frames;
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

Matrix& MataMvidia::operator[](const int idx) {
    if (idx < 0 || idx >= frameCount) {
        exitWithError(MatamErrorType::OutOfBounds);
    }
    return frames[idx];
}

const Matrix& MataMvidia::operator[](const int idx) const {
    if (idx < 0 || idx >= frameCount) {
        exitWithError(MatamErrorType::OutOfBounds);
    }
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

std::ostream& operator<<(std::ostream &os, const MataMvidia &m) {
    os << "Movie Name: " << m.movieName << std::endl;
    os << "Author: " << m.authorName << std::endl;
    for (int i = 0; i < m.frameCount; i++) {
        os << "Frame " << i << ":" << std::endl;
        os << m[i];
    }
    os << "-----End of Movie-----" << std::endl;
    return os;
}
