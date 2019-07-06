#ifndef CABALLO_H
#define CABALLO_H

#include <string>

using namespace std;

class Caballo
{
public:
    Caballo(string nombre, string sexo, int edad);
    virtual ~Caballo(){}
    virtual void acariciar() const = 0;
    virtual void printInfo() const;

protected:
    string nombre, sexo;
    int edad;
};

#endif // CABALLO_H
