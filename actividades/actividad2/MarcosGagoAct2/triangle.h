#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "figure.h"

class Triangle: public Figure
{
public:
    Triangle(float _l);
    float getArea()const;
    float getPerimeter()const;
};

#endif // TRIANGLE_H
