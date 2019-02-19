#ifndef CIRCLE_H
#define CIRCLE_H

#include "figure.h"

class Circle: public Figure
{
public:
    Circle(float _l);
    float getArea()const;
    float getPerimeter()const;
};

#endif // CIRCLE_H
