# Gestión de errores con excepciones

El hecho de que las variables miembro de una clase sean privadas, nos permite controlar los valores que estas pueden tomar (evitando errores). Por ejemplo, en una clase `Persona` podemos controlar si la edad o el peso introducidos son incorrectos a través de las funciones setter. 

```cpp
#include <iostream>
 
using namespace std;
 
class Person{
public:
    Person(string _name, unsigned short int _age, unsigned short int _weight ){
        setName(_name);
        setAge(_age);
        setWeight(_weight);
    }
 
    string getName() const{
        return name;
    }
 
    unsigned short int getAge() const{
        return age;
    }
 
    unsigned short int getWeight() const{
        return weight;
    }
 
    void setName(string const & _name){
        name = _name;
    }
 
    void setAge(unsigned short int _age){
        if (_age > 150){
            cout << "There must be a mistake, your age cannot be " << _age
                 << " . I'll set your age to 0"
                 << endl;
            age = 0;
        }else{
            age = _age;
        }
    }
 
    void setWeight(unsigned short int _weight){
        if (_weight > 200){
            cout << "There must be a mistake, your weight cannot be more than " << _weight
                 << " . I'll set your weight to 0"
                 << endl;
            weight = 0;
        }else{
            weight = _weight;
        }
    }
 
private:
    string name;
    unsigned short int age;
    unsigned short int weight;
};
 
int main()
{
    Person me("Alberto", 75, 17);
    cout << "Hello " << me.getName() << ", you are " << me.getAge() << ", you weight "  << me.getWeight() << " kg." << endl;
 
    me.setAge(78);
    cout << "Hello " << me.getName() << ", today you are " << me.getAge() << endl;
 
    return 0;
}
```

Sin embargo mostrar una cadena de texto por pantalla no es el modo más habitual de hacerlo (y de hecho se debe evitar que las funciones `getter` o `setter` interaccionen con el usuario a través de mensajes de texto o pidiendo que se introduzcan valores, las funciones deben interaccionar a través de los valores de retorno y los parámetros).

Un buen modo de gestionar los errores que sucedan en nuestro programa mientras se ejecuta es mediante el uso de excepciones. Veamos cómo lo hacíamos hasta ahora en la función `setAge().

En el ejemplo anterior estamos comprobando la edad, y si no es aceptable, mostramos un error por pantalla, sin embargo, ¿y si este programa no se ejecutara en una pantalla?, o ¿y si quisiéramos volver a preguntarle al usuario su edad cuando la ha introducido mal?, deberíamos “lanzar” alguna señal a nuestro programa de que ha sucedido algo incorrecto. Eso se hace con las **excepciones**.

Las excepciones son como mensajes que enviamos indicando *ey, algo ha ido mal* y que nuestro programa es capaz de eschucar

## Lanzando una Excepción

```cpp
class Person{
public:
     
  ...
   
    void setAge(unsigned short int _age){
        if (_age > 150){
            throw string{"Age cannot be greater than 150"};
        }else{
            age = _age;
        }
    }
 
    ...
   
};
```
El código `throw string{"Age cannot be greater than 150"};` está lanzando una excepción de tipo `string` con el contenido `Age cannot be greater than 150`. Hemos dicho que nuestro programa es capaz de captar las excepciones, ¿cómo? fijate en el ejemplo.

```cpp
int main()
{
    Person someBody;
    try{
        cout << "Please introduce your name: ";
        string name;
        cin >> name;
        someBody.setName(name);
 
        cout << "Please introduce your age: ";
        unsigned short int age;
        cin >> age;
        someBody.setAge(age);
     
    cout << "Please introduce your weight: ";
        unsigned short int weight;
        cin >> weight;
        someBody.setWeight(weight);
    }catch(string msg){
        cout << msg << endl;
        return 1;
    }
 
    return 0;
}
```
La gestión de excepciones siempre tiene la misma estructura:

```cpp
try{
    //instrucciones
}catch(string msg){
    //gestión de excepcions
}
```

Dentro del bloque `try` están las instrucciones habituales de nuestro programa, que queremos ejecutar. A continuación, con la sentencia `catch` comprobamos si se ha lanzado alguna excepción. En el ejemplo probamos si se han lanzado excepciones de tipo `string`.

¿Qué pasa si en este ejemplo introducimos una edad de 200?

1. Llamaríamos a la función `someBody.setAge(age)`; siendo `age` 200.
2. Dentro de la función `setAge` comprobamos el valor del parámetro.
```cpp 
  void setAge(unsigned short int _age){
      if (_age > 150){
          throw string{"Age cannot be greater than 150"};
      }else{
          age = _age;
      }
  }
```
3. Comprobamos que 200 es mayor de 150
4. Lanzamos una excepción tipo `string` con el valor `{“Age cannot be greater than 150”}`

En el momento en el que hemos lanzado una excepción el programa deja de ejecutar las instrucciones que hay dentro de try, y salta al bloque catch. Es decir, este código no se ejecutará.

```cpp   
int main()
{
    ... // a partir de aquí no se ejecuta
    cout << "Please introduce your weight: ";
        unsigned short int weight;
        cin >> weight;
        someBody.setWeight(weight);
 
  ...
}
```

Saltamos directamente al bloque catch

```cpp
int main()
{
    ...
 
    }catch(string msg){
        cout << msg << endl;
        return 1;
    }
 
    return 0;
}
```

Comprobará si la excepción lanzada es de tipo `string`. Como en este caso sí lo es ejecutará las instrucciones que vienen a continuación.

```cpp
   
int main()
{
    ...
 
        cout << msg << endl;
        return 1;
    
}
```
