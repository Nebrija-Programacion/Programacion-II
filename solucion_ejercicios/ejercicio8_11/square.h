#ifndef SQUARE_H
#define SQUARE_H

#include "figure.h"

class Square: public Figure
{
public:
    Square(float _side);
    float getArea() const override;
    float getPerimeter() const override;
    std::string getType() const override;

private:
    float side;
};

#endif // SQUARE_H
