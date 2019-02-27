#include <iostream>
#include <vector>

#include <figura.h>
#include "circulo.h"
#include "cuadrado.h"
#include "triangulo.h"

using namespace std;

int main()
{
    vector<Figura*> listaFiguras;

    Figura *fig1 = new Circulo(5);
    Figura *fig2 = new Circulo(45);

    if(*fig1 < *fig2){
        cout << "Yes" << endl;
    }

    //string tipo;
    float value{0};
    int auxnumber;
    short opcion = 1;


    while(opcion >= 0){
        switch(opcion){
        // Salir
        case 0:
            return 0;
        case 1:
            cout << "\n0. Salir" << endl;
            cout << "2. Anadir una figura nueva" << endl;
            cout << "3. Eliminar una figura" << endl;
            cout << "4. Imprimir la lista de figuras" << endl;
            cout << "\nElija una opcion: ";
            cin >> opcion;
            break;
        case 2:
            auxnumber = 0;
            while(auxnumber != 1 && auxnumber != 2 && auxnumber != 3){
                cout << "\n1. Circulo" << endl;
                cout << "2. Cuadrado" << endl;
                cout << "3. Triangulo"<< endl;
                cout << "\nIntroduzca el tipo de figura que desee anadir: ";
                cin >> auxnumber;
            }
            if(auxnumber == 1){
                cout << "Introduzca el radio: ";
                cin >> value;
                listaFiguras.push_back(new Circulo(value));
            }
            if(auxnumber == 2){
                cout << "Introduzca el lado: ";
                cin >> value;
                listaFiguras.push_back(new Cuadrado(value));
            }
            if(auxnumber == 3){
                cout << "Introduzca la base: ";
                cin >> value;
                listaFiguras.push_back(new Triangulo(value));
            }
            opcion = 1;
            break;
        case 3:
            int a;
            cout << "Introduzca el indice de la figura a eliminar: ";
            cin >> a;
            listaFiguras.erase(listaFiguras.begin()+a);
            break;
        case 4:
            for(auto figura:listaFiguras){
                figura->print();
            }
            opcion = 1;
            break;

        default:
            opcion = 0;
        }
    }
    return 0;
}
