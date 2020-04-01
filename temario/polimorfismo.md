# Polimorfismo

El polimorfismo es la característica más potente de la Programación Orientada a Objetos y que hace que ésta sea útil en casos en los que no se podría resolver de otro modo (ni siquiera con *templates*).

El polimorfismo se basa en la declaración de *funciones vituales*. Una función virtual es una funcióm miembro de una clase padre, que será posteriormente definida en la clase hija. 

Por ejemplo:

```cpp
#include <iostream>

class Figura{
public:  
  Figura(){};
  virtual ~Figura(){}

  virtual float getArea(){
    std::cout << "No implementado\n";
    return 0;
  }

};

class Cuadrado{
public:
  Cuadrado(float a):lado{a} {}
  float getArea(){
    return a*a;
  }
};
```
¿Qué está pasando aquí?

1. La clase `Figura` tiene una función virtual `virtual float getArea()`. Es virtual por la palabra `virtual`. Una función virtual es una función que se declara y se implementa en la clase padre, y puede volver a ser implementada en las clases hijas.
2. La clase `Figura` por tener funciones virtuales **debe implementar** un destructor virtual `virtual ~Figura()` 
3. La clase `Cuadrado` implementa la función pura `getArea`. La implementa de modo no virtual, ya que no usa la palabra `virtual` (aunque podrñia hacerlo)

Si realizamos un programa como el siguiente:

```cpp
#include <iostream>

class Figura{
public:  
  Figura(){};
  virtual ~Figura(){}
  virtual float getArea(){
    std::cout << "No implementado\n"; 
    return 0;
  };

};

class Cuadrado: public Figura{
public:
  Cuadrado(float a):lado{a} {}
  float getArea(){
    return lado*lado;
  }
private:
  float lado;
};

int main(){
  Figura h;
  h.getArea(); // -> No implementado
  Cuadrado a{4};
  std::cout << a.getArea(); // -> 16
}
```
No apreciamos ninguna ventaja en usar el polimorfismo (funciones virtuales). Entonces, ¿para qué sirve?

## Polimorfismo

El polimorfismo hace lo siguiente (asegurarse de que se entiende): *Si tengo un puntero a una clase padre, creo el puntero como tipo de la clase hija, y llamo a alguna de las funciones virtuales de la padre, se ejecutará la implementación de la hija*.

Se entiende bien con un ejemplo de las clases anteriores.

```cpp
#include <iostream>
#include <memory>

class Figura{
public:  
  Figura(){};
  virtual ~Figura(){};

  virtual float getArea() = 0;

};

class Cuadrado: public Figura{
public:
  Cuadrado(float a):lado{a} {}
  float getArea(){
    return lado*lado;
  }
private:
  float lado;
};

int main(){
  std::unique_ptr<Figura> a = std::make_unique<Cuadrado>(4);
  std::cout << a->getArea(); // -> 16
}
```

¿Qué esta pasando?

1. Creo un puntero a la clase padre `Figura`
2. Inicializo el puntero con un objeto de tipo `Cuadrado` (clase hija)
3. Llamo a `getArea()`. Gracias al polimorfismo no se llama a `getArea()` de `Figura`, sino a `getArea()` de `Cuadrado` y por lo tanto muestra por pantalla 16.

Imaginemos que ahora implementamos otra clase que no reimplementa la función virtual

```cpp
#include <iostream>
#include <memory>

class Figura{
public:  
  Figura(){};
  virtual ~Figura(){};

  virtual float getArea(){
    std::cout << "No implementado\n";
    return 0;
  }

};

class Cuadrado: public Figura{
public:
  Cuadrado(float a):lado{a} {}
  float getArea(){
    return lado*lado;
  }
private:
  float lado;
};

class Triangulo: public Figura{
public:
  Triangulo(float base, float altura): base{base}, altura{altura} {}
private:
  float base;
  float altura;
};

int main(){
  std::unique_ptr<Figura> a = std::make_unique<Triangulo>(4,5);
  a->getArea(); // -> No implementado
}
```
¿Qué esta pasando?

1. Creo un puntero a la clase padre `Figura`
2. Inicializo el puntero con un objeto de tipo `Triangulo` (clase hija)
3. Llamo a `getArea()`. Se llama a `getArea()` de `Figura`, porque en `Triangulo` no se ha reimplementado, y por lo tanto muestra por pantalla: `No implementado`.

## Ejemplo de uso de polimorfismo

En el siguiente ejemplo vamos a ver uno de los usos del polimorfismo: un vector de punteros.

```cpp
#include <iostream>
#include <memory>
#include <vector>

class Figura{
public:  
  Figura(){};
  virtual ~Figura(){};

  virtual float getArea() const{
    std::cout << "No implementado\n";
    return 0;
  }

};

class Cuadrado: public Figura{
public:
  Cuadrado(float a):lado{a} {}
  float getArea() const{
    return lado*lado;
  }
private:
  float lado;
};

class Triangulo: public Figura{
public:
  Triangulo(float base, float altura): base{base}, altura{altura} {}

  float getArea() const{
    return base*altura/2;
  }
private:
  float base;
  float altura;
};

int main(){
  std::vector<std::unique_ptr<Figura>> figuras;

  figuras.push_back(std::make_unique<Triangulo>(4,5));
  figuras.push_back(std::make_unique<Cuadrado>(3));
  figuras.push_back(std::make_unique<Cuadrado>(2));

  for(auto const & elem: figuras){
    std::cout << elem->getArea() << "\n";
  }
}
```

En este ejemplo, creamos un vector de punteros a `Figura` y luego añadimos objetos de tipo `Cuadrado` o `Triangulo`. Al llamar a `getArea()` en el bucle `for` se llamará, gracias al polimorfismo, a la función correspondiente en cada caso.

En el ejemplo que se resolvió en clase **sin polimorfismo** el único modo de resolver este problema era hacer un vector diferente para cada clase de figura.