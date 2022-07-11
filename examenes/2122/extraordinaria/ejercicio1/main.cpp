#include <iostream>

using namespace std;

int sumaDigitos(int numEntero){
    int sumDigit{0};
    while(numEntero != 0) {
        sumDigit += numEntero % 10;;
        numEntero /= 10;
    }
    return sumDigit;
}

int main()
{
    cout << "Introduce un número: ";
    int num{0}; cin >> num;
    std::cout << "La suma de los dígitos es " << sumaDigitos(num) << "\n";
    return 0;
}
