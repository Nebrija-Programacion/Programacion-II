#ifndef POLICEMAN_H
#define POLICEMAN_H

#include "worker.h"

class PoliceMan : public Worker
{
public:
    PoliceMan();

    //It does not need to be virtual, because class PoliceMan has no children
    void printProfessionalInfo() const;
};

#endif // POLICEMAN_H
