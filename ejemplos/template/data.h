#ifndef DATA_H
#define DATA_H

#include <iostream>

using namespace std;

template <class T>
class Data
{
public:
    Data();
    void setValue(const T &v);
    T getValue() const;

private:
    T value;
};

template <class T>
Data<T>::Data(){
    cout << "constructor " << endl;
}

template <class T>
void Data<T>::setValue(const T &v){
    value = v;
}

template<class T>
T Data<T>::getValue() const
{
    return value;
}


#endif // DATA_H
