#ifndef VECTOR_H
#define VECTOR_H


class Vector
{
public:
    Vector();

    // Pure polymorphic function
    virtual double getMod() const = 0;
};

#endif // VECTOR_H
