#include <iostream>
#include "punterointeligente.h"
using namespace std;

int main()
{
    PunteroInteligente<int> pUnt{5};
    {
        std::cout << "Empiezo\n";
        PunteroInteligente<int> pInt{3};
        std::cout << *pInt.get() << "\n"; // 3
        std::cout << *pUnt.get() << "\n"; // 5
    }

    std::cout << "Acabo\n";
    return 0;

    /*
     * Empiezo
     * 3
     * 5
     * Libero espacio de memoria // destructor de pInt
     * Acabo
     * Libero espacio de memoria // destructor de pUnt
     */
}
