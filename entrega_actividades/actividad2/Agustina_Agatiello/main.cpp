#include <iostream>
#include <vector>
#include "figura.h"
#include "cuadrado.h"
#include "circulo.h"
#include "triangulo.h"

using namespace std;

void showMenu()
{
    cout << "--------------- Introduzca que desea hacer ---------------" << endl;
    cout << "(a) Agregar circulo." << endl;
    cout << "(b) Agregar cuadrado. " << endl;
    cout << "(c) Agregar triangulo." << endl;
    cout << "(d) Eliminar figura. " << endl;
    cout << "(e) Imprimir lista de figuras." << endl;
    cout << "(f) Comparar si dos figuras tienen mismo parametro." << endl;
    cout << "(g) Comparar area de dos figuras geometricas." << endl;
    cout << "(z) Salir." << endl;
    cout << "----------------------------------------------------------" << endl;
}

void showMenu2()
{
    cout << "--- Introduzca comparacion ---" << endl;
    cout << "(h) Comparar > " << endl;
    cout << "(i) Comparar >= " << endl;
    cout << "(j) Comparar < " << endl;
    cout << "(k) Comparar <= " << endl;
    cout << "(z) Salir." << endl;
    cout << "------------------------------" << endl;
}

int main()
{
    vector<Figura*> figuras;
    int a, b;
    float value{0};

    char option='x';

    cout << "      !!! BIENVENIDO A FIGURAS GEOMETRICAS !!!      " << endl << endl;

    while(option != 'z'){
        switch(option){
        case 'a':
            cout << "Introduce el radio del circulo: ";
            cin >> value;
            figuras.push_back(new Circulo(value));
            break;

        case 'b':
            cout << "Introduce el lado del cuadrado: ";
            cin >> value;
            figuras.push_back(new Cuadrado(value));
            break;

        case 'c':
            cout << "Introduce el lado del triangulo: ";
            cin >> value;
            figuras.push_back(new Triangulo(value));
            break;

        case 'd':
            cout << "Introduce el indice de la figura a eliminar: ";
            cin >> a;
            figuras.erase(figuras.begin()+a);
            break;

        case 'e':
            for(auto figura:figuras){
                cout << *figura;
            }
            break;

        case 'f':
            cout << "Introduce los indices de las figuras a comparar parametro: " << endl;
            cin >> a;
            cin >> b;
            if(figuras.at(a) == figuras.at(b)){
                cout << "Tienen el mismo parametro." << endl;
            }else{
                cout << "No tienen el mismo parametro." << endl;
            }
            break;

        case 'g':
            char option2 ='x';
            while(option2 != 'z'){
                switch (option2) {

                case 'h':
                    cout << "Introduce los indices de las figuras a comparar: " << endl;
                    cin >> a;
                    cin >> b;
                    if(figuras.at(a)->getArea() > figuras.at(b)->getArea()){
                        cout << "La figura " << a << " es mayor que la figura " << b << endl;
                    }else{
                        cout << "La figura " << a << " no es mayor que la figura " << b << endl;
                    }
                    break;

                case 'i':
                    cout << "Introduce los indices de las figuras a comparar: " << endl;
                    cin >> a;
                    cin >> b;
                    if(figuras.at(a)->getArea() >= figuras.at(b)->getArea()){
                        cout << "La figura " << a << " es mayor o igual que la figura " << b << endl;
                    }else{
                        cout << "La figura " << a << " no es mayor o igual que la figura " << b << endl;
                    }
                    break;

                case 'j':
                    cout << "Introduce los indices de las figuras a comparar: " << endl;
                    cin >> a;
                    cin >> b;
                    if(figuras.at(a)->getArea() < figuras.at(b)->getArea()){
                        cout << "La figura " << a << " es menor que la figura " << b << endl;
                    }else{
                        cout << "La figura " << a << " no es menor que la figura " << b << endl;
                    }
                    break;

                case 'k':
                    cout << "Introduce los indices de las figuras a comparar: " << endl;
                    cin >> a;
                    cin >> b;
                    if(figuras.at(a)->getArea() <= figuras.at(b)->getArea()){
                        cout << "La figura " << a << " es menor o igual que la figura " << b << endl;
                    }else{
                        cout << "La figura " << a << " no es menor o igual que la figura " << b << endl;
                    }
                    break;
                }

                showMenu2();
                cin >> option2;

            }
            break;

        }

        showMenu();
        cin >> option;
    }

    cout << "Hasta pronto!" << endl;
    return 0;
}
