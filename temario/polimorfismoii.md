# Polimorfismo - Clases Abstractas

## Funciones virtuales puras

Una función virtual pura es una función virtual que **no** se implementa en la clase padre (sólo se declara) y que por lo tanto **debe ser implementada** en todas las clases hijas.

Una función virtual pura se declara igualándola a 0, por ejemplo, para nuestra clase `Figura`.

```cpp
class Figura{
public:  
  Figura(){};

  virtual float getArea() const  = 0;

};
```

Se utilizan funciones virtuales puras en aquellos casos en los que no tiene sentido implementarla en la clase Padre, y sin embargo queremos forzar a que se implemente en todas las clases hijas.

## Clase Abstracta

Un clase abstracta es aquella que implementa al menos una función virtual pura. No se pueden crear instancias de clases abstractas.

Por ejemplo, este código daría un error:

```cpp
#include <iostream>

// Clase abstracta porque tiene una funcion virtual pura
class Figura{
public:  
  Figura(){};

  virtual float getArea() const  = 0;

};

int main() {
  Figura fig; // ERROR, no se puede crear una variable de una clase abstracta 
  std::cout << "Hello World!\n";
}
```