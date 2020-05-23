#ifndef DATA_T
#define DATA_T
#include <iostream>

template<typename T>
class Data
{
private:
    std::string clave;
    T valor;
public:
    Data(std::string const& _clave, T const & _valor);
    std::string getClave() const;
    void setClave(const std::string &value);
    T getValor() const;
    void setValor(const T &value);
};





template<typename T>
Data<T>::Data(const std::string & _clave, const T &_valor)
{
    clave = _clave;
    valor = _valor;
}

template<typename T>
std::string Data<T>::getClave() const
{
    return clave;
}

template<typename T>
void Data<T>::setClave(const std::string &value)
{
    clave = value;
}

template<typename T>
T Data<T>::getValor() const
{
    return valor;
}

template<typename T>
void Data<T>::setValor(const T &value)
{
    valor = value;
}

template<typename T>
std::ostream & operator<<(std::ostream & os, Data<T> const & d){
    os<<d.getClave()<<":\n"<<d.getValor()<<"\n";
    return os;
}
#endif // DATA_T
