#include <iostream>
#include "stack.h"
#include "node.h"
#include <memory>
using namespace std;

int main()
{
    Stack pila;
    auto n1 = make_shared<Node>(Node{1});
    auto n2 = make_shared<Node>(Node{2});
    auto n3 = make_shared<Node>(Node{3});

    pila.push(n1);
    pila.push(n2);
    pila.push(n3);

    pila.display();

    cout << pila.pop()->getData() << "\n";

    pila.display();

    return 0;
}
