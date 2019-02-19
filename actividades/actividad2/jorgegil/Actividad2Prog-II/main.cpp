#include <iostream>
#include <vector>

#include "figura.h"
#include "circulo.h"
#include "triangulo.h"
#include "cuadrado.h"

using namespace std;

int main()
{
    vector<Figura*> listaFiguras;
    float num{0};
    char aux{'m'};
    while(aux != 'x'){
        switch(aux){
        case 'm':
            cout << "Que deseas hacer? "<< endl <<
                    "(c) Anadir Cuadrado. " << endl <<
                    "(t) Anadir Triangulo. " << endl <<
                    "(r) Anadir Circulo. " << endl <<
                    "(i) Imprimir figuras. " << endl <<
                    "(e) Eliminar figura. " << endl <<
                    "(x) Salir. " << endl;
            cin >> aux;
            break;
        case 'c':
            cout << "Introduce el lado de su cuadrado: ";
            cin >> num;
            listaFiguras.push_back(new Cuadrado(num));
            aux = 'm';
            break;

        case 't':
            cout << "Introduce el lado de su triangulo: ";
            cin >> num;
            listaFiguras.push_back(new Triangulo(num));
            aux = 'm';
            break;

        case 'r':
            cout << "Introduce el radio de su circulo: ";
            cin >> num;
            listaFiguras.push_back(new Circulo(num));
            aux = 'm';
            break;

        case 'e':
            int a;
            cout << "Dime que el indice para eliminar: " ; cin >> a;
            listaFiguras.erase(listaFiguras.begin()+a);
            aux = 'm';
            break;

        case 'i':
            for(auto elem:listaFiguras){
                elem->print();
            }
            aux ='m';
            break;

        default:
            aux = 'x';
        }
    }

    return 0;
}
