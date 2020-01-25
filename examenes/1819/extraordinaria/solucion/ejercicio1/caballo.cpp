#include <iostream>
#include "caballo.h"

Caballo::Caballo(string nombre, string sexo, int edad):
    nombre{nombre},
    sexo{sexo},
    edad{edad}
{

}

void Caballo::printInfo() const
{
    cout << "Mi nombre es: " << nombre << endl;
    cout << "Mi edad es: " << edad << endl;
    cout << "Mi sexo es: " << sexo << endl;
}
