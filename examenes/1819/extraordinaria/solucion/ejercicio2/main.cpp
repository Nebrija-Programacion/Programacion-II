#include <iostream>

using namespace std;

#include "vector3.h"

int main(){
    Vector3 v1;
    Vector3 v2;

    cout << "Introduce los tres valores del primer vector separados por espacio y pulsa enter" << std::endl;
    cin >> v1;

    cout << "Introduce los tres valores del segundo vector separados por espacio y pulsa enter" << std::endl;
    cin >> v2;

    cout <<"Vector 1: "<< v1 << endl;
    cout <<"Vector 2: "<< v2 << endl;

    cout << "Suma: " << (v1 + v2) << endl;
    cout << "Resta: " << (v1 - v2) << endl;
    cout << "Producto escalar: " << (v1 * v2) << endl;
}
