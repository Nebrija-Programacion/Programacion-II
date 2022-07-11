#include <iostream>
#include "libro.h"
#include "autor.h"
#include "editorial.h"
#include <memory>
#include <vector>

using namespace std;

void printAuthorData(shared_ptr<Autor> const & autor, vector<shared_ptr<Libro>> const & libros){
    cout << "Autor:\t" << autor->getNombre() << "\n";
    cout << "Idioma:\t" << autor->getIdioma() << "\n";
    cout << "Libros: \n";
    for(auto libro: libros){
        if(libro->getAutor() == autor){
            cout << "\t- " << libro->getTitulo() << "\n";
        }
    }
    cout << "\n\n";
}

ostream & operator<<(ostream & os, Libro const & libro){
    return os;
}

int main()
{
    vector<shared_ptr<Libro>> libros;

    auto autor1 = make_shared<Autor>(Autor{"Miguel de Cervantes","Español"});
    auto autor2 = make_shared<Autor>(Autor{"William Shakespeare","Ingles"});


    auto editorial1 = make_shared<Editorial>(Editorial{"Alfaguara","España","www.alfaguara.es"});

    auto libro1 = make_shared<Libro>(Libro{"El quijote", "1605", autor1, editorial1});
    auto libro2 = make_shared<Libro>(Libro{"Novelas Ejemplares", "1613", autor1, editorial1});
    auto libro3 = make_shared<Libro>(Libro{"Romeo y Julieta", "1597", autor2, editorial1});
    auto libro4 = make_shared<Libro>(Libro{"Hamlet", "1603", autor2, editorial1});

    libros.push_back(libro1);
    libros.push_back(libro2);
    libros.push_back(libro3);
    libros.push_back(libro4);

    printAuthorData(autor1, libros);
    printAuthorData(autor2, libros);

    cout << *libro1;
    cout << *libro2;
    cout << *libro3;
    cout << *libro4;

    return 0;
}
