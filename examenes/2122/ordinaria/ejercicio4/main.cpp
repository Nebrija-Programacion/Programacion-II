#include <iostream>
#include <vector>
#include <memory>
#include "bombero.h"
#include "futbolista.h"

using namespace std;

int main()
{
    vector<shared_ptr<Persona>> personas;
    personas.push_back(make_shared<Futbolista>(10,21,1978,"Pedro"));
    personas.push_back(make_shared<Bombero>(12,32,"Luis",1967));

    for(auto p: personas){
        if(p->getJob()=="bombero"){
            auto aux = static_pointer_cast<Bombero>(p);
            std::cout << "Soy un bombero con un biceps de " << aux->getBiceps() << "cm\n";
        }
        if(p->getJob()=="futbolista"){
            auto aux = static_pointer_cast<Futbolista>(p);
            std::cout << "Soy un futbolista y en el banco tengo " << aux->getMillones() << " millones\n";
        }
    }

}
