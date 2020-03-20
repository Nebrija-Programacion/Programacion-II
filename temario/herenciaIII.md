# Herencia. Miembros públicos, protegidos y privados

Vamos a ver quién puede acceder a los miembros de cada clase en función de dos parámetros.
  * El miembro es público, protegido o privado.
  * La herencia es públic, protegida o privada.


## Herecia pública

Se refiere a la herencia en la que todos los miembros públicos y protegidos de la clase base conservan esos mismos niveles de acceso respectivamente en las clases derivadas.

Del tipo

```cpp
class Padre{

};

class Hijo: public Padre{

};
```

|        | public Padre | protected Padre | private Padre | public Hijo | protected Hijo | private Hijo |
| ------ | ------------ | --------------- | ------------- | ----------- | -------------- | ------------ |
| Padre  | x            | x               | x             |             |                |              |
| Hijo   | x            | x               |               | x           | x              | x            |
| Global | x            |                 |               | x           |                |              |


## Herecia protegida

Se refiere a la herencia en la que todos los miembros públicos de la clase base adquieren el nivel de acceso protegido en las clases derivadas, mientras que los miembros protegidos conservan su nivel de acceso. Lo anterior indica que una clase derivada puede luego heredar a otra clase los miembros protegidos que heredó de su clase base.

Del tipo

```cpp
class Padre{

};

class Hijo: protected Padre{

};
```

|        | public Padre | protected Padre | private Padre | public Hijo | protected Hijo | private Hijo |
| ------ | ------------ | --------------- | ------------- | ----------- | -------------- | ------------ |
| Padre  | x            | x               | x             |             |                |              |
| Hijo   | x            | x               |               | x           | x              | x            |
| Global |              |                 |               | x           |                |              |

## Herecia privada

Se refiere a la herencia en la que todos los miembros públicos y protegidos de la clase base adquieren el nivel de acceso privado en las clases derivadas. De ahí se desprende que una clase derivada que haya heredado mediante herencia privada no puede heredar a otras clases los miembros que ha heredado de otras clases.

Del tipo

```cpp
class Padre{

};

class Hijo: private Padre{

};

class Nieto: private Hijo{

}
```

|        | miembros Padre | public/protected Hijo | private Hijo | public Nieto | protected Nieto | private Nieto |
| ------ | -------------- | --------------------- | ------------ | ------------ | --------------- | ------------- |
| Nieto  |                | x                     |              | x            | x               | x             |
| Global |                |                       |              | x            |                 |               |
