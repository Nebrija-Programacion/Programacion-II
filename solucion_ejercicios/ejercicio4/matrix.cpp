#include <string>
#include <iostream>
#include "matrix.h"

Matrix::Matrix(int _rows, int _cols)
{
    if(_cols <= 0 || _rows <= 0) throw std::string{"Dimensiones incorrectas"};
    cols = unsigned(_cols);
    rows = unsigned(_rows);
    data.resize(cols*rows,0);
}

unsigned int Matrix::getCols() const
{
    return cols;
}

unsigned int Matrix::getRows() const
{
    return rows;
}

float &Matrix::at(unsigned i, unsigned j)
{
    if(i >= rows || j >= cols) throw std::string{"Fuera de los limites de la matriz"};
    unsigned elem = i*cols + j;
    return data.at(elem);
}

std::ostream &operator <<(std::ostream &os, Matrix &mat)
{

    for(unsigned i{0}; i<mat.getRows(); i++){
        for(unsigned j{0}; j<mat.getCols(); j++){
            os << mat.at(i,j) <<"\t";
        }
        os << "\n";
    }
    return os;
}

std::istream &operator >>(std::istream &is, Matrix &mat){
    for(unsigned i{0}; i<mat.getRows(); i++){
        for(unsigned j{0}; j<mat.getCols(); j++){
            is >> mat.at(i,j);
        }
    }
    return is;
}

Matrix operator*(Matrix &a, Matrix &b)
{
    if(a.getCols() != b.getRows()) throw std::string{"Tamaños no compatibles"};
    Matrix result(int(a.getRows()), int(b.getCols()));

    for(unsigned i{0}; i<result.getRows(); i++){
        for(unsigned j{0}; j<result.getCols(); j++){
            float aux{0};
            for(unsigned k{0}; k<a.getCols(); k++){
                aux += a.at(i,k)*b.at(k,j);
            }
            result.at(i,j) = aux;
        }
    }
    return result;
}

Matrix operator+(Matrix &a, Matrix &b)
{
    if(a.getCols() != b.getCols() || a.getRows() != b.getRows()) throw std::string{"Los tamaños no coinciden"};
    Matrix result(int(a.getRows()), int(a.getCols()));

    for(unsigned i{0}; i<a.getRows(); i++){
        for(unsigned j{0}; j<a.getCols(); j++){
            result.at(i,j) = a.at(i,j) + b.at(i,j);
        }
    }
    return result;
}

Matrix operator-(Matrix &a, Matrix &b)
{
    if(a.getCols() != b.getCols() || a.getRows() != b.getRows()) throw std::string{"Los tamaños no coinciden"};
    Matrix result(int(a.getRows()), int(a.getCols()));

    for(unsigned i{0}; i<a.getRows(); i++){
        for(unsigned j{0}; j<a.getCols(); j++){
            result.at(i,j) = a.at(i,j) - b.at(i,j);
        }
    }
    return result;
}
