#ifndef VECTOR3_H
#define VECTOR3_H

#include <ostream>

#include "vector.h"

using namespace std;

class Vector3 : public Vector
{
public:
    Vector3(double x, double y, double z);

    double getMod() const;

    double getX() const;

    double getY() const;

    double getZ() const;

private:
    double x,y,z;
};

bool operator == (Vector3 const & v1, Vector3 const & v2);
Vector3 operator + (Vector3 const &v1, Vector3 const &v2);
ostream& operator << (ostream & os, Vector3 const &v);

#endif // VECTOR3_H
