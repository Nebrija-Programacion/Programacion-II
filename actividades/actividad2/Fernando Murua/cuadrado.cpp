#include "cuadrado.h"
#include "math.h"



Cuadrado::Cuadrado(float l):
    Figura{"cuadrado"},
    lado{l}
{

}

float Cuadrado::getArea() const
{
    return pow(lado,2.0);
}

float Cuadrado::getPerimetro() const
{
    return 4*lado;
}
