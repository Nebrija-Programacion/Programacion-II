# Herencia

## ¿Qué es la herencia?

Una de las máximas de la Programación Orientada a Objetos es la reutilización del código. Por ejemplo, si hacemos una clase Persona, con sus variables y funciones miembro, ese código podremos reutilizarlo en cualquier programa en el que necesitemos *Personas*.

Uno de los mecanismos más importantes para la reutilización de código y su mantenibilidad en la POO es la **herencia**.

La **herencia** consiste, fundamentalmente, en la construcción de tipos de datos (*Objetos*) pasando de lo más genérico a lo más particular.

Por ejemplo, si quisiéramos crear un tipo de dato `Triangulo`, podríamos decir que un `Triangulo equilatero` **es una** `figura geométrica regular`. Si en otro programa deseamos crear un `Cuadrado` se puede decir que un cuadrado también **es una**  `figura geométrica regular`. ¿Y si queremos hacer un `pentágono regular`?, vaya también **es una**  `figura geométrica regular`. 

Esto quiere decir que `Triángulo Equilatero`, `Cuadrado` y `Pentágono regular` deben compartir algunos atributos y funciones por el hecho de que todas **son** `Figuras geométricas regulares`. Analicemos cuáles son esos atributos compartidos:

 * longitud lado. Todas las figuras regulares, y por lo tanto estas tres, tienen una longitud de lado.
 * numero de lados. Todas tienen un número de lados.

¿y qué funciones comparten?

 * calcular Perímetro. Podemos saber el perímetro de un figura geométrica (sea cual sea) a partir del número de lados y su longitud.
 * calcular Area. El área de cualquier figura geométrica es `perímetro * apotema / 2`.

Pero también tienen miebros que las diferencian unas de otras:
 * El `triángulo` tiene altura.
 * El `cuadrado` tiene diagonal.
 * etc.

Esta es toda la filosofía que hay detrás de la herencia en la programación orientada a objetos. Se pasa de lo más genérico (`Figura Geométrica Regular`) a lo más particular (`Triángulo`, `Cuadrado`, etc.).

Decimos que `Triangulo`, `Cuadrado` y `Pentágono regular` **heredan** de `Figura Geométrica Regular`. Para saber cuando la herencia está bien planteada se debe cumplir la relación **is-a** , *es un/a*. 

Por ejemplo `Triangulo` **is-a** `Figura Geométrica`. Por lo tanto la herencia es correcta.

¿Otro ejemplo de herencia?. Imaginemos que queremos hacer un programa que trabaje con Profesores y Alumnos. ¿Qué tienen en común (desde el punto de vista de la herencia)? Todos ellos son Personas. Por lo tanto, podríamos construir un modelo de herencia en el que la clase `Profesor` y la clase `Alumno` hereden de una clase `Persona`. Porque ambos cumplen la relación **is-a**.

## Herencia en C++

Para implementar la herencia en C++ empezamos por la clase mas genérica, por ejemplo el caso de lsa figuras, empezaríamos implementando la clase `Figura Geométrica Regular`.

```cpp
class FigGeomRegular {
  public:
   FigGeomRegular(float _long, float _lados);
   float getArea() const;
   float getPerimeter() const;

  private:
    int n_lados;
    float longitud;
};
```

A continuación implemtamos la clase `Triangulo Equilatero`, indicando que deriva de `FigGeomRegular`.

```cpp
class TrianguloEq: public FigGeomRegular{
  TrianguloEq(float _long);
  float getHeight() const;
};
``` 

¿Qué pasa cuando `TrianguloEq` hereda **publicamente** de `FigGeometricaRegular`? Sucede que todos los atributos y funciones de la clase `FigGeometricaRegular` lo son también de `Triangulo`.

Es decir, en nuestro `main.cpp` podríamos hacer lo siguiente.

```cpp

int main() {
  TrianguloEq unTriangulo{5};
  std::cout << unTriangulo.getArea() << "\n";
  std::cout << "Hello World!\n";
} 
```

Observamos, que se llama a `unTriangulo.getArea()`, aunque la función `getArea()` está definida en la clase `FigGeometricaRegular`. Esto es así porque `Triangulo` hereda de `FigGeometricaRegular`.

Realizar los [ejercicios 8 y 9 de la colección](../EJERCICIOS.md).