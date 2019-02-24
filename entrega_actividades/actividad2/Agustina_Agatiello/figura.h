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
    virtual float getLado() const = 0;
    string getType() const;
    void setType(const string &value);

protected:
    string type;

};

bool operator == (Figura const & a, Figura const & b);
bool operator > (Figura const & a, Figura const & b);
bool operator >= (Figura const & a, Figura const & b);
bool operator < (Figura const & a, Figura const & b);
bool operator <= (Figura const & a, Figura const & b);

ostream &operator << (ostream& os, Figura const & a);

#endif // FIGURA_H
