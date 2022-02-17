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

private:
    shared_ptr<Node> top;

};

#endif // STACK_H
