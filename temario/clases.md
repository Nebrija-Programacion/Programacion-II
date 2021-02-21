# Clases en C++ - Introducción

La Programación Orientada a Objetos (POO) es una metodología de programación que busca organizar el código de tal manera que se simplifique su desarrollo y reutilización.

La idea fundamental detrás de la Progrmación Orienta a Objetos consiste en agrupar la información/datos y los métodos que acceden o modifican a dicha información.

Por ejemplo, si estamos haciendo un programa que guarde un listado de números de teléfono podríamos decir que la información/datos que utilizará nuestro programa es:
 * lista de teléfonos
 * lista de nombres

y quizá, los métodos que trabajarán con dichos datos serán:
  * agregar teléfono y nombre
  * borrar teléfono y nombre
  * buscar por nombre
  * buscar por teléfono
  * imprimir listado

En POO aglutinará estos métodos y datos en una entidad llamada *Objeto* (o *Clase*).

En realidad ya hemos trabajado con Objetos sin saberlo. El tipo de datos `string` es un Objeto/Clase. ¿Cuáles serían sus datos? los carácteres que forman el texto, ¿y los métodos/funciones? todos los que conocemos:
  * size
  * find
  * at
  * substr
  * ...

## Declaración de una Clase/Objeto

En C++ una Clase/Objeto se declara del siguiente modo genérico (más adelante añadiremos más elementos):

```cpp
class ClassName {
  public:
    // data
    type data1;
    type data2;
    // ...

    // methods
    return_type function1(params);
    return_type function2(params);
    // ... 
}
```

Por ejemplo, una clase Person se declararía del siguiente modo

```cpp
class Person{
  public:

  // public variables
  std::string name;
  int age;

  // public methods

  void setName(std::string const & n);
  void setAge(int a);

  std::string getName() const;
  int getAge() const;
  void print() const;
};
``` 

¿Qué tiene esta clase?

### Variables miembro
 * `name`, que es un `std::string`
 * `age`, que es un `int`

### Métodos
 * `setName` que es una función que no devuelve nada y recibe un `std::string` como parámetro.
 * `setAge` que es una función que no devuelve nada y recibe un `int` como parámetro.
 * `getName` que es una función que devuelve un `std::string` y no recibe ningún parámetro. Además el `const` nos dice que no modifica los datos de la clase.
 * `getAge` que es una función que devuelve un `int` y no recibe ningún parámetro. Además el `const` nos dice que no modifica los datos de la clase.
 * `print` que no devuelve nada no recibe ningún parámetro. Además el `const` nos dice que no modifica los datos de la clase.

Hasta aquí lo único que hemos hecho ha sido *declarar la clase*, es decir, indicar qué funciones y datos miembro tiene, pero no estamos diciendo que hacen. Es como declarar una variable antes de asignare un valor.

Una vez declarada la clase debemos definirla, es decir: **implementar cada una una de las funciones miembro**

## Definción de una Clase/Objeto

Toca decir qué hace cada una de las funciones miembro de la clase `Person`. La sintaxis general para definir los métodos de una clase es la siguiente:

```cpp
returntype classname::method(params){
  //
}
```
Por lo tanto, para la clase `Person` se haría del siguiente modo:

```cpp
void Person::setName(std::string const & n){
  name = n;
}

void Person::setAge(int a){
  age = a;
}

std::string Person::getName() const {
  return name;
}

int Person::getAge() const {
  return age;
}

void Person::print() const {
  std::cout << "Name: " << name << "\n";
  std::cout << "Age: " << age << "\n";
}

```

Con esto la clase está perfectamente declarada y definida y lista para usar. Pero, ¿qué es un clase?, una clase es un tipo de dato, definido por el programador, que puede ser utilizado en el programa como cualquier otro tipo de dato.

Por ejemplo en el programa se podrían declarar dos variables de tipo `Person`

```cpp
Person person1;
Person person2;
shared_ptr<Person>  person3 = make_shared<Person>();
```

`person1` y `person2` son dos variables/etiquetas de tipo `Person`. En la jerga de C++ se dice que `person1` y `person2` son objetos o instancias de tipo `Person`. `person3` es un puntero a `Person`.

## Acceso a los miembros de una clase.

El acceso a los miembros de un objeto se realiza del mismo modo que con los `struct` a través del operador `.` cuando son variables normales y del operador `->` cuando son punteros.

```cpp
person1.name = "Alberto";
person1.setAge(23);
person1.print(); // Name: Alberto
                 // Age: 23
person2.setName("Maria");
person2.age = 18;
std::cout << "Hola " << person2.getName() << "\n"; // Hola Maria

person3->setName("Luisin");
std::cout << "Como vas " << person3->getName() << "\n"; // Como vas Luisin

```

