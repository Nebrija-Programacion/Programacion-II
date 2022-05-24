#ifndef PERSONA_H
#define PERSONA_H

#include <string>

using namespace std;

class Persona
{
public:
    Persona(int b, string const & n, string const & job);
    Persona(Persona const & other);
    ~Persona();
    int getBirthdate() const;
    void setBirthdate(int newBirthdate);

    const string &getName() const;
    void setName(const string &newName);

    const string &getJob() const;

private:
    int birthdate;
    string name;
    string job;
};

#endif // PERSONA_H
