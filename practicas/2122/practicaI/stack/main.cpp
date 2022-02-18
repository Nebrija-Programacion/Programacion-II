#include  <iostream>
#include  "stack.h"
#include  "node.h"
#include  <memory>

using  namespace  std;

int  main()

{

  Stack  pila;

  auto  n1  =  make_shared<Node>(Node{1});
  auto  n2  =  make_shared<Node>(Node{2});
  auto  n3  =  make_shared<Node>(Node{3});

  pila.push(n1);
  pila.push(n2);
  pila.push(n3);

  pila.display(); // mostrara 3 - 2 - 1 -
  cout  <<  pila.pop()->getData()  <<  "\n"; // mostrara 3
  pila.display(); // mostrara 2 - 1 -
  cout << pila.size() << "\n"; // mostrara 2

  cout << pila.at(1)->getData() << "\n"; // mostrara 1
  cout << pila.bottom()->getData() << "\n"; // mostrara 1
  cout << pila.pop_bottom()->getData() << "\n"; // mostrara 1
  pila.display(); // mostrara 2 -



  return  0;

}
