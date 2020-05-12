#include <iostream>
#include <memory>
#include "lista.h"

using namespace std;
using std::shared_ptr;
using std::make_shared;

class Persona{
public:
    Persona(string name, int age): name{name}, age{age}{};

    int getAge() const;
    void setAge(int value);

    string getName() const;
    void setName(const string &value);

private:
    int age;
    string name;
};

ostream & operator<<(ostream &os, shared_ptr<Persona> p){
    os << p->getName() << ": "<<  p->getAge();
    return os;
}

int main()
{
    Lista<shared_ptr<Persona> > personas;

    personas.push_back(make_shared<Persona>("Juan", 23));
    personas.push_back(make_shared<Persona>("Lucia", 22));
    personas.push_front(make_shared<Persona>("Antonio", 20));
    personas.push_front(make_shared<Persona>("Agueda", 19));

    std::cout << personas << "\n";

    // filter older than 21

    auto filtered = personas.filter([](shared_ptr<Persona> p){
            return p->getAge() > 21;
    });

    std::cout << filtered << "\n";

    // find and erase Lucia

    int index = personas.findIndex([](shared_ptr<Persona> p) {
             return p->getName() == "Lucia";
    });

    if(index != -1) personas.erase(index);

    std::cout << personas << "\n";


    return 0;
}

int Persona::getAge() const
{
return age;
}

void Persona::setAge(int value)
{
age = value;
}

string Persona::getName() const
{
return name;
}

void Persona::setName(const string &value)
{
name = value;
}
