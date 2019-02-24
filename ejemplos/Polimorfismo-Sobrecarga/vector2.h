#ifndef VECTOR2_H
#define VECTOR2_H

#include "vector.h"

class Vector2 : public Vector
{
public:
    Vector2(double x, double y);

    double getMod() const;

    double getX() const;

    double getY() const;

private:
    double x,y;
};

// Overloading == operator
bool operator == (Vector2 const & v1, Vector2 const &v2);

#endif // VECTOR2_H
