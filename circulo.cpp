#include "circulo.h"
#include "math.h"

circulo::circulo(float r):
    Figura {" circulo "},
    radio{r}
{}

float circulo::getArea() const
{
    return M_PI*radio*radio;
}

float circulo::getPerimetro() const
{
    return 2*M_PI*radio;
}
