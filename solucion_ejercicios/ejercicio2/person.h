#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <ostream>

class Person
{
public:
    Person(std::string _nombre, int _edad, std::string _telefono);

    std::string getNombre() const;
    void setName(const std::string &value);

    int getEdad() const;
    void setEdad(int value);

    std::string getTelefono() const;
    void setTelefono(const std::string &value);

private:
    std::string nombre;
    int edad;
    std::string telefono;
};

std::ostream & operator << (std::ostream & os, Person const & p);
#endif // PERSON_H
