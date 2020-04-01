#include <iostream>
#include "listin.h"

using namespace std;

int main()
{

    Listin listin;

    try{
        std::string option{"x"};
        while(option != "q"){
            std::cout << "Introduzca una opción: \n";
            std::cout << "a \tAñadir persona\n";
            std::cout << "l \tListar todas las personas\n";
            std::cout << "b \tBuscar una persona por nombre\n";
            std::cout << "le \tListar todas las personas de una determinda edad\n";
            std::cout << "q \tSalir\n";
            std::cin >> option;

            if(option == "a"){
                std::cout << "Introduzca nombre, edad y telefono: ";
                std::string nombre,telefono; int edad;
                std::cin >> nombre >> edad >> telefono;
                listin.addPerson(new Person(nombre, edad, telefono));
            }else if(option == "l"){
                listin.forEach([](Person* p)->void {
                    std::cout << *p;
                    std::cout << "----------\n";
                });

            }else if(option == "b"){
                std::cout << "Introduzca nombre de la pesona a buscar: ";
                std::string nombre; std::cin >> nombre;
                Person* p = listin.find([&](Person * p)->bool{
                   return p->getNombre()==nombre;

                });
                if(p) std::cout << *p << "------------\n";

            }else if(option == "le"){
                std::cout << "Introduzca la edad que desea buscar: ";
                int edad; std::cin >> edad;
                Listin result = listin.filter([&](Person* p)->bool{
                    return p->getEdad() == edad;
                });

                result.forEach([](Person* p)->void {
                    std::cout << *p;
                    std::cout << "----------\n";
                });

            }
        }
    }catch(std::string e){
        std::cout << "ERROR: " << e << "\n";
    }


    cout << "Adios, gracias!!" << endl;
    return 0;
}
