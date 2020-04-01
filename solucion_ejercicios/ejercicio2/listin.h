#ifndef LISTIN_H
#define LISTIN_H

#include <vector>
#include <functional>
#include "person.h"

class Listin
{
public:
    Listin();
    ~Listin();
    void addPerson(Person* p);
    void forEach(std::function<void(Person*)> op) const;
    Person* find(std::function<bool(Person*)> op) const;
    Listin filter(std::function<bool(Person*)> op) const;


private:
    std::vector<Person*> data;
};

#endif // LISTIN_H
