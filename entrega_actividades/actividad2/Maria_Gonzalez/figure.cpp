#include "figure.h"
#include <math.h>
#include <iomanip> // libreria para redondear decimales

figure::figure(const string &_tipo):
    tipo{_tipo}
{

}

void figure::print() const // setprecision: ajusta los decimales a lo indicado entre paréntesis
{
    cout << "Soy un " << tipo << " de area " << setprecision(3) <<getArea() << " y perimetro " << setprecision(3) << getPerimetro() << endl;
}

string figure::getTipo() const
{
    return tipo;
}

void figure::setTipo(const string &value)
{
    tipo = value;
}

ostream &operator <<(ostream &frase, const figure &a)
{
    if (a.getTipo() == "cuadrado"){
        frase << " -> Soy un: " << a.getTipo() << ", de lado: "<< setprecision(3) << a.getPerimetro()/4 <<", con area: "<< setprecision(3) << a.getArea() << ", y perimetro: "
        << a.getPerimetro() << endl;
        return frase;
    }

    if(a.getTipo()== "triangulo"){
            frase << "-> Soy un: " << a.getTipo() << ", de lado: "<< setprecision(3) << a.getPerimetro()/4 <<", con area: "<< setprecision(3) << a.getArea() << ", y perimetro: "
            << a.getPerimetro() << endl;
            return frase;
    }

    frase << "-> Soy un: " << a.getTipo() << ", de radio: "<< setprecision(3) << a.getPerimetro()/(2*3.14) <<", con area: "<< setprecision(3) << a.getArea() << ", y perimetro: "
    << a.getPerimetro() << endl;
    return frase;
}

bool operator == (const figure &a,const figure &b)
{
    bool respuesta = false;
    if(a.getTipo() == b.getTipo()){
        if(a.getTipo()== "cuadrado"){
            if(a.getPerimetro()/4 == b.getPerimetro()/4){
                respuesta = true;
            }
        }
        if(a.getTipo()== "triangulo"){
            if(a.getPerimetro()/3 == b.getPerimetro()/3){
                respuesta = true;
            }
        }
        if(a.getTipo()== "circulo"){
            if(a.getPerimetro()/(2*3,14) == b.getPerimetro()/(2*3,14)){
                respuesta = true;
            }
        }
    }
    return respuesta;
}

bool operator >(const figure &a, const figure &b)
{
    bool c;
    if(a.getArea() > b.getArea()){
        c = true;
    }else{
        c = false;
    }
    return c;
}

bool operator >=(const figure &a, const figure &b)
{
    bool c;
    if(a.getArea() >= b.getArea()){
        c = true;
    }else{
        c = false;
    }
    return c;
}

bool operator <=(const figure &a, const figure &b)
{
    bool c;
    if(a.getArea() <= b.getArea()){
        c = true;
    }else{
        c = false;
    }
    return c;
}

bool operator <(const figure &a, const figure &b)
{
    bool c;
    if(a.getArea() < b.getArea()){
        c = true;
    }else{
        c = false;
    }
    return c;
    }
