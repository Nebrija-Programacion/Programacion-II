#include "futbolista.h"

Futbolista::Futbolista(int m, int g, int b, string const & n):Persona{b,n, "futbolista"}
{
    setMillones(m);
    setGoles(g);
}

int Futbolista::getGoles() const
{
    return goles;
}

void Futbolista::setGoles(int newGoles)
{
    if (goles < 0) throw string{"that cannot happen"};
    goles = newGoles;
}

int Futbolista::getMillones() const
{
    return millones;
}

void Futbolista::setMillones(int newMillones)
{
    if(millones < 0) throw string{"impossible"};
    millones = newMillones;
}
