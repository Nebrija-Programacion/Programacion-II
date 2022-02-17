#ifndef NODE_H
#define NODE_H

#include <memory>
using namespace std;
class Node
{
public:
    Node(int d);

    int getData() const;
    void setData(int newData);

    const shared_ptr<Node> &getNext() const;
    void setNext(const shared_ptr<Node> &newNext);

private:
    int data;
    shared_ptr<Node> next;
};

#endif // NODE_H
