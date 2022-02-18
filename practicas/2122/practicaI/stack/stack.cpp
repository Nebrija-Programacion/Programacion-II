#include "stack.h"
#include <iostream>

using namespace std;

Stack::Stack()
{
    top=nullptr;
    s=0;
}

void Stack::push(shared_ptr<Node> n)
{
    auto aux = top;
    top = n;
    n->setNext(aux);
    s++;
}

shared_ptr<Node> Stack::pop()
{
    if(!top) return nullptr;
    auto aux = top;
    top = top->getNext();
    s--;
    return aux;

}

void Stack::display() const
{
    auto it = top;
    while(it != nullptr){
        cout << it->getData() << " - ";
        it = it->getNext();
    }
    cout << "\n";
}

int Stack::size() const
{
    return s;
}

shared_ptr<Node> Stack::at(int i) const
{
    if(i >= s) return nullptr;

    auto aux = top;
    for(int pos{0}; pos <i; pos++ ){
        aux = aux->getNext();
    }
    return aux;
}

shared_ptr<Node> Stack::bottom() const
{
    auto aux = top;
    while(aux->getNext() != nullptr){
        aux = aux->getNext();
    }
    return aux;
}

shared_ptr<Node> Stack::pop_bottom()
{
    auto aux = top;
    while(aux->getNext()->getNext() != nullptr){
        aux = aux->getNext();
    }
    auto ret = aux->getNext();
    aux->setNext(nullptr);
    return ret;

}
