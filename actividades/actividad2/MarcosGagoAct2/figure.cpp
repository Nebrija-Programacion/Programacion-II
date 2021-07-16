#include "figure.h"

Figure::Figure(const string _d):
    d{_d}
{

}

string Figure::getD() const
{
    return d;
}

void Figure::setD(const string &value)
{
    d = value;
}

float Figure::getL() const
{
    return l;
}

void Figure::setL(float value)
{
    l = value;
}
bool operator >(const Figure &f1, const Figure &f2)
{
    return (f1.getArea() > f2.getArea());
}

bool operator >=(const Figure &f1, const Figure &f2)
{
    return (f1.getArea() >= f2.getArea());
}

bool operator <(const Figure &f1, const Figure &f2)
{
    return (f1.getArea() < f2.getArea());
}

bool operator <=(const Figure &f1, const Figure &f2)
{
    return (f1.getArea() <= f2.getArea());
}

bool operator == (const Figure &f1, const Figure &f2)
{
    return (f1.getArea() == f2.getArea());
}
ostream &operator<<(ostream &os, const Figure &p)
{
    os << "Hola, soy un "<< p.getD()<<" de lado/radio "<<p.getL() <<" con area "<<p.getArea()
    << " y perimetro "<<p.getPerimeter()<<endl;
return os;
}
