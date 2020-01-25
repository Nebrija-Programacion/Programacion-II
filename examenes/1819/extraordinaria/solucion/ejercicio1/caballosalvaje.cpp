#include "caballosalvaje.h"
#include <iostream>

using namespace std;

CaballoSalvaje::CaballoSalvaje(string nombre, string sexo, int edad):
    Caballo(nombre, sexo, edad)
{

}

void CaballoSalvaje::acariciar() const
{
    cout << "Si me acaricias me encabrito" << endl;
}

void CaballoSalvaje::printInfo() const
{
    Caballo::printInfo();
    cout << "Soy un caballo salvaje y no tengo propietario" << endl;
    acariciar();
}
