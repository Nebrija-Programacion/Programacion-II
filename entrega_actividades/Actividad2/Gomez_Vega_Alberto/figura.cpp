#include "figura.h"

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
bool operator == (const Figura &a,const Figura &b)
{
    bool c = false;
    if(a.getType() == b.getType()){
        if(a.getType()== "cuadrado"){
            if(a.getPerimetro() == b.getPerimetro()){
                c = true;
            }
        }
        if(a.getType()== "triangulo"){
            if(a.getPerimetro() == b.getPerimetro()){
                c = true;
            }
        }
        if(a.getType()== "circulo"){
            if(a.getPerimetro() == b.getPerimetro()){
                c = true;
            }
        }
    }
    return c;
}
bool operator >(const Figura &a, const Figura &b)
{
    bool c;
    if(a.getArea() > b.getArea()){
        c = true;
    }else{
        c = false;
    }
    return c;
}
bool operator >=(const Figura &a, const Figura &b)
{
    bool c;
    if(a.getArea() >= b.getArea()){
        c = true;
    }else{
        c = false;
    }
    return c;
}
bool operator <=(const Figura &a, const Figura &b)
{
    bool c;
    if(a.getArea() <= b.getArea()){
        c = true;
    }else{
        c = false;
    }
    return c;
}
bool operator <(const Figura &a, const Figura &b)
{
    bool c;
    if(a.getArea() < b.getArea()){
        c = true;
    }else{
        c = false;
    }
    return c;
}
