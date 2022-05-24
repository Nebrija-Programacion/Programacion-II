#include "persona.h"
#include <iostream>

Persona::Persona(int b, const string &n, const string &job):job{job}
{
    setBirthdate(b);
    setName(n);
}

Persona::Persona(const Persona &other)
{
    setBirthdate(other.birthdate);
    setName(other.name);
}

Persona::~Persona()
{
    std::cout << name << " ha muerto";
}

int Persona::getBirthdate() const
{
    return birthdate;
}

void Persona::setBirthdate(int newBirthdate)
{
    if(newBirthdate <= 1900) throw string{"year must be greater than 1900"};
    birthdate = newBirthdate;
}

const string &Persona::getName() const
{
    return name;
}

void Persona::setName(const string &newName)
{
    name = newName;
}

const string &Persona::getJob() const
{
    return job;
}
