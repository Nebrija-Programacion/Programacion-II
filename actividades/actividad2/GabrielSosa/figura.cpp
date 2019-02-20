#include "figura.h"

Figura::Figura(const string &_type):
    type{_type}
{

}

void Figura::print() const
{
    cout << "\nSoy un " << type << " de area " << getArea() << " y perimetro " << getPerimetro() << endl;
}

bool operator >(Figura &f1, Figura &f2)
{
    Figura* aux1 = &f1;
    Figura* aux2 = &f2;
    if(aux1->getArea() > aux2->getArea()){
        return true;
    }else {
        return false;
    }
}

bool operator >=(Figura &f1, Figura &f2)
{
    Figura* aux1 = &f1;
    Figura* aux2 = &f2;
    if(aux1->getArea() >= aux2->getArea()){
        return true;
    }else {
        return false;
    }
}

bool operator <(Figura &f1, Figura &f2)
{
    Figura* aux1 = &f1;
    Figura* aux2 = &f2;
    if(aux1->getArea() < aux2->getArea()){
        return true;
    }else {
        return false;
    }
}

bool operator <=(Figura &f1, Figura &f2)
{
    Figura* aux1 = &f1;
    Figura* aux2 = &f2;
    if(aux1->getArea() <= aux2->getArea()){
        return true;
    }else {
        return false;
    }
}

bool operator ==(Figura &f1, Figura &f2)
{
    Figura* aux1 = &f1;
    Figura* aux2 = &f2;
    if(aux1->getArea() == aux2->getArea()){
        return true;
    }else {
        return false;
    }
}

void operator <<(const Figura &f1, const Figura &f2)
{
    f1.print();
}
