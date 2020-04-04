#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "figure.h"

class Triangle: public Figure
{
public:
    Triangle(float _side, float _height);
    float getArea() const override;
    float getPerimeter() const override;
    std::string getType() const override;

private:
    float side;
    float height;
};

#endif // TRIANGLE_H
