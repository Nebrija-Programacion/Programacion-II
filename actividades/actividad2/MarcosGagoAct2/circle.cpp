#include "circle.h"

Circle::Circle(float _l):
        Figure("circle")
{
    l=_l;
}

float Circle::getArea()const
{
    return 3.1416*l*l;
}

float Circle::getPerimeter()const
{
    return 2*3.1416*l;
}
