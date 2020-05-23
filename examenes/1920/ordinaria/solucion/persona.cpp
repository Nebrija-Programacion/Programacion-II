#include "persona.h"

std::string Persona::getNombre() const
{
    return nombre;
}

void Persona::setNombre(const std::string &value)
{
    if(value.size()==0)throw std::string{"Nombre no puede ir en blanco"};
    nombre = value;
}

int Persona::getNacimiento() const
{
    return nacimiento;
}

void Persona::setNacimiento(int value)
{
    nacimiento = value;
}

std::string Persona::getTelefono() const
{
    return telefono;
}

void Persona::setTelefono(std::string value)
{
    if(value.size()!=9)throw std::string{"Los telefonos tienen 9 digitos"};
    telefono = value;
}

Persona::Persona()
{

}

Persona::Persona(const std::string &_nombre, int _nacimiento, const std::string &_telefono)
{
    setNombre(_nombre);
    setTelefono(_telefono);
    setNacimiento(_nacimiento);
}

std::ostream &operator<<(std::ostream &os, const Persona &p)
{
    os<<"Nombre{"<<p.getNombre()<<"}\nNacimiento{"<<p.getNacimiento()<<"}\nTelefono{"<<p.getTelefono()<<"}\n";
    return os;
}
