#ifndef NODE_H
#define NODE_H

#include <memory>
#include <set>

template<class T>
class Node
{
public:
    Node(std::shared_ptr<T> data):data{data}{};
    std::shared_ptr<T> getData() const;
    void setData(std::shared_ptr<T> d);
    void addNeighbour(std::shared_ptr<Node<T>> n);
    std::set<std::shared_ptr<Node<T>>> getNeighbours() const;

private:
    std::shared_ptr<T> data;
    std::set< std::shared_ptr< Node<T> > > neighbours;
};

template<class T>
std::shared_ptr<T> Node<T>::getData() const
{
    return data;
}

template<class T>
void Node<T>::setData(std::shared_ptr<T> d)
{
    data = d;
}

template<class T>
void Node<T>::addNeighbour(std::shared_ptr<Node<T> > n)
{
    neighbours.insert(n);
}

template<class T>
std::set<std::shared_ptr<Node<T> > > Node<T>::getNeighbours() const
{
    return neighbours;
}



#endif // NODE_H
