#ifndef CUADRADO_H
#define CUADRADO_H

#include "figura.h"

class cuadrado : public Figura
{
public:
    cuadrado(float l);
    float getArea() const;
    float getPerimetro() const;

private:
    float lado;
};

#endif // CUADRADO_H
