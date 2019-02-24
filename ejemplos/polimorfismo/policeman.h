#ifndef POLICEMAN_H
#define POLICEMAN_H

#include "worker.h"

class PoliceMan : public Worker
{
public:
    PoliceMan();

    void printProfessionalInfo() const;
};

#endif // POLICEMAN_H
