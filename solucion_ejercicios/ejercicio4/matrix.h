#ifndef MATRIX_H
#define MATRIX_H

#include <vector>
#include <ostream>

class Matrix
{
public:
    Matrix(int _cols, int _rows);

    unsigned int getCols() const;
    unsigned int getRows() const;
    float & at(unsigned i, unsigned j);

private:
    unsigned int cols;
    unsigned int rows;
    std::vector<float> data;
};

std::ostream &operator <<(std::ostream &os, Matrix &mat);
std::istream &operator >>(std::istream &is, Matrix &mat);

Matrix operator*(Matrix & a, Matrix & b);
Matrix operator+(Matrix & a, Matrix & b);
Matrix operator-(Matrix & a, Matrix & b);


#endif // MATRIX_H
