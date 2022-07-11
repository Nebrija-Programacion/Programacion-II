#include <iostream>
#include "ejercicio3.h"

using namespace std;

int main()
{
    Table<int> int1{1,2,3,4};
    Table<int> int2{3,2,3,4};
    Table<string> string1{"hola", "que", "tal", "estas"};
    Table<Complex> complex1{Complex{1,2},Complex{1,5},Complex{4,2},Complex{3,2}};

    cout << int1 << "\n";
    cout << int2 << "\n";
    cout << string1 << "\n";
    cout << complex1 << "\n";




    return 0;
}

