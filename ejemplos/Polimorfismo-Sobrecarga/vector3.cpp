#include "vector3.h"
#include <math.h>
Vector3::Vector3(double x, double y, double z):
    x{x},
    y{y},
    z{z}
{

}

double Vector3::getMod() const
{
    return sqrt(x*x + y*y + z*z);
}

double Vector3::getX() const
{
    return x;
}

double Vector3::getY() const
{
    return y;
}

double Vector3::getZ() const
{
    return z;
}

bool operator ==(const Vector3 &v1, const Vector3 &v2)
{
    return ( (v1.getX() == v2.getX())
             && (v1.getY() && v2.getY())
             && (v1.getZ() == v2.getZ())
             );
}

Vector3 operator +(const Vector3 &v1, const Vector3 &v2)
{
    double x = v1.getX() + v2.getX();
    double y = v1.getY() + v2.getY();
    double z = v1.getZ() + v2.getZ();
    return Vector3{x,y,z};
}

ostream& operator <<(ostream &os, const Vector3 &v)
{
    os << v.getX() << ", " << v.getY() << ", " << v.getZ();
    return os;
}
