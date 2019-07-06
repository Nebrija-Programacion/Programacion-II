#include "caballodomestico.h"

#include <iostream>
using namespace std;

CaballoDomestico::CaballoDomestico(string nombre, string sexo, int edad, string owner):
    Caballo(nombre, sexo, edad),
    owner(owner)
{

}

void CaballoDomestico::acariciar() const
{
    cout << "Si me acaricias agacho la cabeza" << endl;
}

void CaballoDomestico::printInfo() const
{
    Caballo::printInfo();
    cout << "Soy un caballo domestico" << endl;
    cout << "Mi propietario se llama " << owner << endl;
    acariciar();
}
