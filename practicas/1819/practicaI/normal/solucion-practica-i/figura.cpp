#include "figura.h"

Figura::Figura(const string &_type):
    type{_type}
{
}

void Figura::print() const
{
    cout << "Soy un " << type << " de area " << getArea() << " y perimetro " << getPerimetro() << endl;
}
