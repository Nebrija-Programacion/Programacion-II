#include "listado.h"
using namespace std;

int main()
{
    Listado<Persona> listaPersonas;
    bool condicion = true;
    int accion, nacimiento;
    string clave;
    string nombre;
    string telefono;

    while(condicion == true){
        cout<<"1.\tAñadir Persona\n"<<"2.\tEliminar Persona\n"<<"3.\tBuscar Persona\n"<<"4.\tListar\n"<<"5.\tAcabar Programa\n"<<"Elige una accion:";
        cin>>accion;
        while(accion < 1 || accion > 5){
            cout<<"Accion no valida por favor elija una correcta: ";
            cin>>accion;
        }

        cout<<endl;
        switch (accion) {
            case 1:
                cout<<"Introduce la clave para la persona:";cin>>clave;
                cout<<"Introduce el nombre de la persona:";cin>>nombre;
                cout<<"Introduce el año de nacimiento de la persona:";cin>>nacimiento;
                cout<<"Introduce el telefono de la persona:";cin>>telefono;
                cout<<endl;
                try {
                    auto a = std::make_shared<Data<Persona>>(Data<Persona>(clave,Persona{nombre,nacimiento,telefono}));
                    listaPersonas.inserta(a);
                } catch (string msg) {
                    cout<<msg<<endl;
                }
                break;
            case 2:
                try {
                    cout<<"Introduce la clave de la persona a borrar:";cin>>clave;
                    cout<<endl;
                    listaPersonas.elimina(clave);
                } catch (string msg) {
                    cout<<msg<<endl;
                }
                break;
            case 3:
                try {
                    cout<<"Introduce la clave de la persona que deseas buscar:";cin>>clave;
                    auto encontrada = listaPersonas.find([=](std::shared_ptr<Data<Persona> > a){
                        return a->getClave() == clave;
                    });
                    if(encontrada) std::cout<<*encontrada<<"\n";
                    else std::cout << "Persona no encontrada\n";
                } catch (string msg) {
                    cout<<msg<<endl;
                }
                break;
            case 4:
                cout<<listaPersonas;
                break;
            case 5:
                condicion = false;
                break;
        }
    }
    return 0;
}
