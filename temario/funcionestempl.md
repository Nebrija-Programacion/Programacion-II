# Templates - Funciones Templatizadas

En C++ hemos visto cómo una función puede comportarse de modo diferente a través de la **sobrecarga de funciones**. Gracias a la sobrecarga, dos funciones con el mismo nombre y distintos parámetros realizan acciones diferentes, por ejemplo

```cpp
#include <iostream>

void print(int a){
  std::cout << "Esto es un numero: " << a << "\n";
}

void print(std::string a){
  std::cout << "Esto es un string: " << a << "\n";
}

int main() {
  print(3); // Esto es un numero: 3
  print("hola"); // Esto es un string: hola
  return 0;
}
```

En C++ moderno existe otro modo más versatil y con más posibilidades de conseguir esta misma funcinalidad, las plantillas (en inglés *templates*).

Un plantailla en C++ es la funcionalidad mediante la cual definimos una función sin indicar de qué tipo serán los parámetros o los valores de retorno, por ejemplo, una función print que pueda recibir cualquier tipo de datos se haría del siguiente modo usando *plantillas*.

`templates.h`
```cpp
template<typename T>
void print(T const & a){
  std::cout << a << "\n";
}
```

`main.cpp`
```cpp
#include <iostream>
#include "templates.h"
int main() {
  print<int>(3); //  3
  print<std::string>("hola"); //  hola
  return 0;
}
```

Analicemos el código:

En primero lugar, **las funciones templatizadas se deben __declarar__ y __definir__ SIEMPRE en archivos `.h`**.

`templates.h`

1. `template<typename T>` Estamos indicando que vamos a declarar una función templatizada, con un tipo `T`. Es decir, lo que vamos a declarar a continuación usará un tipo `T` que no específicamos cuál será, **eso es un *template***
2. `void print(T const & a)` Declaramos una función `print` que no devuelve nada (`void`) y recibe por parámetro una variable `a` de tipo `T` (referencia constante). En este momento, `T` no se sabe qué es, es una plantilla. ¿Por qué lo hacemos por referencia constante? Porque como no sabemos qué tipo será `T` de este modo aseguramos que nunca se copie su valor, sino que se pase su referencia, sea un tipo simple o un tipo complejo.
3. `std::cout << a << "\n";`. La función mostará por pantalla la variable `a`.

Pasemos al `main.cpp`.

1. `print<int>(3);`. Estoy llamando a la funcitón templatizada `print` pasándole como parámetro un `int`. ¿Qué hace el compilador?, crea de modo automático internamente la siguiente función:

```cpp
void print(int const & a){
  std::cout << a << "\n";
}
```
Es decir, utiliza nuestra plantilla, para crear internamente una función donde `T` es `int`. Es decir, entiende que **donde pone `T` hay que poner `int`. Por lo tanto muestra por pantalla un `3`

2. `print<std::string>("hola")`. El proceso es igual que el anterior. El compilador crea una nueva función (internamente) en la que **donde pone `T` pone `string`. 

¿Qué pasaría con el siguiente código?

```cpp
#include <iostream>
#include "templates.h"

struct Persona{
  std::string nombre;
  int edad;
};

int main() {
  Persona yo{"Alberto", 23};
  print<Persona>(yo);
  return 0;
}
```

1. El compilador entiende que en la función templatizada `print` donde pone `T` debe poner `Persona`, entonces crea la siguiente función:

```cpp
void print(Persona const & a){
  std::cout << a << "\n";
}
```

2. Llama a la función `print` pasándole como parámetro `yo`, por lo que intentar ejecutar `std::cout << yo << "\n` generando un error de compilación, ¿por qué?, por la `std::cout` no sabe cómo mostrar por pantalla una variable (`yo`) de tipo `Persona`.

¿Cómo se soluciona esto? Hay 2 opciones.

1. Sobrecargar el operador `<<` para que sepa como gestionar el tipo `Persona`.
2. Particularizar la plantilla para el tipo `Persona`.

La primera solución ya sabemos como hacerlo (sobrecarga de operadores)

```cpp
#include <iostream>
#include "templates.h"

struct Persona{
  std::string nombre;
  int edad;
};

std::ostream & operator <<(std::ostream & os, Persona const & p){
  os << "nombre: " << p.nombre << "\n";
  os << "edad: " << p.edad << "\n";
  return os;
}

int main() {
  Persona yo{"Alberto", 23};
  print<Persona>(yo);
  return 0;
}
```

Ahora, la función creada internamente
```cpp
void print(Persona const & a){
  std::cout << a << "\n";
}
```
Ya sabe ejecutar `std::cout << a << "\n";`.

## Particularización de un template

La particularización de un template consiste en programar explícitamente un caso particular de una plantilla (en lugar de dejar que el navegador lo haga automáticamente de modo interno). En este caso, queremos particularizar la función `print` para el caso en el que `T` sea de tipo `Persona`. Se hace del siguiente modo

`template.h`
```cpp
#include <iostream>

struct Persona{
  std::string nombre;
  int edad;
};

template<typename T>
void print(T const & a){
  std::cout << a << "\n";
}

template<>
void print(Persona const & a){
  std::cout << "nombre: " << a.nombre << "\n";
  std::cout << "edad: " << a.edad << "\n";
}
``` 

`main.cpp`
```cpp
#include <iostream>
#include "templates.h"


int main() {
  Persona yo{"Alberto", 23};
  print<Persona>(yo);
  return 0;
}
```
## múltiples tipos templatizados

Una plantilla puede incluir múltiples tipos, por ejemplo:

```cpp
template<class T, class Y>
void print(T const & a, Y const &b){
  std::cout << a << "\n";
  std::cout << b << "\n";
}
```

Lo que nos permitiría escribir código del tipo:

```cpp
print<int, std::string>(1, "hola"); // T -> int, Y -> string
print<std::string, std::string>("hola", "que tal") // T -> string, Y ->string
```

# Plantillas, composición de funciones y recorrido de tipos iterables

Las plantillas nos permiten que las funciones que hemos utilizado para trabajar con tipos iterables sean completamente genéricas

## forEach

```cpp
template <class T, class Y>
void forEach(T const & v, std::function<void(Y)> const & op){
  for(auto elem: v){
    op(elem);
  }
}
```

Ejemplo de uso

```cpp
  std::vector<int> v{1,2,3,4};
  forEach<std::vector<int>, int>(v, [](auto elem){
    std::cout << elem << "\n";
  });
```

## filter

```cpp
template <class T, class Y>
T filter(T const & v, std::function<bool(Y)> const & f){
  T result;
  for(auto elem: v){
    if(f(elem)) result.push_back(elem);
  }

  return result;
}
```

## map

```cpp
template <class T, class Y>
T map(T const & v, std::function<Y(Y)> const & f){
  T result;
  for(auto elem: v){
    result.push_back(f(elem));
  }

  return result;
}
```

## find

```cpp
template <class T, class Y>
Y find(T const & v, std::function<bool(Y)> const & f){
  
  for(auto elem: v){
    if(f(elem)) return elem;
  }

  return Y{};
}
``` 
