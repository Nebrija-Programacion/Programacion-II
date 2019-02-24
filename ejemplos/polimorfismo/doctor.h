#ifndef DOCTOR_H
#define DOCTOR_H

#include "worker.h"

class Doctor : public Worker
{
public:
    Doctor();

    //It does not need to be virtual, because class Doctor has no children
    void printProfessionalInfo() const;
};

#endif // DOCTOR_H
