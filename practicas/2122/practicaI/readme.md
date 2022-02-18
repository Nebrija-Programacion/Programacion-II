## Práctica I

Partiendo del ejemplo de la sesión 3 de clase (Pila realizada con clases y punteros inteligentes) añadir los siguientes métodos a la clase Stack (se podrán añadir todo los elementos necesarios para alcanzar el resultado).

 - size() -> devolverá el tamaño de la pila.
 - at(int i) -> devolverá el Nodo en la posición i-esima de la pila. El elemento en la parte superior (el último en ser introducido) ocupará la posición 0, y la posición se irá incrementando según se avance en la pila.
 - bottom() -> devolverá el primer Nodo introducido en la pila (no lo borra).
 - pop_bottom() -> devolverá el primer Nodo introducido en la pila **y lo borra**.  

Realizar el siguiene programa de ejemplo para comprobar el funzionamiento.

```cpp
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
  cout << pila.size(); // mostrara 2

  cout << pila.at(1)->getData() << "\n"; // mostrara 1
  cout << pila.bottom()->getData() << "\n"; // mostrara 1
  cout << pila.pop_bottom()->getData() << "\n"; // mostrara 1
  pila.display(); // mostrara 2 - 
  
  

  return  0;

}

