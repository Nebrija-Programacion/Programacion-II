#include <iostream>
#include <vector>
#include "figura.h"
#include "cuadrado.h"
#include "circulo.h"
#include "triangulo.h"


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
                "(r) Anadir Circulo. " << endl <<
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
                if(figuras.at(a) == figuras.at(b)){
                    cout << "Tienen el mismo parametro " << endl;
                }else{
                    cout << "No tienen el mismo parametro " << endl;
                }
                aux ='m';
                break;
                
            case 'a':
                char c;
                cout << "Dime la comparacion (>, < ó =): "; cin >> c;
                cout << "Dime las posiciones a comparar: "; cin >> a; cin >> b;
                if(c == '>'){
                    if(figuras.at(a)->getArea() > figuras.at(b)->getArea()){
                        cout << "Es mayor la figura " << a << " que la " << b << endl;
                    }else{
                        cout << "No es mayor la figura " << a << " que la " << b << endl;
                    }
                }
                
                if(c == '<'){
                    if(figuras.at(a)->getArea() < figuras.at(b)->getArea()){
                        cout << "Es menor la figura " << a << " que la " << b << endl;
                    }else{
                        cout << "No es menor la figura " << a << " que la " << b << endl;
                    }
                }
                if(c == '='){
                    if(figuras.at(a)->getArea() == figuras.at(b)->getArea()){
                        cout << "Tiene el mismo area la figura " << a << " que la " << b << endl;
                    }else{
                        cout << "No tiene el mismo area la figura " << a << " que la " << b << endl;
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
    
    cout << "Byeeeeee" << endl;
    return 0;
    }
