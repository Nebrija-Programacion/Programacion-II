#ifndef EDITORIAL_H
#define EDITORIAL_H

#include <string>

using namespace std;

class Editorial
{
public:
    Editorial(string const & nombre, string const & pais, string const & web);

    const string &getNombre() const;
    void setNombre(const string &newNombre);

    const string &getPais() const;
    void setPais(const string &newPais);

    const string &getWeb() const;
    void setWeb(const string &newWeb);

private:
    string nombre;
    string pais;
    string web;
};

#endif // EDITORIAL_H
