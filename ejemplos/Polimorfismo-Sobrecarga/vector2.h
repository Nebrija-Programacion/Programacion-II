#ifndef VECTOR2_H
#define VECTOR2_H

#include <ostream>

#include "vector.h"

using namespace std;

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

// Overloading + operator
Vector2 operator + (Vector2 const & v1, Vector2 const &v2);

ostream& operator << (ostream & os, Vector2 const &v);


#endif // VECTOR2_H
