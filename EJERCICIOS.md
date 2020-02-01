1. Crear una clase Person que contenga los siguientes atributos:
   1. Nombre.
   2. Edad. Debe ser mayor o igual que 0.
   3. Teléfono. Debe tener siempre 9 dígitos.

Se deben crear además las funciones `get` y `set` necesarias para poder acceder a los datos además de una función `print` que permita mostrar por pantalla los datos de la persona.

A continuación crear un programa que almacene un listín de personas. El programa debe permitir:
  * Añadir una persona al listín (no puede haber nombres repetidos).
  * Listar todas las personas (utilizar preferentemente programación funcional)
  * Buscar una persona por nombre (utilizar preferentemente programación funcional).
  * Listar todas las personas de una determinada edad (utilizar preferentemente programación funcional).

2. Modificar el ejercicio anterior creando una *clase Listin* que para almacenar y manipular el listín de personas.
   
3. Realizar un programa que contenga una clase llamada `NumeroPositivo`. La clase tiene un solo atributo numero de tipo decimal
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