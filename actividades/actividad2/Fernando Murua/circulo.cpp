#include "circulo.h"
#include "math.h"

Circulo::Circulo(float r):
    Figura{"circulo"},
    radio{r}
{
pi=3.1415;
}

float Circulo::getArea() const
{
    return pi*radio*radio;

}

float Circulo::getPerimetro() const
{
    return 2*pi*radio;
}
