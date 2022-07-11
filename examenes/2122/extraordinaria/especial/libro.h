#ifndef LIBRO_H
#define LIBRO_H

#include <string>
#include <memory>
#include "autor.h"
#include "editorial.h"



using namespace std;

class Libro
{
public:
    Libro(string const & titulo, string const & anio, shared_ptr<Autor> autor, shared_ptr<Editorial> editorial);

    const string &getTitulo() const;
    void setTitulo(const string &newTitulo);

    const string &getAnio() const;
    void setAnio(const string &newAnio);

    const shared_ptr<Autor> &getAutor() const;
    void setAutor(const shared_ptr<Autor> &newAutor);

    const shared_ptr<Editorial> &getEditorial() const;
    void setEditorial(const shared_ptr<Editorial> &newEditorial);

private:
    string titulo;
    string anio;
    shared_ptr<Autor> autor;
    shared_ptr<Editorial> editorial;
};

#endif // LIBRO_H
