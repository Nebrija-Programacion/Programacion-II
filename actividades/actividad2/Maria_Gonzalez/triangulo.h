#ifndef TRIANGULO_H
#define TRIANGULO_H

#include "figure.h"

class triangulo : public figure
{
public:
    triangulo(float );
    float getArea() const;
    float getPerimetro() const;
private:
    float lado;
 };

#endif // TRIANGULO_H
