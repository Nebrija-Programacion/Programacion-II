#include "persona.h"

Persona::Persona(std::string _nombre, int _edad, std::string _dni)
{
    setNombre(_nombre);
    setEdad(_edad);
    setDni(_dni);

}

std::string Persona::getNombre() const
{
    return nombre;
}

void Persona::setNombre(const std::string &value)
{
    nombre = value;
}

int Persona::getEdad() const
{
    return edad;
}

void Persona::setEdad(int value)
{
    if(edad < 0) throw std::string{"La edad no puede ser menor que 0"};
    edad = value;
}

std::string Persona::getDni() const
{
    return dni;
}

void Persona::setDni(const std::string &value)
{
    if(value.length() != 9) throw std::string{"DNI de longitud incorrecta"};
    dni = value;
}
