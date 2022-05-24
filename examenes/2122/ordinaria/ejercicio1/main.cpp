#include <iostream>

using namespace std;

int computeNumber(int n){
    if(n <= 0) throw string{"number must be positive"};
    for(int i=n-1; i>=0; i--){
        if(i%3 == 0) return i;
    }
}

int main()
{
    cout << computeNumber(6) << "\n";
    cout << computeNumber(11) << "\n";
    cout << computeNumber(2) << "\n";
    return 0;
}
