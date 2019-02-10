#include <iostream>
#include <vector>
#include "figura.h"
#include "cuadrado.h"
#include "circulo.h"
#include "triangulo.h"


using namespace std;

int main()
{
    char aux{'m'};
    float value{0};

    vector<Figura*> figuras;

    while(aux != 'x'){
        switch(aux){
        case 'm':
            cout << "Que deseas hacer? "<< endl <<
                    "(c) Anadir Cuadrado. " << endl <<
                    "(t) Anadir Triangulo. " << endl <<
                    "(r) Anadir Ciruclo. " << endl <<
                    "(i) Imprimir figuras. " << endl <<
                    "(x) Salir. " << endl;
            cin >> aux;
            break;
        case 'c':
            cout << "Introduce el lado del cuadrado: ";
            cin >> value;
            figuras.push_back(new Cuadrado(value));
            aux = 'm';
            break;

        case 't':
            cout << "Introduce el lado del triangulo: ";
            cin >> value;
            figuras.push_back(new Triangulo(value));
            aux = 'm';
            break;

        case 'r':
            cout << "Introduce el radio del circulo: ";
            cin >> value;
            figuras.push_back(new Circulo(value));
            aux = 'm';
            break;

        case 'i':
            for(auto figura:figuras){
                figura->print();
            }
            aux ='m';
            break;

        default:
            aux = 'x';
        }
    }

    cout << "Gracias y adios" << endl;
    return 0;
}
