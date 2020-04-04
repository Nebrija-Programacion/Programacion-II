#include <iostream>
#include "matrix.h"
#include "functions.h"


int main()
{
    try{
        std::cout << "Introduce el numero de filas y columnas de la matriz 1: ";
        int fil, cols;
        std::cin >> fil >> cols;
        Matrix mat1{fil, cols};
        std::cout << "Introduce la matriz, numero a numero, por filas:\n";
        std::cin >> mat1;

        std::cout << "Introduce el numero de filas y columnas de la matriz 2: ";

        std::cin >> fil >> cols;
        Matrix mat2{fil, cols};
        std::cout << "Introduce la matriz, numero a numero, por filas:\n";
        std::cin >> mat2;

        Matrix s = suma(mat1,mat2);
        Matrix r = resta(mat1,mat2);
        Matrix m = multiplicacion(mat1, mat2);
        std::cout << "Suma\n" << s << "\n\n";
        std::cout << "Resta\n" << r << "\n\n";
        std::cout << "Multiplicación\n" << m << "\n\n";

    }catch(std::string e){
        std::cout << e << "\n";
    }

    return 0;
}
