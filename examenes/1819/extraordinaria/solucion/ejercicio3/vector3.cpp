#include "vector3.h"
#include <math.h>

Vector3::Vector3():x{0},y{0},z{0}
{

}

Vector3::Vector3(float x, float y, float z):x{x},y{y},z{z}
{

}

float Vector3::getModule() const
{
    return sqrt(x*x + y*y + z*z);
}

istream & operator >> (istream & input, Vector3 & v){
    input >> v.x >> v.y >> v.z;
    return input;
}

ostream & operator << (ostream & os, const Vector3 &v){
    os << "("<< v.x << ", " << v.y << ", " << v.z << ")";
    return os;
}

Vector3 operator +(const Vector3 &v1, const Vector3 &v2)
{
    float x = v1.x + v2.x;
    float y = v1.y + v2.y;
    float z = v1.z + v2.z;
    return Vector3(x,y,z);
}

Vector3 operator -(const Vector3 &v1, const Vector3 &v2)
{
    float x = v1.x - v2.x;
    float y = v1.y - v2.y;
    float z = v1.z - v2.z;
    return Vector3(x,y,z);
}

float operator *(const Vector3 &v1, const Vector3 &v2)
{
    float x = v1.x * v2.x;
    float y = v1.y * v2.y;
    float z = v1.z * v2.z;
    return x + y + z;
}

bool operator <(const Vector3 &v1, const Vector3 &v2)
{
    return (v1.getModule() < v2.getModule());
}
