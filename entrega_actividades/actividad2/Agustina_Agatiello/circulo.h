#ifndef CIRCULO_H
#define CIRCULO_H

#include "figura.h"

class Circulo : public Figura
{
public:
    Circulo(float _r);
    float getArea() const;
    float getPerimetro() const;
    float getLado() const;

private:
    float radio;
};

#endif // CIRCULO_H
