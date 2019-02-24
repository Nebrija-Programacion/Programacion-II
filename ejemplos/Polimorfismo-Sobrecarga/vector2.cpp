#include "vector2.h"
#include <math.h>

Vector2::Vector2(double x, double y):
    x{x},
    y{y}
{

}

double Vector2::getMod() const
{
    return sqrt(x*x + y*y);
}

double Vector2::getX() const
{
    return x;
}

double Vector2::getY() const
{
    return y;
}

bool operator ==(const Vector2 &v1, const Vector2 &v2)
{
    return ( (v1.getX() == v2.getX()) && (v1.getY() && v2.getY()) );
}
