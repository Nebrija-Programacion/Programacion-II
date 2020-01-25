#ifndef VECTOR3_H
#define VECTOR3_H

#include <iostream>

using namespace std;

class Vector3{
    friend istream & operator >> (istream & input, Vector3 & v);
    friend ostream & operator << (ostream & os, Vector3 const & v);
    friend Vector3 operator + (Vector3 const & v1, Vector3 const & v2);
    friend Vector3 operator - (Vector3 const & v1, Vector3 const & v2);
    friend float operator * (Vector3 const & v1, Vector3 const & v2);
    friend bool operator < (Vector3 const & v1, Vector3 const & v2);

public:
    Vector3();
    Vector3(float x, float y, float z);
    float getModule() const;

protected:
    float x,y,z;
};

istream & operator >> (istream & input, Vector3 & v);
ostream & operator << (ostream & os, Vector3 const & v);
Vector3 operator + (Vector3 const & v1, Vector3 const & v2);
Vector3 operator - (Vector3 const & v1, Vector3 const & v2);
float operator * (Vector3 const & v1, Vector3 const & v2);
bool operator < (Vector3 const & v1, Vector3 const & v2);

#endif // VECTOR3_H
