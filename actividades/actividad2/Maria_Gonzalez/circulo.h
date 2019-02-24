#ifndef CIRCULO_H
#define CIRCULO_H

#include "figure.h"

class circulo : public figure
{
public:
    circulo(float _radio);
    float getArea() const;
    float getPerimetro() const;
private:
    float radio;
};

#endif // CIRCULO_H
