#include <iostream>

using namespace std;

#include "persona.h"

int main()
{
    Persona yo(40, "Alberto");
    Persona ella(37, "Nieves");
    cout << yo << endl;
    ++yo;
    cout << yo << endl;
    if(yo > ella){
        cout << yo << " es mayor que " << ella << endl;
    }
    return 0;
}
