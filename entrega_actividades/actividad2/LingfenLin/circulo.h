#ifndef CIRCULO_H
#define CIRCULO_H

#include "figura.h"

class circulo : public Figura
{
public:
    circulo(float _r);
    float getArea() const;
    float getPerimetro() const;

private:
    float radio;
};

#endif // CIRCULO_H
