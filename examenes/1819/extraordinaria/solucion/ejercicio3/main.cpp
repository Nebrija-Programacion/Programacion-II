#include <iostream>

using namespace std;

#include "vector3.h"


bool operator < (string const & s1, string const &s2){
    return s1.length() < s2.length();
}


template<class T>
T menor(T const & var1, T const & var2){
    if(var1 < var2) return var1;
    else return var2;
}

int main(){
    int n1 = 3;
    int n2 = 7;
    Vector3 v1(2,3,4);
    Vector3 v2(2,7,9);
    string s1 = "programacion";
    string s2 = "algoritmos";

    cout << "El menor número es: " << menor(n1,n2) << endl;
    cout << "El menor vector es: " << menor(v1,v2) << endl;
    cout << "La menor cadena es: " << menor(s1,s2) << endl;

}
