#include <iostream>

using namespace std;

int maximo_comun_divisor(int n1, int n2){
    int min = n1<n2?n1:n2;

    for(int i{min}; i>0; i--){
        if(n1 % i == 0 && n2 % i == 0) return i;
    }
}

int main()
{
    cout << "Introduce 2 números separados por un espacio: " << endl;
    int n1,n2; cin >> n1 >> n2;
    cout << "El máximo común divisor de " << n1 << " y " << n2 << " es: " << maximo_comun_divisor(n1, n2) << "\n";
    return 0;
}
