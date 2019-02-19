#include <iostream>
#include <vector>
#include "circulo.h"
#include "cuadrado.h"
#include "figura.h"
#include "triangulo.h"

int main()
{
    char aux{'e'};
    float value{0};
    vector <Figura*> figuras;

    cout << "                                  *************************************" << endl;
    cout << "                                  * BIENVENIDOS A LA LISTA DE FIGURAS *" << endl;
    cout << "                                  *************************************" << endl << endl;

    while(aux != '0'){
        switch(aux){

        case 'e':
            cout << " Estas son las opciones a elegir, cual escoges? "<< endl;
            cout << " ----------------------------------------------" << endl;
            cout << "      | (c) Crear un Cuadrado.           |" << endl;
            cout << "      | (t) Crear un Triangulo.          |" << endl;
            cout << "      | (o) Crear un Circulo.            |" << endl;
            cout << "      | (i) Imprimir las figuras.        |" << endl;
            cout << "      | (x) Eliminar una de las figuras. |" << endl;
            cout << "      | (p) Comparar los parametros.     |" << endl;
            cout << "      | (a) Comparar las areas.          |" << endl;
            cout << "      | (0) Salir.                       |"<< endl;
            cin >> aux;
            break;

        case 'c':
            cout << "Dime el lado de tu cuadrado: ";
            cin >> value;
            figuras.push_back(new cuadrado(value));
            aux = 'e';
            break;

        case 't':
            cout << "Dime el lado de tu triangulo: ";
            cin >> value;
            figuras.push_back(new triangulo(value));
            aux = 'e';
            break;

        case 'o':
            cout << "Dime el radio de tu circulo: ";
            cin >> value;
            figuras.push_back(new circulo(value));
            aux = 'e';
            break;

        case 'x':
            int fig1;
            cout << "Dime el indice para eliminar: " ; cin >> fig1;
            figuras.erase(figuras.begin()+fig1);
            aux = 'e';
            break;

        case 'p':
            int fig2;
            cout << "Dime el indice de las figuras que quieres comparar "; cin >> fig1; cin >> fig2;
            if(figuras.at(fig1) == figuras.at(fig2)){
                cout << "Tienen el mismo parametro " << endl;
            }else{
                cout << "No tienen el mismo parametro " << endl;
            }
            aux ='e';
            break;

        case 'a':
            char c;
            cout << "Escribe el simbolo para empezar a comparar (>, < ó =): "; cin >> c;
            cout << "Dime las figuras a comparar: "; cin >> fig1; cin >> fig2;

            if(c == '>'){
                if(figuras.at(fig1)->getArea() > figuras.at(fig2)->getArea()){
                    cout << "La figura " << fig1 << " es mayor que la figura" << fig2 << endl;
                }else{
                    cout << "La figura " << fig1 << " no es mayor que la figura " << fig2 << endl;
                }
            }

            if(c == '<'){
                if(figuras.at(fig1)->getArea() < figuras.at(fig2)->getArea()){
                    cout << "La figura " << fig1 << " es mayor que la figura " << fig2 << endl;
                }else{
                    cout << "La figura " << fig1 << " no es menor que la figura " << fig2 << endl;
                }
            }

            if(c == '='){
                if(figuras.at(fig1)->getArea() == figuras.at(fig2)->getArea()){
                    cout << "La figura " << fig1 << " tiene el mismo area que la figura " << fig2 << endl;
                }else{
                    cout << "La figura " << fig1 << " no tiene el mismo area que la figura" << fig2 << endl;
                }
            }

            aux ='e';
            break;

        case 'i':
            for(auto figura:figuras)
            {
                cout << *figura;
            }
            aux ='e';
            break;

            //Salida.
        default:
            aux = '0';
        }
    }
    cout << "El programa ha finalizado, que tenga un buen dia!" << endl;
    return 0;
}
