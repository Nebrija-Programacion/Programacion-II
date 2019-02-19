#include "list.h"

List::List(Figure *d):
    figure{d},
    next{nullptr},
    prev{nullptr}
{

}

Figure *List::getFigure() const
{
    return figure;
}

void List::setFigure(Figure *value)
{
    figure = value;
}

List *List::getNext() const
{
    return next;
}

void List::setNext(List *value)
{
    next = value;
}

List *List::getPrev() const
{
    return prev;
}

void List::setPrev(List *value)
{
    prev = value;
}

void List::push_back(Figure *d)
{
    if(next) next->push_back(d);
    else{
        next = new List(d);
        next->setPrev(this);
    }
}
void List::erase(int i)
{
    int j{0};
    List *it;
    for (it = getNext(); it != nullptr; it = it->getNext()){
        if (j!=i && it==nullptr) throw string{"ERROR"};
        else if(j!=i && it!=nullptr) j++;
        else {
            it->getPrev()->setNext(it->getNext());
            it->getNext()->setPrev(it->getPrev());
            delete it;
            return;
        }

    }
}
