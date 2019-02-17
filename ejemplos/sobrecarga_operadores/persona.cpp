#include "persona.h"

Persona::Persona(int _edad, string _nombre):
    edad{_edad},
    nombre{_nombre}
{

}

int Persona::getEdad() const
{
    return edad;
}

void Persona::setEdad(int value)
{
    edad = value;
}

string Persona::getNombre() const
{
    return nombre;
}

void Persona::setNombre(const string &value)
{
    nombre = value;
}

Persona &Persona::operator ++()
{
    edad++;
    return *this;
}

Persona &Persona::operator --()
{
    edad--;
    return *this;
}

bool operator >(const Persona &p1, const Persona &p2)
{
    return (p1.getEdad() > p2.getEdad());
}

bool operator >=(const Persona &p1, const Persona &p2)
{
    return (p1.getEdad() >= p2.getEdad());
}

bool operator <(const Persona &p1, const Persona &p2)
{
    return (p1.getEdad() < p2.getEdad());
}

bool operator <=(const Persona &p1, const Persona &p2)
{
    return (p1.getEdad() <= p2.getEdad());
}

bool operator == (const Persona &p1, const Persona &p2)
{
    return (p1.getEdad() == p2.getEdad());
}

bool operator != (const Persona &p1, const Persona &p2)
{
    return (p1.getEdad() != p2.getEdad());
}

ostream &operator<<(ostream &os, const Persona &p)
{
    os << "Nombre: " << p.getNombre() <<". Edad: " << p.getEdad();
    return os;
}
