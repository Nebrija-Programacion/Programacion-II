#include <iostream>
#include "figure.h"
#include "circle.h"
#include "square.h"
#include "triangle.h"
#include "list.h"

using namespace std;

int main()
{
    int i;
    char aux{'m'};
    float value;
    Figure *d;
    List figuras{d};
    while(aux != 'x'){
            switch(aux){
            case 'm':
                cout << "Que deseas hacer? "<< endl <<
                        "(c) Anadir Cuadrado. " << endl <<
                        "(t) Anadir Triangulo. " << endl <<
                        "(r) Anadir Ciruclo. " << endl <<
                        "(i) Imprimir figuras. " << endl <<
                        "(d) Eliminar figura. " << endl <<
                        "(x) Salir. " << endl;
                cin >> aux;
                break;
            case 'c':
                cout << "Introduce el lado del cuadrado: ";
                cin >> value;
                figuras.push_back(new Square(value));
                aux = 'm';
                break;

            case 't':
                cout << "Introduce el lado del triangulo: ";
                cin >> value;
                figuras.push_back(new Triangle(value));
                aux = 'm';
                break;

            case 'r':
                cout << "Introduce el radio del circulo: ";
                cin >> value;
                figuras.push_back(new Circle(value));
                aux = 'm';
                break;
            case 'd':
                cout << "Introduce el indice: ";
                cin >> i;
                figuras.erase(i);
                aux = 'm';
                break;
            case 'i':
                for (List *it = figuras.getNext(); it != nullptr; it = it->getNext()) {
                    cout<<it;
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
