#include <iostream>
#include <vector>
#include "figura.h"
#include "cuadrado.h"
#include "circulo.h"
#include "triangulo.h"

using namespace std;

void showMenu(){
    cout << "\nQue deseas hacer? "<< endl <<
            "(a) Anadir figuras. " << endl <<
            "(i) Imprimir figuras. " << endl <<
            "(e) Eliminar figuras. " << endl <<
            "(c) Comparar figuras. " << endl <<
            "(x) Salir. " << endl;
}
void showMenu2(){
    cout << "(s) Anadir Cuadrado. " << endl <<
            "(t) Anadir Triangulo. " << endl <<
            "(r) Anadir Circulo. " << endl <<
            "(x) Salir. " << endl;
}
int main()
{
    try{
        char aux='z';
        float value{0};
        vector<Figura*> figuras;
        int a,b;
        while(aux != 'x'){
            switch(aux){
            case 'a':
                while(aux != 'x'){
                    showMenu2();
                    cin >> aux;
                    switch(aux){
                    case 's':
                        cout << "Introduce el lado del cuadrado: ";
                        cin >> value;
                        figuras.push_back(new Cuadrado(value));
                        break;
                    case 't':
                        cout << "Introduce el lado del triangulo: ";
                        cin >> value;
                        figuras.push_back(new Triangulo(value));
                        break;
                    case 'r':
                        cout << "Introduce el radio del circulo: ";
                        cin >> value;
                        figuras.push_back(new Circulo(value));
                        break;
                    }
                }
                cout << "Has introducido las siguientes figuras: \n";
            case 'i':
                for(auto figura:figuras){
                    figura->print();
                }
                break;
            case'e':
                cout << "Dime el indice de la figura que quieres eliminar.\n";
                cout << "Recuerda que el primer indice es el 0.\n";
                for(auto figura:figuras){
                    figura->print();
                }
                cin >> a;
                figuras.erase(figuras.begin()+a);
                break;
            case 'c':
                char c;
                cout << "Dime que comparacion quieres hacer (>, <, =): "; cin >> c;
                cout << "Dime las posiciones a comparar: ";
                cout << "Recuerda que el primer indice es el 0.\n";
                for(auto figura:figuras){
                    figura->print();
                }
                cout << "Dime el primer indice.\n";
                cin >> a;
                cout << "Dime el segundo indice.\n";
                cin >> b;
                if(c == '>'){
                    if(figuras.at(a)->getArea() > figuras.at(b)->getArea()){
                        cout << "La figura " << a << " es mayor que la figura " << b << endl;
                    }else{
                        cout << "La figura " << a << " es menor que la figura " << b << endl;
                    }
                }
                if(c == '<'){
                    if(figuras.at(a)->getArea() < figuras.at(b)->getArea()){
                        cout << "La figura " << a << " es menor que la figura " << b << endl;
                    }else{
                        cout << "La figura " << a << " es mayor que la figura " << b << endl;
                    }
                }
                if(c == '='){
                    if(figuras.at(a)->getArea() == figuras.at(b)->getArea()){
                        cout << "La figura " << a << " tiene el mismo area que la figura " << b << endl;
                    }else{
                        cout << "La figura " << a << " tiene diferente area que la figura " << b << endl;
                    }
                }
            }
            showMenu();
            cin >> aux;
        }
        cout << "Se acabo" << endl;
        return 0;
    }catch(string e){
        cout << e << endl;
        return -1;
    }
}
