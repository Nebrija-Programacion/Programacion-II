# Práctica I - Enunciado

Se desea crear una clase que permita operar con matrices genéricas.

### Paso 1 (2 puntos).
Crear una clase que permita albergar matrices de cualquier dimensión. 
 * La dimensioń de la matriz se pasará como dos parámetros a través del constructor.
 * La matriz se inicializará siempre a 0 en todos sus elementos.

### Paso 2 (2 putnos).
 1. Crear una función `get(row, col)` que nos devuelva el valor del elemento de la fila y columna pasada por parámetro. Esta función debe gestionar con excepciones cuando la fila y columna están fuera de rango.
 2. Crear una función `set(row, col, value)` que nos permita dar valor al elemento de la fila y columna pasada por parámetro. Esta función debe gestionar con excepciones cuando la fila y columna están fuera de rango.

### Paso 3(2 puntos)
Crear una función `print` que muestre la matriz por pantalla en filas y columnas.

### Paso 4 (2 puntos).

Crear una función `add(otherMatrix)`que sume la matriz con otra matriz pasada por parámetro. La función debe gestionar a través de excepciones cuando las matrices no se puedan sumar (porque las dimensiones no son compatibles).

### Paso 5 (2 puntos).

Crear una función `multiplyBy(otherMatrix)`que multiplique la matriz por otra matriz pasada por parámetro. La función debe gestionar a través de excepciones cuando las matrices no se pueden multiplicar (porque las dimensiones no son compatibles).