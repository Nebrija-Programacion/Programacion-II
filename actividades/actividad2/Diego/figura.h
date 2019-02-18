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

    string getType() const;
    void setType(const string &value);

protected:
    string type;
};

ostream &operator << (ostream &os, const Figura &a);
bool &operator == (const Figura &a, const Figura &b);
bool &operator > (const Figura &a, const Figura &b);
bool &operator >= (const Figura &a, const Figura &b);
bool &operator < (const Figura &a, const Figura &b);
bool &operator <= (const Figura &a, const Figura &b);


#endif // FIGURA_H
