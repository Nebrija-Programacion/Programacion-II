# Clases en C++ - Miembros públicos y privados

Como se ha visto las *clases* en C++ están compuestas por miembros (variables y funciones) que tienen sentido como conjunto.

A la hora de decidir qué hay dentro de una clase habrá miembros que tan solo servirán para hacer operaciones internas (estos son los miembros privados), y otros que querremos que los programadores usen (miembros públicos).

Una primera aproximación, las variables miembro de una clase deben ser **siempre** *privadas* y las funciones **en general, pero no siempre** *públicas*.

La clase `Person` por lo tanto debería modificarse del siguiente modo.

```cpp
class Person{
  // private variables
  private:

  std::string name;
  int age;

  // public methods
  public:
  
  void setName(std::string const & n);
  void setAge(int a);

  std::string getName() const;
  int getAge() const;
  void print() const;
};
``` 

¿Qué implicaciones tiene este cambio? El siguiente código sería **incorrecto**

```cpp
Person person1;
person.name = "Alberto";
``` 

La variable miembro `name` de la clase `Person` es privada, por lo que **no se puede acceder a ella desde la instancia**.

¿Entonces? ¿Cómo se lee/escribe el nombre de una persona? A través de las funciones *get* y *set* correspondientes.

```cpp
Person person1;

std::string n;
std::cout << "Cual es tu nombre: ?";
std::cin >> n;

person1.setName(n);

std::cout << "Hola " << person1.getName() << "\n";
```
**¿Es esta una complicación innecesaria? ¿Por qué no hacer simplemente `person1.name`?

Que las variables sean privadas nos permite tener un mejor control sobre ellas. Por ejemplo, para el nombre podría dar igual, pero ¿y para la edad?, ¿se puede tener una edad negativa?, no, entonces podríamos hacer la función `setAge` del siguiente modo.

```cpp
void Person::setAge(int a){
  if(age < 0){
    age = 0;
    std::cout << "Error, I have set age to 0\n"
  }else{
    age = a;
  }
}
```

De este modo, si realizamos el siguiente programa

```cpp
Person person1;
person1.setAge(-3); // -> Error, I have set age to 0
std::cout << "Age: " << person1.getAge() << "\n"; // -> Age: 0
```

En el ejemplo con el que estamos trabajando, por ser muy sencillo, puede no apreciarse la ventaja de que las variables miembro sean siempre privadas, pero es importante quedarse con la idea de que nos proporciona la posibilidad de controlar cómo se usa nuestro código, evitando (o minimizando errores).
