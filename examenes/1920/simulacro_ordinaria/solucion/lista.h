#ifndef LISTA_H
#define LISTA_H

#include <vector>
#include <string>
#include <functional>
#include <ostream>

using std::vector;
using std::string;
using std::function;
using std::ostream;

template <class T>
class Lista{
public:
    Lista(){};
    ~Lista(){};
    void push_back(T const & d);
    void push_front(T const & d);
    void insert(T const & d, int pos);
    void erase(int pos);
    int findIndex( function< bool(T)> const & f);
    Lista<T> filter( function< bool(T)> const & f);
    void forEach(function< bool(T)> const & f);

    vector<T> getData() const;
    void setData(const vector<T> &value);
    T & at(int pos);

private:
    vector<T> data;
};

#endif // LISTA_H

template <class T>
void Lista<T>::push_back(const T &d)
{
    data.push_back(d);
}

template<class T>
void Lista<T>::push_front(const T &d)
{
    data.insert(data.begin(),d);
}

template<class T>
void Lista<T>::insert(const T &d, int pos)
{
    if(pos >= data.size() || pos < 0) throw string{"Out of bounds"};
    data.insert(data.begin() + pos, d);
}

template<class T>
void Lista<T>::erase(int pos)
{
    if(pos >= data.size() || pos < 0) throw string{"Out of bounds"};
    data.erase(data.begin() + pos);
}

template<class T>
int Lista<T>::findIndex(const function<bool (T)> &f)
{
    for(uint i{0}; i < data.size(); i++){
        if(f(data.at(i))) return i;
    }

    return -1;
}

template<class T>
Lista<T> Lista<T>::filter(const function<bool (T)> &f)
{
    Lista<T> result;
    for(auto const & elem: data){
        if(f(elem)) result.push_back(elem);
    }

    return result;

}

template<class T>
void Lista<T>::forEach(const function<bool (T)> &f)
{
    for(auto const & elem: data){
        f(elem);
    }
}

template<class T>
vector<T> Lista<T>::getData() const
{
    return data;
}

template <class T>
void Lista<T>::setData(const vector<T> &value)
{
    data = value;
}

template<class T>
T &Lista<T>::at(int pos)
{
    if(pos >= data.size() || pos < 0) throw string{"Out of bounds"};
    return data.at(pos);
}

template <class T>
ostream & operator<<(ostream &os, Lista<T> p){
    auto data = p.getData();
    for(auto elem: data){
        os << elem << "  --  ";
    }
    return os;
}
