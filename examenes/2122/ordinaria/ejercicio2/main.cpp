#include <iostream>

using namespace std;

string nveces(string const & cad, int n){
    if(n<=0) throw string{"Number must be positive"};
    string result{""};
    for(int i=0; i<n; i++){
        result+=cad;
    }
    return result;
}

int main()
{
    cout << nveces("hola", 3);
    return 0;
}
