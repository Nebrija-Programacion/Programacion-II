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

bool operator == (const Figura &, const Figura &);
bool operator > (const Figura &fig1, const Figura &fig2);
bool operator >= (const Figura &fig1, const Figura &fig2);
bool operator < (const Figura &fig1, const Figura &fig2);
bool operator <= (const Figura &fig1, const Figura &fig2);
ostream &operator << (ostream &os, const Figura &fig1);

#endif // FIGURA_H
