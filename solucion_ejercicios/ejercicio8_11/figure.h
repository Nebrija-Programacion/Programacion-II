#ifndef FIGURE_H
#define FIGURE_H

#include <string>

class Figure
{
public:
    Figure();
    virtual ~Figure(){};

    virtual float getArea() const = 0;
    virtual float getPerimeter() const = 0;
    virtual std::string getType() const = 0;

};

#endif // FIGURE_H
