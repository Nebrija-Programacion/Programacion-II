#include "bombero.h"

Bombero::Bombero(float b, int f, const string &n, int birth):Persona{birth, n, "bombero"}
{
    setBiceps(b);
    setFires(f);
}

float Bombero::getBiceps() const
{
    return biceps;
}

void Bombero::setBiceps(float newBiceps)
{
    if(newBiceps <= 0) throw string{"wrong biceps lenght"};
    biceps = newBiceps;
}

int Bombero::getFires() const
{
    return fires;
}

void Bombero::setFires(int newFires)
{
    if(fires < 0) throw string{"wrong number of fires"};
    fires = newFires;
}
