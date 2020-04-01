#include <iostream>
#include <vector>
#include <functional>
#include "person.h"

using namespace std;

void forEach(std::vector<Person*> p, std::function<void(Person*)> op){
    for(auto elem:p){
        op(elem);
    }
}

Person* find(std::vector<Person*> p, std::function<bool(Person*)> op){
    for(auto elem:p){
        if(op(elem)) return elem;
    }

    return nullptr;
}

std::vector<Person*> filter(std::vector<Person*> p, std::function<bool(Person*)> op){
    std::vector<Person*> result;
    for(auto elem:p){
        if(op(elem)) result.push_back(elem);
    }

    return result;
}


int main()
{

    std::vector<Person*> listin;

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
                listin.push_back(new Person(nombre, edad, telefono));
            }else if(option == "l"){
                forEach(listin, [](Person* p)->void {
                    std::cout << *p;
                    std::cout << "----------\n";
                });

            }else if(option == "b"){
                std::cout << "Introduzca nombre de la pesona a buscar: ";
                std::string nombre; std::cin >> nombre;
                Person* p = find(listin, [&](Person * p)->bool{
                   return p->getNombre()==nombre;

                });
                if(p) std::cout << *p << "------------\n";

            }else if(option == "le"){
                std::cout << "Introduzca la edad que desea buscar: ";
                int edad; std::cin >> edad;
                std::vector<Person*> result = filter(listin, [&](Person* p)->bool{
                    return p->getEdad() == edad;
                });

                forEach(result, [](Person* p)->void {
                    std::cout << *p;
                    std::cout << "----------\n";
                });

            }
        }
    }catch(std::string e){
        std::cout << "ERROR: " << e << "\n";
    }

    // clear memory
    for(auto p:listin){
        delete p;
    }

    cout << "Adios, gracias!!" << endl;
    return 0;
}
