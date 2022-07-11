#include "libro.h"

Libro::Libro(const string &titulo, const string &anio, shared_ptr<Autor> autor, shared_ptr<Editorial> editorial):
    titulo{titulo}, anio{anio}, autor{autor}, editorial{editorial}
{

}

const string &Libro::getTitulo() const
{
    return titulo;
}

void Libro::setTitulo(const string &newTitulo)
{
    titulo = newTitulo;
}

const string &Libro::getAnio() const
{
    return anio;
}

void Libro::setAnio(const string &newAnio)
{
    anio = newAnio;
}

const shared_ptr<Autor> &Libro::getAutor() const
{
    return autor;
}

void Libro::setAutor(const shared_ptr<Autor> &newAutor)
{
    autor = newAutor;
}

const shared_ptr<Editorial> &Libro::getEditorial() const
{
    return editorial;
}

void Libro::setEditorial(const shared_ptr<Editorial> &newEditorial)
{
    editorial = newEditorial;
}
