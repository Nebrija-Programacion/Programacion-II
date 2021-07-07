#include "figura.h"
#include <vector>

Figura::Figura(const string &_type):
    type{_type}
{
}

void Figura::print() const
{
    cout << "Soy un " << type << " de area " << getArea() << " y perimetro " << getPerimetro() << endl;
}

string Figura::getType() const
{
    return type;
}

void Figura::setType(const string &value)
{
    type = value;
}

bool operator >(Figura &f1, Figura &f2)
{
    Figura * aux1 = &f1;
    Figura* aux2 = &f2;
    if(aux1->getArea() > aux2->getArea()){
        return true;
    }else {
        return false;
    }
}

bool operator >=(Figura &f1, Figura &f2)
{
    Figura * aux1 = &f1;
    Figura* aux2 = &f2;
    if(aux1->getArea() >= aux2->getArea()){
        return true;
    }else {
        return false;
    }
}

bool operator <(Figura &f1, Figura &f2)
{
    Figura * aux1 = &f1;
    Figura* aux2 = &f2;
    if(aux1->getArea() < aux2->getArea()){
        return true;
    }else {
        return false;
    }
}

bool operator <=(Figura &f1, Figura &f2)
{
    Figura * aux1 = &f1;
    Figura* aux2 = &f2;
    if(aux1->getArea() <= aux2->getArea()){
        return true;
    }else {
        return false;
    }
}

bool operator ==(Figura &f1, Figura &f2)
{
    Figura * aux1 = &f1;
    Figura* aux2 = &f2;
    if(aux1->getArea() == aux2->getArea()){
        return true;
    }else {
        return false;
    }
}

/*bool operator <<(Figura &f1, Figura &f2)
{
    Figura * aux1 = &f1;
    Figura* aux2 = &f2;
    if(aux1->getArea() << aux2->getArea()){
        return true;
    }else {
        return false;
    }
}*/
