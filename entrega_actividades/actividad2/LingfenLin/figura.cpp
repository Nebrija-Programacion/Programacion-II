#include "figura.h"
#include <math.h>

Figura::Figura(const string &_type):
    type{_type}
{}

void Figura::print() const
{}

string Figura::getType() const
{
    return type;
}

void Figura::setType(const string &value)
{
    type = value;
}


ostream &operator <<(ostream &os, const Figura &fig1)
{
    if(fig1.getType()== "Cuadrado")
    {
        os << "Hola, soy un " << fig1.getType() << ", de lado " << fig1.getPerimetro()/4 <<", con un area de " << fig1.getArea() << ", y un perimetro de " << fig1.getPerimetro() << endl;
        return os;
    }
    if(fig1.getType()== "Triangulo")
    {
        os << "Hola, soy un " << fig1.getType() << ", de lado " << fig1.getPerimetro()/4 <<", con un area de " << fig1.getArea() << ", y un perimetro de " << fig1.getPerimetro() << endl;
        return os;
    }
    os << "Hola, soy un " << fig1.getType() << ", con un radio de " << fig1.getPerimetro()/(2*3,14) <<", un area de " << fig1.getArea() << ", y un perimetro de " << fig1.getPerimetro() << endl;
    return os;
}


bool operator == (const Figura &fig1,const Figura &fig2)
{
    bool c = false;
    if(fig1.getType() == fig2.getType())
    {
        if(fig1.getType()== "Cuadrado")
        {
            if(fig1.getPerimetro()/4 == fig2.getPerimetro()/4)
            {
                c = true;
            }
        }

        if(fig1.getType()== "Triangulo")
        {
            if(fig1.getPerimetro()/3 == fig2.getPerimetro()/3)
            {
                c = true;
            }
        }

        if(fig1.getType()== "Circulo")
        {
            if(fig1.getPerimetro()/(2*3,14) == fig2.getPerimetro()/(2*3,14))
            {
                c = true;
            }
        }
    }
    return c;
}


bool operator >(const Figura &fig1, const Figura &fig2)
{
    bool c;
    if(fig1.getArea() > fig2.getArea())
    {
        c = true;
    }
    else
    {
        c = false;
    }
    return c;
}


bool operator >=(const Figura &fig1, const Figura &fig2)
{
    bool c;
    if(fig1.getArea() >= fig2.getArea()){
        c = true;
    }else{
        c = false;
    }
    return c;
}

bool operator <(const Figura &fig1, const Figura &fig2)
{
    bool c;
    if(fig1.getArea() < fig2.getArea())
    {
        c = true;
    }
    else
    {
        c = false;
    }
    return c;
}



bool operator <=(const Figura &fig1, const Figura &fig2)
{
    bool c;
    if(fig1.getArea() <= fig2.getArea())
    {
        c = true;
    }
    else
    {
        c = false;
    }
    return c;
}
