#include "figura.h"
#include <math.h>

Figura::Figura(const string &_type):
    type{_type}
{
}

void Figura::print() const
{
    cout << "Hola! Soy un " << type << " de area: " << getArea() << " y perimetro: " << getPerimetro() << endl;
}
string Figura::getType() const
{
    return type;
}

void Figura::setType(const string &value)
{
    type = value;
}
ostream &operator <<(ostream &os, const Figura &f1)
{
    if(f1.getType()== "cuadrado"){
        os << "Hola! Soy un: " << f1.getType() << ", de lado: " << f1.getPerimetro()/4 <<"/ con area: " << f1.getArea() << "/ y perimetro: "
        << f1.getPerimetro() << endl;
        return os;
    }
    if(f1.getType()== "triangulo"){
        os << "Hola! Soy un: " << f1.getType() << ", de lado: " << f1.getPerimetro()/4 <<"/ con area: " << f1.getArea() << "/ y perimetro: "
        << f1.getPerimetro() << endl;
        return os;
    }
    if(f1.getType()=="circulo"){ //aunque ya no haga falta este if me gusta como queda asi :D
    os << "Hola! Soy un: " << f1.getType() << ", de radio: " << f1.getPerimetro()/(2,0*3,14) <<"/ con area: " << f1.getArea() << "/ y perimetro: "
    << f1.getPerimetro() << endl;
    return os;
    }
}


bool operator == (const Figura &f1,const Figura &f2)
{
    bool aux = false;
    if(f1.getType() == f2.getType()){
        if(f1.getType()== "cuadrado"){
            if(f1.getPerimetro()/4 == f2.getPerimetro()/4){
                aux = true;
            }
        }
        if(f1.getType()== "triangulo"){
            if(f1.getPerimetro()/3 == f2.getPerimetro()/3){
                aux = true;
            }
        }
        if(f1.getType()== "circulo"){
            if(f1.getPerimetro()/(2*3,14) == f2.getPerimetro()/(2*3,14)){
                aux = true;
            }
        }
    }
    return aux;
}

bool operator >(const Figura &f1, const Figura &f2)
{
    bool aux;
    if(f1.getArea() > f2.getArea()){
        aux = true;
    }else{
        aux = false;
    }
    return aux;
}
bool operator >=(const Figura &f1, const Figura &f2)
{
    bool aux;
    if(f1.getArea() >= f2.getArea()){
        aux = true;
    }else{
        aux = false;
    }
    return aux;
}
bool operator <=(const Figura &f1, const Figura &f2)
{
    bool aux;
    if(f1.getArea() <= f2.getArea()){
        aux = true;
    }else{
        aux = false;
    }
    return aux;
}
bool operator <(const Figura &f1, const Figura &f2)
{
    bool aux;
    if(f1.getArea() < f2.getArea()){
        aux = true;
    }else{
        aux = false;
    }
    return aux;
    }
