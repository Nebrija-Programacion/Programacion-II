#include "triangulo.h"
#include <math.h>

Triangulo::Triangulo(float l):
    Figura{"triangulo"},
    lado{l}
{

}

float Triangulo::getArea() const
{
    const float h = sqrt(3)*lado/2.0;
    return lado * h / 2.0;
}

float Triangulo::getPerimetro() const
{
    return 3*lado;
}
