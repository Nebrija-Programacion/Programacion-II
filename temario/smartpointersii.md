# Punteros Inteligentes - shared_ptr

Los punteros inteligentes se diferencian de los punteros tradicionales de c++ (`tipo* var`) en que realizan una gestión automatizada de la memoria utilizada, liberándose automáticamente (por lo tanto no es necesario hacer `delete`) cuando la memoria reservada ya no es necesaria.

En el estándard actual de C++ se recomiendo usar **siempre** *smart pointers*.

Aquí vamos a estudiar dos tipos de punteros inteligentes, ambos introducidos desde C++11.
* `unique_ptr`
* `shared_ptr`

## shared_ptr

Una variable de tipo `shared_ptr` es una referencia a un objeto que solo existe en el ámbito de la variable, y que puede ser referenciado por otras variables.

Por ejemplo, si queremos un puntero a un tipo `std::string` y otro a tipo `int`.

```cpp
#include <iostream>
#include <memory>

int main(){
  std::shared_ptr<std::string> pString;
  std::shared_ptr<int> pInt;
  pString = std::make_shared<std::string>("hola");
  pInt = std::make_shared<int>(3);
}
```

También podríamos hacer uso del tipo `auto`.

```cpp
#include <iostream>
#include <memory>

int main(){
  auto pString = std::make_shared<std::string>("hola");
  auto pInt = std::make_shared<int>(3);
}
```

Una vez creado el puntero, puedo de-referenciarlo con `*` del mismo modo que hago con los punteros clásicos

```cpp
#include <iostream>
#include <memory>

int main(){
  auto pString = std::make_shared<std::string>("hola");
  auto pInt = std::make_shared<int>(3);

  std::cout << *pString << "\n"; // -> hola
  std::cout << *pInt << "\n"; // -> 3
}
``` 

En el caso de ser un objeto, puedo acceder a sus miembros con el operador `->` 

```cpp
#include <iostream>
#include <memory>

class Foo{
public:
  Foo(int a):a{a}{}
  int getA()const {return a;}
private:
  int a;
};

int main(){
  auto p = std::make_shared<Foo>(32);
  std::cout << p->getA() << "\n"; // -> 32
}
``` 

Hay que notar, que en ninguno de estos programas estoy haciendo `delete`, porque el programa lo gestiona automáticamente. Veamos un ejemplo del ciclo de vida de un `smart pointer`

```cpp
#include <iostream>
#include <memory>

class Foo{
public:
  Foo(int a):a{a}{}
  int getA()const {return a;}
private:
  int a;
};

int main(){
  auto fil = std::make_shared<int>(21);
  if(true){
    auto p = std::make_shared<int>(32);
    std::cout << *p << "\n"; // -> 32
  } // se libera la memoria de p

  std::cout << *fil << "\n";
  return 0;
} // se libera la memoria de fil
```

Incluso, al ser `shared_ptr`, si tiene varias referencias, saber cuál es el momento oportuno para borrar. Modificando ligeramente el ejemplo anterior.

```cpp
#include <iostream>
#include <memory>

class Foo{
public:
  Foo(int a):a{a}{}
  int getA()const {return a;}
private:
  int a;
};

int main(){
  std::shared_ptr<int> fil;
  if(true){
    auto p = std::make_shared<int>(32);
    std::cout << *p << "\n"; // -> 32
    fil = p;
  } // NO se libera la memoria de p porque la comparte con fil

  std::cout << *fil << "\n";
  return 0;
} // se libera la memoria de fil (que es la misma que p)
```

Como se ha dicho, lo que caracteriza un `shared_ptr` es que el objeto referenciado puede estar referenciado por otras variables. Es decir, **si** puede haber varios punteros apuntando la mismo espacio de memoria. Por lo tanto, los siguientes ejemplos serían **correctos**.

```cpp
#include <iostream>
#include <memory>

void foo(std::shared_ptr<int> p){
  std::cout << *p << "\n";
}

void fii(std::shared_ptr<int> & p){
  std::cout << *p << "\n";
}


int main(){
  auto p = std::make_shared<int>(21);
  
  auto h = p; // CORRECTO, h y p apuntan a lo mismo
  foo(p); // CORRECTO, el parámetro lo estoy pasando como copia
  fii(p); // CORRECTO, el parametro no se copia, es referencia
  return 0;
}
``` 

En este caso, por lo tanto, esto también es correcto.

```cpp
#include <iostream>
#include <memory>
#include <vector>


int main(){
  std::vector<std::shared_ptr<int>> v;
  auto p = std::make_shared<int>(21);
  v.push_back(p);

  return 0;
}
```

Al igual que esto

```cpp
#include <iostream>
#include <memory>
#include <vector>


int main(){
  std::vector<std::shared_ptr<int>> v;
  v.push_back(std::make_shared<int>(21));
  v.push_back(std::make_shared<int>(22));
  v.push_back(std::make_shared<int>(23));

  for(auto elem: v){
    std::cout << *elem << "\n";
  }

  return 0;
}
```

