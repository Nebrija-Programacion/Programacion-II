#ifndef PROFESIONAL_H
#define PROFESIONAL_H


class Worker
{
public:
    Worker();

    // Pure virtual function
    // Pure ( = 0 )-> because Worker has no implementation of this function
    virtual void printProfessionalInfo() const = 0;

};

#endif // PROFESIONAL_H
