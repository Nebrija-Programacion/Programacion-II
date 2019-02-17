#ifndef PERSONA_H
#define PERSONA_H

#include <iostream>

using namespace std;

class Persona
{
public:
    Persona(int _edad, string _nombre);

    int getEdad() const;
    void setEdad(int value);

    string getNombre() const;
    void setNombre(const string &value);

    Persona& operator ++();
    Persona& operator --();

private:
    int edad;
    string nombre;
};

bool operator > (Persona const & p1, Persona const & p2);
bool operator >= (Persona const & p1, Persona const & p2);
bool operator < (Persona const & p1, Persona const & p2);
bool operator <= (Persona const & p1, Persona const & p2);
bool operator == (Persona const & p1, Persona const & p2);
bool operator != (Persona const & p1, Persona const & p2);

ostream& operator<<(ostream& os, Persona const & p);


#endif // PERSONA_H
