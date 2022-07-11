#ifndef EJERCICIO3_H
#define EJERCICIO3_H

#include <array>
#include <ostream>

using namespace std;

template<class T>
class Table{
public:
    Table(T const & f1c1,  T const & f1c2, T const & f2c1, T const & f2c2){
        data={f1c1, f1c2, f2c1, f2c2};
    }

    const array<T, 4> &getData() const{return data;};

private:
    array<T,4> data;
};

template<class T>
ostream & operator<<(ostream & os, Table<T> const & t){
    os << t.getData().at(0) << "\t" << t.getData().at(1) << "\n"
       << t.getData().at(2) << "\t" << t.getData().at(3) << "\n";
    return os;
}

struct Complex{
    float r,i;
};

ostream & operator<<(ostream & os, Table<Complex> const & t){
    os << t.getData().at(0).r << " + " <<t.getData().at(0).i << "i" << "\t"
              << t.getData().at(1).r << " + " <<t.getData().at(1).i << "i" << "\n"
              << t.getData().at(2).r << " + " <<t.getData().at(2).i << "i" << "\t"
              << t.getData().at(3).r << " + " <<t.getData().at(3).i << "i" << "\n";
    return os;
}

#endif // EJERCICIO3_H
