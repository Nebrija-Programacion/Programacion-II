#include <iostream>
#include <vector>
#include "figura.h"
#include "cuadrado.h"
#include "circulo.h"
#include "triangulo.h"

void Menus(){
  cout <<  "(0) Anadir un Cuadrado. " << endl;
  cout <<   "(1) Anadir un Triangulo. " << endl;
  cout <<   "(2) Anadir un Circulo. " << endl ;
  cout <<   "(3) Imprimir las figuras anadidas. " << endl ;
  cout <<   "(4) Eliminar cualquier figura. " << endl ;
 cout <<    "(5) Comparar areas de las figuras. " << endl ;
  cout <<   "(6) Salir. " << endl;
}
int main()
{
    int indice=-1;
   int aux;
   bool menu=true;
   vector<Figura*> misFiguras;
   Menus();
   while (menu==true) {
       cout << "Elige una de estas opciones por favor: ";
       float value;
       cin >> aux;
       if(aux==0){ // añade un cuadrado
           cout << "Introduce el lado del cuadrado: ";
             cin >> value;
             misFiguras.push_back(new Cuadrado(value));
             indice++;
             cout <<"Se ha añadido la figura y su indice es: " << indice << endl;
       }
       if(aux==1){ // añade un triangulo
           cout << "Introduce el lado del triangulo: ";
             cin >> value;
             misFiguras.push_back(new Triangulo(value));
             indice++;
             cout <<"Se ha añadido la figura y su indice es: " << indice << endl;
       }
       if(aux==2){// añade un circulo
           cout << "Introduce el radio del circulo: ";
             cin >> value;
             misFiguras.push_back(new Circulo(value));
             indice++;
             cout <<"Se ha añadido la figura y su indice es: " << indice << endl;
       }
       if(aux==3){//imprime las figuras
           for(auto figura:misFiguras){
               cout << *figura;
           }
       }
       if(aux==4){//Aqui lo que hago es eliminar una figura por el indice
           int aux1;
            cout << "Dime que el indice para eliminar: " ;
            cin >> aux1;
            misFiguras.erase(misFiguras.begin()+aux1);
       }
       if(aux==5){//compara las areas
           char aux2;
           int indice1,indice2;
           cout << "Que comparacion quieres hacer?(</>/=) ";
           cin >> aux2;
           cout << "Dime el indice de la figura 1 para comparar: ";
           cin >> indice1;
           cout << "Dime el indice de la figura 2 para comparar: ";
           cin >> indice2;
           if(aux2 == '>'){
               if(misFiguras.at(indice1)->getArea() > misFiguras.at(indice2)->getArea()){
                   cout << "El resultado es: " << indice1 << " > " << indice2 << endl;
               }else{
                   cout << "El resultado es:  " << indice1 << " < " << indice2 << endl;
               }
           }

           if(aux2 == '<'){
               if(misFiguras.at(indice1)->getArea() < misFiguras.at(indice2)->getArea()){
                   cout << "El resultado es:  " << indice1 << " < " << indice2 << endl;
               }else{
                   cout << "El resultado es: " << indice1 << " > " << indice2<< endl;
               }
           }
           if(aux2 == '='){
               if(misFiguras.at(indice1)->getArea() == misFiguras.at(indice2)->getArea()){
                   cout << "El resultado es:  " << indice1 << " = " << indice2 << endl;
               }else{
                   cout << "El resultado es:  " << indice1 << " != " << indice2 << endl;
               }
           }
       }
       if(aux==6){//sale
       menu=false;
       }
   }
}
