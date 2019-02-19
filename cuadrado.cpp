#include "cuadrado.h"
#include <math.h>

cuadrado::cuadrado(float l):
    Figura {" cuadrado "},
    lado{l}
{}

float cuadrado::getArea() const
{
    return lado*lado;
}

float cuadrado::getPerimetro() const
{
    return 4*lado;
}
