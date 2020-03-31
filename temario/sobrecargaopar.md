# Sobrecarga operadores aritméticos

La sobrecarga de un operador es definir el funcionamiento de ese operador para tipos de datos para los que no está definido por defecto.

Por ejemplo, si tenemos una clase `Matriz` y un programa así:

```cpp
Matriz matriz1;
Matriz matriz2;
// ...
Matriz matriz3 = matriz1 + matriz2;
``` 

Obtendremos un error de compilación indicándonos que el operador `+` no está definido para la clase `Matriz`.

## Operadores aritméticos en C++  - Operadores binarios

Los operadores aritméticos binarios (que tienen dos términos) en C++ son los siguientes:
 * Suma: `+`
 * Resta: `-`
 * Multiplicación: `*`
 * División: `/`
 * Módulo: `%`

La sobrecarga tendrá esta estructura, por ejemplo para la suma:

```cpp
Tipo operator+(Tipo const & a, Tipo const & b){
  // lo que sea
  // return el resultado
}
```

De modo que ahora podríamos hacer un programa así:

```cpp
Tipo a;
Tipo b;
Tipo c = a + b;
```

## Operadores aritméticos en C++  - Operadores unarios

Son operadores artiméticos unarios en C++ los siguientes:

* Incremento: `++`
* Decremento: `--`

Hay que distinguir dos casos:

```cpp
Tipo a;
a++; // Postfix increment
++a; // Prefix increment
```

Para distinguir uno de otro, la sobrecarga es del siguiente modo:

```cpp
Tipo& operator++( Tipo & a )      // Prefix increment
Tipo& operator++( Tipo & a, int )      // Prefix increment
```

El argumento de tipo int que denota la forma de postfijo del operador de incremento o decremento no se usa normalmente para pasar argumentos. Normalmente contiene el valor 0.

Veamos un ejemplo, para una clase `Point`. La suma sumará los puntos, el incremento sumará una unidad a cada coordenada.

```cpp
#include <iostream>

class Point{
public:
  Point():x{0},y{0}{}
  Point(float x, float y):x(x),y(y){}
  void print(){
    std::cout << x << ", " << y << "\n";
  }
  float x;
  float y;
};

Point& operator++(Point & p){
  ++p.x;
  ++p.y;
  return p;
}

Point& operator++(Point & p, int){
  p.x++;
  p.y++;
  return p;
}

Point operator+(Point const & a, Point const &b){
  return Point{a.x + b.x, a.y + b.y};
}

int main() {
  Point p1{1,2};
  Point p2{3,3};

  Point p3 = p1 + p2;
  p3.print(); // -> 4, 5
  
  ++p3;
  p3.print(); // -> 5, 6
  
  p3++;
  p3.print(); // -> 6, 7
}
```

Es importante destacar que no se puede redefinir un operador para un tipo para el que ya está definido. Por ejemplo, no podríamos redefinir la suma para un float

```cpp
float operator+(float const & a, float const & b); // ERROR DE COMPILACION
```
