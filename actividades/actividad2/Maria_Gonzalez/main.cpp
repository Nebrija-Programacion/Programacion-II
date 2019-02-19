#include <iostream>
#include <vector>
#include "figure.h"
#include "cuadrado.h"
#include "circulo.h"
#include "triangulo.h"

void menu(){

    cout << "*********MENU********** "<< endl << endl;
    cout << "1.- Adjuntar Cuadrado: " << endl;
    cout << "2.- Adjuntar Triangulo: " << endl;
    cout << "3.- Adjuntar Circulo: " << endl;
    cout << "4.- Imprimir figuras: " << endl;
    cout << "5.- Eliminar figura: " << endl;
    cout << "6.- Comparar areas: " << endl;
    cout << "0.- Salir " << endl << endl;
    cout << "Introduce una opcion: ";

}
int main()
{
    int opcion;
    float value{0};


    vector < figure* > figures;

    while(opcion != 0){

        menu();
        cin >> opcion;
        cout << endl;


        switch(opcion){

            case 1:
                cout << "Introduce el lado del cuadrado: ";
                cin >> value;
                cout << endl;
                figures.push_back(new cuadrado(value));

                break;

            case 2:
                cout << "Introduce el lado del triangulo: ";
                cin >> value;
                cout << endl;
                figures.push_back(new triangulo(value));

                break;

            case 3:
                cout << "Introduce el radio del circulo: ";
                cin >> value;
                cout << endl;
                figures.push_back(new circulo(value));

                break;

             case 4:
                for(auto figure:figures){
                    cout << *figure << endl;
                }

                break;

            case 5:
                int a;
                cout << "Que indice quieres eliminar: " ;
                cin >> a;
                cout << endl;

                figures.erase(figures.begin()+a);

                break;

            case 6:
                char respuesta;
                int b;

                cout << "Que es lo que quieres comparar (>, < ó =): ";
                cin >> respuesta;
                cout << "Cuales son las posiciones que quieres comparar: ";
                cin >> a;
                cin >> b;
                cout << endl;

                if(respuesta == '>'){
                    if(figures.at(a)->getArea() > figures.at(b)->getArea()){
                        cout << "Es MAYOR la figura " << a << " que la " << b << endl;
                    }else{
                        cout << "Es MENOR la figura " << a << " que la " << b << endl;
                    }
                }

                if(respuesta == '<'){
                    if(figures.at(a)->getArea() < figures.at(b)->getArea()){
                        cout << "Es MAYOR la figura " << b << " que la " << a << endl;
                    }else{
                        cout << "Es MENOR la figura " << b << " que la " << a << endl;
                    }
                }
                if(respuesta == '='){
                    if(figures.at(a)->getArea() == figures.at(b)->getArea()){
                        cout << " " << a << " tiene el mismo area que " << b << endl;
                    }else{
                        cout << "La figura " << a << " y la figura " << b << "no comparten el mismo area" << endl;
                    }
                }


                break;

            default:
                opcion = 0;
        }
    }

    cout << " ESPERO VOLVER A VERTE!! " << endl << endl;
    return 0;
    }
