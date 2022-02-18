#ifndef STACK_H
#define STACK_H

#include <memory>
#include "node.h"

using namespace std;

class Stack
{
public:
    Stack();
    void push(shared_ptr<Node> n);
    shared_ptr<Node> pop();
    void display() const;
    int size() const;
    shared_ptr<Node> at(int i) const;
    shared_ptr<Node> bottom() const;
    shared_ptr<Node> pop_bottom();

private:
    shared_ptr<Node> top;
    int s;
};

#endif // STACK_H
