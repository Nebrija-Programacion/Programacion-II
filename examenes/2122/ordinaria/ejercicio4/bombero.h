#ifndef BOMBERO_H
#define BOMBERO_H

#include "persona.h"

class Bombero : public Persona
{
public:
    Bombero(float b, int f, string const & n, int birth);
    float getBiceps() const;
    void setBiceps(float newBiceps);

    int getFires() const;
    void setFires(int newFires);

private:
    float biceps;
    int fires;
};

#endif // BOMBERO_H
