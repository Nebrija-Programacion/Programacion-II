#include "triangulo.h"
#include <math.h>

triangulo::triangulo(float l):
    Figura{"triangulo"},
    lado{l}
{}

float triangulo::getArea() const
{
    const float h = sqrt(3)*lado/2.0;
    return lado * h / 2.0;
}

float triangulo::getPerimetro() const
{
    return 3*lado;
}
