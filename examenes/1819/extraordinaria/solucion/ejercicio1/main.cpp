#include <iostream>
#include <vector>

#include "caballodomestico.h"
#include "caballosalvaje.h"

using namespace std;

int main()
{
    vector<Caballo*> caballos;

    string nombre, owner, sexo;
    int edad;

    int opcion = 9;

    while(opcion != 0){
        cout << "¿Que quieres hacer?" << endl;
        cout << "1. Nuevo Caballo Salvaje " << endl;
        cout << "2. Nuevo Caballo Domestico " << endl;
        cout << "3. Imprimir lista de caballos " << endl;
        cout << "0. Salir " << endl;
        cin >> opcion;

        if(opcion == 1){
            cout << "Nombre: "; cin >> nombre;
            cout << "Sexo: "; cin >> sexo;
            cout << "Edad: "; cin >> edad;
            Caballo* caballo = new CaballoSalvaje{nombre, sexo,edad};
            caballos.push_back(caballo);
        }

        if(opcion == 2){
            cout << "Nombre: "; cin >> nombre;
            cout << "Sexo: "; cin >> sexo;
            cout << "Edad: "; cin >> edad;
            cout << "Propietario: "; cin >> owner;
            Caballo* caballo = new CaballoDomestico{nombre, sexo,edad, owner};
            caballos.push_back(caballo);
        }

        if(opcion == 3){
            cout << " =================================================== " << endl << endl;
            cout << "Lista de Caballos: " << endl;
            for(auto caballo:caballos){
                caballo->printInfo();
                cout << " --------------------------------------------------- " << endl << endl;
            }
            cout << " =================================================== " << endl << endl;
        }
    }

    // liberar toda la memoria reservada
    for(auto caballo:caballos){
        delete caballo;
    }


    return 0;
}
