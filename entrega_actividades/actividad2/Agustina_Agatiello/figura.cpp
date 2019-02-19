#include "figura.h"
#include <math.h>

Figura::Figura(const string &_type):
    type{_type}
{

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
    if(a.getType() == b.getType()){
        if(a.getType()== "cuadrado"){
            if(a.getPerimetro()/4 == b.getPerimetro()/4){
                return true;
            }
        }
        if(a.getType()== "triangulo"){
            if(a.getPerimetro()/3 == b.getPerimetro()/3){
                return true;
            }
        }
        if(a.getType()== "circulo"){
            if(a.getPerimetro()/(static_cast<void>(2*3),14) == b.getPerimetro()/(static_cast<void>(2*3),14)){
                return true;
            }
        }
    }
    return false;
}

bool operator >(const Figura &a, const Figura &b)
{
    if(a.getArea() > b.getArea()){
        return true;
    }else{
        return false;
    }
}

bool operator >=(const Figura &a, const Figura &b)
{
    if(a.getArea() >= b.getArea()){
        return true;
    }else{
        return false;
    }
}

bool operator <(const Figura &a, const Figura &b)
{
    if(a.getArea() < b.getArea()){
        return true;
    }else{
        return false;
    }
}

bool operator <=(const Figura &a, const Figura &b)
{
    if(a.getArea() <= b.getArea()){
        return true;
    }else{
        return false;
    }
}

ostream &operator <<(ostream &os, const Figura &a)
{
    if(a.getType() == "cuadrado"){
        os << "Hola, soy un " << a.getType() << ", de lado: " << a.getLado() <<", con area: " << a.getArea() << ", y perimetro: " << a.getPerimetro() << endl;
        return os;
    }
    if(a.getType() == "triangulo"){
        os << "Hola, soy un " << a.getType() << ", de lado: " << a.getLado() <<", con area: " << a.getArea() << ", y perimetro: " << a.getPerimetro() << endl;
        return os;
    }
    if(a.getType() == "circulo"){
        os << "Hola, soy un " << a.getType() << ", de radio: " << a.getLado() <<", con area: " << a.getArea() << ", y perimetro: " << a.getPerimetro() << endl;
        return os;
    }
}
