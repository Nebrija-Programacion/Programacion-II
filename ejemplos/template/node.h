#ifndef NODE_H
#define NODE_H

#include "data.h"

template<class T>
class Node
{
public:
    Node(Data<T> d);

    Data<T> getData() const;

protected:
    Data<T> data;
};

template<class T>
Node<T>::Node(Data<T> d):
    data{d}
{

}

template<class T>
Data<T> Node<T>::getData() const
{
    return data;
}


#endif // NODE_H
