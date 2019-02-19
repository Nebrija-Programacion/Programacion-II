#include "triangulo.h"
#include <math.h>

triangulo::triangulo(float):
    figure{"triangulo"},
    lado{1}
{

}

float triangulo::getArea() const
{
    const float altura = sqrt(3) * lado/2.0;
    return lado * altura / 2.0;
}

float triangulo::getPerimetro() const
{
    return lado * 3;
}
