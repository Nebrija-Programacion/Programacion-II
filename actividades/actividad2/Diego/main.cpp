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
                    "(e) Eliminar figura. " << endl <<
                    "(p) Tienen mismos parametros. " << endl <<
                    "(a) Comparar areas. " << endl <<
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

        case 'e':
            int a;
            cout << "Dime que el indice para eliminar: " ; cin >> a;
            figuras.erase(figuras.begin()+a);
            aux = 'm';
            break;

        case 'p':
            int b;
            cout << "Dime la posicion de  figura 1 y la 2 "; cin >> a; cin >> b;
            if((figuras.at(a) == figuras.at(b)) == true){
                cout << "Tienen el mismo parametro " << endl;
            }else{
                cout << "No tienen el mismo parametro " << endl;
            }
            aux ='m';
            break;

        case 'a':
            char aa;
            cout << "Dime el simbolo: "; cin >> aa;
            cout << "Dime los comparaciones: "; cin >> a; cin >> b;
            if(aa == '>'){
                if(a > b){
                    cout << "Es correcto " << endl;
                }else{
                    cout << "Es incorrecto " << endl;
                }
            }
            if(aa == '>='){
                if(a >= b){
                    cout << "Es correcto " << endl;
                }
                else{
                    cout << "Es incorrecto " << endl;
                }
                
            }
            if(aa == '<'){
                if(a < b){
                    cout << "Es correcto " << endl;
                }else{
                    cout << "Es incorrecto " << endl;
                }
            }
            if(aa == '<='){
                if(a <= b){
                    cout << "Es correcto " << endl;
                }else{
                    cout << "Es incorrecto " << endl;
                }
            }

            aux ='m';
            break;

        case 'i':
            for(auto figura:figuras){
                cout << *figura;
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
