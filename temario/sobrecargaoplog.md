# Sobrecarga operadores lógicos

La sobrecarga de un operador es definir el funcionamiento de ese operador para tipos de datos para los que no está definido por defecto.

Por ejemplo, si tenemos una clase `Circulo` y un programa así:

```cpp
Circulo c1;
Circulo c2;
// ...
if(c1 > c2){
  // ....
}
``` 

Obtendremos un error de compilación indicándonos que el operador lógico `>` no está definido para la clase `Circulo`.

## Operadores lógicos en C++  - Operadores binarios

Los operadores aritméticos binarios (que tienen dos términos) en C++ son los siguientes:
 * Mayor y Mayor o igual: `>`, `>=`
 * Menor y Menor o igual: `<`, `<=`
 * Igual: `==`
 * Diferente: `=!`
 * AND lógico: `&&`
 * OR lógico: `||`

La sobrecarga tendrá esta estructura, por ejemplo para la suma:

```cpp
bool operator>(Tipo const & a, Tipo const & b){
  // lo que sea
  // return el resultado
}
```

Es importante notar que un operador lógico **siempre** devolverá `bool`.

De modo que ahora podríamos hacer un programa así:

```cpp
Tipo a;
Tipo b;
if(a > b){
  // ...
}
```

## Operadores lógicos en C++  - Operadores unarios

Son operadores artiméticos unarios en C++ los siguientes:

* Negación: `!`

La sobrecarga es del siguiente modo:

```cpp
bool operator++( Tipo const & a )
```

Veamos un ejemplo, para una clase `Circle`. Un círculo se comparará con otro en función de su radio. En este caso no tendría sentido definir `&&` `||` y `!`, dado que esas operaciones no tienen sentido para este objeto.

```cpp
#include <iostream>

class Circle{
public:
  Circle(float r):radius{r}{}
  float radius;
};

bool operator> (Circle const &c1, Circle const &c2){
  return c1.radius > c2.radius;
}

int main(){
  Circle cir1{3};
  Circle cir2{5};
  if(cir1 > cir2){
    std::cout << "cir 1 es mayor\n"; 
  }else{
    std::cout << "cir 2 es mayor\n";
  } // -> cir 2 es mayor
}
```

Es importante destacar que no se puede redefinir un operador para un tipo para el que ya está definido. Por ejemplo, no podríamos redefinir el operador `>` para un float

```cpp
bool operator>(float const & a, float const & b); // ERROR DE COMPILACION
```
