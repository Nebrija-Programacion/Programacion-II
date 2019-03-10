#ifndef COMPLEX_H
#define COMPLEX_H

#include <ostream>

using namespace std;

class Complex
{
    friend ostream & operator << (ostream & os, Complex const & c);
public:
    Complex(float r, float i);
    float module() const;

protected:
    float r,i;
};

ostream & operator << (ostream & os, Complex const & c);

#endif // COMPLEX_H
