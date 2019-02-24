#ifndef CUADRADO_H
#define CUADRADO_H

#include "figure.h"

class cuadrado : public figure
{
public:
    cuadrado(float );
    float getArea() const;
    float getPerimetro() const;
private:
    float lado;
};

#endif // CUADRADO_H
