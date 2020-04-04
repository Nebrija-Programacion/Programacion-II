#include "square.h"

Square::Square(float _side)
{
    if(_side <=0) throw std::string{"Incorrect side length"};
    side = _side;
}

float Square::getArea() const
{
    return side*side;
}

float Square::getPerimeter() const
{
    return 4*side;
}

std::string Square::getType() const
{
    return "square";
}
