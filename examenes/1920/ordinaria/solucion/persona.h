#ifndef PERSONA_H
#define PERSONA_H
#include <iostream>

class Persona
{
private:
    std::string nombre;
    int nacimiento;
    std::string telefono;
public:
    Persona();
    Persona(std::string const & _nombre, int _nacimiento, std::string const & _telefono);
    std::string getNombre() const;
    void setNombre(const std::string &value);
    int getNacimiento() const;
    void setNacimiento(int value);
    std::string getTelefono() const;
    void setTelefono(std::string value);
};

std::ostream & operator<<(std::ostream & os, Persona const & p);
#endif // PERSONA_H
