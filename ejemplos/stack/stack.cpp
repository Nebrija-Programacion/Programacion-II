#include "stack.h"
#include <iostream>

using namespace std;

Stack::Stack()
{
    top=nullptr;
}

void Stack::push(shared_ptr<Node> n)
{
    auto aux = top;
    top = n;
    n->setNext(aux);
}

shared_ptr<Node> Stack::pop()
{
    if(!top) return nullptr;
    auto aux = top;
    top = top->getNext();
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
