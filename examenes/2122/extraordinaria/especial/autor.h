#ifndef AUTOR_H
#define AUTOR_H

#include <string>

using namespace std;

class Autor
{
public:
    Autor(string const & nombre, string const & idioma);

    const string &getNombre() const;
    void setNombre(const string &newNombre);

    const string &getIdioma() const;
    void setIdioma(const string &newIdioma);

private:
    string nombre;
    string idioma;

};



#endif // AUTOR_H
