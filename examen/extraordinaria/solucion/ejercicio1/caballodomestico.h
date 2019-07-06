#ifndef CABALLODOMESTICO_H
#define CABALLODOMESTICO_H

#include "caballo.h"

using namespace std;

class CaballoDomestico: public Caballo
{
public:
    CaballoDomestico(string nombre, string sexo, int edad, string owner);
    void acariciar() const;
    void printInfo() const;

protected:
    string owner;
};

#endif // CABALLODOMESTICO_H
