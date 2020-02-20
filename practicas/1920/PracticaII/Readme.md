# Práctica I - Enunciado

Se desea crear una clase que permita operar con matrices genéricas.

### Paso 1 (1 puntos).
Crear una clase que permita albergar matrices de cualquier dimensión. 
 * La dimensioń de la matriz se pasará como dos parámetros a través del constructor.
 * La matriz se inicializará siempre a 0 en todos sus elementos.

 1. Crear una función `get(row, col)` que nos devuelva el valor del elemento de la fila y columna pasada por parámetro. Esta función debe gestionar con excepciones cuando la fila y columna están fuera de rango.
 2. Crear una función `set(row, col, value)` que nos permita dar valor al elemento de la fila y columna pasada por parámetro. Esta función debe gestionar con excepciones cuando la fila y columna están fuera de rango.

### Paso 3(2 puntos)
1. Sobrecargar el operador `<<`para imprimir la matriz por filas y columnas.
2. Buscar en internet cómo sobrecargar el operador `>>` para poder introducir todos los elementos de la matriz por teclado de una sola vez.

```cpp
Matrix mat1{2,2};
cin >> mat1; // el usuario teclea 3 4 1 2 (enter) para introducir estos números en la matriz.
```

### Paso 4 (2 puntos).
Sobrecargar los operadores `+`, `-`, `*` para poder realizar operaciones aritméticas con matrices.

### Paso 5 (3 puntos).
Crear la función miembro `determinant` que devuelva el determinante de la matriz (en el caso de que éste exista, en caso de que no exista debe lanzar una excepción).