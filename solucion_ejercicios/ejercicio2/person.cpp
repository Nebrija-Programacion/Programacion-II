#include "person.h"

Person::Person(std::string _nombre, int _edad, std::string _telefono)
{
    setName(_nombre);
    setEdad(_edad);
    setTelefono(_telefono);

}

std::string Person::getNombre() const
{
    return nombre;
}

void Person::setName(const std::string &value)
{
    nombre = value;
}

int Person::getEdad() const
{
    return edad;
}

void Person::setEdad(int value)
{
    if(edad < 0) throw std::string{"Edad incorrecta"};
    edad = value;
}

std::string Person::getTelefono() const
{
    return telefono;
}

void Person::setTelefono(const std::string &value)
{
    if (value.length() != 9) throw std::string{"Longitud incorrecta"};
    telefono = value;
}

std::ostream & operator << (std::ostream & os, Person const & p){
    os << "Nombre: " << p.getNombre() << "\n";
    os << "Edad: " << p.getEdad() << "\n";
    os << "Telefono: " << p.getTelefono() << "\n";
    return os;
}
