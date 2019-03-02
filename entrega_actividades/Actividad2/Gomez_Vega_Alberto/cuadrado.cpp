#include "cuadrado.h"

Cuadrado::Cuadrado(float l):
    Figura{"cuadrado"},
    lado{l}
{
}
float Cuadrado::getArea() const
{
    return lado*lado;
}
float Cuadrado::getPerimetro() const
{
    return 4*lado;
}
