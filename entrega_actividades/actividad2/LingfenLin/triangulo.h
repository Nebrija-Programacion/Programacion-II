#ifndef TRIANGULO_H
#define TRIANGULO_H

#include "figura.h"

class triangulo : public Figura
{
public:
    triangulo(float l);
    float getArea() const;
    float getPerimetro() const;

private:
    float lado;
};

#endif // TRIANGULO_H
