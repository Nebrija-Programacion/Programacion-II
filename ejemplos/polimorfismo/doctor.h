#ifndef DOCTOR_H
#define DOCTOR_H

#include "worker.h"

class Doctor : public Worker
{
public:
    Doctor();

    void printProfessionalInfo() const;
};

#endif // DOCTOR_H
