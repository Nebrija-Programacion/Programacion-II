#ifndef SQUARE_H
#define SQUARE_H

#include "figure.h"

class Square: public Figure
{
public:
    Square(float _l);
    float getArea()const;
    float getPerimeter()const;
};

#endif // SQUARE_H
