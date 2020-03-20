# Herencia - Constructores y destructores

## Constructores de clases heredadas

Cuando construímos una clase qué hereda de otra, ¿cómo invocamos el constructor de la clase padre? Veamos algunos ejemplos:

### Constructor padre sin parámetros
```cpp
#include <iostream>

class Padre{
  public:
  Padre(){
    std::cout << "Constructor Padre\n";
  }
};

class Hija: public Padre{
  public:
  Hija(){
    std::cout << "Clase Hija\n";
  }
};

int main() {
  Hija miClase;
}
```

En este ejemplo la clase `Padre` tiene un constructor sin parámetros, este constructor no es necesario llamarlo explícitamente desde la clase `Hija`. Se llamará al llamar al constructor de la clase `Hija` (antes de que este se ejecute).

Por lo tanto, este programa mostrará por pantalla.

``` 
Constructor Padre
Clase Hija
```

### Constructor padre con parámetros

Si el constructor de la clase `Padre` tiene parámetros, la llamada al constructor no se puede realizar de modo implícito, y por lo tanto el programa anterior daría un error de compilación, porque al llamar al constructor de la clase `Hija` no sabe cómo llamar al constructor de la clase `Padre`. En este caso, la llamada al constructor debe ser explícita, del siguiente modo.

```cpp
#include <iostream>

class Padre{
  public:
  Padre(int a){
    std::cout << "Constructor Padre\n";
  }
};

class Hija: public Padre{
  public:
  Hija():Padre(1){
    std::cout << "Clase Hija\n";
  }
};

int main() {
  Hija miClase;
}
```

En el constructor de la clase `Hija` estamos llamado al constructor de `Padre` pasándole como parámetro el valor `1`.

```cpp
  Hija():Padre(1){
    std::cout << "Clase Hija\n";
  }
```

Se volverá a mostrar por pantalla lo mismo

```
Constructor Padre
Clase Hija
```

¿Qué se mostrará por pantalla en el siguiente código?

```cpp
#include <iostream>

class Padre{
  public:
  Padre(int a){
    std::cout << "Constructor Padre\n";
  }
};

class Hija: public Padre{
  public:
  Hija():Padre(1){
    std::cout << "Constructor Hija\n";
  }
};

class Nieta: public Hija{
  public:
  Nieta(){
    std::cout<< "Constructor Nieta";
  }
};

int main() {
  Nieta miClase;
}
```

## Destructores de clases heredadas

Los destructores no reciben nunca parámetros, por lo que en este caso la llamada siempre será implícita. En este caso, la llamada será en orden inverso al constructor, es decir, empezamos por la clase más baja en la jerarquía hasta llegar a la clase Padre.

Recordemos que los destructores se llaman cuando finaliza el ámbito de una variable, o cuando se llama a `delete` en el caso de los punteros.

Veamos el ejemplo con el siguiente código.

```cpp
#include <iostream>

class Padre{
  public:
  Padre(){
    std::cout << "Constructor Padre\n";
  }
  ~Padre(){
    std::cout << "Destructor Padre\n";
  }
};

class Hija: public Padre{
  public:
  Hija(){
    std::cout << "Constructor Hija\n";
  }
  ~Hija(){
    std::cout << "Destructor Hija\n";
  }
};

class Nieta: public Hija{
  public:
  Nieta(){
    std::cout<< "Constructor Nieta\n";
  }
  ~Nieta(){
    std::cout<< "Destructor Nieta\n";
  }
};

int main() {
  Nieta miClase;
  std::cout << "hago cosas\n";
  return 1;
}
```
que muestra por pantalla:

```
Constructor Padre
Constructor Hija
Constructor Nieta
hago cosas
Destructor Nieta
Destructor Hija
Destructor Padre
```

y este otro ejemplo con punteros

```cpp
#include <iostream>

class Padre{
  public:
  Padre(){
    std::cout << "Constructor Padre\n";
  }
  ~Padre(){
    std::cout << "Destructor Padre\n";
  }
};

class Hija: public Padre{
  public:
  Hija(){
    std::cout << "Constructor Hija\n";
  }
  ~Hija(){
    std::cout << "Destructor Hija\n";
  }
};

class Nieta: public Hija{
  public:
  Nieta(){
    std::cout<< "Constructor Nieta\n";
  }
  ~Nieta(){
    std::cout<< "Destructor Nieta\n";
  }
};

int main() {
  Nieta *miClase;
  std::cout << "Todavia no he hecho new\n";
  miClase = new Nieta{};
  std::cout << "hago cosas\n";
  delete miClase;
  std::cout << "Hago algo más\n";
  return 1;
}
```

y esta es la salida (**__analizar con atención__**)

```
Todavia no he hecho new
Constructor Padre
Constructor Hija
Constructor Nieta
hago cosas
Destructor Nieta
Destructor Hija
Destructor Padre
Hago algo más
``` 