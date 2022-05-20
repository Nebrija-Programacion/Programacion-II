#include <iostream>

using namespace std;

int minimo_comun_multiplo(int n1, int n2){
    int max = n1>n2?n1:n2;

    for(int i{max}; true; i++){
        if(i % n1 == 0 && i % n2 == 0) return i;
    }
}

int main()
{
    cout << "Introduce 2 números separados por un espacio: " << endl;
    int n1,n2; cin >> n1 >> n2;
    cout << "El mínimo común múltiplo de " << n1 << " y " << n2 << " es: " << minimo_comun_multiplo(n1, n2) << "\n";
    return 0;
}
