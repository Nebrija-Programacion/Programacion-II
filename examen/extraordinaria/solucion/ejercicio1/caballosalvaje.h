#ifndef CABALLOSALVAJE_H
#define CABALLOSALVAJE_H

#include "caballo.h"

using namespace std;


class CaballoSalvaje: public Caballo
{
public:
    CaballoSalvaje(string nombre, string sexo, int edad);
    void acariciar() const;
    void printInfo() const;
};

#endif // CABALLOSALVAJE_H
