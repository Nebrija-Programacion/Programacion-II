# Templates - Clases Templatizadas

Al igual que las funciones se pueden templatizar, las Clases también pueden tener miembros (tanto variables como funciones) cuyos tipos estén definidos en plantillas (o templates).

La sintaxis para templatizar una clase es equivalente a la que se usa para templatizar una función. 

Por ejemplo, vamos a crear una clase `Pair` que tenga dos campos: `key` y `value`, de modo que asocie a una clave (`key`) un valor determinado. La clase `Pair` estará templatizada, es decir, no sabremos a priori los tipos de `key` y de `value`

## Declaración de la clase templatizada

```cpp
template <typename K, typename V>
class Pair{
public:
  Pair(K v0, V v1);
K key() const;
V value() const;
private:
  K _key;
  V _value;

};
``` 

La clase `Pair` tiene:
 * Una variable miembro privada `_key` de tipo `K` 
 * Una variable miembro privada `_value` de tipo `V`
 * Un constructor que inicializa `_key` y `_value` según sus tipos correspondientes
 * Una función `key()` que devuelve la clave
 * Una función `value()` que devuelve el valor.

## Definción de una clase templatizada

La definción de la clase templatizada **debe estar en el archivo .h**. Con en cuaquier clase definiremos cada uno de sus métodos, usando en este caso la sintaxis de las plantillas en C++.

```cpp
template <typename K, typename V>
Pair<K,V>::Pair(K v0, V v1){
  _key = v0;
  _value = v1;
}


template <typename K, typename V>
V Pair<K,V>::value() const{
  return _value;
}

template <typename K, typename V>
K Pair<K,V>::key() const{
  return _key;
}
``` 


Una vez definida y declarada la clase templatizada `Pair` podemos usarla del siguiente modo:

```cpp
int main() {
  Pair<std::string, int> myPair{"tel", 34434423};
  std::cout << myPair.key() << ":" << myPair.value() << "\n"; // tel:34434423
  return 0;
}
``` 