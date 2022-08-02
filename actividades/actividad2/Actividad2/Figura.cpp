//
//  Figura.cpp
//  Actividad2
//
//  Created by Familia Ancona Ortiz Mac on 19/2/19.
//  Copyright © 2019 Familia Ancona Ortiz Mac. All rights reserved.
//
#include "Figura.h"

Figura::Figura(const string &_type):
type{_type}
{
}

void Figura::imprimir() const
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
ostream &operator <<(ostream &os, const Figura &a)
{
    if(a.getType()== "cuadrado"){
        os << "Soy un: " << a.getType() << ", de lado: " << a.getPerimetro()/4 <<", con area: " << a.getArea() << ", y perimetro: "<< a.getPerimetro() << endl;
        return os;
    }
    if(a.getType()== "triangulo"){
        os << "Soy un: " << a.getType() << ", de lado: " << a.getPerimetro()/4 <<", con area: " << a.getArea() << ", y perimetro: " << a.getPerimetro() << endl;
        return os;
    }
    if(a.getType()=="circulo"){
        os << "Soy un: " << a.getType() << ", de radio: " << a.getPerimetro()/(2*3,14) <<", y su area: " << a.getArea() << ", y perimetro: "<< a.getPerimetro() << endl;
    return os;
    }
    
}


bool operator == (const Figura &a,const Figura &b)
{
    bool c = false;
    if(a.getType() == b.getType()){
        if(a.getType()== "cuadrado"){
            if(a.getPerimetro()/4 == b.getPerimetro()/4){
                c = true;
            }
        }
        if(a.getType()== "triangulo"){
            if(a.getPerimetro()/3 == b.getPerimetro()/3){
                c = true;
            }
        }
        if(a.getType()== "circulo"){
            if(a.getPerimetro()/(2*3,14) == b.getPerimetro()/(2*3,14)){
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
