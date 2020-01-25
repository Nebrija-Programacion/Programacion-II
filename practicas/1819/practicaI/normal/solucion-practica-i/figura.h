#ifndef FIGURA_H
#define FIGURA_H

#include <iostream>

using namespace std;

class Figura
{
public:
    Figura(string const &  _type);

    virtual float getArea() const = 0;
    virtual float getPerimetro() const = 0;
    void print() const;

protected:
    string type;

};

#endif // FIGURA_H
