#ifndef LIST_H
#define LIST_H

#include "figure.h"


class List
{
public:
    List(Figure *d);
     void push_back(Figure* d);
    void erase(int i);
    Figure *getFigure() const;
    void setFigure(Figure *value);
    List *getNext() const;
    void setNext(List *value);
    List *getPrev() const;
    void setPrev(List *value);
private:
    Figure *figure;
    List *next;
    List *prev;
};

#endif // LIST_H
