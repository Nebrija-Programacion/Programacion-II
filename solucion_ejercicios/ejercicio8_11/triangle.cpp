#include "triangle.h"

Triangle::Triangle(float _side, float _height)
{
    if(_side <=0 || _height <=0 ) throw std::string{"Incorrect side or height length"};
    side = _side;
    height = _height;
}

float Triangle::getArea() const
{
    return side * height / 2;
}

float Triangle::getPerimeter() const
{
    return 3 * side;
}

std::string Triangle::getType() const
{
    return "triangle";
}
