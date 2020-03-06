# Práctica III - Enunciado

## PASO I (1 punto) 
Crear una clase `Pair` que admita una clave y un valor. Los tipos de la clave y el valor estarán templatizados.

## PASO II (1 puntos)
Crear una clase templatizada `Data` que contenga un vector de `Pair`.

## PASO III (2 puntos)
Crear una clase templatizada `DB` que contenga un vector de punteros a `Data`.
 1. Realizar las siguientes funciones miembro de la clase `DB`
    1. `find()` -> devuelve el puntero al primer `Data` que contenga el criterio de búsqueda.
    2. `filter()` -> devuelve una variable de tipo `DB` con los punteros a `Data` que cumplan el criterior de búsqueda.
    3. `forEach()` -> recorre todos los elementos `Data` de `DB` realizando alguna operación sobre ellos.
## PASO IV (2 puntos)
Sobrecargar el operador `<<` para `Pair`, `Data` y `DB`, de modo que se puedan mostrar por pantalla usando `std::cout << var`

## PASO V (4 puntos)
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
 4. Mostrar los correspondientes resultados por pantalla usando el operador `<<`