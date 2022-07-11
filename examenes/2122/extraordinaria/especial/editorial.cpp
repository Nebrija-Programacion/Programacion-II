#include "editorial.h"

Editorial::Editorial(const string &nombre, const string &pais, const string &web):nombre{nombre}, pais{pais}, web{web}
{

}

const string &Editorial::getNombre() const
{
    return nombre;
}

void Editorial::setNombre(const string &newNombre)
{
    nombre = newNombre;
}

const string &Editorial::getPais() const
{
    return pais;
}

void Editorial::setPais(const string &newPais)
{
    pais = newPais;
}

const string &Editorial::getWeb() const
{
    return web;
}

void Editorial::setWeb(const string &newWeb)
{
    web = newWeb;
}
