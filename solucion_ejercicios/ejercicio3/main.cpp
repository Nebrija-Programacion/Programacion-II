#include <iostream>
#include "numeropositivo.h"

int main()
{
    float num{0};
    std::cout << "Introduce un numero positivo: ";
    std::cin >> num;
    try{
        NumeroPositivo numPosi{num};
        std::cout << "Dividirlo por ... ";
        std::cin >> num;
        std::cout << numPosi.divideBy(num) << "\n";
        std::cout << "Multiplicarlo por ... ";
        std::cin >> num;
        std::cout << numPosi.multiplyBy(num) << "\n";
        std::cout << "Sumarle ... ";
        std::cin >> num;
        std::cout << numPosi.add(num) << "\n";
    }catch(std::string e){
        std::cout << e << "\n";
    }
    return 0;
}
