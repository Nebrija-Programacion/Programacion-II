#ifndef FIGURE_H
#define FIGURE_H

#include <iostream>

using namespace std;

class figure
{
public:
    figure(string const & _tipo);

    virtual float getArea() const = 0;
    virtual float getPerimetro() const = 0;
    void print() const;
    string getTipo() const;
    void setTipo(const string &value);


   protected:
       string tipo;

};

bool operator == (const figure &, const figure &);
bool operator > (const figure &a, const figure &b);
bool operator >= (const figure &a, const figure &b);
bool operator < (const figure &a, const figure &b);
bool operator <= (const figure &a, const figure &b);
ostream &operator << (ostream &frase, const figure &a);

#endif // FIGURE_H
