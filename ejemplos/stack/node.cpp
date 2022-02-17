#include "node.h"

Node::Node(int d)
{
    data = d;
}

int Node::getData() const
{
    return data;
}

void Node::setData(int newData)
{
    data = newData;
}

const shared_ptr<Node> &Node::getNext() const
{
    return next;
}

void Node::setNext(const shared_ptr<Node> &newNext)
{
    next = newNext;
}
