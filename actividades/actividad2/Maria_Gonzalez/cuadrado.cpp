#include "cuadrado.h"

cuadrado::cuadrado(float):
    figure{"Cuadrado"},
    lado{1}
{

}

float cuadrado::getArea() const
{
    return lado*lado;
}

float cuadrado::getPerimetro() const
{
    return lado * 4;
}
