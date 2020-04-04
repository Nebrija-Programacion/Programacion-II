#include <string>
#include "numeropositivo.h"

NumeroPositivo::NumeroPositivo(float n)
{
    setNum(n);
}

float NumeroPositivo::getNum() const
{
    return num;
}

void NumeroPositivo::setNum(float value)
{
    if(value <= 0) throw std::string{"El numero debe ser positivo"};
    num = value;
}

float NumeroPositivo::divideBy(float other)
{
    if(other==0) throw std::string{"No se puede dividir por 0"};
    if(other <0) throw std::string{"No pudedes dividir por un numero negativo"};
    num /= other;
    return num;
}

float NumeroPositivo::multiplyBy(float other)
{
    if(other<=0) throw std::string{"No se puede multiplicar por un numero menor o igual que 0"};
    num *= other;
    return num;
}

float NumeroPositivo::add(float other)
{
    float aux = num + other;
    if(aux<=0) throw std::string{"El resultado no es un numero positivo"};
    num = aux;
    return num;
}
