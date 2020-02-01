# Clases. Constructor

Se ha visto anteriormente que una variable se puede inicializar a la vez que se declara.

```cpp
int a{3};
```
Se crea una variable llamada `a` que se asocia al valor `a`.

Lo mismo sucede con las Clases. Cuando se declara una clase se pueden inicializar las variables miembro que decida el programador. Para eso se utiliza el **Constructor**

## Constructor de una clase

El *constructor* de una *Clase* es una función especial que se ejecuta cuando se declara una variable de dicha clase. Esta función tiene las siguientes características:

  * Tiene el mismo nombre que la Clase.
  * No tiene valor de retorno.
  * Puede tener parámetros (o no tenerlos).
  * Siempre debe ser público.

Por ejemplo:

```cpp
#include <iostream>

class Foo{
  public:
  
  // public constructor without parameters
  Foo(){
    std::cout << "I am de constructor of Foo\n";
  }
};

int main(){
  Foo myFoo; // what happens here?
  return 0;
}
```

En este ejemplo se ha declarado la clase `Foo`. Esta clase sólo tiene un miembro público: `Foo()`. Este es el construcor, ¿cómo lo sabemos?
  * Se llama igual que la clase `Foo`
  * No tiene un valor de retorno.

¿Qué hace el constructor `Foo()`. Muestra por pantalla el texto `I am de constructor of Foo`.

Pasemos a la función `main`. La función `main` declara una variable de tipo `Foo`. **Al declarar una variable de una clase se llama a su constructor**, por lo tanto se llamará a la función `Foo()` y se mostrará por pantalla `I am de constructor of Foo`.

¿Cómo puede por lo tanto servir el contructor para inicializar las variables miembro de una clase? Veamos otro ejemplo.

```cpp
#include <iostream>
#include <array>

class Matrix2x2{
  public:
  // public constructor without parameters
  Matrix2x2();

  void print() const;

  private:
  std::array<float, 4> data;
};

Matrix2x2::Matrix2x2(){
  data = {0,0,0,0};
}

void Matrix2x2::print() const{
  std::cout << data.at(0) << "\t" << data.at(1) << "\n";
  std::cout << data.at(2) << "\t" << data.at(3) << "\n";
}

int main(){
  Matrix2x2 myMatrix;
  myMatrix.print();
  return 0;
}
``` 

En este caso se ha declarado una clase `Matrix2x2` que albergará una matriz de 2x2 en la variable miembro privada `data`.

La clase `Matrix2x2` tiene un constructor (función pública que no devuelve ningún parámetro y que se llama igual que la clase) que no recibe ningún parámetro, y que inicializará la matriz a *todo 0*.

Finalmente, la función `print()` mostrará la matriz por pantalla.

### Constructor con parámetros

Pero, ¿y si queremos inicializar la instancia de la clase con valores diferentes cada vez? Basta hacer que el constructor tenga parámetros.

```cpp
#include <iostream>
#include <array>

class Matrix2x2{
  public:
  // public constructor without parameters
  Matrix2x2(std::array<float, 4> const & v);

  void print() const;

  private:
  std::array<float, 4> data;
};

Matrix2x2::Matrix2x2(std::array<float, 4> const & v){
  data = v;
}

void Matrix2x2::print() const{
  std::cout << data.at(0) << "\t" << data.at(1) << "\n";
  std::cout << data.at(2) << "\t" << data.at(3) << "\n";
}

int main(){
  Matrix2x2 myMatrix{{1,2,3,4}};
  myMatrix.print();
  return 0;
}
```

En este caso el constructor recibe un `array` de 4 elementos por parámetro. A través de este `array` inicializa la matrix

```cpp
Matrix2x2::Matrix2x2(std::array<float, 4> const & v){
  data = v;
}
``` 

Por lo tanto, cuando declaramos la variable `myMatrix` debemos pasarle un `array`, que será el parámetro del constructor

```cpp
Matrix2x2 myMatrix{{1,2,3,4}};
```

Ojo, la doble llave es porque el `array` se pasa directamente al parámetro, también se podría haber hecho así:

```cpp
  std::array<float, 4> init{1,2,3,4};
  Matrix2x2 myMatrix{init};
```

### Sobrecarga del constructor

En caso de que queramos tener la opción de pasar o no pasar parámetros al declarar una instancia de una clase podemos sobrecargar el constructor como haríamos con cualquier otra función.

```cpp
#include <iostream>
#include <array>

class Matrix2x2{
  public:
  // public constructor with parameters
  Matrix2x2(std::array<float, 4> const & v);
  // public constructor wihtout parameters
  Matrix2x2();

  void print() const;

  private:
  std::array<float, 4> data;
};

Matrix2x2::Matrix2x2(std::array<float, 4> const & v){
  data = v;
}

Matrix2x2::Matrix2x2(){
  data = {0,0,0,0};
}

void Matrix2x2::print() const{
  std::cout << data.at(0) << "\t" << data.at(1) << "\n";
  std::cout << data.at(2) << "\t" << data.at(3) << "\n";
}

int main(){
  Matrix2x2 myMatrix1{{1,2,3,4}};
  Matrix2x2 myMatrix2;
  myMatrix1.print(); // 1 2
                     // 3 4
  myMatrix2.print(); // 0 0
                     // 0 0
  return 0;
}
``` 

En este caso hay dos constructores, uno con parámetros y otro sin parámetros, según la inicialización de la instancia de la clase se ejecutará uno u otro:

```cpp
Matrix2x2 myMatrix1{{1,2,3,4}}; // se ejecuta el constructor con parámetros
Matrix2x2 myMatrix2; // se ejecuta el constructor sin parámetros
```

### Constructor Copia

El constructor copia es un constructor especial que se ejecuta cuando un objeto se asigna a otro, por ejemplo:

```cpp
Matrix2x2 myMatrix1{{1,2,3,4}};
Matrix2x2 myMatrix2 = myMatrix1;
```
La instrucción `myMatrix2 = myMatrix1` necesita del *constructor copia*, que dirá cómo se deben copiar los datos de `myMatrix1` en `myMatrix2`.

El constructor copia será un constructor que recibe como único parámetro una **referencia constante a un objeto de la propia clase**. Es decir 

```cpp
Matrix2x2(Matrix2x2 const & other);
```
En este ejemplo, la definición del constructor copia será del siguiete modo:

```cpp
Matrix2x2::Matrix2x2(Matrix2x2 const & other){
  data = other.data;
}
```
El constructor copia se llamará siempre que se haga una copia del objeto **(incluyendo cuando el objeto de devuelve desde una función o cuando se pasa como parámetro por copia)**
