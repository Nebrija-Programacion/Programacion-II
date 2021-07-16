#include "triangle.h"
#include <cmath>

Triangle::Triangle(float _l):
    Figure{"triangle"}
{
    l=_l;
}

float Triangle::getArea()const
{
    return l*(sqrt((l*l)-(l*l*0.25)))/2;
}

float Triangle::getPerimeter()const
{
    return l*3;
}
