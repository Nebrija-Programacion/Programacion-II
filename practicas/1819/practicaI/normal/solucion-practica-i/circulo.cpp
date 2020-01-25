#include "circulo.h"
#include "math.h"

Circulo::Circulo(float r):
    Figura{"circulo"},
    radio{r}
{

}

float Circulo::getArea() const
{
    return M_PI*radio*radio;

}

float Circulo::getPerimetro() const
{
    return 2*M_PI*radio;
}
