//
//  main.cpp
//  Actividad2
# include  <iostream>
# include  <vector>
# include  "Figura.h"
# include  "Cuadrado.h"
# include  "Circulo.h"
# include  "Triangulo.h"
using namespace std;

int  main ()
{
    char aux=s;
    float value =0;
    
    vector <Figura *> figuras;
    
    while (aux! = ' x ' ) {
        switch(aux) {
            caso  ' s ' :
                cout << " Escoge una opcion: " << endl <<
            " (a) Anadir Cuadrado. " << endl <<
            " (b) Anadir Triangulo. " << endl <<
            " (c) Anadir Circulo. " << endl <<
            " (d) Imprimir figuras. " << endl <<
            " (e) Eliminar figura. " << endl <<
            " (f) Tienen los mismos parámetros. " << endl <<
            " (g) comparando áreas. " << endl <<
            " (h) Salir. " << endl;
            cin >> aux;
            break ;
            caso  ' a ' :
            cout << " Introduce el lado del cuadrado: " ;
            cin >> value;
            figuras push_back ( nuevo  Cuadrado (valor));
            aux = ' s ' ;
            break ;
            
            caso  ' b ' :
            cout << " Introduce el lado del triangulo: " ;
            cin >> value;
            figuras push_back ( nuevo  Triangulo (valor));
            aux = ' s ' ;
            break ;
            
            caso  ' c ' :
            cout << " Introduce el radio del circulo: " ;
            cin >> value;
            figuras push_back ( nuevo  Circulo (valor));
            aux = ' s ' ;
            break ;
            
            caso  ' e ' :
            int a
            cout << " Dime que el indice para eliminar: " ; cin >> a;
            figuras borrar (figuras. comenzar () + a);
            aux = ' s ' ;
            braek ;
            
            caso  ' f ' :
            int b;
            cout << " Dime la posicion de figura 1 y la 2 " ; cin >> a; cin >> b;
            if (figuras. at (a) == figuras. at (b)) {
                cout << " Tienen el mismo parametro " << endl;
            } else {
                cout << " No tienen el mismo parametro " << endl;
            }
            aux = ' s ' ;
            break;
            
            caso  ' g ' :
            char c;
            cout << " Dime la comparacion (>, <ó =): " ; cin >> c;
            cout << " Dime las posiciones a comparar: " ; cin >> a; cin >> b;
            si (c == ' > ' ) {
                if (figuras. at (a) -> getArea ()> figuras. at (b) -> getArea ()) {
                    cout << " Es mayor la figura " << a << " que la " << b << endl;
                } else {
                    cout << " No es mayor la figura " << a << " que la " << b << endl;
                }
            }
            
            si (c == ' < ' ) {
                if (figuras. at (a) -> getArea () <figuras. at (b) -> getArea ()) {
                    cout << " Es menor la figura " << a << " que la " << b << endl;
                } else {
                    cout << " No es menor la figura " << a << " que la " << b << endl;
                }
            }
            si (c == ' = ' ) {
                if (figuras. at (a) -> getArea () == figuras. at (b) -> getArea ()) {
                    cout << " Tiene el mismo area la figura " << a << " que la " << b << endl;
                } else {
                    cout << " No tiene el mismo área la figura " << a << " que la " << b << endl;
                }
            }
            
            aux = ' s ' ;
             break;
            
            caso  ' d ' :
            para ( auto figura: figuras) {
                cout << * figura;
            }
            aux = ' s ' ;
            break ;
        
            default :
            aux = ' h ' ;
        }
    }
    
    cout << " El programa se esta cerrando. " << endl;
    return   0 ;
    }
