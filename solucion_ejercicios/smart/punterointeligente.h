#ifndef PUNTEROINTELIGENTE_H
#define PUNTEROINTELIGENTE_H

#include<iostream>

template<class T>
class PunteroInteligente
{
public:
    PunteroInteligente(T dato);
    ~PunteroInteligente();
    T* get() const;

private:
    T* punt;
};

template<class T>
PunteroInteligente<T>::PunteroInteligente(T dato)
{
    punt = new T{dato};
}

template<class T>
PunteroInteligente<T>::~PunteroInteligente()
{
    std::cout << "Libera espacio de memoria\n";
    delete punt;
}

template<class T>
T *PunteroInteligente<T>::get() const
{
    return punt;
}



#endif // PUNTEROINTELIGENTE_H
