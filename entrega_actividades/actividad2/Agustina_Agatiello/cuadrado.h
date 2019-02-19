#ifndef CUADRADO_H
#define CUADRADO_H

#include "figura.h"

class Cuadrado : public Figura
{
public:
    Cuadrado(float l);
    float getArea() const;
    float getPerimetro() const;
    float getLado() const;

private:
    float lado;
};

#endif // CUADRADO_H
