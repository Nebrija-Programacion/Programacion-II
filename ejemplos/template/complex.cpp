#include "complex.h"

#include <math.h>

Complex::Complex(float r, float i):
    r{r},
    i{i}
{

}

float Complex::module() const
{
    return sqrt(r*r + i*i);
}

ostream &operator <<(ostream &os, const Complex &c)
{
    os << c.r << " + " << c.i << "i";
    return os;
}
