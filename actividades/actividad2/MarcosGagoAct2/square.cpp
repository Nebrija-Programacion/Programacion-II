#include "square.h"

Square::Square(float _l):
Figure{"square"}
{
    l=_l;
}

float Square::getArea()const
{
    return l*l;
}

float Square::getPerimeter()const
{
    return l*4;
}
