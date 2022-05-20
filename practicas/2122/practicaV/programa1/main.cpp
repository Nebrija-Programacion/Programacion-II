#include <iostream>
#include <vector>

using namespace std;

bool esPrimo(int n){
    for(int i{2}; i <= n/2; i++){
        if(n%i == 0) return false;
    }

    return true;
}

vector<int> factores(int n){
    vector<int> result;
    for(int i{2}; i <= n/2; i++){
        if(esPrimo(i) && n%i == 0) result.push_back(i);
    }

    return result;
}


int main()
{
    cout << "Introduce un número entero: ";
    int n; cin >> n;
    cout << "Los factores de " << n << " son: ";
    for(auto f: factores(n)) cout << f << ", ";

    return 0;
}
