#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "complex.h"

template <class T>
T getMax(T const & a, T const & b){
    if(a > b) return a;
    else return b;
}

template<>
Complex getMax<Complex>(Complex const & a, Complex const & b){
    if(a.module() > b.module()) return a;
    else return b;
}

#endif // FUNCTIONS_H
