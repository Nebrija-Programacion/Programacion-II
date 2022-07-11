#include "autor.h"

Autor::Autor(const string &nombre, const string &idioma):nombre{nombre}, idioma{idioma}
{

}

const string &Autor::getNombre() const
{
    return nombre;
}

void Autor::setNombre(const string &newNombre)
{
    nombre = newNombre;
}

const string &Autor::getIdioma() const
{
    return idioma;
}

void Autor::setIdioma(const string &newIdioma)
{
    idioma = newIdioma;
}



