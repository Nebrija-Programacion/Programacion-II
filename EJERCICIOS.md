### Ejercicio 1
Crear una clase Person que contenga los siguientes atributos:
   1. Nombre.
   2. Edad. Debe ser mayor o igual que 0.
   3. Teléfono. Debe tener siempre 9 dígitos.

Se deben crear además las funciones `get` y `set` necesarias para poder acceder a los datos además de una función `print` que permita mostrar por pantalla los datos de la persona.

A continuación crear un programa que almacene un listín de personas. El programa debe permitir:
  * Añadir una persona al listín (no puede haber nombres repetidos).
  * Listar todas las personas (utilizar preferentemente programación funcional)
  * Buscar una persona por nombre (utilizar preferentemente programación funcional).
  * Listar todas las personas de una determinada edad (utilizar preferentemente programación funcional).

### Ejercicio 2

Modificar el ejercicio anterior creando una *clase Listin* que para almacenar y manipular el listín de personas.
   
### Ejercicio 3

Realizar un programa que contenga una clase llamada `NumeroPositivo`. La clase tiene un solo atributo numero de tipo decimal
La clase tiene las funciones `setter` y `getter` oportunas y estas otras funciones miembro:
  * `divideBy(float otherNumber);` que devuelve el resultado de dividir número por otro número (y modifica el número en cuestión).
  * `multiplyBy(float otherNumber);` que devuelve el resultado de multiplicar por otro número (y modifica el número en cuestión).
  * `add(float otherNumer);` que devuelve el resultado de sumar otro número (y modifica el número en cuestión).

La función `divideBy` debe lanzar una excepción (tipo `string`) cuando se intentar realizar una división por 0.

El programa debe:

  1. Pedirle al usuario que introduzca un número
  2. Pedirle al usuario un número por el que desee dividir (y mostrar el resultado por pantalla)
  3. Pedirle al usuario un número por el que desee multiplicar (y mostrar el resultado por pantalla)
  4. Pedirle al usuario un número que desee sumar (y mostrar el resultado por pantalla)

### Ejercicio 4
Crear una clase matriz que reciba a través del constructor el número de filas y columnas.

1. Sobrecargar los operadores `+`, `-`, `*` para que se realicen las operaciones aritméticas oportunas.
2. Sobrecargar el operador `<<` para mostrar por pantalla la matriz en filas y columnas.

### Ejercicio 5
Templatizar las funciones `suma`, `resta` y `multiplicacion` para que puedan recibir:
  * 2 enteros -> devolverá un entero.
  * 2 decimales -> devolverá un decimal.
  * 2 matrices -> devolverá una matriz.

### Ejercicio 6
Realizar un clase `Persona` que contenga los siguientes datos miembro:
  * Nombre
  * Edad
  * DNI

Realizar un programa que a partir de una función templatizada `find` (a través de programación funcional) recorra un `vector` de **punteros a `Persona`** y devuelva:
  * el puntero a la persona cuyo DNI coincida con el buscado.
  * `nullptr` si no encontramos nadie con dicho DNI.

### Ejercicio 7

 1. Crear una clase `Pair` que admita una clave y un valor. Los tipos de la clave y el valor estarán templatizados.
 2. Crear una clase templatizada `Data` que contenga un vector de `Pair`.
 3. Crear una clase templatizada `DB` que contenga un vector de punteros a `Data`.
 4. Realizar las siguientes funciones miembro de la clase `DB`
    1. `find()` -> devuelve el puntero al primer `Data` que contenga el criterio de búsqueda.
    2. `filter()` -> devuelve una variable de tipo `DB` con los punteros a `Data` que cumplan el criterior de búsqueda.
    3. `forEach()` -> recorre todos los elementos `Data` de `DB` realizando alguna operación sobre ellos.
 5. Sobrecargar el operador >> para `Pair`, `Data` y `DB`, de modo que se puedan mostrar por pantalla usando `std::cout << var`
Crear un programa `main` que realice lo siguiente

 1. Crea una variable de tipo `DB<string, string>`
 2. La rellena con los siguientes datos

```json
  [
    {
      "nombre": "Julian",
      "apellido": "Santurche",
      "telefono": "32323232",
    },
    {
      "nombre": "Alberto",
      "apellido": "Valero",
      "telefono": "12345644",
    },
    {
      "nombre": "Julian",
      "apellido": "Romeva",
      "telefono": "12345644",
      "DNI": "23232334J",
    },
    {
      "nombre": "Lucrecia",
      "apellido": "Aveces",
      "email": "lalucre@gmail.com",
    },
  ]
```

 2. Utilizar la función `find` para encontrar la primera ocurrencia de `nombre: Julian`
 3. Utilizar la función `filter` para encontrar todas las ocurrencias de `nombre: Julian`
 4. Mostrar los correspondientes resultados por pantalla usando el operador `<<>