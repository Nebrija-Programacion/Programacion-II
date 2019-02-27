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

bool operator > (Figura const & f1, Figura const & f2);
bool operator >= (Figura const & f1, Figura const & f2);
bool operator < (Figura  &f1, Figura &f2);
bool operator <= (Figura const & f1, Figura const & f2);
bool operator == (Figura const & f1, Figura const & f2);
void operator << (Figura const & f1, Figura const & f2);

#endif // FIGURA_H
