#include "listin.h"

Listin::Listin()
{

}

Listin::~Listin()
{
    // clear memory
    for(auto p: data){
        delete p;
    }

}

void Listin::addPerson(Person *p)
{
    if(p) data.push_back(p);
    else throw std::string{"Person is wrong"};
}

void Listin::forEach(std::function<void (Person *)> op) const
{
    for(auto p: data){
        op(p);
    }
}

Person *Listin::find(std::function<bool (Person *)> op) const
{
    for(auto p:data){
        if(op(p)) return p;
    }

    return nullptr;
}

Listin Listin::filter(std::function<bool (Person *)> op) const
{
    Listin result;
    for(auto p:data){
        if(op(p)) result.addPerson(p);
    }
    return result;
}
