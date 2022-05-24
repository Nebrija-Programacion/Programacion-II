#ifndef FUTBOLISTA_H
#define FUTBOLISTA_H

#include "persona.h"

class Futbolista : public Persona
{
public:
    Futbolista(int m, int g, int b, const string &n);
    int getGoles() const;
    void setGoles(int newGoles);

    int getMillones() const;
    void setMillones(int newMillones);

private:
    int goles;
    int millones;
};

#endif // FUTBOLISTA_H
