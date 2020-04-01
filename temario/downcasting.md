# Polimorfismo - Downcasting

En algunos casos nos podemos encontrar con funciones que solo pertenecen a las hijas, y si usamos el polimorfismo como hasta ahora no podríamos invocar. Por ejemplo

```cpp
#include <iostream>
#include <memory>
#include <vector>

class Figura{
public:  
  Figura(){};
  virtual ~Figura(){};

  virtual float getArea() const  = 0;
  virtual std::string getTipo() const = 0;

};

class Cuadrado: public Figura{
public:
  Cuadrado(float a):lado{a} {}
  float getArea() const{
    return lado*lado;
  }

  std::string getTipo() const {
    return "cuadrado";
  }

private:
  float lado;
};

class Triangulo: public Figura{
public:
  Triangulo(float base, float altura): base{base}, altura{altura} {}

  float getArea() const{
    return base*altura/2;
  }

  std::string getTipo() const {
    return "triangulo";
  }

  float getAltura() const {
    return altura;
  }
  
private:
  float base;
  float altura;
};

int main(){
  std::vector<std::unique_ptr<Figura>> figuras;

  figuras.push_back(std::make_unique<Triangulo>(4,5));
  figuras.push_back(std::make_unique<Cuadrado>(3));
  figuras.push_back(std::make_unique<Cuadrado>(2));

  for(auto const & elem: figuras){
    if(elem->getTipo() == "triangulo"){
      std::cout << elem->getAltura(); // ERROR, porque elem es de tipo Figura, y Figura no tiene getAltura
    }
  }
}
```

¿Por qué da un error?

Cuando entramos en `for` y recorremos las figuras llegamos a una figura que sabemos que es un `Triangulo` (`if(elem->getTipo() == "triangulo")` ). Sin embargo, `elem` es de tipo `Figura`, porque el vector es de `Figura`. Como la clase `Figura` no tiene la función `getArea()`, da un error de compilación, sin embargo ¡nosotros sabemos que es un triángulo!, y que esa función existe.

¿Cómo lo resolvemos? Haciendo *downcasting*, que es convirtiendo un tipo de la clase Padre en un tipo de la clase Hija. Es decir, vamos a convertir una `Figura` en un `Triangulo`. Esto es posible por dos motivos:
 * `Triangulo` hereda de `Figura` (si no fuera asi no se podria)
 * Sabemos que esa `Figura` es en realidad un `Triangulo` (si fuera un cuadrado no funcionaría)

Esta línea se encarga de transformar `elem` en un `Triangulo` (porque se cumplen las dos condiciones anteriores)

`Triangulo* t = dynamic_cast<Triangulo*>(elem.get());`

¿Qué está pasando aquí?

1. Creamos una variable tipo `Triangulo*` (puntero clásico).
2. Realizamos un *casting* (conversión de tipos): `dynamic_cast`
3. Indicamos qué tipo deseamos obtener: `<Triangulo*>`.
4. Obtenemos el *puntero clásico* asociado a `elem` (que es un *puntero inteligente*): `elem.get()`.

Ahora `t` es un `Triangulo`, y por lo tanto, podemos acceder a su función `getArea()`.

El programa completo quedaria así: 

```cpp
#include <iostream>
#include <memory>
#include <vector>

class Figura{
public:  
  Figura(){};
  virtual ~Figura(){};

  virtual float getArea() const  = 0;
  virtual std::string getTipo() const = 0;

};

class Cuadrado: public Figura{
public:
  Cuadrado(float a):lado{a} {}
  float getArea() const{
    return lado*lado;
  }

  std::string getTipo() const {
    return "cuadrado";
  }

private:
  float lado;
};

class Triangulo: public Figura{
public:
  Triangulo(float base, float altura): base{base}, altura{altura} {}

  float getArea() const{
    return base*altura/2;
  }

  std::string getTipo() const {
    return "triangulo";
  }

  float getAltura() const {
    return altura;
  }
  
private:
  float base;
  float altura;
};

int main(){
  std::vector<std::unique_ptr<Figura>> figuras;

  figuras.push_back(std::make_unique<Triangulo>(4,5));
  figuras.push_back(std::make_unique<Cuadrado>(3));
  figuras.push_back(std::make_unique<Cuadrado>(2));

  for(auto const & elem: figuras){
    if(elem->getTipo() == "triangulo"){
      Triangulo* t = dynamic_cast<Triangulo*>(elem.get());
      std::cout << t->getAltura();
    }
  }
}
```

## ¿Qué pasa si la conversión no es válida?

¿Qué pasa si intentamos convertir algo que no se puede? Por ejemplo, si intentamos convertir un `Cuadrado` en un `Triangulo`, como en este ejemplo:

```cpp
int main(){
  auto c = std::make_unique<Cuadrado>(3);
  Triangulo* t = dynamic_cast<Triangulo*>(c.get());
}
```

El programa compilará correctamente, porque el `dynamic_cast` se realiza en tiempo de ejecución, sin embargo la conversión no será posible.

Entonces `t` será `nullptr`. Por lo tanto, si queremos acceder a `getAltura()` deberíamos asegurarnos que la conversión ha sido correcta.

```cpp
int main(){
  auto c = std::make_unique<Cuadrado>(3);
  Triangulo* t = dynamic_cast<Triangulo*>(c.get());
  if(t) t->getAltura();
}
```

Cuando hacemos `if(t)` comprobamos si `t` apunta a algo, es decir, sería lo mismo que hacer `if(t != nullptr)`.

