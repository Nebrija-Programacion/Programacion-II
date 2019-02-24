#include "circulo.h"
#include <math.h>

circulo::circulo(float radio):

    figure{"circulo"},
    radio{radio}
{

}

float circulo::getArea() const
{
    return (3.14*(pow(radio,2)));
}

float circulo::getPerimetro() const
{
    return (2*3.14*radio);
}
