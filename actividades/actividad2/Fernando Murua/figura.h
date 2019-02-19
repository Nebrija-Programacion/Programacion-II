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
bool operator == (const Figura &f1, const Figura &f2);
bool operator > (const Figura &f1, const Figura &f2);
bool operator >= (const Figura &f1, const Figura &f2);
bool operator < (const Figura &f1, const Figura &f2);
bool operator <= (const Figura &f1, const Figura &f2);
ostream &operator << (ostream &os, const Figura &f1);

#endif // FIGURA_H
