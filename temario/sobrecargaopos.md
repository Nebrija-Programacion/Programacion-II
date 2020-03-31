# Sobrecarga operadores de flujo (istream ostream)

La sobrecarga de un operador es definir el funcionamiento de ese operador para tipos de datos para los que no está definido por defecto.

Por ejemplo, si tenemos una clase `Persona` y un programa así:

```cpp
Persona p{"Alberto", 24};
std::cout << p << "\n;
``` 

Obtendremos un error de compilación indicándonos que el operador lógico `<<` no está definido para la clase `Persona`.

## Operadores de flujo en C++

Los operadores de flujo en C++ son los siguientes:
 * Flujo de salida: `<<`
 * Flujo de entrada: `>>`

La sobrecarga tendrá esta estructura, por ejemplo para la suma:

```cpp
std::ostream& operator<<(std::ostream& os, Tipo const & a){
  // lo que sea
  return os;
}

std::istream& operator>>(std::istream& os, Tipo & a){
  // lo que sea
  return is;
}
```

Es importante notar que un operador de flujo **siempre** devolverá una *referencia* a `ostream` o `istream` según corresponda. Esto es así para que podamos encadenar varios operadores de flujo, por ejemplo:

```cpp
std::cout << a << b << c << "hola";
```

Ahora podríamos hacer un programa así:

```cpp
Tipo a;
Tipo b;
std::cin >> a;
std::cint >> b;
std::cout << a << b << "\n";
```

Veamos un ejemplo, para una clase `Persona`.

```cpp
#include <iostream>
#include <ostream>
#include <istream>

class Persona{
public:
  Persona(): nombre{""}, edad{0}{}
  std::string nombre;
  float edad;
};

std::ostream & operator << (std::ostream & os, Persona const & p){
  os << p.nombre << ": " << p.edad;
  return os;
}

std::istream & operator >> (std::istream & is, Persona & p){
  is >> p.nombre >> p.edad;
  return is;
}


int main(){
  Persona yo;
  std::cout << "Introduzca nombre y edad: ";
  std::cin >> yo; //escribo "Alberto 24 enter"
  std::cout << yo << "\n"; // -> Alberto 24
}
```

Es importante destacar que no se puede redefinir un operador para un tipo para el que ya está definido. Por ejemplo, no podríamos redefinir el operador `<<` para un float

```cpp
ostream & operator<<(ostream & os, float & a); // ERROR DE COMPILACION
```